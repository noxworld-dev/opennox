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
option (HIGH_RES "Allow higher resolution" OFF)

option (USE_OPENAL "Use OpenAL in Nox, disabling results in no sound" ON)
option (USE_OPENGL "Use OpenGL in Nox, disabling results in running in SDL Rendering" ON)
option (PLAY_MOVIES "Disable movies playback" ON)

if (MSVC)
    add_compile_options ("$<$<CONFIG:DEBUG>:/RTCs>")
    add_compile_options ("/MP")
else ()
    add_compile_options (-g -m32 -fshort-wchar)
    add_compile_options (-fno-strict-aliasing)
    add_compile_options (-fno-strict-overflow)

    add_compile_options (-Werror=return-type)
    add_compile_options (-Werror=implicit-function-declaration)
    add_compile_options (-Werror=pointer-arith)
    add_compile_options (-Werror=implicit-int)
    add_compile_options (-Werror=unused-label)
    add_compile_options (-Werror=uninitialized)
    add_compile_options (-Werror=address)
    add_compile_options (-Werror=unused-variable)
    add_compile_options (-Werror=stringop-overflow)

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

    if (HIGH_RES)
        add_definitions (-DNOX_HIGH_RES)
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
    find_library (SDL2_LIBRARIES SDL2.lib)
    find_library (OPENAL_LIBRARIES OpenAL32.lib)
    if (USE_OPENGL)
        find_library (GLEW_LIBRARIES glew32.lib)
        find_library (OPENGL_LIBRARIES OpenGL32.lib)
    endif ()
    set (WIN32_LIBRARIES ws2_32 winmm)
elseif (APPLE)
    set (OPENAL_LIBRARIES "-framework OpenAL")
    if (USE_OPENGL)
        set (OPENGL_LIBRARIES "-framework OpenGL")
	endif ()
elseif (${CMAKE_SYSTEM_NAME} STREQUAL "Emscripten")
    set (SDL2_LIBRARIES SDL2)
    set (OPENAL_LIBRARIES openal)
    if (USE_OPENGL)
        set (OPENGL_LIBRARIES GL)
	endif ()
    set (PTHREAD_LIBRARIES pthread)
else ()
    set(CMAKE_PREFIX_PATH /usr)
    set(CMAKE_LIBRARY_ARCHITECTURE i386-linux-gnu)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(SDL2 REQUIRED sdl2)
    set (OPENAL_LIBRARIES openal)
    if (USE_OPENGL)
        set (OPENGL_LIBRARIES GL)
	endif ()
    set (PTHREAD_LIBRARIES pthread)
endif ()

if (WIN32)
    set (COMPAT_SOURCES )
else ()
    set (COMPAT_SOURCES compat.c )
endif ()

if(USE_OPENAL)
    set (AUDIO_BACKEND client/audio/ail/compat_mss_al.c)
    set (EXTRA_LIBRARIES ${EXTRA_LIBRARIES} "${OPENAL_LIBRARIES}")
else ()
    set (OPENAL_LIBRARIES )
    set (OPENAL_INCLUDE_DIR )
    set (AUDIO_BACKEND client/audio/ail/compat_mss_null.c)
    unset (NOX_PLAY_MOVIES )
endif ()

if (USE_OPENGL)
	set (DRAW_BACKEND client__video__sdlgl__draw_gl.c)
else ()
	set (DRAW_BACKEND client__video__sdl__draw_nogl.c)
endif()

if (PLAY_MOVIES)
    set (MOVIE_DECODER_SOURCES vqa/aud_decode.cpp vqa/ddpf_conversion.cpp vqa/vqa_decode.cpp vqa/vqa_file.cpp vqa/vqa_public.cpp)
    add_definitions (-DNOX_PLAY_MOVIES)
else ()
    set (MOVIE_DECODER_SOURCES )
endif ()

set (
	SOURCE_LIST
    main/main.c
	ConvertUTF.c
    common/platform/platform.c
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
    main/GAME_data.c
    main/GAME_data_init.c
    cdrom.c
    input.c
    input_common.c
    movie.c
    sm.c
    noxstring.c
    win.c
    mutexes.c
    nox_net.c
    memmap.c
    static.c
    MixPatch.c
    GameEx.c
    memfile.c
    thing.c
    vardefs.c

    client__audio__auddiag.c
    client__audio__audevent.c
    client__draw__image.c
    client__draw__parse__parse.c
    client__draw__animdraw.c
    client__draw__armordraw.c
    client__draw__arrowdraw.c
    client__draw__basedraw.c
    client__draw__boulderdraw.c
    client__draw__bubbledraw.c
    client__draw__canidraw.c
    client__draw__debugdraw.c
    client__draw__doordraw.c
    client__draw__drawrays.c
    client__draw__drawwin.c
    client__draw__flagdraw.c
    client__draw__fx.c
    client__draw__glowdraw.c
    client__draw__glyphdraw.c
    client__draw__harpoondraw.c
    client__draw__lightning.c
    client__draw__lvupdraw.c
    client__draw__magicdrw.c
    client__draw__maidendraw.c
    client__draw__mgendraw.c
    client__draw__mondraw.c
    client__draw__npcdraw.c
    client__draw__partrain.c
    client__draw__partscrn.c
    client__draw__plasma.c
    client__draw__playerdraw.c
    client__draw__powderdraw.c
    client__draw__pressureplatedraw.c
    client__draw__selectdw.c
    client__draw__slavedraw.c
    client__draw__souldraw.c
    client__draw__spiderspitdraw.c
    client__draw__staticdraw.c
    client__draw__summondraw.c
    client__draw__triggerdraw.c
    client__draw__udeddraw.c
    client__draw__vectdraw.c
    client__draw__vortexdraw.c
    client__draw__weapondraw.c
    client__drawable__drawable.c
    client__drawable__drawdb.c
    client__drawable__update__charmup.c
    client__drawable__update__cloud.c
    client__drawable__update__dball.c
    client__drawable__update__drainup.c
    client__drawable__update__fireball.c
    client__drawable__update__healup.c
    client__drawable__update__manabomb.c
    client__drawable__update__mmislup.c
    client__drawable__update__mtailup.c
    client__drawable__update__sparklup.c
    client__drawable__update__telwake.c
    client__drawable__update__vortexup.c
    client__gui__chathelp.c
    client__gui__chaticon.c
    client__gui__conntype.c
    client__gui__gadgets__listbox.c
    client__gui__gamewin__gamewin.c
    client__gui__gamewin__psscript.c
    client__gui__gui_ctf.c
    client__gui__guibook.c
    client__gui__guibrief.c
    client__gui__guicon.c
    client__gui__guicurs.c
    client__gui__guidlg.c
    client__gui__guifb.c
    client__gui__guigen.c
    client__gui__guiggovr.c
    client__gui__guiinput.c
    client__gui__guiinv.c
    client__gui__guijourn.c
    client__gui__guimeter.c
    client__gui__guimsg.c
    client__gui__guicon.c
    client__gui__guiobs.c
    client__gui__guiquit.c
    client__gui__guirank.c
    client__gui__guisave.c
    client__gui__guishop.c
    client__gui__guispell.c
    client__gui__guisumn.c
    client__gui__guitrade.c
    client__gui__guivote.c
    client__gui__servopts__access.c
    client__gui__servopts__advserv.c
    client__gui__servopts__general.c
    client__gui__servopts__guiserv.c
    client__gui__servopts__objlst.c
    client__gui__servopts__playrlst.c
    client__gui__servopts__spelllst.c
    client__gui__tooltip.c
    client__gui__window.c
    client__gui__woldisc.c
    client__io__console.c
    client__io__win95__dxinput.c
    client__io__win95__dxvideo.c
    client__io__win95__focus.c
    client__io__win95__jstick.c
    client__io__win95__video.c
    client__light__light16.c
    client__network__cdecode.c
    client__network__deathmsg.c
    client__network__inform.c
    client__network__netclint.c
    client__shell__arnamain.c
    client__shell__inputcfg__inputcfg.c
    client__shell__mainmenu.c
    client__shell__noxworld.c
    client__shell__options.c
    client__shell__optsback.c
    client__shell__selchar.c
    client__shell__selclass.c
    client__shell__selcolor.c
    client__shell__wolapi__locale.c
    client__shell__wolapi__wolchat.c
    client__shell__wolapi__woldlgs.c
    client__shell__wolapi__wollogin.c
    client__shell__wolapi__wolprog.c
    client__shell__wolapi__wolreg.c
    client__system__client.c
    client__system__ctrlevnt.c
    client__system__gameloop.c
    client__system__npcinfo.c
    client__system__parsecmd.c
    common/alloc/classes/alloc_class.c
    common/fs/nox_fs.c
    common__random.c
    common__strman.c
    common__binfile.c
    common__config.c
    common__log.c
    common__net_list.c
    common__ability__comablty.c
    common__gamemech__pausefx.c
    common__magic__comguide.c
    common__magic__speltree.c
    common__object__armrlook.c
    common__object__modifier.c
    common__object__weaplook.c
    common__system__gamedisk.c
    common__system__group.c
    common__system__settings.c
    common__system__team.c
    common__telnet__telnetd.c
    common__wolapi__wol.c
    common__wolapi__wolchnl.c
    common__wolapi__wolpatch.c
    common__wolapi__wolstate.c
    common__wolapi__woluser.c
    common__xfer__savegame__xferplyr.c
    comw32__comlib.c
    server__ability__ability.c
    server__dbase__objdb.c
    server__gamemech__explevel.c
    server__magic__plyrgide.c
    server__magic__plyrspel.c
    server__magic__spell__execdur.c
    server__mapgen__generate__populate.c
    server__network__mapsend.c
    server__network__playback.c
    server__network__sdecode.c
    server__object__die__die.c
    server__object__health.c
    server__object__objutil.c
    server__object__pickdrop__pickup.c
    server__system__cscrfunc.c
    server__system__server.c
    server__system__trade.c
    server__script__script.c
    server__script__builtin.c
    server__script__panic.c
    server__script__file.c
    server__xfer__savegame__savegame.c

    client__video__draw_common.c
    "${DRAW_BACKEND}"
    "${COMPAT_SOURCES}"
    "${AUDIO_BACKEND}"
    "${MOVIE_DECODER_SOURCES}"
)

add_executable (
    out
    ${SOURCE_LIST}
)
if (${CMAKE_SYSTEM_NAME} STREQUAL "Emscripten")
    set (WASM_FLAGS "-g -o out.html --pre-js ${CMAKE_SOURCE_DIR}/pre.js -lidbfs.js -s CASE_INSENSITIVE_FS=1 -s ASYNCIFY -s TOTAL_MEMORY=201326592 -s EMULATE_FUNCTION_POINTER_CASTS=1 -s ASSERTIONS=1 -mnontrapping-fptoint -s EXIT_RUNTIME=1")
endif ()
target_include_directories(out PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries (
    out
    "${WASM_FLAGS}"
    "${SDL2_LIBRARIES}"
    "${GLEW_LIBRARIES}"
    "${OPENGL_LIBRARIES}"
    "${OPENAL_LIBRARIES}"
    "${PTHREAD_LIBRARIES}"
    "${WIN32_LIBRARIES}"
    "${EXTRA_LIBRARIES}"
)

if (MSVC)
	source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_LIST})
    find_path(SDL_INCLUDE_DIR SDL2/SDL.h)
    include_directories("${SDL_INCLUDE_DIR}")
	if (USE_OPENGL)
	    find_path(GLEW_INCLUDE_DIR GL/glew.h)
        include_directories("${GLEW_INCLUDE_DIR}")
	endif ()
    if (USE_OPENAL)
        find_path(OPENAL_INCLUDE_DIR AL/al.h)
        include_directories("${OPENAL_INCLUDE_DIR}")
    endif ()
else ()
    target_link_options (out PUBLIC -m32)
    if (USE_ASAN)
        target_link_options (out PRIVATE -fsanitize=address)
    endif ()
endif ()
