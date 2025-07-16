<div align="center">

![CFallSave++ Logo 192x192](../assets/cfallsave++_logo_192x192.png)

# CFallSave++ API

[Back to Documentation](../DOCS.md)

</div>



# Summary

* [Code](#code)
* [Naming](#naming)
* [Macros](#macros)
* [Version](#version)



# Code

> Headers: [`cfallsave++.hpp`](../src/cplusplus/cfallsave++.hpp), [`export.hpp`](../src/cplusplus/export.hpp)



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
> CFallSave++ follows [SemVer standard](https://semver.org/)!

| Macro                                      | Value                              |
| :----------------------------------------- | :--------------------------------- |
| `CFALLSAVEPP_VERSION`                      | `ABC`                              |
| `CFALLSAVEPP_VERSION_MAJOR`                | `A`                                |
| `CFALLSAVEPP_VERSION_MINOR`                | `B`                                |
| `CFALLSAVEPP_VERSION_PATCH`                | `C`                                |
| `CFALLSAVEPP_FRIENDLY_VERSION`             | `A.B.C`                            |
| `CFALLSAVEPP_MIN_VERSION`                  | `ABC`                              |
| `CFALLSAVEPP_MIN_VERSION_MAJOR`            | `A`                                |
| `CFALLSAVEPP_MIN_VERSION_MINOR`            | `B`                                |
| `CFALLSAVEPP_MIN_VERSION_PATCH`            | `C`                                |
| `CFALLSAVEPP_FRIENDLY_MIN_VERSION`         | `A.B.C`                            |
| `CFALLSAVEPP_VERSION_S` (*DEPRECATED*)     | `CFALLSAVEPP_FRIENDLY_VERSION`     |
| `CFALLSAVEPP_MIN_VERSION_S` (*DEPRECATED*) | `CFALLSAVEPP_FRIENDLY_MIN_VERSION` |
| `CFALLSAVEPP_LIBRARY`                      |                                    |
| `CFALLSAVEPP_API`                          |                                    |

> [!NOTE]
> `CFALLSAVEPP_LIBRARY` is only defined on Windows!
>
> Read more about [dllexport-dllimport](https://learn.microsoft.com/cpp/cpp/dllexport-dllimport).



# Version

> Headers: [`version.hpp`](../src/cplusplus/version.hpp)

* `int cfspp_getVersion()`
* `int cfspp_getVersionMajor()`
* `int cfspp_getVersionMinor()`
* `int cfspp_getVersionPatch()`
* `const char* cfspp_getFriendlyVersion()`
* `int cfspp_getMinVersion()`
* `int cfspp_getMinVersionMajor()`
* `int cfspp_getMinVersionMinor()`
* `int cfspp_getMinVersionPatch()`
* `const char* cfspp_getMinFriendlyVersion()`
* `bool cfspp_isCompatible(int major, int minor, int patch)`
