/*
* Author: Lauren Bell
* Description: 
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include "game.hpp"

/*
 * Function: get_width
 * Description: Prompts the user for the game board width (# of columns)
 * Returns (int): Valid width supplied by user
 */
int get_width() {
	int width;
	bool first = true;
	do {
		if (!first) {
			std::cout << std::endl << "Invalid width!" << std::endl <<
				std::endl;
		}
		first = false;
		std::cout << "Enter the game board width between 4 and 30: ";
		std::cin >> width;
	} while(width < 4 || width > 30);
	return width;
}

/*
 * Function: get_height
 * Description: Prompts the user for the game board height (# of columns)
 * Returns (int): Valid height supplied by user
 */
int get_height() {
	int height;
	bool first = true;
	do {
		if (!first) {
			std::cout << std::endl << "Invalid height!" << std::endl <<
				std::endl;
		}
		first = false;
		std::cout << "Enter the game board height between 4 and 30: ";
		std::cin >> height;
	} while(height < 4 || height > 30);
	return height;
}

/*
 * Function: get_debug
 * Description: Prompts the user whether they want to play in debug mode
 * Returns (bool): True if the user wants to play in debug mode. False
 * 		otherwise.
 */
bool get_debug() {
	int debug_input;
	bool first = true;
	do {
		if (!first) {
			std::cout << std::endl << "Invalid input!" << std::endl <<
				std::endl;
		}
		first = false;
		std::cout << "Would you like to play in debug mode? (1-yes, 0-no): ";
		std::cin >> debug_input;
	} while(debug_input != 0 && debug_input != 1);
	return debug_input == 1;
}

void exposition() {
	int x;
	std::cout << "To watch intro, press 1. To skip, press 2.";
	std::cin >> x;
	if (x == 1) {
		std::cout << "\n\n" << std::endl;
		std::cout << "In a faraway kingdom, there lives a monstrous creature." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::cout << "The Wumpus was seen by few and feared by all..." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::cout << "and survived by none.\n" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::cout << R"(                       +++++++++++++++++++                       
                     +++++++++++++++++++++++                     
                   +++++++++++++++++++++++++++                   
                ++++++++++++++++++++++++++++++++                 
              +++++++++++++++++++++++++++++++++++++              
            +++++++++++++++++++++++++++++++++++++++++            
          +++++++++++++++++++++++++++++++++++++++++++++          
        +++++++++++++++++++++++++++++++++++++++++++++++++        
     +++++++++++++++++++++    +++++    ++++++++++++++++++++      
   ++++++++++++++++++++++      +++      ++++++++++++++++++++++   
 ++++++++++++++++++++++++ ++++ +++ ++++ ++++++++++++++++++++++++ 
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
+++++++++++++++  +++++++++++++++++++++++++++++++  +++++++++++++++
++++++++++++     +++++++++++++++++++++++++++++++    +++++++++++++
++++++++++       +++++++++++++++++++++++++++++++       ++++++++++
+++++++++        +++++++ +++ +++ +++ ++  +++++++       ++++++++++
+++++++++        ++++    +++ +++ +++ ++     ++++       ++++++++++
+++++++++        ++                           ++       ++++++++++
+++++++++        ++                           ++       ++++++++++
+++++++++        ++++    +++ +++ +++ ++     ++++       ++++++++++
+++++++++        ++++++  +++ +++ +++ ++   ++++++       ++++++++++
+++++++++        +++++++++++++++++++++++++++++++       ++++++++++
  +++++++++      +++++++++++++++++++++++++++++++      +++++++++  
    +++++++++       +++++++++++++++++++++++++       +++++++++    
      ++++++++++      +++++++++++++++++++++      ++++++++++      
       +++++++++++      +++++++++++++++++      +++++++++++       
     +++++++++++++++                         +++++++++++++++     
   +++++++++  ++++++++                     ++++++++  +++++++++   
 +++++++++      +++++++++               +++++++++      +++++++++  )" << "\n" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::cout << "Will thou be the one to slay this wretched beast or steal its precious gold?" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::cout << "The adventurer descends into the cave fabled to hold the monster..." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	}
}

int main()
{
	// Set the random seed
	srand(time(nullptr));
	
	// Ask user for width and height of game board
	int width = get_width();
	int height = get_height();

	// Ask user whether they want debug mode
	bool debug = get_debug();

	exposition();

	// Construct game object
	game g(width, height, debug);

	//Play game
	g.play_game();

	return 0;
}
