#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "character.h"
#include "room.h"
#include "creature.h"
#include "item.h"
#include "gameFunctions.h"
#include "extraFunctions.h"

int main()
{
    Room rooms[ROOM_NUMBER];
    Creature creatures[CREATURES_NUMBER];
    Item items[ITEMS_NUMBER];
    Character character;
    Character *charPtr = &character;

    memset(rooms, 0, sizeof(rooms));
    memset(items, 0, sizeof(items));
    memset(creatures, 0, sizeof(creatures));

    generateCreatures(creatures);
    generateItems(items);
    makeRooms(rooms, items, creatures);
    setCharacter(charPtr, rooms);
    getCharacterName(charPtr);


    char input[52];
    char command[25];
    char info[25];
    
    
    characterInfo(charPtr);
    gameCommands();

    while (1)
    {
        memset(input, 0, sizeof(input));
        memset(command, 0, sizeof(command));
        memset(info, 0, sizeof(info));

        printf("\nEnter your command: ");

        if (fgets(input, sizeof(input), stdin) != NULL)
        {
            size_t len = strlen(input);
            if (len > 0 && input[len - 1] == '\n')
            {
                input[len - 1] = '\0';
            }
            else
            {
                clear_stdin();
            }

            strncat(input, " ", sizeof(input) - strlen(input) - 1);
        }
        else
        {
            printf("Input could not be read.\n");
        }

        
        if(strchr(input, '/') != NULL && input[0] != '/'){
            strcpy(command, strtok(input, "/"));
            strcpy(info, strtok(NULL, "/"));
        } else {
            printf("Invalid command!\n");
            continue;
        }

        /////
        if (strcmp(command, "charinfo") == 0)
        {
            characterInfo(charPtr);
            continue;
        } else if (strcmp(command, "look") == 0)
        {
            look(charPtr);
            continue;
        } else if (strcmp(command, "move") == 0)
        {
            move(charPtr, info);
            continue;
        } else if (strcmp(command, "pickup") == 0)
        {
            pickup(charPtr, info);
            continue;
        } else if (strcmp(command, "delete") == 0)
        {
            deleteItem(charPtr, info);
            continue;
        } else if (strcmp(command, "attack") == 0)
        {
            attack(charPtr, info);
            continue;
        } if (strcmp(command, "comms") == 0)
        {
            gameCommands();
            continue;
        } else if (strcmp(command, "exit") == 0)
        {
            break;
        } else 
        {
            printf("Invalid command!\n");
        }
    }

    return 0;
}