#ifndef CSC_275_TEST1_KENO_PLAYER_H
#define CSC_275_TEST1_KENO_PLAYER_H
#include <vector>

class Player {

private:
    // Encapsulation on the privatized numbers
    std::vector<int> m_playerNumbers;

public:
    void inputPlayerNumbers();
    std::vector<int> getPlayerNumbers();
    void printPlayerNumbers();
    void clearPlayerNumbers();
};
#endif // CSC_275_TEST1_KENO_PLAYER_H

