<div align="center">

![Fallout 2 Logo 192x192](../assets/fo2/fo2_logo_192x192.png)

# Fallout 2 Save Format

[Back to Documentation](../DOCS.md)

</div>



# Summary

* [Save File](#save-file)
* [Data Structure](#data-structure)



# Save File

> [!NOTE]
> Fallout 2 Format IS VERY CLOSE to Fallout 1 Save Format

| Property       | Save Type | CFAllSave Type |
| :------------- | :-------- | :------------- |
| Save Signature | char[18]  | char[18]       |
| Player Name    | char[32]  | char[32]       |
| Save Name      | char[32]  | char[32]       |



# Data Structure

> Source: [fo2.h](../src/fo2.h)

```c
#define FO2SAVE_GAME_NAME           "Fallout 2"
#define FO2SAVE_SIGNATURE           "FALLOUT SAVE FILE"
#define FO2SAVE_SIGNATURE_LENGTH    17
#define FO2SAVE_PROPS_COUNT         3

typedef enum FO2SAVE_PROPS
{
    FO2SAVE_PROPS_SAVE_SIGNATURE    = 0,
    FO2SAVE_PROPS_SAVE_NAME         = 1,
    FO2SAVE_PROPS_PLAYER_NAME       = 2
} FO2SAVE_PROPS;

typedef struct FO2SAVE
{
    FILE* save;

    char* saveFileName;

    char saveSignature[FO2SAVE_SIGNATURE_LENGTH + 1];
    char saveName[32];

    char playerName[32];

    unsigned long propAddresses[FO2SAVE_PROPS_COUNT];
} FO2SAVE;
```
