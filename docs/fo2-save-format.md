# Fallout 2 Save File Format

> [Back to Documentation](../DOCS.md)



> [!NOTE]
> Fallout 2 Format IS VERY CLOSE to Fallout 1 Save Format

| Property       | Type     | CFAllSave Type |
| :------------- | :------- | :------------- |
| Save Signature | char[18] | char[18]       |
| Player Name    | char[32] | char[32]       |
| Save Name      | char[32] | char[32]       |



## Data Structure

Source: [fo2.h](../src/fo2.h)

```c
#define FO2SAVE_SIGNATURE           "FALLOUT SAVE FILE"
#define FO2SAVE_SIGNATURE_LENGTH    17

typedef struct FO2SAVE
{
    char saveSignature[FO2SAVE_SIGNATURE_LENGTH + 1];
    char saveName[32];

    char playerName[32];
} FO2SAVE;
```
