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
    add_compile_options (-Werror=address)
    add_compile_options (-Werror=unused-variable)

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
    find_library (SDL2_LIBRARIES SDL2.lib)
    find_library (OPENAL_LIBRARIES OpenAL32.lib)
    find_library (GLEW_LIBRARIES glew32.lib)
    find_library (OPENGL_LIBRARIES OpenGL32.lib)
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
    vardefs.c

    client/audio/auddiag.c
    client/audio/audevent.c
    client/draw/animdraw.c
    client/draw/armordraw.c
    client/draw/arrowdraw.c
    client/draw/basedraw.c
    client/draw/boulderdraw.c
    client/draw/bubbledraw.c
    client/draw/canidraw.c
    client/draw/debugdraw.c
    client/draw/doordraw.c
    client/draw/drawrays.c
    client/draw/drawwin.c
    client/draw/flagdraw.c
    client/draw/fx.c
    client/draw/glowdraw.c
    client/draw/glyphdraw.c
    client/draw/harpoondraw.c
    client/draw/litning.c
    client/draw/lvupdraw.c
    client/draw/magicdrw.c
    client/draw/maidendraw.c
    client/draw/mgendraw.c
    client/draw/mondraw.c
    client/draw/npcdraw.c
    client/draw/partrain.c
    client/draw/partscrn.c
    client/draw/plasma.c
    client/draw/playerdraw.c
    client/draw/powderdraw.c
    client/draw/pressureplatedraw.c
    client/draw/selectdw.c
    client/draw/slavedraw.c
    client/draw/souldraw.c
    client/draw/spiderspitdraw.c
    client/draw/staticdraw.c
    client/draw/summondraw.c
    client/draw/triggerdraw.c
    client/draw/udeddraw.c
    client/draw/vectdraw.c
    client/draw/vortexdraw.c
    client/draw/weapondraw.c
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
target_include_directories(out PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries (
    out
    "${WASM_FLAGS}"
    "${SDL2_LIBRARIES}"
    "${OPENAL_LIBRARIES}"
    "${GLEW_LIBRARIES}"
    "${OPENGL_LIBRARIES}"
    "${OPENAL_LIBRARIES}"
    "${OPENGL_LIBRARIES}"
    "${PTHREAD_LIBRARIES}"
    "${WIN32_LIBRARIES}"
)
if (MSVC)
    find_path(SDL_INCLUDE_DIR SDL2/SDL.h)
    find_path(GLEW_INCLUDE_DIR GL/glew.h)
    find_path(OPENAL_INCLUDE_DIR AL/al.h)
    include_directories("${SDL_INCLUDE_DIR}")
    include_directories("${GLEW_INCLUDE_DIR}")
    include_directories("${OPENAL_INCLUDE_DIR}")
else ()
    target_link_options (out PUBLIC -m32)
    if (USE_ASAN)
        target_link_options (out PRIVATE -fsanitize=address)
    endif ()
endif ()
