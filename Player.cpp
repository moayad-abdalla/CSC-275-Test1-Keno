#include "Player.h"
#include <iostream>

void Player::inputPlayerNumbers() {

    // Abstraction for player input
    int number;
    int pick = 0;

    while (pick < 10) {

        std::cout << "Enter your pick #" << pick + 1 << ": ";

        if (!(std::cin >> number)) {

            if (std::cin.eof()) {
                return;
            }

            std::cin.clear();
            std::cin.ignore(10000, '\n');

            std::cout << "Invalid data input! Try again. ";
            continue;
        }

        if (number < 1 || number > 80) {

            std::cout << number << " is out of range! Try again. ";
            continue;
        }
        bool alreadyPicked = false;
        for (int chosen : m_playerNumbers) {
            if (chosen == number) {
                alreadyPicked = true;
            }
        }

        if (alreadyPicked) {
            std::cout << number << " was already picked! Try again. ";

        }
        else {
            m_playerNumbers.push_back(number);
            pick++;

        }

    }

}
std::vector<int> Player::getPlayerNumbers() {
    return m_playerNumbers;

}
void Player::printPlayerNumbers() {
    std::vector<int> numbers = m_playerNumbers;
    for (int i = 0; i < (int)numbers.size(); i++) {
        for (int j = i + 1; j < (int)numbers.size(); j++) {
            if (numbers[j] < numbers[i]) {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    std::cout << "Player Picks: ";
    for (int number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;
}
void Player::clearPlayerNumbers() {
    m_playerNumbers.clear();
}
