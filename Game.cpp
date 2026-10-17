#include "Game.h"
#include <iostream>

Game::Game() {
    playGame();
}

void Game::printMatches(std::vector<int> playerPicks, std::vector<int> kenoNumbers) {
    m_matches.clear();
    for (int pick : playerPicks) {
        for (int winningNumber : kenoNumbers) {
            if (pick == winningNumber) {
                m_matches.push_back(pick);
            }
        }
    }

    for (int i = 0; i < (int)m_matches.size(); i++) {

        for (int j = i + 1; j < (int)m_matches.size(); j++) {
            if (m_matches[j] < m_matches[i]) {
                int temp = m_matches[i];
                m_matches[i] = m_matches[j];
                m_matches[j] = temp;
            }
        }
    }
    std::cout << "You matched: ";
    for (int number : m_matches) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

}
void Game::displayResults() {

    // Abstraction: game calls methods from player

    std::cout << "\n----------------------------------Results----------------------------------\n";


    m_keno.printKenoNumbers();
    m_player.printPlayerNumbers();
    printMatches(m_player.getPlayerNumbers(), m_keno.getKenoNumbers());
    std::cout << "Matching " << m_matches.size() << " of 20 numbers wins ";

    switch (m_matches.size()) {

        case 10:
            std::cout << "the GRAND PRIZE of $25,000";
            break;

        case 9:
            std::cout << "$2,500";
            break;

        case 8:
            std::cout << "$250";
            break;

        case 7:
            std::cout << "$50";
            break;

        case 6:
            std::cout << "$10";
            break;

        case 5:
            std::cout << "$5";
            break;

        default:
            std::cout << "$0";
            break;

    }

    std::cout << std::endl;
}

void Game::playGame() {

    // Abstraction: game control method

    char again = 'y';
    while (again == 'y' || again == 'Y') {

        m_player.clearPlayerNumbers();
        m_keno.clearKenoNumbers();
        m_matches.clear();

        std::cout << "\nTo play Keno, select 10 unique (no repeats) numbers in the range of 1-80.\n\n";
        std::cout << "Let's Play Keno!\n\n";

        m_player.inputPlayerNumbers();

        if (!std::cin) {
            return;
        }
        m_keno.generateNumbers();
        displayResults();
        std::cout << "\nPlay another round? (y/n): ";

        if (!(std::cin >> again)) {
            return;
        }
    }
    std::cout << "\nTHANKS FOR PLAYING!!\n";
}

