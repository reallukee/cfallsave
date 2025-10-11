/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ library to read and write Fallout save files
 *
 * File Name   : fo4.h
 *
 * Title       : FALLOUT 4 HEADER
 * Description : Fallout 4 Header
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.2.0
 * License     : MIT
 */

#ifndef CFALLSAVE_FO4_H
#define CFALLSAVE_FO4_H

#include "header.h"

#define FO4SAVE_GAME_NAME           "Fallout 4"

#define FO4SAVE_SIGNATURE           "FO4_SAVEGAME"  // Save Signature
#define FO4SAVE_SIGNATURE_LENGTH    12              // Save Signature Length
#define FO4SAVE_PROPS_COUNT         14              // Number of properties

#define FO4SAVE_STANDARD_EXT        ".fos"

/// @brief Fallout 4 save properties.
typedef enum FO4SAVE_PROPS
{
    FO4SAVE_PROPS_SAVE_SIGNATURE        = 0,
    FO4SAVE_PROPS_ENGINE_VERSION        = 1,
    FO4SAVE_PROPS_SAVE_NUMBER           = 2,
    FO4SAVE_PROPS_PLAYER_NAME           = 3,
    FO4SAVE_PROPS_PLAYER_LEVEL          = 4,
    FO4SAVE_PROPS_PLAYER_LOCATION       = 5,
    FO4SAVE_PROPS_PLAYER_PLAYTIME       = 6,
    FO4SAVE_PROPS_PLAYER_RACE           = 7,
    FO4SAVE_PROPS_PLAYER_SEX            = 8,
    FO4SAVE_PROPS_PLAYER_CURRENT_XP     = 9,
    FO4SAVE_PROPS_PLAYER_REQUIRED_XP    = 10,
    FO4SAVE_PROPS_SNAPSHOT_WIDTH        = 11,
    FO4SAVE_PROPS_SNAPSHOT_HEIGHT       = 12,
    FO4SAVE_PROPS_SNAPSHOT              = 13
} FO4SAVE_PROPS;

#define FO4SAVE_MAX_SNAPSHOT_WIDTH      640     // Snapshot standard max width
#define FO4SAVE_MAX_SNAPSHOT_HEIGHT     384     // Snapshot standard max height
#define FO4SAVE_MAX_SNAPSHOT_LENGTH     983040  // Snapshot standard max length

#define FO4SAVE_SNAPSHOT_COLOR_BYTES    4       // Snapshot color bytes count
#define FO4SAVE_SNAPSHOT_FORMAT         "RGBA"  // Snapshot color format

#define FO4SAVE_PLAYER_SEX_MALE         0
#define FO4SAVE_PLAYER_SEX_FEMALE       1

/// @brief Fallout 4 Save.
typedef struct FO4SAVE
{
    FILE* save;         // Save file

    char* saveFileName; // Save file name

    char saveSignature[FO4SAVE_SIGNATURE_LENGTH + 1];   // 0
    unsigned int engineVersion;                         // 1
    unsigned int saveNumber;                            // 2

    char* playerName;                                   // 3
    unsigned int playerLevel;                           // 4
    char* playerLocation;                               // 5
    char* playerPlaytime;                               // 6
    char* playerRace;                                   // 7
    short unsigned int playerSex;                       // 8
    float playerCurrentXp;                              // 9
    float playerRequiredXp;                             // 10

    unsigned int snapshotWidth;                         // 11
    unsigned int snapshotHeight;                        // 12
    long unsigned int snapshotLength;                   // 13
    unsigned char* snapshot;                            // 14

    long unsigned int propAddresses[FO4SAVE_PROPS_COUNT];
} FO4SAVE;

#define FO4SAVE_PROPS_SIZE  sizeof(FO4SAVE_FIELDS)
#define FO4SAVE_SIZE        sizeof(FO4SAVE)



/// @brief   Reads the specified Fallout 4 save file.
///          If successful, a pointer to a FO4SAVE structure
///          is returned, otherwise NULL.
/// @param   saveName Path and name of the Fallout 4 save file.
/// @return  A pointer to a FO4SAVE data structure or NULL.
///
/// @see     FO4SAVE
/// @see     isFO4Save
/// @see     isFO4SaveOpen
/// @see     closeFO4Save
///
/// @note    Use closeFO4Save to properly free the returned
///          pointer and avoid memory leaks.
/// @warning This function may return NULL. Always check the
///          pointer before attempting to access its contents.
CFALLSAVE_API FO4SAVE* readFO4Save(
    const char* saveName
);

/// @brief   Writes the specified Fallout 4 save file.
/// @param   save A pointer to a FO4SAVE data structure.
/// @return  True if writing is successful, otherwise false.
///
/// @see     FO4SAVE
/// @see     isFO4Save
/// @see     openFO4Save
/// @see     isFO4SaveOpen
///
/// @note    The target save file will be overwritten.
/// @warning This operation is irreversible. Make sure to
///          back up the original file if needed.
CFALLSAVE_API bool writeFO4Save(
    FO4SAVE* save
);

/// @brief  Checks if the specified Fallout save file is
///         a Fallout 4 save file.
/// @param  saveName Path and name of the Fallout 4 save file.
/// @return True if the save file is a Fallout 4 save,
///         otherwise false.
CFALLSAVE_API bool isFO4Save(
    const char* saveName
);

/// @brief  Checks if the Fallout 4 save file is open.
/// @param  save A pointer to a FO4SAVE data structure.
/// @return True if the save file is open, otherwise false.
///
/// @see    FO4SAVE
/// @see    openFO4Save
/// @see    isFO4SaveOpen
/// @see    closeFO4Save
CFALLSAVE_API bool isFO4SaveOpen(
    FO4SAVE* save
);

/// @brief Closes a Fallout 4 save file
/// @param save A pointer to a FO4SAVE data structure.
///
/// @see   FO4SAVE
/// @see   openFO4Save
/// @see   isFO4SaveOpen
CFALLSAVE_API void closeFO4Save(
    FO4SAVE* save
);



/// @brief   Gets the value of the specified Fallout 4
///          save property.
/// @param   save A pointer to a FO4SAVE data structure.
/// @param   prop Property to get.
/// @param   destination Variable to put the value in.
/// @return  True if is successful, otherwise false.
///
/// @see     FO4SAVE
/// @see     openFO4Save
/// @see     isFO4SaveOpen
/// @see     setFO4SaveProp
/// @see     readFO4SaveProp
///
/// @warning Experimental!!!
CFALLSAVE_API bool getFO4SaveProp(
    FO4SAVE* save,
    FO4SAVE_PROPS prop,
    void** destination
);

/// @brief   Sets the value of the specified Fallout 4
///          save property.
/// @param   save A pointer to a FO4SAVE data structure.
/// @param   prop Properties to set.
/// @param   value Variable from which to take the value.
/// @return  True if is successful, otherwise false.
///
/// @see     FO4SAVE
/// @see     openFO4Save
/// @see     isFO4SaveOpen
/// @see     getFO4SaveProp
/// @see     writeFO4SaveProp
///
/// @warning Experimental!!!
CFALLSAVE_API bool setFO4SaveProp(
    FO4SAVE* save,
    FO4SAVE_PROPS prop,
    void** value
);



/// @brief   Reads the value of the specified Fallout 4
///          save property.
///          The value is directly obtained from the save
///          file.
/// @param   save A pointer to a FO4SAVE data structure.
/// @param   prop Property to read.
/// @param   destination Variable to put the value in.
/// @return  True if is successful, otherwise false.
///
/// @see     FO4SAVE
/// @see     openFO4Save
/// @see     isFO4SaveOpen
/// @see     writeFO4SaveProp
/// @see     getFO4SaveProp
///
/// @warning Experimental!!!
CFALLSAVE_API bool readFO4SaveProp(
    FO4SAVE* save,
    FO4SAVE_PROPS prop,
    void** destination
);

/// @brief   Writes the value of the specified Fallout 4
///          save property.
///          The value is directly set on the save file.
/// @param   save A pointer to a FO4SAVE data structure.
/// @param   prop Property to read.
/// @param   value Variable from which to take the value.
/// @return  True if is successful, otherwise false.
///
/// @see     FO4SAVE
/// @see     openFO4Save
/// @see     isFO4SaveOpen
/// @see     readFO4SaveProp
/// @see     setFO4SaveProp
///
/// @warning Experimental!!!
CFALLSAVE_API bool writeFO4SaveProp(
    FO4SAVE* save,
    FO4SAVE_PROPS prop,
    void** value
);



/// @brief  Show Fallout 4 save properties and properties
///         addresses on terminal.
/// @param  save A pointer to a FO4SAVE data structure.
/// @return True if is successful, otherwise false.
///
/// @see    FO4SAVE
/// @see    openFO4Save
/// @see    isFO4SaveOpen
CFALLSAVE_API bool printFO4Save(
    FO4SAVE* save
);

/// @brief  Show Fallout 4 save properties addresses on
///         terminal.
/// @param  save A pointer to a FO4SAVE data structure.
/// @return True if is successful, otherwise false.
///
/// @see    FO4SAVE
/// @see    openFO4Save
/// @see    isFO4SaveOpen
CFALLSAVE_API bool printFO4SaveProps(
    FO4SAVE* save
);

/// @brief  Show Fallout 4 save properties on terminal.
/// @param  save A pointer to a FO4SAVE data structure.
/// @return True if is successful, otherwise false.
///
/// @see    FO4SAVE
/// @see    openFO4Save
/// @see    isFO4SaveOpen
CFALLSAVE_API bool printFO4SavePropAddresses(
    FO4SAVE* save
);

/// @brief  Show Fallout 4 save snapshot on terminal.
/// @param  save A pointer to a FO4SAVE data structure.
/// @return True if is successful, otherwise false.
///
/// @see    FO4SAVE
/// @see    openFO4Save
/// @see    isFO4SaveOpen
CFALLSAVE_API bool printFO4SaveSnapshot(
    FO4SAVE* save
);

#endif  // !CFALLSAVE_FO4_H
