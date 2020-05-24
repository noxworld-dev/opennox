cmake_minimum_required (VERSION 3.11)
project (nox-port)

# Set default build type
if (NOT CMAKE_BUILD_TYPE)
    message (STATUS "Build type not set - defaulting to Release")
    set (
        CMAKE_BUILD_TYPE "Release"
        CACHE
        STRING
        "Choose the type of build from: Debug Release RelWithDebInfo MinSizeRel Coverage."
        FORCE)
endif ()

option (USE_ASAN "Enable address sanitizer" OFF)
option (STRICT_MODE "Fail on compilation warnings" OFF)

if (MSVC)
    add_compile_options ("$<$<CONFIG:DEBUG>:/RTCs>")
else ()
    add_compile_options (-g -fno-strict-aliasing -fno-strict-overflow -m32 -fshort-wchar -Werror=return-type -Werror=implicit-function-declaration)

    if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
        add_compile_options (-O0)
        add_definitions (-DNOX_NO_MOUSE_GRAB)
    else ()
        add_compile_options (-O3)
    endif ()

    if (STRICT_MODE)
        add_compile_options (-Werror=incompatible-pointer-types)
        add_compile_options (-Werror=int-conversion)
    endif ()

    if (USE_ASAN)
        add_compile_options (-fsanitize=address)
    endif ()

    if (${CMAKE_SYSTEM_NAME} STREQUAL "Emscripten")
        add_compile_options (-s USE_SDL=2)
    endif ()
endif ()
include_directories (external/include)
link_directories (${PROJECT_SOURCE_DIR}/external/lib)
if (WIN32)
    set (OPENAL_LIBRARIES openal)
    set (OPENGL_LIBRARIES glew32 opengl32)
    set (WIN32_LIBRARIES ws2_32 winmm)
elseif (APPLE)
    set (OPENAL_LIBRARIES "-framework OpenAL")
    set (OPENGL_LIBRARIES "-framework OpenGL")
else ()
    set (OPENAL_LIBRARIES openal)
    set (OPENGL_LIBRARIES GL)
    set (PTHREAD_LIBRARIES pthread)
endif ()

if (WIN32)
    set (COMPAT_SOURCES compat_mss.c)
else ()
    set (COMPAT_SOURCES compat.c compat_mss.c)
endif ()

add_executable (
    out
    ConvertUTF.c
    platform.c
    e2e.c
    GAME1.c
    GAME1_1.c
    GAME1_2.c
    GAME1_3.c
    GAME2.c
    GAME2_1.c
    GAME2_2.c
    GAME2_3.c
    GAME3.c
    GAME3_1.c
    GAME3_2.c
    GAME3_3.c
    GAME4.c
    GAME4_1.c
    GAME4_2.c
    GAME4_3.c
    GAME5.c
    GAME5_2.c
    GAME_data.c
    GAME_data_init.c
    cdrom.c
    draw.c
    imm.c
    input.c
    main.cpp
    movie.c
    sm.c
    noxstring.c
    win.c
    memmap.c
    static.c
    MixPatch.c
    GameEx.c
    memfile.c
    thing.c
    common/system/settings.c
    server/system/server.c
    server/system/trade.c
    server/system/cscrfunc.c
    server/object/health.c
    server/object/objutil.c
    server/object/die/die.c
    server/object/pickdrop/pickup.c
    server/dbase/objdb.c
    server/gamemech/explevel.c
    server/magic/spell/execdur.c
    server/magic/plyrspel.c
    server/magic/plyrgide.c
    server/ability/ability.c
    server/xfer/savegame/savegame.c
    server/mapgen/generate/populate.c
    server/network/playback.c
    server/network/sdecode.c
    server/network/mapsend.c
    client/audio/auddiag.c
    client/draw/animdraw.c
    client/draw/canidraw.c
    client/draw/mgendraw.c
    client/draw/vectdraw.c
    client/drawable/drawable.c
    client/gui/chaticon.c
    client/gui/guimsg.c
    client/io/console.c
    client/shell/wolapi/locale.c
    client/shell/wolapi/wolchat.c
    client/shell/wolapi/wollogin.c
    client/shell/wolapi/woldlgs.c
    client/shell/wolapi/wolprog.c
    client/shell/wolapi/wolreg.c
    vqa/aud_decode.cpp
    vqa/ddpf_conversion.cpp
    vqa/vqa_decode.cpp
    vqa/vqa_file.cpp
    vqa/vqa_public.cpp
    "${COMPAT_SOURCES}"
)
if (${CMAKE_SYSTEM_NAME} STREQUAL "Emscripten")
    set (WASM_FLAGS "-g -o out.html --pre-js ${CMAKE_SOURCE_DIR}/pre.js -lidbfs.js -s CASE_INSENSITIVE_FS=1 -s ASYNCIFY -s TOTAL_MEMORY=201326592 -s EMULATE_FUNCTION_POINTER_CASTS=1 -s ASSERTIONS=2 -mnontrapping-fptoint -s EXIT_RUNTIME=1")
endif ()
target_link_libraries (
    out
    "${WASM_FLAGS}"
    SDL2
    "${OPENAL_LIBRARIES}"
    "${OPENGL_LIBRARIES}"
    "${PTHREAD_LIBRARIES}"
    "${WIN32_LIBRARIES}"
)
if (MSVC)
else ()
    target_link_options (out PUBLIC -m32)
    if (USE_ASAN)
        target_link_options (out PRIVATE -fsanitize=address)
    endif ()
endif ()
