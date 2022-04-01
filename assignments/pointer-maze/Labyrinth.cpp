#include "Labyrinth.h"

bool isPathToFreedom(MazeCell* start, const std::string& moves) {
  //given a string, determine if that string will get u to freedom
  //string contains N, S, W, F
  //all paths should be legal -> check for out of bounds?
  //all three items must be picked up
  //startLocation is not a nullpointer
  //the string only contains N, S, E, W


  //create counter to check if Spellbook, wand, and potion is picked up
  int numSpellbook = 0;
  int numPotion = 0;
  int numWand = 0;
  //Item itemFound;
  //create a loop that will go throgh the given sequence
  for (int i = 0; i < moves.length(); i++){
    //it is assumed that starting cell is not nbull
    if (start == nullptr)
      return false;
    char direction = moves[i];
    if (direction == 'N')
      start = start->north;
    else if (direction == 'S')
	start = start->south;
    else if (direction == 'W')
	start = start->west;
    else //if E
      start = start->east;

    //after checking the direction, determine if there is an item
    //if an item is found, the counter should inrease
    //if (start != nullprt){
      Item itemFound = start->whatsHere;
      if (itemFound == Item::SPELLBOOK){
	numSpellbook++;
      }
      else if (itemFound == Item::POTION)
	numPotion++;
      else if (itemFound == Item::WAND)
	numWand++;
      //}
  }

  if (numSpellbook > 0 && numPotion > 0 && numWand > 0)
    return true;
  else
    return false;
  //once we have found the items, and the loops ends, we are done
}
