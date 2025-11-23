@echo off

setlocal enabledelayedexpansion

set folders=bin obj windows\.vs windows\bin windows\obj macos\bin macos\obj

for %%f in (%folders%) do (
    if exist "..\%%f\" (
        rmdir /s /q "..\%%f"
    )
)
