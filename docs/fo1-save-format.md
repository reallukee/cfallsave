# Fallout 1 Save File Format

> [Back to Documentation](../DOCS.md)



> [!NOTE]
> Fallout 1 Format IS VERY CLOSE to Fallout 2 Save Format

| Property       | Type     | CFAllSave Type |
| :------------- | :------- | :------------- |
| Save Signature | char[18] | char[18]       |
| Player Name    | char[32] | char[32]       |
| Save Name      | char[32] | char[32]       |



## Data Structure

Source: [fo1.h](../src/fo1.h)

```c
#define FO1SAVE_SIGNATURE           "FALLOUT SAVE FILE"
#define FO1SAVE_SIGNATURE_LENGTH    17

typedef struct FO1SAVE
{
    char saveSignature[FO1SAVE_SIGNATURE_LENGTH + 1];
    char saveName[32];

    char playerName[32];
} FO1SAVE;
```
