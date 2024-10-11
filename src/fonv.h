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

#ifndef FONV_H   // FONV_H
#define FONV_H

#define SAVE_SIGNATURE "FONVSAVEGAME"
#define SAVE_SIGNATURE_LENGTH 11

typedef struct {
    FILE* saveFile;

    char saveSignature[12];

    unsigned long saveSignatureAddress;
} FONVSAVE;

FONVSAVE* readF3Save(char* saveName);
bool writeFONVSave(FONVSAVE* save, char* saveName);
bool closeFONVSave(FONVSAVE* save);
void printFONVSave(FONVSAVE* save);

bool readFONVProperty(FONVSAVE* save, void* property, unsigned long* address, unsigned long skip, unsigned size, bool next);
bool readFONVStringProperty(FONVSAVE* save, void** property, unsigned long* address, unsigned long skip, bool next);
bool readFONVArrayProperty(FONVSAVE* save, void* property, unsigned long* address, unsigned long skip, int length, bool next);

bool writeFONVProperty(FONVSAVE* save, void* property, void* value, unsigned long* address, unsigned long skip, unsigned size, bool next);
bool writeFONVStringProperty(FONVSAVE* save, void** property, void* value, unsigned long* address, unsigned long skip, bool next);
bool writeFONVArrayProperty(FONVSAVE* save, void* property, void* value, unsigned long* address, unsigned long skip, int length, bool next);

#endif  // ! FONV_H
