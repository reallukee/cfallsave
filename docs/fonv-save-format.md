# Fallout: New Vegas Save File Format

> [Back to Documentation](../DOCS.md)



> [!NOTE]
> Fallout: New Vegas Save Format IS VERY CLOSE to Fallout 3 Save Format

| Property         | Type                 | CFAllSave Type |
| :--------------- | :------------------- | :------------- |
| Save Signature   | char[12]             | char[12]       |
| Engine Version ? | unsigned             | unsigned       |
| Snapshot Width   | unsigned             | unsigned       |
| Snapshot Height  | unsigned             | unsigned       |
| Save Number      | unsigned             | unsigned       |
| Player Name      | short + '\|' + char* | char*          |
| Player Level     | unsigned             | unsigned       |
| Player Title     | short + '\|' + char* | char*          |
| Player Location  | short + '\|' + char* | char*          |
| Player Playtime  | short + '\|' + char* | char*          |
| Snapshot         | unsigned char*       | unsigned char* |



## Data Structure

Source: [fonv.h](../src/fonv.h)

```c
#define FONVSAVE_SIGNATURE          "FO3SAVEGAME"
#define FONVSAVE_SIGNATURE_LENGTH   11

typedef struct FONVSAVE
{
    char saveSignature[FONVSAVE_SIGNATURE_LENGTH + 1];
    unsigned engineVersion;
    unsigned saveNumber;

    char* playerName;
    unsigned playerLevel;
    char* playerTitle;
    char* playerLocation;
    char* playerPlaytime;

    unsigned snapshotWidth;
    unsigned snapshotHeight;
    unsigned char* snapshot;
} FONVSAVE;
```



## Data Types

### char[n]

`char[n] = '\n'`

### short + '|' + char*

```binary
0C 00   7C   4A 6F 68 6E 20 46 61 6C 6C 6F 75 74
```

| Bytes                               | Type      | Value        |
| :---------------------------------- | :-------- | :----------- |
| 0C 00                               | Length    | 12           |
| 7C                                  | Separator | \|           |
| 4A 6F 68 6E 20 46 61 6C 6C 6F 75 74 | Value     | John Fallout |
