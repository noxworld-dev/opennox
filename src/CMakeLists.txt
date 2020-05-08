cmake_minimum_required (VERSION 3.11)
project (nox-port)

option (USE_ASAN "Enable address sanitizer" OFF)

if (MSVC)
    add_compile_options ("$<$<CONFIG:DEBUG>:/RTCs>")
else ()
    add_compile_options (-O3 -g -fno-strict-aliasing -fno-strict-overflow -m32 -fshort-wchar -Werror=return-type)
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
    GAME1_2.c
    GAME2.c
    GAME2_2.c
    GAME3.c
    GAME4.c
    GAME5.c
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
