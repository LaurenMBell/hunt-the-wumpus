/*
* Author: Lauren Bell
* Description: 
*/

#include "event.hpp"
#include <iostream>

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
void Event::percept() const{}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
bool Event::encounter(bool& has_gold, bool& is_alive, bool& is_confused, 
                        int& num_arrows, bool& game_won) {
        return true;
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
void Event::arrow_hit(bool& wumpus_killed, bool& game_won) {
    wumpus_killed = false;
    game_won = true;
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
char Event::get_symbol() const {
    return 'E';
}