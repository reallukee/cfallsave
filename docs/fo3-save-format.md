# Fallout 3 Save File Format

> [Back to Documentation](../DOCS.md)



> [!NOTE]
> Fallout 3 Save Format IS VERY CLOSE to Fallout: New Vegas Save Format

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

Source: [fo3.h](../src/fo3.h)

```c
#define FO3SAVE_SIGNATURE           "FO3SAVEGAME"
#define FO3SAVE_SIGNATURE_LENGTH    11

typedef struct FO3SAVE
{
    char saveSignature[FO3SAVE_SIGNATURE_LENGTH + 1];
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
} FO3SAVE;
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
