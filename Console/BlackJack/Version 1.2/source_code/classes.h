
class Player {
  protected:
  
    std::string type;
    int money;
    bool busted;
    
    std::vector<std::string> hand;
    int points;

  public:
    
    Player(std::string new_type, int new_money) {
        type = new_type;
        money = new_money;

        busted = false;

    }

    bool get_busted() {
      return busted;
    }

      
};





class Game {
  protected:
    
    std::string type;
    std::vector<Player> players;
    std::map<Player, int> bets;

  public:

    Game(std::vector<Player> new_players, std::string new_type) {
        type = new_type;
        
        for (int i = 0; i < new_players.size(); i++) {
            players.push_back(new_players[i]);
        }
    }


};