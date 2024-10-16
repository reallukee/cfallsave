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

#ifndef FO3_H   // FO3_H
#define FO3_H   // FO3_H

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
} FO3SAVE;

FO3SAVE* readFO3Save(
    char* saveName,
    bool readProperties
);

bool isFO3Save(
    char* saveName
);

bool readFO3Properties(
    FO3SAVE* save
);

bool writeFO3Save(
    FO3SAVE* save,
    char* saveName
);

bool closeFO3Save(
    FO3SAVE* save
);



unsigned long getNextFO3PropertyAddress(
    unsigned long address,
    unsigned long skip
);



bool readFO3Property(
    FO3SAVE* save,
    void* property,
    unsigned long* address,
    unsigned long skip,
    unsigned size,
    bool next
);

bool readFO3StringProperty(
    FO3SAVE* save, 
    void** property, 
    unsigned long* address, 
    unsigned long skip, 
    bool next
);

bool readFO3ArrayProperty(
    FO3SAVE* save, 
    void* property, 
    unsigned long* address, 
    unsigned long skip, 
    int length, 
    bool next
);



bool writeFO3Property(
    FO3SAVE* save,
    void* property,
    void* value,
    unsigned long* address,
    unsigned long skip,
    unsigned size,
    bool next
);

bool writeFO3StringProperty(
    FO3SAVE* save,
    void** property,
    void* value,
    unsigned long* address,
    unsigned long skip,
    bool next
);

bool writeFO3ArrayProperty(
    FO3SAVE* save,
    void* property,
    void* value,
    unsigned long* address,
    unsigned long skip,
    int length,
    bool next
);



void printFO3Save(
    FO3SAVE* save
);

#endif  // ! FO3_H
