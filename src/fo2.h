/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ library to read and write Fallout save files
 *
 * File Name   : fo2.h
 *
 * Title       : FALLOUT 2 HEADER
 * Description : Fallout 2 Header
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#ifndef CFALLSAVE_FO2_H
#define CFALLSAVE_FO2_H

#include "header.h"

#define FO2SAVE_GAME_NAME           "Fallout 2"

#define FO2SAVE_SIGNATURE           "FALLOUT SAVE FILE" // Save Signature
#define FO2SAVE_SIGNATURE_LENGTH    17                  // Save Signature Length
#define FO2SAVE_PROPS_COUNT         3                   // Number of properties

#define FO2SAVE_STANDARD_EXT        ".dat"

/// @brief Fallout 2 save properties.
typedef enum FO2SAVE_PROPS
{
    FO2SAVE_PROPS_SAVE_SIGNATURE    = 0,
    FO2SAVE_PROPS_SAVE_NAME         = 1,
    FO2SAVE_PROPS_PLAYER_NAME       = 2
} FO2SAVE_PROPS;

#define FO2SAVE_STRING_SIZE 32

/// @brief Fallout 2 Save.
typedef struct FO2SAVE
{
    FILE* save;         // Save file

    char* saveFileName; // Save file name

    char saveSignature[FO2SAVE_SIGNATURE_LENGTH + 1];   // 0
    char saveName[FO2SAVE_STRING_SIZE + 1];             // 1

    char playerName[FO2SAVE_STRING_SIZE + 1];           // 2

    long unsigned int propAddresses[FO2SAVE_PROPS_COUNT];
} FO2SAVE;

#define FO2SAVE_PROPS_SIZE  sizeof(FO2SAVE_PROPS)
#define FO2SAVE_SIZE        sizeof(FO2SAVE)



/// @brief   Reads the specified Fallout 2 save file.
///          If successful, a pointer to a FO2SAVE structure
///          is returned, otherwise NULL.
/// @param   saveName Path and name of the Fallout 2 save file.
/// @return  A pointer to a FO2SAVE data structure or NULL.
///
/// @see     FO2SAVE
/// @see     isFO2Save
/// @see     isFO2SaveOpen
/// @see     closeFO2Save
///
/// @note    Use closeFO2Save to properly free the returned
///          pointer and avoid memory leaks.
/// @warning This function may return NULL. Always check the
///          pointer before attempting to access its contents.
CFALLSAVE_API FO2SAVE* readFO2Save(
    const char* saveName
);

/// @brief   Writes the specified Fallout 2 save file.
/// @param   save A pointer to a FO2SAVE data structure.
/// @return  True if writing is successful, otherwise false.
///
/// @see     FO2SAVE
/// @see     isFO2Save
/// @see     openFO2Save
/// @see     isFO2SaveOpen
///
/// @note    The target save file will be overwritten.
/// @warning This operation is irreversible. Make sure to
///          back up the original file if needed.
CFALLSAVE_API bool writeFO2Save(
    FO2SAVE* save
);

/// @brief  Checks if the specified Fallout save file is
///         a Fallout 2 save file.
/// @param  saveName Path and name of the Fallout 2 save file.
/// @return True if the save file is a Fallout 2 save,
///         otherwise false.
CFALLSAVE_API bool isFO2Save(
    const char* saveName
);

/// @brief  Checks if the Fallout 2 save file is open.
/// @param  save A pointer to a FO2SAVE data structure.
/// @return True if the save file is open, otherwise false.
///
/// @see    FO2SAVE
/// @see    openFO2Save
/// @see    isFO2SaveOpen
/// @see    closeFO2Save
CFALLSAVE_API bool isFO2SaveOpen(
    FO2SAVE* save
);

/// @brief Closes a Fallout 2 save file
/// @param save A pointer to a FO2SAVE data structure.
///
/// @see   FO2SAVE
/// @see   openFO2Save
/// @see   isFO2SaveOpen
CFALLSAVE_API void closeFO2Save(
    FO2SAVE* save
);



/// @brief   Gets the value of the specified Fallout 2
///          save property.
/// @param   save A pointer to a FO2SAVE data structure.
/// @param   prop Property to get.
/// @param   destination Variable to put the value in.
/// @return  True if is successful, otherwise false.
///
/// @see     FO2SAVE
/// @see     openFO2Save
/// @see     isFO2SaveOpen
/// @see     setFO2SaveProp
/// @see     readFO2SaveProp
///
/// @warning Experimental!!!
CFALLSAVE_API bool getFO2SaveProp(
    FO2SAVE* save,
    FO2SAVE_PROPS prop,
    void** destination
);

/// @brief   Sets the value of the specified Fallout 2
///          save property.
/// @param   save A pointer to a FO2SAVE data structure.
/// @param   prop Properties to set.
/// @param   value Variable from which to take the value.
/// @return  True if is successful, otherwise false.
///
/// @see     FO2SAVE
/// @see     openFO2Save
/// @see     isFO2SaveOpen
/// @see     getFO2SaveProp
/// @see     writeFO2SaveProp
///
/// @warning Experimental!!!
CFALLSAVE_API bool setFO2SaveProp(
    FO2SAVE* save,
    FO2SAVE_PROPS prop,
    void** value
);



/// @brief   Reads the value of the specified Fallout 2
///          save property.
///          The value is directly obtained from the save
///          file.
/// @param   save A pointer to a FO2SAVE data structure.
/// @param   prop Property to read.
/// @param   destination Variable to put the value in.
/// @return  True if is successful, otherwise false.
///
/// @see     FO2SAVE
/// @see     openFO2Save
/// @see     isFO2SaveOpen
/// @see     writeFO2SaveProp
/// @see     getFO2SaveProp
///
/// @warning Experimental!!!
CFALLSAVE_API bool readFO2SaveProp(
    FO2SAVE* save,
    FO2SAVE_PROPS prop,
    void** destination
);

/// @brief   Writes the value of the specified Fallout 2
///          save property.
///          The value is directly set on the save file.
/// @param   save A pointer to a FO2SAVE data structure.
/// @param   prop Property to read.
/// @param   value Variable from which to take the value.
/// @return  True if is successful, otherwise false.
///
/// @see     FO2SAVE
/// @see     openFO2Save
/// @see     isFO2SaveOpen
/// @see     readFO2SaveProp
/// @see     setFO2SaveProp
///
/// @warning Experimental!!!
CFALLSAVE_API bool writeFO2SaveProp(
    FO2SAVE* save,
    FO2SAVE_PROPS prop,
    void** value
);



/// @brief  Show Fallout 2 save properties and properties
///         addresses on terminal.
/// @param  save A pointer to a FO2SAVE data structure.
/// @return True if is successful, otherwise false.
///
/// @see    FO2SAVE
/// @see    openFO2Save
/// @see    isFO2SaveOpen
CFALLSAVE_API bool printFO2Save(
    FO2SAVE* save
);

/// @brief  Show Fallout 2 save properties addresses on
///         terminal.
/// @param  save A pointer to a FO2SAVE data structure.
/// @return True if is successful, otherwise false.
///
/// @see    FO2SAVE
/// @see    openFO2Save
/// @see    isFO2SaveOpen
CFALLSAVE_API bool printFO2SaveProps(
    FO2SAVE* save
);

/// @brief  Show Fallout 2 save properties on terminal.
/// @param  save A pointer to a FO2SAVE data structure.
/// @return True if is successful, otherwise false.
///
/// @see    FO2SAVE
/// @see    openFO2Save
/// @see    isFO2SaveOpen
CFALLSAVE_API bool printFO2SavePropAddresses(
    FO2SAVE* save
);



/// @brief  Create a Fallout 2 sample save.
/// @return True if is successful, otherwise false.
CFALLSAVE_API bool createFO2SampleSave();

#endif  // !CFALLSAVE_FO2_H
