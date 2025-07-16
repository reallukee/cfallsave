<div align="center">

![CFallSave Logo 192x192](../assets/cfallsave_logo_192x192.png)

# CFallSave API

[Back to Documentation](../DOCS.md)

</div>



# Summary

* [Code](#code)
* [Naming](#naming)
* [Macros](#macros)
* [Version](#version)



# Code

> Headers: [`cfallsave.h`](../src/cfallsave.h), [`export.h`](../src/export.h)



# Naming

| Abbreviation | Full Name                               |
| :----------- | :-------------------------------------- |
| `FO1`        | *Fallout 1*                             |
| `FO2`        | *Fallout 2*                             |
| `FOTBOS`     | *Fallout Tactics: Brotherhood of Steel* |
| `FO3`        | *Fallout 3*                             |
| `FONV`       | *Fallout: New Vegas*                    |
| `FO4`        | *Fallout 4*                             |



# Macros

> [!NOTE]
> CFallSave follows [SemVer standard](https://semver.org/)!

| Macro                                    | Value                            |
| :--------------------------------------- | :------------------------------- |
| `CFALLSAVE_VERSION`                      | `ABC`                            |
| `CFALLSAVE_VERSION_MAJOR`                | `A`                              |
| `CFALLSAVE_VERSION_MINOR`                | `B`                              |
| `CFALLSAVE_VERSION_PATCH`                | `C`                              |
| `CFALLSAVE_FRIENDLY_VERSION`             | `A.B.C`                          |
| `CFALLSAVE_MIN_VERSION`                  | `ABC`                            |
| `CFALLSAVE_MIN_VERSION_MAJOR`            | `A`                              |
| `CFALLSAVE_MIN_VERSION_MINOR`            | `B`                              |
| `CFALLSAVE_MIN_VERSION_PATCH`            | `C`                              |
| `CFALLSAVE_FRIENDLY_MIN_VERSION`         | `A.B.C`                          |
| `CFALLSAVE_VERSION_S` (*DEPRECATED*)     | `CFALLSAVE_FRIENDLY_VERSION`     |
| `CFALLSAVE_MIN_VERSION_S` (*DEPRECATED*) | `CFALLSAVE_FRIENDLY_MIN_VERSION` |
| `CFALLSAVE_LIBRARY`                      |                                  |
| `CFALLSAVE_API`                          |                                  |

> [!NOTE]
> `CFALLSAVE_LIBRARY` is only defined on Windows!
>
> Read more about [dllexport-dllimport](https://learn.microsoft.com/cpp/cpp/dllexport-dllimport).



# Version

> Headers: [`version.h`](../src/version.h)

* `int cfs_getVersion()`
* `int cfs_getVersionMajor()`
* `int cfs_getVersionMinor()`
* `int cfs_getVersionPatch()`
* `const char* cfs_getFriendlyVersion()`
* `int cfs_getMinVersion()`
* `int cfs_getMinVersionMajor()`
* `int cfs_getMinVersionMinor()`
* `int cfs_getMinVersionPatch()`
* `const char* cfs_getMinFriendlyVersion()`
* `bool cfs_isCompatible(int major, int minor, int patch)`
