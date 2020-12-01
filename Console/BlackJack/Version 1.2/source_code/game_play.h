void start_game() {
    while (true) {


        clear();
        const char *screen = 
        "                    ~~ Gamemode ~~                 \n"
        "                                                   \n"
        "  -------------------------------------------------\n"
        "                                                   \n"
        "          [A] Money Game      [B] Free Game        \n"
        "          [I] Info            [X] Exit             \n";

        print(screen);

        std::string choice = to_lower(input("              >> "));
        while ((choice != "a") && (choice != "b") && (choice != "i") && (choice != "x")) {
            clear();
            print(screen);
            print("              \"" + choice + "\" is an invalid answer...\n              Please enter the letter\n              corresponding to your choice\n");
            choice = to_lower(input("          >> "));
        }

        if (choice == "a") {
            
            //Player user("player", 500);
        
        } else if (choice == "b") {

            

        } else if (choice == "i") {
            
            clear();

            const char* screen = 
            "                    ~~   Info   ~~                 \n"
            "  -------------------------------------------------\n"
            "                                                   \n"
            "        Money Game:   Play against the dealer      \n"
            "                      using money from your        \n"
            "                      account.                     \n"
            "                                                   \n"
            "        Free Game:    Play against the dealer      \n"
            "                      with unlimited money for     \n"
            "                      practice. Your wins and      \n"
            "                      losses are displayed so      \n"
            "                      you can keep track.          \n"
            "                                                   \n"
            "        [A] Next                                   \n";

            print(screen);

            std::string choice = to_lower(input("        >> "));
            while (choice != "a") {
                clear();
                print(screen);
                print("Please type [A] to continue...\n");
                choice = to_lower(input("        >> "));
            }
            
        
        } else {
            break;
        }

    }
}