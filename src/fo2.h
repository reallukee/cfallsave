/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ Library to Read Fallout Save Files
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
#define FO2SAVE_SIGNATURE           "FALLOUT SAVE FILE"
#define FO2SAVE_SIGNATURE_LENGTH    17
#define FO2SAVE_PROPS_COUNT         3
#define FO2SAVE_SAVE_STANDARD_EXT   ".dat"

typedef enum FO2SAVE_PROPS
{
    FO2SAVE_PROPS_SAVE_SIGNATURE    = 0,
    FO2SAVE_PROPS_SAVE_NAME         = 1,
    FO2SAVE_PROPS_PLAYER_NAME       = 2
} FO2SAVE_PROPS;

typedef struct FO2SAVE
{
    FILE* save;

    char* saveFileName;

    char saveSignature[FO2SAVE_SIGNATURE_LENGTH + 1];
    char saveName[32];

    char playerName[32];

    long unsigned int propAddresses[FO2SAVE_PROPS_COUNT];
} FO2SAVE;

#define FO2SAVE_PROPS_SIZE  sizeof(FO2SAVE_PROPS)
#define FO2SAVE_SIZE        sizeof(FO2SAVE)



CFALLSAVE_API FO2SAVE* readFO2Save(
    const char* saveName
);

CFALLSAVE_API bool writeFO2Save(
    FO2SAVE* save
);

CFALLSAVE_API bool isFO2Save(
    const char* saveName
);

CFALLSAVE_API bool isFO2SaveOpen(
    FO2SAVE* save
);

CFALLSAVE_API void closeFO2Save(
    FO2SAVE* save
);



CFALLSAVE_API bool getFO2SaveProp(
    FO2SAVE* save,
    FO2SAVE_PROPS prop,
    void** destination
);

CFALLSAVE_API bool setFO2SaveProp(
    FO2SAVE* save,
    FO2SAVE_PROPS prop,
    void** value
);



CFALLSAVE_API bool readFO2SaveProp(
    FO2SAVE* save,
    FO2SAVE_PROPS prop,
    void** destination
);

CFALLSAVE_API bool writeFO2SaveProp(
    FO2SAVE* save,
    FO2SAVE_PROPS prop,
    void** value
);



CFALLSAVE_API bool printFO2Save(
    FO2SAVE* save
);

CFALLSAVE_API bool printFO2SaveProps(
    FO2SAVE* save
);

CFALLSAVE_API bool printFO2SavePropAddresses(
    FO2SAVE* save
);

#endif  // !CFALLSAVE_FO2_H
