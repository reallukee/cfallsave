/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ Library to Read and Write Fallout Save Files
 *
 * File Name   : fo1.h
 *
 * Title       : FALLOUT 1 HEADER
 * Description : Fallout 1 Header
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#ifndef CFALLSAVE_FO1_H
#define CFALLSAVE_FO1_H

#include "header.h"

#define FO1SAVE_GAME_NAME           "Fallout 1"
#define FO1SAVE_SIGNATURE           "FALLOUT SAVE FILE"
#define FO1SAVE_SIGNATURE_LENGTH    17
#define FO1SAVE_PROPS_COUNT         3
#define FO1SAVE_SAVE_STANDARD_EXT   ".dat"

typedef enum FO1SAVE_PROPS
{
    FO1SAVE_PROPS_SAVE_SIGNATURE    = 0,
    FO1SAVE_PROPS_SAVE_NAME         = 1,
    FO1SAVE_PROPS_PLAYER_NAME       = 2
} FO1SAVE_PROPS;

typedef struct FO1SAVE
{
    FILE* save;

    char* saveFileName;

    char saveSignature[FO1SAVE_SIGNATURE_LENGTH + 1];
    char saveName[32];

    char playerName[32];

    long unsigned int propAddresses[FO1SAVE_PROPS_COUNT];
} FO1SAVE;

#define FO1SAVE_PROPS_SIZE  sizeof(FO1SAVE_PROPS)
#define FO1SAVE_SIZE        sizeof(FO1SAVE)



CFALLSAVE_API FO1SAVE* readFO1Save(
    const char* saveName
);

CFALLSAVE_API bool writeFO1Save(
    FO1SAVE* save
);

CFALLSAVE_API bool isFO1Save(
    const char* saveName
);

CFALLSAVE_API bool isFO1SaveOpen(
    FO1SAVE* save
);

CFALLSAVE_API void closeFO1Save(
    FO1SAVE* save
);



CFALLSAVE_API bool getFO1SaveProp(
    FO1SAVE* save,
    FO1SAVE_PROPS prop,
    void** destination
);

CFALLSAVE_API bool setFO1SaveProp(
    FO1SAVE* save,
    FO1SAVE_PROPS prop,
    void** value
);



CFALLSAVE_API bool readFO1SaveProp(
    FO1SAVE* save,
    FO1SAVE_PROPS prop,
    void** destination
);

CFALLSAVE_API bool writeFO1SaveProp(
    FO1SAVE* save,
    FO1SAVE_PROPS prop,
    void** value
);



CFALLSAVE_API bool printFO1Save(
    FO1SAVE* save
);

CFALLSAVE_API bool printFO1SaveProps(
    FO1SAVE* save
);

CFALLSAVE_API bool printFO1SavePropAddresses(
    FO1SAVE* save
);

#endif  // !CFALLSAVE_FO1_H
