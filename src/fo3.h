/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ library to read and write Fallout save files
 *
 * File Name   : fo3.h
 *
 * Title       : FALLOUT 3 HEADER
 * Description : Fallout 3 Header
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.2.0
 * License     : MIT
 */

#ifndef CFALLSAVE_FO3_H
#define CFALLSAVE_FO3_H

#include "header.h"

#define FO3SAVE_GAME_NAME           "Fallout 3"

#define FO3SAVE_SIGNATURE           "FO3SAVEGAME"   // Save Signature
#define FO3SAVE_SIGNATURE_LENGTH    11              // Save Signature Length
#define FO3SAVE_PROPS_COUNT         11              // Number of properties

#define FO3SAVE_STANDARD_EXT        ".fos"

/// @brief Fallout 3 save properties.
typedef enum FO3SAVE_PROPS
{
    FO3SAVE_PROPS_SAVE_SIGNATURE    = 0,
    FO3SAVE_PROPS_ENGINE_VERSION    = 1,
    FO3SAVE_PROPS_SAVE_NUMBER       = 2,
    FO3SAVE_PROPS_PLAYER_NAME       = 3,
    FO3SAVE_PROPS_PLAYER_LEVEL      = 4,
    FO3SAVE_PROPS_PLAYER_TITLE      = 5,
    FO3SAVE_PROPS_PLAYER_LOCATION   = 6,
    FO3SAVE_PROPS_PLAYER_PLAYTIME   = 7,
    FO3SAVE_PROPS_SNAPSHOT_WIDTH    = 8,
    FO3SAVE_PROPS_SNAPSHOT_HEIGHT   = 9,
    FO3SAVE_PROPS_SNAPSHOT          = 10
} FO3SAVE_PROPS;

#define FO3SAVE_MAX_SNAPSHOT_WIDTH      512     // Snapshot standard max width
#define FO3SAVE_MAX_SNAPSHOT_HEIGHT     288     // Snapshot standard max height
#define FO3SAVE_MAX_SNAPSHOT_LENGTH     442368  // Snapshot standard max length

#define FO3SAVE_SNAPSHOT_COLOR_BYTES    3       // Snapshot color bytes count
#define FO3SAVE_SNAPSHOT_FORMAT         "RGB"   // Snapshot color format

#define FO3SAVE_PLAYER_SEX_MALE         0
#define FO3SAVE_PLAYER_SEX_FEMALE       1

/// @brief Fallout 3 Save.
typedef struct FO3SAVE
{
    FILE* save;         // Save file

    char* saveFileName; // Save file name

    char saveSignature[FO3SAVE_SIGNATURE_LENGTH + 1];   // 0
    unsigned int engineVersion;                         // 1
    unsigned int saveNumber;                            // 2

    char* playerName;                                   // 3
    unsigned int playerLevel;                           // 4
    char* playerTitle;                                  // 5
    char* playerLocation;                               // 6
    char* playerPlaytime;                               // 7

    unsigned int snapshotWidth;                         // 8
    unsigned int snapshotHeight;                        // 9
    long unsigned int snapshotLength;                   // 10
    unsigned char* snapshot;                            // 11

    long unsigned int propAddresses[FO3SAVE_PROPS_COUNT];
} FO3SAVE;

#define FO3SAVE_PROPS_SIZE  sizeof(FO3SAVE_PROPS)
#define FO3SAVE_SIZE        sizeof(FO3SAVE)



/// @brief   Reads the specified Fallout 3 save file.
///          If successful, a pointer to a FO3SAVE structure
///          is returned, otherwise NULL.
/// @param   saveName Path and name of the Fallout 3 save file.
/// @return  A pointer to a FO3SAVE data structure or NULL.
///
/// @see     FO3SAVE
/// @see     isFO3Save
/// @see     isFO3SaveOpen
/// @see     closeFO3Save
///
/// @note    Use closeFO3Save to properly free the returned
///          pointer and avoid memory leaks.
/// @warning This function may return NULL. Always check the
///          pointer before attempting to access its contents.
CFALLSAVE_API FO3SAVE* readFO3Save(
    const char* saveName
);

/// @brief   Writes the specified Fallout 3 save file.
/// @param   save A pointer to a FO3SAVE data structure.
/// @return  True if writing is successful, otherwise false.
///
/// @see     FO3SAVE
/// @see     isFO3Save
/// @see     openFO3Save
/// @see     isFO3SaveOpen
///
/// @note    The target save file will be overwritten.
/// @warning This operation is irreversible. Make sure to
///          back up the original file if needed.
CFALLSAVE_API bool writeFO3Save(
    FO3SAVE* save
);

/// @brief  Checks if the specified Fallout save file is
///         a Fallout 3 save file.
/// @param  saveName Path and name of the Fallout 3 save file.
/// @return True if the save file is a Fallout 3 save,
///         otherwise false.
CFALLSAVE_API bool isFO3Save(
    const char* saveName
);

/// @brief  Checks if the Fallout 3 save file is open.
/// @param  save A pointer to a FO3SAVE data structure.
/// @return True if the save file is open, otherwise false.
///
/// @see    FO3SAVE
/// @see    openFO3Save
/// @see    isFO3SaveOpen
/// @see    closeFO3Save
CFALLSAVE_API bool isFO3SaveOpen(
    FO3SAVE* save
);

/// @brief Closes a Fallout 3 save file
/// @param save A pointer to a FO3SAVE data structure.
///
/// @see   FO3SAVE
/// @see   openFO3Save
/// @see   isFO3SaveOpen
CFALLSAVE_API void closeFO3Save(
    FO3SAVE* save
);



/// @brief   Gets the value of the specified Fallout 3
///          save property.
/// @param   save A pointer to a FO3SAVE data structure.
/// @param   prop Property to get.
/// @param   destination Variable to put the value in.
/// @return  True if is successful, otherwise false.
///
/// @see     FO3SAVE
/// @see     openFO3Save
/// @see     isFO3SaveOpen
/// @see     setFO3SaveProp
/// @see     readFO3SaveProp
///
/// @warning Experimental!!!
CFALLSAVE_API bool getFO3SaveProp(
    FO3SAVE* save,
    FO3SAVE_PROPS prop,
    void** destination
);

/// @brief   Sets the value of the specified Fallout 3
///          save property.
/// @param   save A pointer to a FO3SAVE data structure.
/// @param   prop Properties to set.
/// @param   value Variable from which to take the value.
/// @return  True if is successful, otherwise false.
///
/// @see     FO3SAVE
/// @see     openFO3Save
/// @see     isFO3SaveOpen
/// @see     getFO3SaveProp
/// @see     writeFO3SaveProp
///
/// @warning Experimental!!!
CFALLSAVE_API bool setFO3SaveProp(
    FO3SAVE* save,
    FO3SAVE_PROPS prop,
    void** value
);



/// @brief   Reads the value of the specified Fallout 3
///          save property.
///          The value is directly obtained from the save
///          file.
/// @param   save A pointer to a FO3SAVE data structure.
/// @param   prop Property to read.
/// @param   destination Variable to put the value in.
/// @return  True if is successful, otherwise false.
///
/// @see     FO3SAVE
/// @see     openFO3Save
/// @see     isFO3SaveOpen
/// @see     writeFO3SaveProp
/// @see     getFO3SaveProp
///
/// @warning Experimental!!!
CFALLSAVE_API bool readFO3SaveProp(
    FO3SAVE* save,
    FO3SAVE_PROPS prop,
    void** destination
);

/// @brief   Writes the value of the specified Fallout 3
///          save property.
///          The value is directly set on the save file.
/// @param   save A pointer to a FO3SAVE data structure.
/// @param   prop Property to read.
/// @param   value Variable from which to take the value.
/// @return  True if is successful, otherwise false.
///
/// @see     FO3SAVE
/// @see     openFO3Save
/// @see     isFO3SaveOpen
/// @see     readFO3SaveProp
/// @see     setFO3SaveProp
///
/// @warning Experimental!!!
CFALLSAVE_API bool writeFO3SaveProp(
    FO3SAVE* save,
    FO3SAVE_PROPS prop,
    void** value
);



/// @brief  Show Fallout 3 save properties and properties
///         addresses on terminal.
/// @param  save A pointer to a FO3SAVE data structure.
/// @return True if is successful, otherwise false.
///
/// @see    FO3SAVE
/// @see    openFO3Save
/// @see    isFO3SaveOpen
CFALLSAVE_API bool printFO3Save(
    FO3SAVE* save
);

/// @brief  Show Fallout 3 save properties addresses on
///         terminal.
/// @param  save A pointer to a FO3SAVE data structure.
/// @return True if is successful, otherwise false.
///
/// @see    FO3SAVE
/// @see    openFO3Save
/// @see    isFO3SaveOpen
CFALLSAVE_API bool printFO3SaveProps(
    FO3SAVE* save
);

/// @brief  Show Fallout 3 save properties on terminal.
/// @param  save A pointer to a FO3SAVE data structure.
/// @return True if is successful, otherwise false.
///
/// @see    FO3SAVE
/// @see    openFO3Save
/// @see    isFO3SaveOpen
CFALLSAVE_API bool printFO3SavePropAddresses(
    FO3SAVE* save
);

/// @brief  Show Fallout 3 save snapshot on terminal.
/// @param  save A pointer to a FO3SAVE data structure.
/// @return True if is successful, otherwise false.
///
/// @see    FO3SAVE
/// @see    openFO3Save
/// @see    isFO3SaveOpen
CFALLSAVE_API bool printFO3SaveSnapshot(
    FO3SAVE* save
);

#endif // !CFALLSAVE_FO3_H
