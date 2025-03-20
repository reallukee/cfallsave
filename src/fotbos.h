/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ Library to Read Fallout Save Files
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

#define FOTBOSSAVE_GAME_NAME            "Fallout Tactics: Brotherhood of Steel"
#define FOTBOSSAVE_SIGNATURE            "<saveh>"
#define FOTBOSSAVE_SIGNATURE_LENGTH     7
#define FOTBOSSAVE_PROPS_COUNT          5
#define FOTBOSSAVE_SAVE_STANDARD_EXT    ".sav"

typedef enum FOTBOSSAVE_PROPS
{
    FOTBOSSAVE_PROPS_SAVE_SIGNATURE     = 0,
    FOTBOSSAVE_PROPS_SAVE_NAME          = 1,
    FOTBOSSAVE_PROPS_PLAYER_NAME        = 2,
    FOTBOSSAVE_PROPS_PLAYER_LOCATION    = 3,
    FOTBOSSAVE_PROPS_GAME_DATE_TIME     = 4
} FOTBOSSAVE_PROPS;

typedef struct FOTBOSSAVE
{
    FILE* save;

    char* saveFileName;

    char saveSignature[FOTBOSSAVE_SIGNATURE_LENGTH + 1];
    char* saveName;

    char* playerName;
    char* playerLocation;
    char* gameDateTime;

    long unsigned int propAddresses[FOTBOSSAVE_PROPS_COUNT];
} FOTBOSSAVE;

#define FOTBOSSAVE_PROPS_SIZE   sizeof(FOTBOSSAVE_PROPS)
#define FOTBOSSAVE_SIZE         sizeof(FOTBOSSAVE)



CFALLSAVE_API FOTBOSSAVE* readFOTBOSSave(
    const char* saveName
);

CFALLSAVE_API bool writeFOTBOSSave(
    FOTBOSSAVE* save
);

CFALLSAVE_API bool isFOTBOSSave(
    const char* saveName
);

CFALLSAVE_API bool isFOTBOSSaveOpen(
    FOTBOSSAVE* save
);

CFALLSAVE_API void closeFOTBOSSave(
    FOTBOSSAVE* save
);



CFALLSAVE_API bool getFOTBOSSaveProp(
    FOTBOSSAVE* save,
    FOTBOSSAVE_PROPS prop,
    void** destination
);

CFALLSAVE_API bool setFOTBOSSaveProp(
    FOTBOSSAVE* save,
    FOTBOSSAVE_PROPS prop,
    void** value
);



CFALLSAVE_API bool readFOTBOSSaveProp(
    FOTBOSSAVE* save,
    FOTBOSSAVE_PROPS prop,
    void** destination
);

CFALLSAVE_API bool writeFOTBOSSaveProp(
    FOTBOSSAVE* save,
    FOTBOSSAVE_PROPS prop,
    void** value
);



CFALLSAVE_API bool printFOTBOSSave(
    FOTBOSSAVE* save
);

CFALLSAVE_API bool printFOTBOSSaveProps(
    FOTBOSSAVE* save
);

CFALLSAVE_API bool printFOTBOSSavePropAddresses(
    FOTBOSSAVE* save
);

#endif // !CFALLSAVE_FOTBOS_H
