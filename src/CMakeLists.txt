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
option (E2E_TEST "Run in end-to-end test mode" OFF)

option (USE_OPENAL "Use OpenAL in Nox, disabling results in no sound" ON)
option (USE_OPENGL "Use OpenGL in Nox, disabling results in running in SDL Rendering" ON)

if (MSVC)
    add_compile_options ("$<$<CONFIG:DEBUG>:/RTCs>")
else ()
    if (CMAKE_CL_64)
        add_compile_options( -m32 )
    endif ()
    add_compile_options (-g -fshort-wchar)
    add_compile_options (-fno-strict-aliasing)
    add_compile_options (-fno-strict-overflow)

    add_compile_options (-Werror=return-type)
    add_compile_options (-Werror=implicit-function-declaration)
    add_compile_options (-Werror=pointer-arith)
    add_compile_options (-Werror=implicit-int)
    add_compile_options (-Werror=unused-label)
    add_compile_options (-Werror=address)

    if (${CMAKE_SYSTEM_NAME} STREQUAL "Emscripten")
        add_compile_options (-Werror=bad-function-cast)
    else ()
        add_compile_options (-Werror=cast-function-type)
    endif ()

    if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
        add_compile_options (-O0)
        add_definitions (-DNOX_NO_MOUSE_GRAB)
        add_definitions (-DNOX_DEBUG)
    else ()
        add_compile_options (-O3)
    endif ()

    if (E2E_TEST)
        add_definitions (-DNOX_PREDICTABLE)
        add_definitions (-DNOX_E2E_TEST)
    endif ()

    if (STRICT_MODE)
        add_compile_options (-Werror=incompatible-pointer-types)
        add_compile_options (-Werror=int-conversion)
    else ()
        # TODO: make those errors eventually
        add_compile_options (-Wno-pointer-to-int-cast)
        add_compile_options (-Wno-int-to-pointer-cast)
        add_compile_options (-Wno-incompatible-pointer-types)
        add_compile_options (-Wno-int-conversion)
        add_compile_options (-Wno-format)
        add_compile_options (-Wno-shift-count-overflow)
        add_compile_options (-Wno-pedantic)
        add_compile_options (-Wno-bad-function-cast)
        add_compile_options (-Wno-strict-prototypes)
        if (${CMAKE_SYSTEM_NAME} STREQUAL "Emscripten")
            add_compile_options (-Wno-ignored-qualifiers)
            add_compile_options (-Wno-return-stack-address)
            add_compile_options (-Wno-pointer-sign)
        else ()
            add_compile_options (-Wno-discarded-qualifiers)
            add_compile_options (-Wno-return-local-addr)
        endif ()
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
    find_library (SDL2_LIBRARIES SDL2.lib OPTIONAL)
    find_library (OPENAL_LIBRARIES OpenAL32.lib)
    find_library (OPENGL_LIBRARIES OpenGL32.lib)
    find_library (GLEW_LIBRARIES    glew32.lib)
    set (WIN32_LIBRARIES ws2_32 winmm)
elseif (APPLE)
    set (OPENAL_LIBRARIES "-framework OpenAL")
    set (OPENGL_LIBRARIES "-framework OpenGL")
elseif (${CMAKE_SYSTEM_NAME} STREQUAL "Emscripten")
    set (SDL2_LIBRARIES SDL2)
    set (OPENAL_LIBRARIES openal)
    set (OPENGL_LIBRARIES GL)
    set (PTHREAD_LIBRARIES pthread)
else ()
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(SDL2 REQUIRED sdl2)
    set (OPENAL_LIBRARIES openal)
    set (OPENGL_LIBRARIES GL)
    set (PTHREAD_LIBRARIES pthread)
endif ()

if(NOT USE_OPENAL)
    set (OPENAL_LIBRARIES a)
    set (OPENAL_INCLUDE_DIR a)
endif ()

if (WIN32)
    set (COMPAT_SOURCES )
else ()
    set (COMPAT_SOURCES compat.c )
endif ()

if(USE_OPENAL)
    set (AUDIO_BACKEND compat_mss_al.c)
    set (AUDIO_BACKEND ${AUDIO_BACKEND} vqa/aud_decode.cpp vqa/ddpf_conversion.cpp vqa/vqa_decode.cpp vqa/vqa_file.cpp vqa/vqa_public.cpp)
    set (EXTRA_LIBRARIES ${EXTRA_LIBRARIES} "${OPENAL_LIBRARIES}")
else ()
    set (AUDIO_BACKEND compat_mss_null.c)
endif ()

if(USE_OPENGL)
    set (RENDERING_BACKEND draw_sdl_gl.c)
    set (EXTRA_LIBRARIES ${EXTRA_LIBRARIES} "${OPENGL_LIBRARIES}")
    if (WIN32)
         set (EXTRA_LIBRARIES ${EXTRA_LIBRARIES} "${GLEW_LIBRARIES}")
    endif()
else ()
    set (RENDERING_BACKEND draw_sdl.c)
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
    vardefs.c

    client/audio/auddiag.c
    client/audio/audevent.c
    client/draw/animdraw.c
    client/draw/canidraw.c
    client/draw/drawrays.c
    client/draw/drawwin.c
    client/draw/fx.c
    client/draw/glowdraw.c
    client/draw/litning.c
    client/draw/lvupdraw.c
    client/draw/magicdrw.c
    client/draw/mgendraw.c
    client/draw/mondraw.c
    client/draw/partrain.c
    client/draw/partscrn.c
    client/draw/plasma.c
    client/draw/selectdw.c
    client/draw/udeddraw.c
    client/draw/vectdraw.c
    client/drawable/drawable.c
    client/drawable/drawdb.c
    client/drawable/update/charmup.c
    client/drawable/update/cloud.c
    client/drawable/update/dball.c
    client/drawable/update/drainup.c
    client/drawable/update/fireball.c
    client/drawable/update/healup.c
    client/drawable/update/manabomb.c
    client/drawable/update/mmislup.c
    client/drawable/update/mtailup.c
    client/drawable/update/sparklup.c
    client/drawable/update/telwake.c
    client/drawable/update/vortexup.c
    client/gui/chathelp.c
    client/gui/chaticon.c
    client/gui/conntype.c
    client/gui/gadgets/listbox.c
    client/gui/gamewin/gamewin.c
    client/gui/gamewin/psscript.c
    client/gui/gui_ctf.c
    client/gui/guibook.c
    client/gui/guibrief.c
    client/gui/guicon.c
    client/gui/guicurs.c
    client/gui/guidlg.c
    client/gui/guifb.c
    client/gui/guigen.c
    client/gui/guiggovr.c
    client/gui/guiinput.c
    client/gui/guiinv.c
    client/gui/guijourn.c
    client/gui/guimeter.c
    client/gui/guimsg.c
    client/gui/guiobs.c
    client/gui/guiquit.c
    client/gui/guirank.c
    client/gui/guisave.c
    client/gui/guishop.c
    client/gui/guispell.c
    client/gui/guisumn.c
    client/gui/guitrade.c
    client/gui/guivote.c
    client/gui/servopts/access.c
    client/gui/servopts/advserv.c
    client/gui/servopts/general.c
    client/gui/servopts/guiserv.c
    client/gui/servopts/objlst.c
    client/gui/servopts/playrlst.c
    client/gui/servopts/spelllst.c
    client/gui/tooltip.c
    client/gui/woldisc.c
    client/io/console.c
    client/io/win95/dxinput.c
    client/io/win95/dxvideo.c
    client/io/win95/focus.c
    client/io/win95/jstick.c
    client/io/win95/video.c
    client/light/light16.c
    client/network/cdecode.c
    client/network/deathmsg.c
    client/network/inform.c
    client/network/netclint.c
    client/shell/arnamain.c
    client/shell/inputcfg/inputcfg.c
    client/shell/mainmenu.c
    client/shell/noxworld.c
    client/shell/options.c
    client/shell/optsback.c
    client/shell/selchar.c
    client/shell/selclass.c
    client/shell/selcolor.c
    client/shell/wolapi/locale.c
    client/shell/wolapi/wolchat.c
    client/shell/wolapi/woldlgs.c
    client/shell/wolapi/wollogin.c
    client/shell/wolapi/wolprog.c
    client/shell/wolapi/wolreg.c
    client/system/client.c
    client/system/ctrlevnt.c
    client/system/gameloop.c
    client/system/npcinfo.c
    client/system/parsecmd.c
    common/ability/comablty.c
    common/gamemech/pausefx.c
    common/magic/comguide.c
    common/magic/speltree.c
    common/object/armrlook.c
    common/object/modifier.c
    common/object/weaplook.c
    common/system/gamedisk.c
    common/system/group.c
    common/system/settings.c
    common/system/team.c
    common/telnet/telnetd.c
    common/wolapi/wol.c
    common/wolapi/wolchnl.c
    common/wolapi/wolpatch.c
    common/wolapi/wolstate.c
    common/wolapi/woluser.c
    common/xfer/savegame/xferplyr.c
    comw32/comlib.c
    server/ability/ability.c
    server/dbase/objdb.c
    server/gamemech/explevel.c
    server/magic/plyrgide.c
    server/magic/plyrspel.c
    server/magic/spell/execdur.c
    server/mapgen/generate/populate.c
    server/network/mapsend.c
    server/network/playback.c
    server/network/sdecode.c
    server/object/die/die.c
    server/object/health.c
    server/object/objutil.c
    server/object/pickdrop/pickup.c
    server/system/cscrfunc.c
    server/system/server.c
    server/system/trade.c
    server/xfer/savegame/savegame.c


    "${COMPAT_SOURCES}"
    "${RENDERING_BACKEND}"
    "${AUDIO_BACKEND}"
)
if (${CMAKE_SYSTEM_NAME} STREQUAL "Emscripten")
    set (WASM_FLAGS "-g -o out.html --pre-js ${CMAKE_SOURCE_DIR}/pre.js -lidbfs.js -s CASE_INSENSITIVE_FS=1 -s ASYNCIFY -s TOTAL_MEMORY=201326592 -s EMULATE_FUNCTION_POINTER_CASTS=1 -s ASSERTIONS=2 -mnontrapping-fptoint -s EXIT_RUNTIME=1")
endif ()
target_include_directories(out PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries (
    out
    "${WASM_FLAGS}"
    "${SDL2_LIBRARIES}"
    "${PTHREAD_LIBRARIES}"
    "${WIN32_LIBRARIES}"
    "${EXTRA_LIBRARIES}"
)
if (MSVC)
    find_path(SDL_INCLUDE_DIR SDL2/SDL.h)
    include_directories("${SDL_INCLUDE_DIR}")
    if (USE_OPENGL)
        find_path(GLEW_INCLUDE_DIR GL/glew.h)
        include_directories("${GLEW_INCLUDE_DIR}")
    endif()
    if (USE_OPENAL)
        find_path(OPENAL_INCLUDE_DIR AL/al.h)
        include_directories("${OPENAL_INCLUDE_DIR}")
    endif ()
else ()
    if (CMAKE_CL_64)
        target_link_options (out PUBLIC -m32)
    endif ()

    if (USE_ASAN)
        target_link_options (out PRIVATE -fsanitize=address)
    endif ()
endif ()
