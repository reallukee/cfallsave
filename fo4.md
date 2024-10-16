# Fallout 4 Save File Format

| Property              | Type           | CFAllSave Type |
| :-------------------  | :------------- | :------------- |
| Save Signature        | char[12]       | char[12]       |
| Engine Version        | unsigned       | unsigned       |
| Save Number           | unsigned       | unsigned       |
| Character Name        | wstring        | char*          |
| Character Level       | unsigned       | unsigned       |
| Character Location    | wstring        | char*          |
| Character Playtime    | wstring        | char*          |
| Character Race        | wstring        | char*          |
| Character Sex         | unsigned short | unsigned short |
| Character Current Xp  | float          | float          |
| Character Required Xp | float          | float          |
| Snapshot Widht        | unsigned       | unsigned       |
| Snapshot Height       | unsigned       | unsigned       |
| Snapshot              | unsigned char* | unsigned char* |
