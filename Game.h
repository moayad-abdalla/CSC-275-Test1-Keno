#ifndef CSC_275_TEST1_KENO_GAME_H
#define CSC_275_TEST1_KENO_GAME_H
#include "Player.h"
#include "KenoNumbers.h"
#include <vector>

class Game {

private:
    // Encapsulation: private game data
    KenoNumbers m_keno;
    Player m_player;
    std::vector<int> m_matches;

public:
    Game();
    void printMatches(std::vector<int> playerPicks, std::vector<int> kenoNumbers);
    void displayResults();
    void playGame();
};

#endif // CSC_275_TEST1_KENO_GAME_H

