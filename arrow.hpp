/*
* Author: Lauren Bell
* Description: 
*/

#ifndef ARROW_HPP
#define ARROW_HPP

#include "event.hpp"

class Arrow : public Event {
    public: 
        void percept() const override;
        bool encounter(bool& has_gold, bool& is_alive, bool& is_confused, 
                        int& num_arrows, bool& game_won) override;
        char get_symbol() const override;
        Event* clone() const override;
};

#endif
