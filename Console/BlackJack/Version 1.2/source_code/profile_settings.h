void settings() {
    while (true) {

        clear();
        const char *screen = 
        "                    ~~ Settings ~~                 \n"
        "                                                   \n"
        "  -------------------------------------------------\n"
        "                                                   \n"
        "            [A] Money          [B] Dealer          \n"
        "            [C] Color          [D] Reset           \n"
        "                                                   \n"
        "            [X] Exit                               \n"
        "                                                   \n";
        
        print(screen);

        std::string choice = to_lower(input("            >> "));
        while ((choice != "a") && (choice != "b") && (choice != "c") && (choice != "d") && (choice != "x")) {
            clear();
            print(screen);
            print("              \"" + choice + "\" is an invalid answer...\n              Please enter the letter\n              corresponding to your choice\n");
            choice = to_lower(input("            >> "));
        }

        if (choice == "a") {
            bool money_settings = true;
            while (money_settings) {
                
                clear(); 
                std::cout << "\n  Account: " << profile_money << "$\n";

                const char* screen = 
                "  -------------------------------------------------\n"
                "                                                   \n"
                "         [A] Add Money      [B] Remove Money       \n"
                "                                                   \n"
                "         [X] Exit                                  \n"
                "                                                   \n";

                print(screen);

                std::string choice = to_lower(input("         >> "));
                while ((choice != "a") && (choice != "b") && (choice != "x")) {
                    clear();
                    std::cout << "\n  Account: " << profile_money << "$\n";
                    print(screen);
                    print("              \"" + choice + "\" is an invalid answer...\n              Please enter the letter\n              corresponding to your choice\n");
                    choice = to_lower(input("        >> "));
                }

                if (choice == "a") {

                    clear();

                    std::cout << "\n  Account: " << profile_money << "$\n" << "  -------------------------------------------------\n";
                    std::string choice = to_lower(input("  Money to add: "));

                    while (!all_int(choice)) {
                        clear();
                        std::cout << "\n  Account: " << profile_money << "$\n" << "  -------------------------------------------------\n";
                        print("  Please enter only a positive integer value with the characters 0 - 9\n  Enter 0 to cancel.\n");
                        choice = to_lower(input("  Money to add: "));
                    }
                    
                    int old_amount = profile_money;
                    profile_money += to_int(choice);
                    if (profile_money < old_amount) {
                        profile_money = old_amount;
                        std::string trash = input("Integer data error!!\nTo avoid this I reccomend entering values less\nthan 5 digits in length, type [A] to continue");
                    }
                    
                } else if (choice == "b") {
                    
                    clear();

                    std::cout << "\n  Account: " << profile_money << "$\n" << "  -------------------------------------------------\n";
                    std::string choice = to_lower(input("  Money to remove: "));

                    while (!all_int(choice)) {
                        clear();
                        std::cout << "\n  Account: " << profile_money << "$\n" << "  -------------------------------------------------\n";
                        print("  Please enter only a positive integer value with the characters 0 - 9.\n  Enter 0 to cancel.\n");
                        choice = to_lower(input("  Money to remove: "));
                    }
 
                    profile_money -= to_int(choice);
                    if (profile_money < 0) {
                        profile_money = 0;
                    }
                    

                } else {
                    
                    money_settings = false;
                    
                }
            }

        } else if (choice == "b") {

        } else if (choice == "c") {

            clear();

            const char* screen = 
            "                     Text  Color                   \n"
            "  -------------------------------------------------\n"
            "           Enter your preffered color number:      \n"
            "                                                   \n"
            "                                                   \n"
            "                                                   \n"
            "                                                   \n";

        } else if (choice == "d") {

            clear();
            print("\n  Are you sure you would like to reset your account?\n\n  All of your settings and stats will be returned\n  to their default state.\n\n  [A] Yes        [B] No");    
            std::string choice = to_lower(input("  >> "));
            while ((choice != "a") && (choice != "b")) {
                clear();
                print("\n  Are you sure you would like to reset your account?\n\n  All of your settings and stats will be returned\n  to their default state.\n\n  [A] Yes        [B] No");
                print("              \"" + choice + "\" is an invalid answer...\n              Please enter the letter\n              corresponding to your choice\n");
                choice = to_lower(input("  >> "));
            }

            if (choice == "a") {
                profile_money = 500;
                dealers_play = "h17";
                game_save();
            } 

        } else {
            game_save();
            break;
        }

    }
    

}