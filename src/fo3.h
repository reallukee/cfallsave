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
#define FO3_H

#define SAVE_SIGNATURE "FO3SAVEGAME"
#define SAVE_SIGNATURE_LENGTH 11

typedef struct {
    FILE* saveFile;

    char saveSignature[12];
    unsigned snapshotWidth;
    unsigned snapshotHeight;
    unsigned saveNumber;
    char* characterName;
    unsigned characterLevel;
    char* characterTitle;
    char* characterLocation;
    char* characterPlaytime;

    unsigned long saveSignatureAddress;
    unsigned snapshotWidthAddress;
    unsigned snapshotHeightAddress;
    unsigned long saveNumberAddress;
    unsigned long characterNameAddress;
    unsigned long characterLevelAddress;
    unsigned long characterTitleAddress;
    unsigned long characterLocationAddress;
    unsigned long characterPlaytimeAddress;
} FO3SAVE;

FO3SAVE* readFO3Save(char* saveName);
bool writeFO3Save(FO3SAVE* save, char* saveName);
bool closeFO3Save(FO3SAVE* save);
void printFO3Save(FO3SAVE* save);

bool readFO3Property(FO3SAVE* save, void* property, unsigned long* address, unsigned long skip, unsigned size, bool next);
bool readFO3StringProperty(FO3SAVE* save, void** property, unsigned long* address, unsigned long skip, bool next);
bool readFO3ArrayProperty(FO3SAVE* save, void* property, unsigned long* address, unsigned long skip, int length, bool next);

bool writeFO3Property(FO3SAVE* save, void* property, void* value, unsigned long* address, unsigned long skip, unsigned size, bool next);
bool writeFO3StringProperty(FO3SAVE* save, void** property, void* value, unsigned long* address, unsigned long skip, bool next);
bool writeFO3ArrayProperty(FO3SAVE* save, void* property, void* value, unsigned long* address, unsigned long skip, int length, bool next);

#endif  // ! FO3_H
