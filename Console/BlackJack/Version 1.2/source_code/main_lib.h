#include "globals.h"
#include "classes.h"
#include "file_handling.h"
#include "game_play.h"
#include "profile_settings.h"
#include "help_menu.h"
#include "credits_display.h"



/*#########################################*/
// Resource Functions


void startup_display() {
    clear();
    type("Welcome to Console Casino!", "", 50, 1000);
    backspace(15);
    type("BLACKJACK!", "", 50, 2000);
    print("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b", "");
    type("                    ~ Black Jack ~");
    
    const char *screen =
    "\n  -------------------------------------------------\n"
    "       /\\     [A] Play      [B] Help        /\\   \n"
    "      /  \\    [C] Settings  [D] Credits    /  \\  \n"
    "      \\  /                                 \\  /  \n"
    "       \\/     [X] Exit                      \\/   \n";
    type(screen, "/n", 20);
}




/*#########################################*/
// Main Game Functions

void get_deck(std::vector<std::string> &deck, std::map<std::string, int> &points) {
    
    std::string ranks[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    std::string suits[4] = {"Spades", "Clubs", "Hearts", "Diamonds"};
    std::vector<std::string> cards;

    for (int i=0; i < 13; i++) {
        for (int j=0; j < 4; j++) {
           cards.push_back(ranks[i] + " of " + suits[j]); 
        }
    }

    for (int i=0; i < cards.size(); i++) {
        if (cards[i][0] == '2') {
            points[cards[i]] = 2;
        
        } else {
            points[cards[i]] = 0;

        }
    }


}



// Main Menu and Redirect

std::string main_menu() {
    clear();

    const char *screen = 
    "                    ~ Black Jack ~                 \n"
    "                                                   \n"
    "  -------------------------------------------------\n"
    "       /\\     [A] Play      [B] Help        /\\   \n"
    "      /  \\    [C] Settings  [D] Credits    /  \\  \n"
    "      \\  /                                 \\  /  \n"
    "       \\/     [X] Exit                      \\/   \n";

    print(screen);

    std::string choice = to_lower(input("              >> "));
    

    while ((choice != "a") && (choice != "b") && (choice != "c") && (choice != "d") && (choice != "x")) {
        clear();
        print(screen);
        print("              \"" + choice + "\" is an invalid answer...\n              Please enter the letter\n              corresponding to your choice\n");
        choice = to_lower(input("              >> "));
    }
    
    if (choice == "a") {
        return "play";
    } else if (choice == "b") {
        return "help";
    } else if (choice == "c") {
        return "settings";
    } else if (choice == "d") {
        return "credits";
    } else {
        return "exit";
    }
}



void redirect(std::string choice) {
    if (choice == "play") {
        start_game();
    } else if (choice == "help") {
        help();
    } else if (choice == "settings") {
        settings();
    } else {
        credits();
    }
}