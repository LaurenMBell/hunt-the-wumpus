/*
* Author: Lauren Bell
* Description: 
*/

#ifndef WUMPUS_HPP
#define WUMPUS_HPP


#include "event.hpp"

class Wumpus : public Event {
    public: 
        void percept() const override;
        bool encounter(bool& has_gold, bool& is_alive, bool& is_confused, 
                        int& num_arrows, bool& game_won) override;
        void arrow_hit(bool& wumpus_killed, bool& game_won) override;
        char get_symbol() const override;
        Event* clone() const override;
};

#endif
