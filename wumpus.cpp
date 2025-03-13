/*
* Author: Lauren Bell
* Description: 
*/

#include "wumpus.hpp"
#include <iostream>

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
void Wumpus::percept() const {
    std::cout << "The tender hairs on the back of thy neck raise... something is deeply amiss." << std::endl;
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
bool Wumpus::encounter(bool& has_gold, bool& is_alive, bool& is_confused,
                        int& num_arrows, bool& game_won) {
    std::cout << "You fall to thy knees at the very sight of a tremendous beast!" <<std::endl;
    std::cout << "The adventurer has encountered the Wumpus. You have woken it from its slumber..." << std::endl;
    std::cout << "The beast picks its teeth with your bones." << std::endl;
    
    is_alive = false;
    game_won = false;
    return true;
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
void Wumpus::arrow_hit(bool& wumpus_killed, bool& game_won) {
    std::cout << "You hear a howl that could shake the heavens above." << std::endl;
    std::cout << "The Wumpus hath been slain at the adventurers hand!" << std::endl;

    wumpus_killed = true;
    game_won = true;
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
char Wumpus::get_symbol() const {
    return 'W';
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
Event* Wumpus::clone() const {
    return new Wumpus(*this);
}