@echo off

setlocal enabledelayedexpansion

set folders=bin obj windows\.vs windows\bin windows\obj osx\bin osx\obj

for %%f in (%folders%) do (
    if exist "..\%%f\" (
        rmdir /s /q "..\%%f"
    )
)
