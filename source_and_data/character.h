#ifndef CHARACTER_H
#define CHARACTER_H

#include "room.h"
#include "item.h"
#include "creature.h"
#include "extraFunctions.h"

#define INVENTORY_CAPACITY 10
#define NAME_LENGTH 30
#define CODE_LENGTH 5
#define DESCRIPTION_LENGTH 300

typedef struct Character
{
    char name[NAME_LENGTH];
    int atk;
    int atkBonus;
    int hp;
    int hpBonus;
    Room *location;
    Item *inventory[INVENTORY_CAPACITY];
} Character;

void getCharacterName(Character *character);
void setCharacter(Character *character, Room rooms[]);
#endif