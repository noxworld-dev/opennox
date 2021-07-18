Unicode true

Name "OpenNox ${VERSION}"
OutFile "${OUTDIR}\OpenNox-${VERSION}.exe"
InstallDir `C:\Games\OpenNox`
AllowRootDirInstall true
SetCompressor lzma

!include "MUI2.nsh"
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES
!insertmacro MUI_LANGUAGE "English"

Section ""
SetOutPath "$INSTDIR"
File /r "${DATA}\*"
SectionEnd
