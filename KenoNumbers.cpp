#include "KenoNumbers.h"
#include <iostream>
#include <random>

void KenoNumbers::generateNumbers() {

    // ABSTRACTION: creates its numbers without other classes.
    std::mt19937 gen;
    gen.seed(0);
    std::uniform_int_distribution<int> distrib(1, 80);

    while (m_numbers.size() < 20) {
        int num = distrib(gen);
        bool repeated = false;
        for (int number : m_numbers) {
            if (num == number) {
                repeated = true;
            }
        }
        if (!repeated) {
            m_numbers.push_back(num);
        }
    }
    for (int i = 0; i < 20; i++) {
        for (int j = i + 1; j < 20; j++) {
            if (m_numbers[j] < m_numbers[i]) {
                int temp = m_numbers[i];
                m_numbers[i] = m_numbers[j];
                m_numbers[j] = temp;
            }
        }
    }
}

std::vector<int> KenoNumbers::getKenoNumbers() {
    return m_numbers;
}

void KenoNumbers::printKenoNumbers() {
    std::cout << "Keno Numbers: ";
    for (int number : m_numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;
}

void KenoNumbers::clearKenoNumbers() {
    m_numbers.clear();

}
