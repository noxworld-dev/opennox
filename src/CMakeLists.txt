cmake_minimum_required (VERSION 3.11)
project (nox-port)

option (USE_ASAN "Enable address sanitizer" OFF)

find_package(SDL2 CONFIG REQUIRED)
find_package(OpenAL CONFIG REQUIRED)
find_package(GLEW REQUIRED)

if (MSVC)
    add_compile_options ("$<$<CONFIG:DEBUG>:/RTCs>")
else ()
    add_compile_options (-O3 -g -fno-strict-aliasing -fno-strict-overflow -m32 -fshort-wchar)
    if (USE_ASAN)
        add_compile_options (-fsanitize=address)
    endif ()
endif ()
include_directories (external/include)
link_directories (${PROJECT_SOURCE_DIR}/external/lib)
if (WIN32)
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
    GAME1.c
    GAME2.c
    GAME3.c
    GAME4.c
    GAME5.c
    GAME_data.c
    cdrom.c
    draw.c
    imm.c
    input.c
    main.cpp
    movie.c
    sm.c
    string.c
    win.c
	MixPatch.c
    "${COMPAT_SOURCES}"
)
target_link_libraries (
    out
    $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
	$<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
    GLEW::GLEW
    OpenAL::OpenAL
    "${WIN32_LIBRARIES}"
)
if (MSVC)
else ()
    target_link_options (out PUBLIC -m32)
    if (USE_ASAN)
        target_link_options (out PRIVATE -fsanitize=address)
    endif ()
endif ()
