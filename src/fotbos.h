/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ library to read and write Fallout save files
 *
 * File Name   : fotbos.h
 *
 * Title       : FALLOUT TACTICS: BROTHERHOOD OF STEEL HEADER
 * Description : Fallout Tactics: Brotherhood of Steel Header
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#ifndef CFALLSAVE_FOTBOS_H
#define CFALLSAVE_FOTBOS_H

#include "header.h"

#define FOTBOSSAVE_GAME_NAME        "Fallout Tactics: Brotherhood of Steel"

#define FOTBOSSAVE_SIGNATURE        "<saveh>"   // Save Signature
#define FOTBOSSAVE_SIGNATURE_LENGTH 7           // Save Signature Length
#define FOTBOSSAVE_PROPS_COUNT      5           // Number of properties

#define FOTBOSSAVE_STANDARD_EXT     ".sav"

/// @brief Fallout Tactics: Brotherhood of Steel save properties.
typedef enum FOTBOSSAVE_PROPS
{
    FOTBOSSAVE_PROPS_SAVE_SIGNATURE     = 0,
    FOTBOSSAVE_PROPS_SAVE_NAME          = 1,
    FOTBOSSAVE_PROPS_PLAYER_NAME        = 2,
    FOTBOSSAVE_PROPS_PLAYER_LOCATION    = 3,
    FOTBOSSAVE_PROPS_GAME_DATE_TIME     = 4
} FOTBOSSAVE_PROPS;

/// @brief Fallout Tactics: Brotherhood of Steel Save.
typedef struct FOTBOSSAVE
{
    FILE* save;         // Save file

    char* saveFileName; // Save file name

    char saveSignature[FOTBOSSAVE_SIGNATURE_LENGTH + 1];    // 0
    char* saveName;                                         // 1

    char* playerName;                                       // 2
    char* playerLocation;                                   // 3
    char* gameDateTime;                                     // 4

    long unsigned int propAddresses[FOTBOSSAVE_PROPS_COUNT];
} FOTBOSSAVE;

#define FOTBOSSAVE_PROPS_SIZE   sizeof(FOTBOSSAVE_PROPS)
#define FOTBOSSAVE_SIZE         sizeof(FOTBOSSAVE)



/// @brief   Reads the specified Fallout Tactics: Brotherhood of Steel save file.
///          If successful, a pointer to a FOTBOSSAVE structure
///          is returned, otherwise NULL.
/// @param   saveName Path and name of the Fallout Tactics: Brotherhood of Steel save file.
/// @return  A pointer to a FOTBOSSAVE data structure or NULL.
///
/// @see     FOTBOSSAVE
/// @see     isFOTBOSSave
/// @see     isFOTBOSSaveOpen
/// @see     closeFOTBOSSave
///
/// @note    Use closeFOTBOSSave to properly free the returned
///          pointer and avoid memory leaks.
/// @warning This function may return NULL. Always check the
///          pointer before attempting to access its contents.
CFALLSAVE_API FOTBOSSAVE* readFOTBOSSave(
    const char* saveName
);

/// @brief   Writes the specified Fallout Tactics: Brotherhood of Steel save file.
/// @param   save A pointer to a FOTBOSSAVE data structure.
/// @return  True if writing is successful, otherwise false.
///
/// @see     FOTBOSSAVE
/// @see     isFOTBOSSave
/// @see     openFOTBOSSave
/// @see     isFOTBOSSaveOpen
///
/// @note    The target save file will be overwritten.
/// @warning This operation is irreversible. Make sure to
///          back up the original file if needed.
CFALLSAVE_API bool writeFOTBOSSave(
    FOTBOSSAVE* save
);

/// @brief  Checks if the specified Fallout save file is
///         a Fallout Tactics: Brotherhood of Steel save file.
/// @param  saveName Path and name of the Fallout Tactics: Brotherhood of Steel save file.
/// @return True if the save file is a Fallout Tactics: Brotherhood of Steel save,
///         otherwise false.
CFALLSAVE_API bool isFOTBOSSave(
    const char* saveName
);

/// @brief  Checks if the Fallout Tactics: Brotherhood of Steel save file is open.
/// @param  save A pointer to a FOTBOSSAVE data structure.
/// @return True if the save file is open, otherwise false.
///
/// @see    FOTBOSSAVE
/// @see    openFOTBOSSave
/// @see    isFOTBOSSaveOpen
/// @see    closeFOTBOSSave
CFALLSAVE_API bool isFOTBOSSaveOpen(
    FOTBOSSAVE* save
);

/// @brief Closes a Fallout Tactics: Brotherhood of Steel save file
/// @param save A pointer to a FOTBOSSAVE data structure.
///
/// @see   FOTBOSSAVE
/// @see   openFOTBOSSave
/// @see   isFOTBOSSaveOpen
CFALLSAVE_API void closeFOTBOSSave(
    FOTBOSSAVE* save
);



/// @brief   Gets the value of the specified Fallout Tactics: Brotherhood of Steel
///          save property.
/// @param   save A pointer to a FOTBOSSAVE data structure.
/// @param   prop Property to get.
/// @param   destination Variable to put the value in.
/// @return  True if is successful, otherwise false.
///
/// @see     FOTBOSSAVE
/// @see     openFOTBOSSave
/// @see     isFOTBOSSaveOpen
/// @see     setFOTBOSSaveProp
/// @see     readFOTBOSSaveProp
///
/// @warning Experimental!!!
CFALLSAVE_API bool getFOTBOSSaveProp(
    FOTBOSSAVE* save,
    FOTBOSSAVE_PROPS prop,
    void** destination
);

/// @brief   Sets the value of the specified Fallout Tactics: Brotherhood of Steel
///          save property.
/// @param   save A pointer to a FOTBOSSAVE data structure.
/// @param   prop Properties to set.
/// @param   value Variable from which to take the value.
/// @return  True if is successful, otherwise false.
///
/// @see     FOTBOSSAVE
/// @see     openFOTBOSSave
/// @see     isFOTBOSSaveOpen
/// @see     getFOTBOSSaveProp
/// @see     writeFOTBOSSaveProp
///
/// @warning Experimental!!!
CFALLSAVE_API bool setFOTBOSSaveProp(
    FOTBOSSAVE* save,
    FOTBOSSAVE_PROPS prop,
    void** value
);



/// @brief   Reads the value of the specified Fallout Tactics: Brotherhood of Steel
///          save property.
///          The value is directly obtained from the save
///          file.
/// @param   save A pointer to a FOTBOSSAVE data structure.
/// @param   prop Property to read.
/// @param   destination Variable to put the value in.
/// @return  True if is successful, otherwise false.
///
/// @see     FOTBOSSAVE
/// @see     openFOTBOSSave
/// @see     isFOTBOSSaveOpen
/// @see     writeFOTBOSSaveProp
/// @see     getFOTBOSSaveProp
///
/// @warning Experimental!!!
CFALLSAVE_API bool readFOTBOSSaveProp(
    FOTBOSSAVE* save,
    FOTBOSSAVE_PROPS prop,
    void** destination
);

/// @brief   Writes the value of the specified Fallout Tactics: Brotherhood of Steel
///          save property.
///          The value is directly set on the save file.
/// @param   save A pointer to a FOTBOSSAVE data structure.
/// @param   prop Property to read.
/// @param   value Variable from which to take the value.
/// @return  True if is successful, otherwise false.
///
/// @see     FOTBOSSAVE
/// @see     openFOTBOSSave
/// @see     isFOTBOSSaveOpen
/// @see     readFOTBOSSaveProp
/// @see     setFOTBOSSaveProp
///
/// @warning Experimental!!!
CFALLSAVE_API bool writeFOTBOSSaveProp(
    FOTBOSSAVE* save,
    FOTBOSSAVE_PROPS prop,
    void** value
);



/// @brief  Show Fallout Tactics: Brotherhood of Steel save properties and properties
///         addresses on terminal.
/// @param  save A pointer to a FOTBOSSAVE data structure.
/// @return True if is successful, otherwise false.
///
/// @see    FOTBOSSAVE
/// @see    openFOTBOSSave
/// @see    isFOTBOSSaveOpen
CFALLSAVE_API bool printFOTBOSSave(
    FOTBOSSAVE* save
);

/// @brief  Show Fallout Tactics: Brotherhood of Steel save properties addresses on
///         terminal.
/// @param  save A pointer to a FOTBOSSAVE data structure.
/// @return True if is successful, otherwise false.
///
/// @see    FOTBOSSAVE
/// @see    openFOTBOSSave
/// @see    isFOTBOSSaveOpen
CFALLSAVE_API bool printFOTBOSSaveProps(
    FOTBOSSAVE* save
);

/// @brief  Show Fallout Tactics: Brotherhood of Steel save properties on terminal.
/// @param  save A pointer to a FOTBOSSAVE data structure.
/// @return True if is successful, otherwise false.
///
/// @see    FOTBOSSAVE
/// @see    openFOTBOSSave
/// @see    isFOTBOSSaveOpen
CFALLSAVE_API bool printFOTBOSSavePropAddresses(
    FOTBOSSAVE* save
);



/// @brief  Create a Fallout Tactics: Brotherhood of Steel sample save.
/// @return True if is successful, otherwise false.
CFALLSAVE_API bool createFOTBOSSampleSave();

#endif // !CFALLSAVE_FOTBOS_H
