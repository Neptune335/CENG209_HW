#ifndef ROOM_H
#define ROOM_H

#include "item.h"
#include "creature.h"
#include "direction.h"

#define ROOM_NUMBER 8

#define ITEM_CAPACITY 5
#define CREATURE_CAPACITY 5

#define NAME_LENGTH 30
#define CODE_LENGTH 5
#define DESCRIPTION_LENGTH 300

#define ITEMS_NUMBER 11
#define CREATURES_NUMBER 18

typedef struct Room Room;
struct Room
{
    Room *up;
    Room *down;
    Room *right;
    Room *left;
    int number;
    char name[NAME_LENGTH];
    char description[DESCRIPTION_LENGTH];
    Item *items[ITEM_CAPACITY];
    Creature *creatures[ITEM_CAPACITY];
};

void addRoomInfo(Room rooms[]);
void addRoomItems(Room *room, Item items[]);
void addRoomCreatures(Room *room, Creature creatures[]);
void addRoomEntities(Room rooms[], Item items[], Creature creatures[]);
void connectRooms(Room rooms[]);
void makeRooms(Room rooms[], Item items[], Creature creatures[]);



#endif