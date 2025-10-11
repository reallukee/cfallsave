/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ library to read and write Fallout save files
 *
 * File Name   : fo1.h
 *
 * Title       : FALLOUT 1 HEADER
 * Description : Fallout 1 Header
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.2.0
 * License     : MIT
 */

#ifndef CFALLSAVE_FO1_H
#define CFALLSAVE_FO1_H

#include "header.h"

#define FO1SAVE_GAME_NAME           "Fallout 1"

#define FO1SAVE_SIGNATURE           "FALLOUT SAVE FILE" // Save Signature
#define FO1SAVE_SIGNATURE_LENGTH    17                  // Save Signature Length
#define FO1SAVE_PROPS_COUNT         3                   // Number of properties

#define FO1SAVE_STANDARD_EXT        ".dat"

/// @brief Fallout 1 save properties.
typedef enum FO1SAVE_PROPS
{
    FO1SAVE_PROPS_SAVE_SIGNATURE    = 0,
    FO1SAVE_PROPS_SAVE_NAME         = 1,
    FO1SAVE_PROPS_PLAYER_NAME       = 2
} FO1SAVE_PROPS;

#define FO1SAVE_STRING_SIZE 32

/// @brief Fallout 1 Save.
typedef struct FO1SAVE
{
    FILE* save;         // Save file

    char* saveFileName; // Save file name

    char saveSignature[FO1SAVE_SIGNATURE_LENGTH + 1];   // 0
    char saveName[FO1SAVE_STRING_SIZE + 1];             // 1

    char playerName[FO1SAVE_STRING_SIZE + 1];           // 2

    long unsigned int propAddresses[FO1SAVE_PROPS_COUNT];
} FO1SAVE;

#define FO1SAVE_PROPS_SIZE  sizeof(FO1SAVE_PROPS)
#define FO1SAVE_SIZE        sizeof(FO1SAVE)



/// @brief   Reads the specified Fallout 1 save file.
///          If successful, a pointer to a FO1SAVE structure
///          is returned, otherwise NULL.
/// @param   saveName Path and name of the Fallout 1 save file.
/// @return  A pointer to a FO1SAVE data structure or NULL.
///
/// @see     FO1SAVE
/// @see     isFO1Save
/// @see     isFO1SaveOpen
/// @see     closeFO1Save
///
/// @note    Use closeFO1Save to properly free the returned
///          pointer and avoid memory leaks.
/// @warning This function may return NULL. Always check the
///          pointer before attempting to access its contents.
CFALLSAVE_API FO1SAVE* readFO1Save(
    const char* saveName
);

/// @brief   Writes the specified Fallout 1 save file.
/// @param   save A pointer to a FO1SAVE data structure.
/// @return  True if writing is successful, otherwise false.
///
/// @see     FO1SAVE
/// @see     isFO1Save
/// @see     openFO1Save
/// @see     isFO1SaveOpen
///
/// @note    The target save file will be overwritten.
/// @warning This operation is irreversible. Make sure to
///          back up the original file if needed.
CFALLSAVE_API bool writeFO1Save(
    FO1SAVE* save
);

/// @brief  Checks if the specified Fallout save file is
///         a Fallout 1 save file.
/// @param  saveName Path and name of the Fallout 1 save file.
/// @return True if the save file is a Fallout 1 save,
///         otherwise false.
CFALLSAVE_API bool isFO1Save(
    const char* saveName
);

/// @brief  Checks if the Fallout 1 save file is open.
/// @param  save A pointer to a FO1SAVE data structure.
/// @return True if the save file is open, otherwise false.
///
/// @see    FO1SAVE
/// @see    openFO1Save
/// @see    isFO1SaveOpen
/// @see    closeFO1Save
CFALLSAVE_API bool isFO1SaveOpen(
    FO1SAVE* save
);

/// @brief Closes a Fallout 1 save file
/// @param save A pointer to a FO1SAVE data structure.
///
/// @see   FO1SAVE
/// @see   openFO1Save
/// @see   isFO1SaveOpen
CFALLSAVE_API void closeFO1Save(
    FO1SAVE* save
);



/// @brief   Gets the value of the specified Fallout 1
///          save property.
/// @param   save A pointer to a FO1SAVE data structure.
/// @param   prop Property to get.
/// @param   destination Variable to put the value in.
/// @return  True if is successful, otherwise false.
///
/// @see     FO1SAVE
/// @see     openFO1Save
/// @see     isFO1SaveOpen
/// @see     setFO1SaveProp
/// @see     readFO1SaveProp
///
/// @warning Experimental!!!
CFALLSAVE_API bool getFO1SaveProp(
    FO1SAVE* save,
    FO1SAVE_PROPS prop,
    void** destination
);

/// @brief   Sets the value of the specified Fallout 1
///          save property.
/// @param   save A pointer to a FO1SAVE data structure.
/// @param   prop Properties to set.
/// @param   value Variable from which to take the value.
/// @return  True if is successful, otherwise false.
///
/// @see     FO1SAVE
/// @see     openFO1Save
/// @see     isFO1SaveOpen
/// @see     getFO1SaveProp
/// @see     writeFO1SaveProp
///
/// @warning Experimental!!!
CFALLSAVE_API bool setFO1SaveProp(
    FO1SAVE* save,
    FO1SAVE_PROPS prop,
    void** value
);



/// @brief   Reads the value of the specified Fallout 1
///          save property.
///          The value is directly obtained from the save
///          file.
/// @param   save A pointer to a FO1SAVE data structure.
/// @param   prop Property to read.
/// @param   destination Variable to put the value in.
/// @return  True if is successful, otherwise false.
///
/// @see     FO1SAVE
/// @see     openFO1Save
/// @see     isFO1SaveOpen
/// @see     writeFO1SaveProp
/// @see     getFO1SaveProp
///
/// @warning Experimental!!!
CFALLSAVE_API bool readFO1SaveProp(
    FO1SAVE* save,
    FO1SAVE_PROPS prop,
    void** destination
);

/// @brief   Writes the value of the specified Fallout 1
///          save property.
///          The value is directly set on the save file.
/// @param   save A pointer to a FO1SAVE data structure.
/// @param   prop Property to read.
/// @param   value Variable from which to take the value.
/// @return  True if is successful, otherwise false.
///
/// @see     FO1SAVE
/// @see     openFO1Save
/// @see     isFO1SaveOpen
/// @see     readFO1SaveProp
/// @see     setFO1SaveProp
///
/// @warning Experimental!!!
CFALLSAVE_API bool writeFO1SaveProp(
    FO1SAVE* save,
    FO1SAVE_PROPS prop,
    void** value
);



/// @brief  Show Fallout 1 save properties and properties
///         addresses on terminal.
/// @param  save A pointer to a FO1SAVE data structure.
/// @return True if is successful, otherwise false.
///
/// @see    FO1SAVE
/// @see    openFO1Save
/// @see    isFO1SaveOpen
CFALLSAVE_API bool printFO1Save(
    FO1SAVE* save
);

/// @brief  Show Fallout 1 save properties addresses on
///         terminal.
/// @param  save A pointer to a FO1SAVE data structure.
/// @return True if is successful, otherwise false.
///
/// @see    FO1SAVE
/// @see    openFO1Save
/// @see    isFO1SaveOpen
CFALLSAVE_API bool printFO1SaveProps(
    FO1SAVE* save
);

/// @brief  Show Fallout 1 save properties on terminal.
/// @param  save A pointer to a FO1SAVE data structure.
/// @return True if is successful, otherwise false.
///
/// @see    FO1SAVE
/// @see    openFO1Save
/// @see    isFO1SaveOpen
CFALLSAVE_API bool printFO1SavePropAddresses(
    FO1SAVE* save
);

#endif  // !CFALLSAVE_FO1_H
