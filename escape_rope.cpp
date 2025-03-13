/*
* Author: Lauren Bell
* Description: 
*/

#include "escape_rope.hpp"
#include <iostream>

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
void Escape_Rope::percept() const {
    std::cout << "";
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
bool Escape_Rope::encounter(bool& has_gold, bool& is_alive, bool& is_confused, 
                            int& num_arrows, bool& game_won) {
    std::cout << "You spy the rope of escape from across the way!" << std::endl;
    std::cout << "You reach for your satchel and feel for the Wumpus' gold..." << std::endl;

    if (has_gold) {
        std::cout << "Your fingers brush the cold metal as you graspeth the rope." << std::endl;
        std::cout << "The adventurer climbs up and out of the cave, as if on angels wings." << std::endl;
        game_won = true;
    } else {
        std::cout << "There is no gold in thy satchel." << std::endl;
        std::cout << "The adventurer hath found the escape from this hellish cave, but they must first find the gold of the Wumpus!" << std::endl;
        game_won = false;
    }
    return false;
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
char Escape_Rope::get_symbol() const {
    return 'R';
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
Event* Escape_Rope::clone() const {
    return new Escape_Rope(*this);
}