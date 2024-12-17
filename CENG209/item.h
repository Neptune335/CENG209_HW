#ifndef ITEM_H
#define ITEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ITEM_CAPACITY 5
#define CREATURE_CAPACITY 5
#define NAME_LENGTH 30
#define CODE_LENGTH 5
#define DESCRIPTION_LENGTH 300
#define ITEMS_NUMBER 11

typedef struct Item
{
    int roomNumber;
    char name[NAME_LENGTH];
    char code[CODE_LENGTH];
    int atk;
    int hp;
} Item;

void generateItems(Item items[]);

#endif