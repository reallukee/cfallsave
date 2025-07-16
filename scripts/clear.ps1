$folders = @(
    "bin",
    "obj",
    "windows\.vs",
    "windows\bin",
    "windows\obj",
    "osx\bin",
    "osx\obj"
)

foreach ($folder in $folders) {
    $path = Join-Path -Path ".." -ChildPath $folder

    if (Test-Path -Path $path -PathType Container) {
        Remove-Item -Path $path -Recurse -Force
    }
}
