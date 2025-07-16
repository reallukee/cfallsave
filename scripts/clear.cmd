@echo off

setlocal enabledelayedexpansion

set folders=bin obj windows\.vs windows\bin windows\obj osx\bin osx\obj

for %%folder in (%folders%) do (
    if exist "..\%%folder\" (
        rmdir /s /q "..\%%folder"
    )
)
