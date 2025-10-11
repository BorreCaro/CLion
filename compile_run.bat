@echo off
set SOURCE=%1
set DIR=%~dp1
set NAME=%~n1
set PROJECT_ROOT=C:\Users\danis.DESKTOP-HQR1BPJ\CLionProjects\EjerciciosClion

REM Crear carpeta exes si no existe
if not exist "%DIR%exes" mkdir "%DIR%exes"

REM Crear o actualizar .gitignore en la raíz del proyecto
if not exist "%PROJECT_ROOT%\.gitignore" (
    echo exes/ > "%PROJECT_ROOT%\.gitignore"
    echo *.exe >> "%PROJECT_ROOT%\.gitignore"
) else (
    findstr /C:"exes/" "%PROJECT_ROOT%\.gitignore" >nul || echo exes/ >> "%PROJECT_ROOT%\.gitignore"
    findstr /C:"*.exe" "%PROJECT_ROOT%\.gitignore" >nul || echo *.exe >> "%PROJECT_ROOT%\.gitignore"
)

REM Compilar
g++ -std=c++20 "%SOURCE%" -o "%DIR%exes\%NAME%.exe"

REM Ejecutar si compiló correctamente
if %errorlevel% equ 0 (
    "%DIR%exes\%NAME%.exe"
)