#include <iostream>

#include "game.hpp"
#include "gold.hpp"
#include "bat_swarm.hpp"
#include "bottomless_pit.hpp"
#include "wumpus.hpp"
#include "escape_rope.hpp"
#include "arrow.hpp"

// game implementation

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
game::game(int width, int height, bool debug) :
		width(width),
		height(height),
		debug(debug) {

	game_board.resize(height, std::vector<Room>(width));
	srand(time(0));

	place('*');
	place('W');
	place('G');
	place('B');
	place('B');
	place('P');
	place('P');
	place('E');
	place('A');
	place('A');
	
	is_confused = false;
	is_alive = true;
	num_arrows = 0;
	has_gold = false;
	wumpus_alive = true;
	game_won = false;

}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
void game::place(char to_place) {
	int r, c;
	do {
		r = rand() % height;
		c = rand() % width;
	} while (game_board[r][c].get_event() != nullptr);

	Event* new_event = nullptr;
	switch (to_place) {
		case '*': player_row = r; player_col = c; return;
		case 'W': new_event = new Wumpus(); wumpus_row = r; wumpus_col = c; break;
		case 'G': new_event = new Gold(); break;
		case 'B': new_event = new Bat_Swarm(); break;
		case 'P': new_event = new Bottomless_Pit(); break;
		case 'E': 
			new_event = new Escape_Rope();
			escape_row = r;
			escape_col = c;
			break;
		case 'A': new_event = new Arrow(); break;
	}
	game_board[r][c].set_event(new_event);
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
void game::display_game() const{

	std::string row_border = "+";
	for (int i = 0; i < this->width; ++i) {
		row_border += "--+";
	}

	std::cout << "" << std::endl;

	std::cout << row_border << std::endl;
	for (int i = 0; i < this->height; ++i) { 
		std::cout << "|";
		for (int j = 0; j < this->width; ++j) {
			
			if (i == player_row && j == player_col) {
				std::cout << "*";
			} else {
				std::cout << " ";
			}
			
			if (debug && game_board[i][j].get_event() != nullptr) {
				std::cout << game_board[i][j].get_event()->get_symbol();
			} else {
				std::cout << " ";
			}


			std::cout << "|";
		}
		std::cout << std::endl;
		std::cout << row_border << std::endl;
	}
	std::cout << std::endl << std::endl;
	std::cout << "Arrows in quiver: " << this->num_arrows << std::endl;
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
void game::display_percepts() {
	const int dx[]  = {0,1,0,-1};
	const int dy[]  = {-1,0,1,0};

	for (int i = 0; i <4; i++) {
		int new_row = player_row + dy[i];
		int new_col = player_col + dx[i];

		if (new_row >= 0 && new_row < height && new_col >= 0 && new_col < width) {
			if (game_board[new_row][new_col].get_event() != nullptr) {
				game_board[new_row][new_col].trigger_percept();
			}
		}
	}
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
bool game::check_win() const{
	return is_alive && ((has_gold && player_row == escape_row && player_col == escape_col) || game_won || !wumpus_alive);
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
bool game::check_lose() const {
    return !is_alive || (player_row == wumpus_row && player_col == wumpus_col);
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
bool game::is_direction(char c) {
	return (c == 'w' || c == 'a' || c == 's' || c == 'd');
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
void game::encounter_event() {
	int x = player_row;
    int y = player_col;

    if (game_board[x][y].get_event() != nullptr) { 
        bool keep_event = game_board[x][y].enter_room(has_gold, is_alive, is_confused, num_arrows, game_won);

        if (!keep_event) { 
            game_board[x][y].set_event(nullptr);  
        }
    }
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
char game::to_lower(char direction) {
	if (direction >= 'A' && direction <= 'Z') {
		return direction + ('a' - 'A');
	}
	return direction;
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
bool game::can_move_in_direction(char direction) {
	switch(direction) {
		case 'w': return player_row > 0;
		case 'a': return player_col > 0;
		case 's': return player_row < height -1;
		case 'd': return player_col < width - 1;
		default: return false;
	}
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
bool game::is_valid_action(char action) {
	if (this->is_direction(action)) {
		char direction = action;
		return this->can_move_in_direction(direction);
	} else if (action == 'f') {
		return this->num_arrows > 0;
	}
	return false;
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
void game::print_action_error(char action) {
	if (this->is_direction(action)) {
		std::cout << "Thy desired direction is invalid..." << std::endl <<
			std::endl;
	} else if (action == 'f') {
		std::cout << "The adveturer is out of arrows!" << std::endl << std::endl;
	} else {
		std::cout << std::endl << "Hark! Thy input is invalid!" << std::endl
			<< std::endl;
	}
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
char game::get_player_action() {
	char action;
	bool first = true;
	do {
		if (!first) {
			char previous_action = action;
			this->print_action_error(previous_action);
		}
		first = false;

		std::cout << std::endl << std::endl << "What would thou liketh to do?" <<
			std::endl << std::endl;
		std::cout << "w: moveth up" << std::endl;
		std::cout << "a: moveth left" << std::endl;
		std::cout << "s: moveth down" << std::endl;
		std::cout << "d: moveth right" << std::endl;
		std::cout << "f: fireth an arrow" << std::endl;

		std::cin >> action;
		action = this->to_lower(action);
	} while (!this->is_valid_action(action));

	return action;
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
char game::get_arrow_fire_direction() {
	char direction;
	bool first = true;
	do {
		if (!first) {
			std::cout << std::endl << "Thy input is invalid!" <<
				std::endl << std::endl;
		}
		first = false;

		std::cout << std::endl << std::endl <<
			"Prithee, what direction would the adventurer like to fireth the arrow?" << std::endl <<
			std::endl;
		std::cout << "w: up" << std::endl;
		std::cout << "a: left" << std::endl;
		std::cout << "s: down" << std::endl;
		std::cout << "d: right" << std::endl;

		std::cin >> direction;
		direction = this->to_lower(direction);
	} while (!this->is_direction(direction));

	return direction;
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
void game::move(char direction) {
	if (is_confused) {
        char directions[4] = {'w', 'a', 's', 'd'};
        direction = directions[rand() % 4];
        is_confused = false;
		std::cout << "You find thyself unable to see straight. \n Dizzly, you stumble forward in a direction you know not..." << std::endl;
    }
	if (direction == 'w') {
		if (player_row > 0) { 
			player_row--;
		};
	} else if (direction == 'a') {
		if (player_col > 0) {
			player_col--;
		}
	} else if (direction == 's') {
		if (player_row < height - 1) {
			player_row++;
		}
	} else {
		if (player_col < width - 1) {
			player_col++;
		}
	}

}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
void game::fire_arrow(char direction) {
    bool wumpus_killed = false;

    int current_row = player_row;
    int current_col = player_col;

    for (int step = 1; step <= 3; step++) {
        if (direction == 'w') current_row--;
        else if (direction == 'a') current_col--;  
        else if (direction == 's') current_row++;  
        else if (direction == 'd') current_col++;  

        if (current_row < 0 || current_row >= height || current_col < 0 || current_col >= width) {
            break; 
        }

        if (current_row == wumpus_row && current_col == wumpus_col) {
            wumpus_killed = true;
            wumpus_alive = false;
            std::cout << "The arrow pierced the darkness and struck the Wumpus!" << std::endl;
            game_won = true;
			break;  
        }
    }

    this->num_arrows--;

    if (!wumpus_killed) {
        std::cout << "The adventurer's arrow was fired with strength imbued, but it did not meet an enemy..." << std::endl;
    }
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
void game::play_game(){
    while (!this->check_win() && !this->check_lose()) { 
        this->display_game();

        if (!this->check_win()) {
			this->display_percepts();
		}

        char action = this->get_player_action();

        if (this->is_direction(action)) {
            char direction = action;
            this->move(direction);
        } else {
            char direction = this->get_arrow_fire_direction();
            this->fire_arrow(direction);
        }

        this->encounter_event();

		if (!this->is_alive) {
			std::cout << "Alas, you hath perished. Thy adventure hath come to a bitter end." << std::endl;
			break; 
		}

		if ((this->check_win() && is_alive == true) || wumpus_alive == false) {
			std::cout << "Huzzah! Thou hath won!" << std::endl;
			break;
		}
	}
}