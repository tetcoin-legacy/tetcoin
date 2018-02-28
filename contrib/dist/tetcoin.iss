; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "Tetcoin"
#define MyAppVersion "0.8.7.5"
#define MyAppPublisher "Kedia"
#define MyAppURL "https://tetcoin.com"
#define MyAppExeName "tetcoin-qt.exe"

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{6B096E1D-BEA8-4D0E-9AB7-8C0ED04E53BE}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={pf}\{#MyAppName}
DisableProgramGroupPage=yes
LicenseFile=C:\Users\kedia\Downloads\tetcoin-0.8-02.27.18-win64\copying.txt
InfoAfterFile=C:\Users\kedia\Downloads\tetcoin-0.8-02.27.18-win64\readme.txt
OutputDir=C:\Users\kedia\Downloads\tetcoin-0.8-02.27.18-win64
OutputBaseFilename=tetcoin-0.8-win64
Compression=lzma
SolidCompression=yes

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "C:\Users\kedia\Downloads\tetcoin-0.8-02.27.18-win64\tetcoin-qt.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\kedia\Downloads\tetcoin-0.8-02.27.18-win64\copying.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\kedia\Downloads\tetcoin-0.8-02.27.18-win64\readme.txt"; DestDir: "{app}"; Flags: ignoreversion
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{commonprograms}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent

