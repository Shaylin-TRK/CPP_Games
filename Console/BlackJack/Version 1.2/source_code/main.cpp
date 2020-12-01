#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>

#include "./resources/Sierra.h"
#include "main_lib.h"

/*###########################################################*/
// Main Game Function


int main() {
    
    bool running = true;
    clear();

    // Build Deck
    
    std::vector<std::string> deck;
    std::map<std::string, int> points;

    get_deck(deck, points);
    
    for (int i=0; i < deck.size(); i++) {
        print(points[deck[i]]);
    }
    
    
    // Opening Intro


//*
    login();

    startup_display();

    while (running) {

        std::string user_choice = main_menu();
        if (user_choice == "exit") {
            running = false;
            break;
        } else {
            redirect(user_choice);
        }

    }

    clear();
    print("              ", "");
    type("Exiting Game  ", "");
    game_save();
    spinner(4);
    clear();


//*/    
}