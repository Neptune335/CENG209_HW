#include <stdio.h>
#include <stdlib.h>

#include "room.h"

void addRoomInfo(Room rooms[])
{
    int roomNumber = 0;
    int currentLine = 0;
    char line[500];

    FILE *roomsDoc = fopen("data/RoomsAndDescriptions.csv", "r");
    if (roomsDoc == NULL)
    {
        perror("RoomsAndDescriptions.csv could not be opened");
    }

    while (fgets(line, sizeof(line), roomsDoc))
    {
        if (currentLine > 0)
        {
            roomNumber = atoi(strtok(line, "/"));
            rooms[roomNumber].number = roomNumber;
            strcpy(rooms[roomNumber].name, strtok(NULL, "/"));
            strcpy(rooms[roomNumber].description, strtok(NULL, "/"));
            roomNumber++;
        }

        currentLine++;
    }
    fclose(roomsDoc);
}

void addRoomItems(Room *room, Item items[])
{
    int roomItemNumber = 0;
    for (int i = 0; i < ITEMS_NUMBER; i++)
    {
        if (items[i].roomNumber == room->number)
        {
            if (roomItemNumber >= ITEM_CAPACITY)
            {
                printf("Warning: Item capacity exceeded for Room %d\n", room->number);
                break;
            }
            room->items[roomItemNumber] = &items[i];
            roomItemNumber++;
        }
    }
}

void addRoomCreatures(Room *room, Creature creatures[])
{
    int roomCreatureNumber = 0;
    for (int i = 0; i < CREATURES_NUMBER; i++)
    {
        if (creatures[i].roomNumber == room->number)
        {
            if (roomCreatureNumber >= CREATURE_CAPACITY)
            {
                printf("Warning: Creature capacity exceeded for Room %d\n", room->number);
                break;
            }
            room->creatures[roomCreatureNumber] = &creatures[i];
            roomCreatureNumber++;
        }
    }
}

void addRoomEntities(Room rooms[], Item items[], Creature creatures[])
{
    for (int i = 0; i < ROOM_NUMBER; i++)
    {
        addRoomCreatures(&rooms[i], creatures);
        addRoomItems(&rooms[i], items);
    }
}

void connectRooms(Room rooms[])
{
    int currentLine = 0;
    char line[50];
    int roomNumber;
    int up, down, right, left;
    FILE *ConnectDoc = fopen("data/RoomsConnection.csv", "r");
    if (ConnectDoc == NULL)
    {
        perror("RoomsConnection.csv could not be opened");
    }

    while (fgets(line, sizeof(line), ConnectDoc))
    {
        if (currentLine > 0)
        {
            roomNumber = atoi(strtok(line, "/"));
            up = atoi(strtok(NULL, "/"));
            down = atoi(strtok(NULL, "/"));
            right = atoi(strtok(NULL, "/"));
            left = atoi(strtok(NULL, "/"));

            if (up > -1 && up < ROOM_NUMBER)
            {
                rooms[roomNumber].up = &rooms[up];
            }
            else
            {
                rooms[roomNumber].up = NULL;
            }

            if (down > -1 && down < ROOM_NUMBER)
            {
                rooms[roomNumber].down = &rooms[down];
            }
            else
            {
                rooms[roomNumber].down = NULL;
            }

            if (right > -1 && right < ROOM_NUMBER)
            {
                rooms[roomNumber].right = &rooms[right];
            }
            else
            {
                rooms[roomNumber].right = NULL;
            }

            if (left > -1 && left < ROOM_NUMBER)
            {
                rooms[roomNumber].left = &rooms[left];
            }
            else
            {
                rooms[roomNumber].left = NULL;
            }
        }
        currentLine++;
    }
}

void makeRooms(Room rooms[], Item items[], Creature creatures[])
{
    for (int i = 0; i < ROOM_NUMBER; i++)
    {
        for (int j = 0; j < ITEM_CAPACITY; j++)
        {
            rooms[i].items[j] = NULL;
            rooms[i].creatures[j] = NULL;
        }
    }
    addRoomInfo(rooms);
    addRoomEntities(rooms, items, creatures);
    connectRooms(rooms);
}