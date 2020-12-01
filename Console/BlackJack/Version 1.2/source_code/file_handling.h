/*#########################################*/
// File Handling



void create_new_profile() {
    clear();
    mkdir("./BJ_Profiles");
    bool finished = false;

    while (!finished) {
       
        print("What would you like your profiles name to be?");
        std::string new_name = input(">>> ");

        while (!finished) {
            if (!all_alpha(new_name)) {
            
                clear();
                print("What would you like your profiles name to be?");
                print("\nPlease enter a name that only contains a - z and A - Z\n");
                new_name = input(">>> ");

            } else {
                std::fstream new_file;
                std::string first = "./BJ_profiles/";
                std::string last = ".ccas";
                new_file.open(to_const_char(first + to_lower(new_name) + last), std::ios::in);
                if (new_file) {
                    clear();
                    print("This profile already exists\nPlease choose a different name\n");
                    new_name = input(">>> ");
                } else {

                    clear();
                    print("Please verify the name you chose: " + new_name + "\n[Y] Yes    [N] No    [X] Exit");
                    std::string user_input = to_lower(input(">>> "));

                    while (user_input != "x" && user_input != "y" && user_input != "n") {
                        clear();
                        print("Please verify the name you chose: " + new_name + "\n[Y] Yes    [N] No    [X] Exit");
                        print("              \"" + user_input + "\" is an invalid answer...\n              Please enter the letter\n              corresponding to your choice\n");
                        user_input = to_lower(input(">>> "));
                    }

                    if (user_input == "x") {
                        
                        clear();
                        finished = true;
                        

                    } else if (user_input == "y") {
                        new_file.close();
                        std::ofstream new_profile_file;
                        new_profile_file.open(to_const_char(first + to_lower(new_name) + last));
                        new_profile_file << new_name << "\n" << "500" << "\n" << "h17";
                        new_profile_file.close();
                        finished = true;
                        

                    } else {
                        
                        clear();
                        break;
                    
                    }
                }
            }
        }
    }
}



void login() {
    clear();

    const char *screen = 
    "                     Login:                  \n"
    "  ------------------------------------------ \n"
    "       Please type in your account name      \n"
    "                                             \n";

    print(screen);

    std::string user_input = input("       >>> ");

    std::ifstream profile_file;
    
    std::string first = "./BJ_Profiles/";
    std::string last = ".ccas";
    profile_file.open(to_const_char(first + user_input + last));

    while (to_lower(user_input) != "_new" && to_lower(user_input) != "_guest" && !profile_file) {
        clear();
        print(screen);
        print("       There is no account with the\n       name: \"" + user_input + "\"\n       You could log in with \"_guest\"");
        print("       or you could create a new  \n       account by typing \"_new\"\n");
        
        user_input = input("       >>> ");
        profile_file.open(to_const_char(first + user_input + last));
    }

    if (to_lower(user_input) == "_new") {
            
        create_new_profile();
        login();
 
    } else if (to_lower(user_input) == "_guest") {

         profile_file.close();

         user_name = "guest";
         profile_money = 500;
         dealers_play = "h17";

    } else {

        std::string m;
        profile_file >> user_name;
        profile_file >> profile_money_string;
        profile_money = to_int(profile_money_string);
        profile_file >> dealers_play;
        profile_file.close();
        }
        
    }




void game_save() {
    std::ofstream profile_file;
    std::string first = "./BJ_Profiles/";
    std::string last = ".ccas";

    profile_file.open(to_const_char(first + user_name + last));
    if (profile_file) {
        profile_file << user_name << "\n" << profile_money << "\n" << dealers_play;
    }
    
}