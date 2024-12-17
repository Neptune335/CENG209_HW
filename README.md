# CENG209 - FALL HOMEWORK: Command-Line-Based Adventure Game
*Author:* Medine Merve MARAL

## Description:
This application is a simple text-based game that runs on the terminal.

## About Game:
In this game, you find yourself in an abandoned laboratory. While you search for a way out of the laboratory, you can collect items and fight creatures. The end of your adventure may be unexpected.

**Character**: Your character. When you start the game you give a name to the character. Character can move between rooms, collect items and fight creatures.

**Rooms**: There are 7 rooms in this game. You can find room connections in the room descriptions.
Character can go in four directions, if there is a connection.

**Directions**:
-up: You pass through the door ahead.
-down: You pass through the door behind you.
-right: You go through the door on your right.
-left: You go through the door on your left.

**Items**: They can grant HP and ATK bonuses to the character when they picked up by character. Some may have surprising behavior.

**Creatures**: You can start a fight by attacking them. If you defeat it, the creature disappears and your HP is restored. If you lose, the game is over.

**Commands**:
-*comms/*: shows game commands.
-*charinfo/*: shows character's name, ATK, bonus ATK, HP, bonus HP and inventory. 
-*look/*: shows room information: descriptions, items and creatures in the room.
-*move/<direction>*: character go to the room in given direction.
-*pickup/<item code>*: add the item with the given code to character inventory.
-*delete/<slot number>*: deletes the item at the given character inventory slot.
-*attack/<creature code>*: start a fight with the creature with given code.
-*exit/*: exit the program.


## ABOUT SOURCE CODE
**data(folder):**
-*Creatures.csv*: Keeps the number and name of the room the creature is in, the creature's name, its code for commands, its ATK and HP.
-*Items.csv*: Keeps the number and name of the room the item is in, the item's name, its code for commands, its ATK and HP bonuses.
-*RoomsAndDescriptions.csv*: Keeps the number, name and description of the room.
-*RoomsConnection*: Keeps the connection of rooms by numbers and direction.-1 means there is no connection in that direction.
-*DefaultCharacter*: keeps default character name, first location, ATK, bonus ATK, HP and bonus HP. 

**Source code:**
*character.c/character.h*:
    >>Struct:
    -Character: Keeps name, ATK, bonus ATK, HP, bonus HP, location and inventory.
    >>Function:
    -getCharacterName: Gets character name from user.
    -setCharacter: It is used when the game is started and sets given character's information.

*room.c/room.h*
>>Struct:
    -Room: Keeps rooms each direction of room, room number, name, description, items and creatures.
>>Function:
    -addRoomInfo: Writes room info to the given room array.
    -addRoomItems: Places items in the given room.
    -addRoomCreatures: Places creatures in the given room.
    -addRoomEntities: calls addRoomItems and addRoomCreatures for given room, item and creature arrays.
    -connectRooms: connects the rooms in the given array according to the data.
    makeRooms: calls aaddRoomInfo, addRoomEntities and connectRooms for given room, item and creature arrays.

*direction.h*
>>struct:
    -Direction: up, down, right, left

*creature.c/creature.h*:
>>Struct:
    -Creature: Keeps room number, name, code, ATK and HP.
>>Function:
    -generateCreatures: Writes creature information to the given creature array.

*item.c/item.h*
>>Struct:
    -Item: Keeps room number, name, code, ATK and HP.
 >>Function:
    -generateItems: Writes items information to the given item array.

*gameFunctions.c/gameFunctions.h*
>>Function:
    -look: Prints the information of the room where the character is located.
    -move: Moves the character into the room in the given direction.
    -attack: Character makes a fight with the creature with the given code.
    -pickup: Add the item with the given code to the character's inventory.
    -deleteItem: Deletes the item in the given character inventory slot.
    -inventory: Prints character inventory.
    -characterInfo: Prints character's information and inventory.
    -gameCommands: Prints active game commands.

*extraFunctions.c/extraFunctions.h*
>>Function:
    -clear_stdin: clears stdin to prevent input errors.

