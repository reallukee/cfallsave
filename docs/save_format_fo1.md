<div align="center">

![Fallout 1 Logo 192x192](../assets/fo1/fo1_logo_192x192.png)

# Fallout 1 Save Format

[Back to Documentation](../DOCS.md)

</div>



# Summary

* [Save File](#save-file)
* [Data Structure](#data-structure)



# Save File

> [!NOTE]
> Fallout 1 Format IS VERY CLOSE to Fallout 2 Save Format

| Property       | Save Type | CFAllSave Type |
| :------------- | :-------- | :------------- |
| Save Signature | char[18]  | char[18]       |
| Player Name    | char[32]  | char[32]       |
| Save Name      | char[32]  | char[32]       |



# Data Structure

> Source: [fo1.h](../src/fo1.h)

```c
#define FO1SAVE_GAME_NAME           "Fallout 1"
#define FO1SAVE_SIGNATURE           "FALLOUT SAVE FILE"
#define FO1SAVE_SIGNATURE_LENGTH    17
#define FO1SAVE_PROPS_COUNT         3

typedef enum FO1SAVE_PROPS
{
    FO1SAVE_PROPS_SAVE_SIGNATURE    = 0,
    FO1SAVE_PROPS_SAVE_NAME         = 1,
    FO1SAVE_PROPS_PLAYER_NAME       = 2
} FO1SAVE_PROPS;

typedef struct FO1SAVE
{
    FILE* save;

    char* saveFileName;

    char saveSignature[FO1SAVE_SIGNATURE_LENGTH + 1];
    char saveName[32];

    char playerName[32];

    unsigned long propAddresses[FO1SAVE_PROPS_COUNT];
} FO1SAVE;
```
