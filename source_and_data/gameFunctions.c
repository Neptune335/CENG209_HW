#include "gameFunctions.h"

void look(Character *character)
{
    if (character->location != NULL)
    {
        printf("\nYou are at: %s (Room %d)\n", character->location->name, character->location->number);
        printf("%s\n", character->location->description);
        printf("Items:\n");
        printf("Name/Code/ATK/HP\n");

        for (int i = 0; i < ITEM_CAPACITY; i++)
        {
            if (character->location->items[i] != NULL)
            {
                Item *item = character->location->items[i];
                printf("%s %s %d %d\n", item->name, item->code, item->atk, item->hp);
            }
        }

        printf("Creatures:\n");
        printf("Name/Code/ATK/HP\n");
        for (int j = 0; j < CREATURE_CAPACITY; j++)
        {
            if (character->location->creatures[j] != NULL)
            {
                Creature *creature = character->location->creatures[j];
                printf("%s %s %d %d\n", creature->name, creature->code, creature->atk, creature->hp);
            }
        }
        printf("\n");
    }
    else
    {
        printf("Character is nowhere...");
    }
}

void move(Character *character, char directionInput[])
{
    Direction direction;
    Room *room = character->location;
    if (strcmp(directionInput, "up ") == 0)
        direction = UP;
    else if (strcmp(directionInput, "down ") == 0)
        direction = DOWN;
    else if (strcmp(directionInput, "right ") == 0)
        direction = RIGHT;
    else if (strcmp(directionInput, "left ") == 0)
        direction = LEFT;
    else
    {
        printf("Invalid direction!\n");
        return;
    }

    switch (direction)
    {
    case UP:
        if (room->up == NULL)
        {
            printf("There is no room...\n");
        }
        else
        {
            character->location = character->location->up;
        }
        break;

    case DOWN:
        if (room->down == NULL)
        {
            printf("There is no room...\n");
        }
        else
        {
            character->location = character->location->down;
        }
        break;

    case RIGHT:
        if (room->right == NULL)
        {
            printf("There is no room...\n");
        }
        else
        {
            character->location = character->location->right;
        }
        break;

    case LEFT:
        if (room->left == NULL)
        {
            printf("There is no room...\n");
        }
        else
        {
            character->location = character->location->left;
        }
        break;
    }
    printf("You are at: %s (Room %d)\n", character->location->name, character->location->number);
}

void attack(Character *character, char creatureCode[])
{
    size_t codeLength = strlen(creatureCode);
    if (codeLength > 0) {
        creatureCode[codeLength - 1] = '\0';
    }

    Creature *thisCreature = NULL;
    Creature kill;
    int creatureIndex = -1;
    int characterHp = character->hp + character->hpBonus;
    int creatureHp;

    for (int i = 0; i < CREATURE_CAPACITY; i++)
    {
        if (character->location->creatures[i] != NULL)
        {
            if (strcmp(character->location->creatures[i]->code, creatureCode) == 0)
            {
                thisCreature = character->location->creatures[i];
                kill = *thisCreature;
                creatureIndex = i;
                creatureHp = thisCreature->hp;
                break;
            }
        }
        else
        {
            printf("No creature here.");
            return;
        }
    }

    if (thisCreature == NULL)
    {
        printf("No such creature here.");
        return;
    }

    while (creatureHp > 0 && characterHp > 0)
    {

        creatureHp -= (character->atk + character->atkBonus);
        printf("%s was attacked!\n", thisCreature->name);
        if (creatureHp <= 0)
        {
            printf("%s was defeated!\nCharacter HP restored!\n", thisCreature->name);
            character->location->creatures[creatureIndex] = NULL;
            return;
        }

        printf("%s HP left: %d\n", thisCreature->name, creatureHp);
        characterHp -= thisCreature->atk;
        if (characterHp <= 0)
        {
            printf("%s was defeated...\n", character->name);
            sleep(2);
            printf("Game Over.\n");
            sleep(1);
            exit(0);
            return;
        }
        else
        {
            printf("%s was attacked...\nHP left: %d\n", character->name, characterHp);
        }
    }
}

void pickup(Character *character, char itemCode[])
{
    size_t codeLength = strlen(itemCode);
    if (codeLength > 0) {
        itemCode[codeLength - 1] = '\0';
    }

    Item *thisItem = NULL;
    for (int i = 0; i < ITEM_CAPACITY; i++)
    {
        if (character->location->items[i] != NULL)
        {
            if (strcmp(character->location->items[i]->code, itemCode) == 0)
            {
                thisItem = character->location->items[i];
                character->location->items[i] = NULL;
                printf("%s picked.\n", thisItem->name);

                 
                 if(strcmp(thisItem->code, "sgo") == 0) {
                    printf("\n");
                    sleep(1);
                    printf("You suddenly feel dizzy and your heart starts racing...\n");
                    sleep(1);
                    printf("Flashing red lights, ear-splitting alarms...\n");
                    sleep(1);
                    printf("Everything slowly fades into darkness, and you lose consciousness...\n");
                    sleep(5);
                    printf("THE END.");
                    exit(0);
                    
                 }

                break;
            }
        }
    }

    if (thisItem == NULL)
    {
        printf("No such item in this room.\n");
        return;
    }
    else
    {
        for (int j = 0; j < INVENTORY_CAPACITY; j++)
        {
            if (character->inventory[j] == NULL)
            {
                character->inventory[j] = thisItem;
                character->atkBonus += thisItem->atk;
                character->hpBonus += thisItem->hp;
                return;
            }
        }

        printf("Inventory is full!\n");
    }
}

void deleteItem(Character *character, char slot[])
{
    char *left = NULL;
    int slotNumber = strtol(slot, &left, 10);

    if (slotNumber < 0 || slotNumber >= INVENTORY_CAPACITY)
    {
        printf("Invalid slot number!");
    }
    else
    {
        if (character->inventory[slotNumber] != NULL)
        {
            character->atkBonus -= character->inventory[slotNumber]->atk;
            character->hpBonus -= character->inventory[slotNumber]->hp;
            character->inventory[slotNumber] = NULL;
            printf("Item deleted! Slot[%d] is empty.\n", slotNumber);
        }
        else
        {
            printf("Slot is empty!\n");
        }
    }
}

void inventory(Character *character)
{
    printf("Inventory:\n");
    for (int i = 0; i < INVENTORY_CAPACITY; i++)
    {
        if (character->inventory[i] != NULL)
        {
            printf("Inventory Slot %d: %s(%s): ATK: %d, HP: %d\n", i, character->inventory[i]->name,
                   character->inventory[i]->code, character->inventory[i]->atk, character->inventory[i]->hp);
        }
        else
        {
            printf("Inventory Slot %d: empty\n", i);
        }
    }
}

void characterInfo(Character *character)
{
    if (character != NULL)
    {
        printf("\nName: %s\nATK: %d (%d(base) + %d(bonus))\nHP:: %d (%d(base) + %d(bonus))\n", character->name,
               (character->atk + character->atkBonus), character->atk, character->atkBonus, (character->hp + character->hpBonus),
               character->hp, character->hpBonus);
        inventory(character);
    }
}

void gameCommands() {
    printf("\nCOMMANDS:\n");
    printf("comms/: see game commands.\n");
    printf("charinfo/: see character's informations and inventory.\n");
    printf("look/: see the room description and items and creatures in the room you are in.\n");
    printf("move/<direction>: go to the room at the given direction.\n");
    printf("pickup/<item code>: add the item with the given code to the character inventory.\n");
    printf("delete/<slot number>: deletes the item at the given character inventory slot.\n");
    printf("attack/<creature code>: start a fight with the creature with the given code.\n");
    printf("exit/: exit the program. (Your changes will be lost.)\n");

}