/*
* Author: Lauren Bell
* Description: 
*/

#include "bat_swarm.hpp"
#include <iostream>

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
void Bat_Swarm::percept() const {
    std::cout << "A wicked screeching assaults thy ears..." << std::endl;
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
bool Bat_Swarm::encounter(bool& has_gold, bool& is_alive, bool& is_confused,
                            int& num_arrows, bool& game_won) {
    std::cout << "A swarm of bats hath descended on thy weary frame!" << std::endl;
    std::cout << "You findeth yourself confused and blundered..." <<std::endl;
    is_confused = true;
    return true;
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
char Bat_Swarm::get_symbol() const {
    return 'B';
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
Event* Bat_Swarm::clone() const {
    return new Bat_Swarm(*this);
}