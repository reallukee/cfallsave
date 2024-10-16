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

#ifndef FO4_H   // FO4_H
#define FO4_H   // FO4_H

#define SAVE_SIGNATURE "FO4_SAVEGAME"
#define SAVE_SIGNATURE_LENGTH 12

typedef struct {
    FILE* saveFile;

    char saveSignature[12];
    unsigned engineVersion;
    unsigned saveNumber;
    char* characterName;
    unsigned characterLevel;
    char* characterLocation;
    char* characterPlaytime;
    char* characterRace;

    unsigned short characterSex;
    float characterCurrentXp;
    float characterRequiredXp;

    unsigned snapshotWidth;
    unsigned snapshotHeight;
    unsigned long snapshotLength;
    unsigned char* snapshot;

    unsigned long saveSignatureAddress;
    unsigned long engineVersionAddress;
    unsigned long saveNumberAddress;

    unsigned long characterNameAddress;
    unsigned long characterLevelAddress;
    unsigned long characterLocationAddress;
    unsigned long characterPlaytimeAddress;
    unsigned long characterRaceAddress;
    unsigned long characterSexAddress;
    unsigned long characterCurrentXpAddress;
    unsigned long characterRequiredXpAddress;

    unsigned long snapshotWidthAddress;
    unsigned long snapshotHeightAddress;
    unsigned long snapshotAddress;
} FO4SAVE;

FO4SAVE* readFO4Save(
    char* saveName,
    bool readProperties
);

bool isFO4Save(
    char* saveName
);

bool readFO4Properties(
    FO4SAVE* save
);

bool writeFO4Save(
    FO4SAVE* save,
    char* saveName
);

bool closeFO4Save(
    FO4SAVE* save
);



unsigned long getNextFO4PropertyAddress(
    unsigned long address,
    unsigned long skip
);



bool readFO4Property(
    FO4SAVE* save,
    void* property,
    unsigned long* address,
    unsigned long skip,
    unsigned size,
    bool next
);

bool readFO4StringProperty(
    FO4SAVE* save,
    void** property,
    unsigned long* address,
    unsigned long skip,
    bool next
);

bool readFO4ArrayProperty(
    FO4SAVE* save,
    void* property,
    unsigned long* address,
    unsigned long skip,
    int length,
    bool next
);



bool writeFO4Property(
    FO4SAVE* save,
    void* property,
    void* value,
    unsigned long* address,
    unsigned long skip,
    unsigned size,
    bool next
);

bool writeFO4StringProperty(
    FO4SAVE* save,
    void** property,
    void* value,
    unsigned long* address,
    unsigned long skip,
    bool next
);

bool writeFO4ArrayProperty(
    FO4SAVE* save,
    void* property,
    void* value,
    unsigned long* address,
    unsigned long skip,
    int length,
    bool next
);



void printFO4Save(
    FO4SAVE* save
);

#endif  // ! FO4_H
