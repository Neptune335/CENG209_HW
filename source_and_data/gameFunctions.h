#ifndef GAMEFUNCTIONS_H
#define GAMEFUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "character.h"
#include "room.h"
#include "creature.h"
#include "item.h"

void look(Character *character);
void move(Character *character, char directionInput[]);
void attack(Character *character, char creatureCode[]);
void pickup(Character *character, char itemCode[]);
void deleteItem(Character *character, char slot[]);//used in characterInfo, not for user.
void inventory(Character *character);
void characterInfo(Character *character);
void gameCommands();

#endif