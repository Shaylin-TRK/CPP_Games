void help() {
    while (true) {
        const char* main_screen = 
        "                     ~~ Help ~~                   \n"
        "  ------------------------------------------------\n"
        "                                                  \n"
        "      [A] Game Play           [B] Options Menu    \n"
        "      [X] Exit                                    \n"
        "                                                  \n";
        
        clear();
        print(main_screen);

        std::string choice = to_lower(input("      >>> "));
        while ((choice != "a") && (choice != "b") && (choice != "x")) {
            clear();
            print(main_screen);
            print("      \"" + choice + "\" is not a valid option...\n      Please enter the letter corresonding to your choice.");
            std::string choice = to_lower(input("      >>> "));
        }

        if (choice == "a") {

            const char* screen1 = 
            "                  ~~ Game  Play ~~                \n"
            "  ------------------------------------------------\n"
            "                                                  \n"
            "        The object of blackjack is to collect       \n"
            "      cards, each having a point value. You       \n"
            "      must get your points as close to 21 as      \n"
            "      possible without exceeding that number.     \n"
            "        ";

        } else if (choice == "b") {



        } else if (choice == "x") {
            break;
        }
    }
        
        

}