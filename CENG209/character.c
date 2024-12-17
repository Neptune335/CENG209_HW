#include "character.h"

void getCharacterName(Character *character)
{
    char input[NAME_LENGTH];
    printf("\nEnter your character's name: ");

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
    }
    else
    {
        printf("Input could not be read");
    }

    strcpy(character->name, input);
}

void setCharacter(Character *character, Room rooms[])
{
    char line[NAME_LENGTH];
    int currentLine = 0;
    char defaultName[30];
    FILE *defaultCharDoc = fopen("data/DefaultCharacter.csv", "r");
    while (fgets(line, sizeof(line), defaultCharDoc))
    {
        if (currentLine > 1)
        {
            strcpy(defaultName, strtok(line, "/"));
            if (character->name == NULL)
            {
                strcpy(character->name, defaultName);
            }
            character->location = &rooms[atoi(strtok(NULL, "/"))]; // edit invalid room number must be checked.
            character->atk = atoi(strtok(NULL, "/"));
            character->atkBonus = atoi(strtok(NULL, "/"));
            character->hp = atoi(strtok(NULL, "/"));
            character->hpBonus = atoi(strtok(NULL, "/"));
        }
        currentLine++;
    }

    for (int i = 0; i < INVENTORY_CAPACITY; i++)
    {
        character->inventory[i] = NULL;
    }

    fclose(defaultCharDoc);
}