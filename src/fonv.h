/**
 * CFallSave
 *
 * Version : 1.0
 * Author  : Reallukee
 * License : MIT
 */

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef FONV_H  // FONV_H
#define FONV_H  // FONV_H

#define SAVE_SIGNATURE "FO3SAVEGAME"
#define SAVE_SIGNATURE_LENGTH 11

typedef struct {
    FILE* saveFile;

    char saveSignature[12];
    unsigned saveNumber;

    char* characterName;
    unsigned characterLevel;
    char* characterTitle;
    char* characterLocation;
    char* characterPlaytime;

    unsigned snapshotWidth;
    unsigned snapshotHeight;
    unsigned long snapshotLength;
    unsigned char* snapshot;

    unsigned long saveSignatureAddress;
    unsigned long saveNumberAddress;

    unsigned long characterNameAddress;
    unsigned long characterLevelAddress;
    unsigned long characterTitleAddress;
    unsigned long characterLocationAddress;
    unsigned long characterPlaytimeAddress;

    unsigned snapshotWidthAddress;
    unsigned snapshotHeightAddress;
    unsigned snapshotAddress;
} FONVSAVE;

FONVSAVE* readFONVSave(
    char* saveName,
    bool readProperties
);

bool isFONVSave(
    char* saveName
);

bool readFONVProperties(
    FONVSAVE* save
);

bool writeFONVSave(
    FONVSAVE* save,
    char* saveName
);

bool closeFONVSave(
    FONVSAVE* save
);



unsigned long getNextFONVPropertyAddress(
    unsigned long address,
    unsigned long skip
);



bool readFONVProperty(
    FONVSAVE* save,
    void* property,
    unsigned long* address,
    unsigned long skip,
    unsigned size,
    bool next
);

bool readFONVStringProperty(
    FONVSAVE* save, 
    void** property, 
    unsigned long* address, 
    unsigned long skip, 
    bool next
);

bool readFONVArrayProperty(
    FONVSAVE* save, 
    void* property, 
    unsigned long* address, 
    unsigned long skip, 
    int length, 
    bool next
);



bool writeFONVProperty(
    FONVSAVE* save,
    void* property,
    void* value,
    unsigned long* address,
    unsigned long skip,
    unsigned size,
    bool next
);

bool writeFONVStringProperty(
    FONVSAVE* save,
    void** property,
    void* value,
    unsigned long* address,
    unsigned long skip,
    bool next
);

bool writeFONVArrayProperty(
    FONVSAVE* save,
    void* property,
    void* value,
    unsigned long* address,
    unsigned long skip,
    int length,
    bool next
);



void printFONVSave(
    FONVSAVE* save
);

#endif  // ! FONV_H
