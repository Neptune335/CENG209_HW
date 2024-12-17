#include "item.h"

void generateItems(Item items[])
{
    int currentLine = 0;
    int currentItem = 0;
    char line[100];

    FILE *ItemsDoc = fopen("data/Items.csv", "r");
    if (ItemsDoc == NULL)
    {
        perror("Items.csv could not be opened");
    }

    while (fgets(line, sizeof(line), ItemsDoc))
    {
        if (currentLine > 0)
        {
            if (currentItem > ITEMS_NUMBER)
            {
                printf("Warning: Items capacity exceeded.");
                return;
            }

            items[currentItem].roomNumber = atoi(strtok(line, "/"));
            strtok(NULL, "/");
            strcpy(items[currentItem].name, strtok(NULL, "/"));
            strcpy(items[currentItem].code, strtok(NULL, "/"));
            items[currentItem].atk = atoi(strtok(NULL, "/"));
            items[currentItem].hp = atoi(strtok(NULL, "/"));
            currentItem++;
        }
        currentLine++;
    }
    fclose(ItemsDoc);
}