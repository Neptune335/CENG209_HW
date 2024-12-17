#include "creature.h"

void generateCreatures(Creature creatures[])
{
    int currentLine = 0;
    int currentCreature = 0;
    char line[100];

    FILE *CreaturesDoc = fopen("data/Creatures.csv", "r");
    if (CreaturesDoc == NULL)
    {
        perror("Creatures.csv could not be opened");
    }

    while (fgets(line, sizeof(line), CreaturesDoc))
    {
        if (currentLine > 0)
        {
            if (currentCreature > CREATURES_NUMBER)
            {
                printf("Warning: Creature capacity exceeded.");
                return;
            }
            creatures[currentCreature].roomNumber = atoi(strtok(line, "/"));
            strtok(NULL, "/");
            strcpy(creatures[currentCreature].name, strtok(NULL, "/"));
            strcpy(creatures[currentCreature].code, strtok(NULL, "/"));
            creatures[currentCreature].atk = atoi(strtok(NULL, "/"));
            creatures[currentCreature].hp = atoi(strtok(NULL, "/"));
            currentCreature++;
        }
        currentLine++;
    }
    fclose(CreaturesDoc);
}