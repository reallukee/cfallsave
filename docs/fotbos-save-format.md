# Fallout Tactics: Brotherhood of Steel Save File Format

> [Back to Documentation](../DOCS.md)



| Property        | Type                        | CFAllSave Type |
| :-------------- | :-------------------------- | :------------- |
| Save Signature  | char[8]                     | char[8]        |
| Save Name       | short + "0x20 0x20" + char* | char*          |
| Player Name     | short + "0x20 0x20" + char* | char*          |
| Player Location | short + "0x20 0x20" + char* | char*          |
| Game Date Time  | short + "0x20 0x20" + char* | char*          |



## Data Structure

Source: [fotbos.h](../src/fotbos.h)

```c
#define FOTBOS_SAVE_SIGNATURE           "<saveh>"
#define FOTBOS_SAVE_SIGNATURE_LENGTH    7

typedef struct FOTBOSSAVE
{
    char saveSignature[FOTBOS_SAVE_SIGNATURE_LENGTH + 1];
    char* saveName;

    char* playerName;
    char* playerLocation;
    char* gameDateTime;
} FOTBOSSAVE;
```
