/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ library to read and write Fallout save files
 *
 * File Name   : fonv.h
 *
 * Title       : FALLOUT: NEW VEGAS HEADER
 * Description : Fallout: New Vegas Header
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.2.0
 * License     : MIT
 */

#ifndef CFALLSAVE_FONV_H
#define CFALLSAVE_FONV_H

#include "header.h"

#define FONVSAVE_GAME_NAME          "Fallout: New Vegas"

#define FONVSAVE_SIGNATURE          "FO3SAVEGAME"   // Save Signature
#define FONVSAVE_SIGNATURE_LENGTH   11              // Save Signature Length
#define FONVSAVE_PROPS_COUNT        11              // Number of properties

#define FONVSAVE_STANDARD_EXT       ".fos"

/// @brief Fallout: New Vegas save properties.
typedef enum FONVSAVE_PROPS
{
    FONVSAVE_PROPS_SAVE_SIGNATURE   = 0,
    FONVSAVE_PROPS_ENGINE_VERSION   = 1,
    FONVSAVE_PROPS_SAVE_NUMBER      = 2,
    FONVSAVE_PROPS_PLAYER_NAME      = 3,
    FONVSAVE_PROPS_PLAYER_LEVEL     = 4,
    FONVSAVE_PROPS_PLAYER_TITLE     = 5,
    FONVSAVE_PROPS_PLAYER_LOCATION  = 6,
    FONVSAVE_PROPS_PLAYER_PLAYTIME  = 7,
    FONVSAVE_PROPS_SNAPSHOT_WIDTH   = 8,
    FONVSAVE_PROPS_SNAPSHOT_HEIGHT  = 9,
    FONVSAVE_PROPS_SNAPSHOT         = 10
} FONVSAVE_PROPS;

#define FONVSAVE_MAX_SNAPSHOT_WIDTH     512     // Snapshot standard max width
#define FONVSAVE_MAX_SNAPSHOT_HEIGHT    288     // Snapshot standard max height
#define FONVSAVE_MAX_SNAPSHOT_LENGTH    442368  // Snapshot standard max length

#define FONVSAVE_SNAPSHOT_COLOR_BYTES   3       // Snapshot color bytes count
#define FONVSAVE_SNAPSHOT_FORMAT        "RGB"   // Snapshot color format

#define FONVSAVE_PLAYER_SEX_MALE        0
#define FONVSAVE_PLAYER_SEX_FEMALE      1

/// @brief Fallout: New Vegas Save.
typedef struct FONVSAVE
{
    FILE* save;         // Save file

    char* saveFileName; // Save file name

    char saveSignature[FONVSAVE_SIGNATURE_LENGTH + 1];  // 0
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

    long unsigned int propAddresses[FONVSAVE_PROPS_COUNT];
} FONVSAVE;

#define FONVSAVE_PROPS_SIZE sizeof(FONVSAVE_PROPS)
#define FONVSAVE_SIZE       sizeof(FONVSAVE)



/// @brief   Reads the specified Fallout: New Vegas save file.
///          If successful, a pointer to a FONVSAVE structure
///          is returned, otherwise NULL.
/// @param   saveName Path and name of the Fallout: New Vegas save file.
/// @return  A pointer to a FONVSAVE data structure or NULL.
///
/// @see     FONVSAVE
/// @see     isFONVSave
/// @see     isFONVSaveOpen
/// @see     closeFONVSave
///
/// @note    Use closeFONVSave to properly free the returned
///          pointer and avoid memory leaks.
/// @warning This function may return NULL. Always check the
///          pointer before attempting to access its contents.
CFALLSAVE_API FONVSAVE* readFONVSave(
    const char* saveName
);

/// @brief   Writes the specified Fallout: New Vegas save file.
/// @param   save A pointer to a FONVSAVE data structure.
/// @return  True if writing is successful, otherwise false.
///
/// @see     FONVSAVE
/// @see     isFONVSave
/// @see     openFONVSave
/// @see     isFONVSaveOpen
///
/// @note    The target save file will be overwritten.
/// @warning This operation is irreversible. Make sure to
///          back up the original file if needed.
CFALLSAVE_API bool writeFONVSave(
    FONVSAVE* save
);

/// @brief  Checks if the specified Fallout save file is
///         a Fallout: New Vegas save file.
/// @param  saveName Path and name of the Fallout: New Vegas save file.
/// @return True if the save file is a Fallout: New Vegas save,
///         otherwise false.
CFALLSAVE_API bool isFONVSave(
    const char* saveName
);

/// @brief  Checks if the Fallout: New Vegas save file is open.
/// @param  save A pointer to a FONVSAVE data structure.
/// @return True if the save file is open, otherwise false.
///
/// @see    FONVSAVE
/// @see    openFONVSave
/// @see    isFONVSaveOpen
/// @see    closeFONVSave
CFALLSAVE_API bool isFONVSaveOpen(
    FONVSAVE* save
);

/// @brief Closes a Fallout: New Vegas save file
/// @param save A pointer to a FONVSAVE data structure.
///
/// @see   FONVSAVE
/// @see   openFONVSave
/// @see   isFONVSaveOpen
CFALLSAVE_API void closeFONVSave(
    FONVSAVE* save
);



/// @brief   Gets the value of the specified Fallout: New Vegas
///          save property.
/// @param   save A pointer to a FONVSAVE data structure.
/// @param   prop Property to get.
/// @param   destination Variable to put the value in.
/// @return  True if is successful, otherwise false.
///
/// @see     FONVSAVE
/// @see     openFONVSave
/// @see     isFONVSaveOpen
/// @see     setFONVSaveProp
/// @see     readFONVSaveProp
///
/// @warning Experimental!!!
CFALLSAVE_API bool getFONVSaveProp(
    FONVSAVE* save,
    FONVSAVE_PROPS prop,
    void** destination
);

/// @brief   Sets the value of the specified Fallout: New Vegas
///          save property.
/// @param   save A pointer to a FONVSAVE data structure.
/// @param   prop Properties to set.
/// @param   value Variable from which to take the value.
/// @return  True if is successful, otherwise false.
///
/// @see     FONVSAVE
/// @see     openFONVSave
/// @see     isFONVSaveOpen
/// @see     getFONVSaveProp
/// @see     writeFONVSaveProp
///
/// @warning Experimental!!!
CFALLSAVE_API bool setFONVSaveProp(
    FONVSAVE* save,
    FONVSAVE_PROPS prop,
    void** value
);



/// @brief   Reads the value of the specified Fallout: New Vegas
///          save property.
///          The value is directly obtained from the save
///          file.
/// @param   save A pointer to a FONVSAVE data structure.
/// @param   prop Property to read.
/// @param   destination Variable to put the value in.
/// @return  True if is successful, otherwise false.
///
/// @see     FONVSAVE
/// @see     openFONVSave
/// @see     isFONVSaveOpen
/// @see     writeFONVSaveProp
/// @see     getFONVSaveProp
///
/// @warning Experimental!!!
CFALLSAVE_API bool readFONVSaveProp(
    FONVSAVE* save,
    FONVSAVE_PROPS prop,
    void** destination
);

/// @brief   Writes the value of the specified Fallout: New Vegas
///          save property.
///          The value is directly set on the save file.
/// @param   save A pointer to a FONVSAVE data structure.
/// @param   prop Property to read.
/// @param   value Variable from which to take the value.
/// @return  True if is successful, otherwise false.
///
/// @see     FONVSAVE
/// @see     openFONVSave
/// @see     isFONVSaveOpen
/// @see     readFONVSaveProp
/// @see     setFONVSaveProp
///
/// @warning Experimental!!!
CFALLSAVE_API bool writeFONVSaveProp(
    FONVSAVE* save,
    FONVSAVE_PROPS prop,
    void** value
);



/// @brief  Show Fallout: New Vegas save properties and properties
///         addresses on terminal.
/// @param  save A pointer to a FONVSAVE data structure.
/// @return True if is successful, otherwise false.
///
/// @see    FONVSAVE
/// @see    openFONVSave
/// @see    isFONVSaveOpen
CFALLSAVE_API bool printFONVSave(
    FONVSAVE* save
);

/// @brief  Show Fallout: New Vegas save properties addresses on
///         terminal.
/// @param  save A pointer to a FONVSAVE data structure.
/// @return True if is successful, otherwise false.
///
/// @see    FONVSAVE
/// @see    openFONVSave
/// @see    isFONVSaveOpen
CFALLSAVE_API bool printFONVSaveProps(
    FONVSAVE* save
);

/// @brief  Show Fallout: New Vegas save properties on terminal.
/// @param  save A pointer to a FONVSAVE data structure.
/// @return True if is successful, otherwise false.
///
/// @see    FONVSAVE
/// @see    openFONVSave
/// @see    isFONVSaveOpen
CFALLSAVE_API bool printFONVSavePropAddresses(
    FONVSAVE* save
);

/// @brief  Show Fallout: New Vegas save snapshot on terminal.
/// @param  save A pointer to a FONVSAVE data structure.
/// @return True if is successful, otherwise false.
///
/// @see    FONVSAVE
/// @see    openFONVSave
/// @see    isFONVSaveOpen
CFALLSAVE_API bool printFONVSaveSnapshot(
    FONVSAVE* save
);

#endif // !CFALLSAVE_FONV_H
