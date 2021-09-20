// Game «Guess the number»

#include <iostream>

int main() {
	const int MIN_NUMBER = 1;
	const int MAX_NUMBER = 100;

	int hidden_number = rand() % MAX_NUMBER + MIN_NUMBER;
	int entered_number;
	int tries = 0;

	std::cout << "Welcome to the game \"Guess the number\"!" << std::endl;
	std::cout << "You need to write the hidden number (" << MIN_NUMBER << " - " << MAX_NUMBER << ")." << std::endl;
	std::cout << std::endl;

	do {
		std::cout << "Enter a guess (" << MIN_NUMBER << " - " << MAX_NUMBER << "): ";
		std::cin >> entered_number;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Oops.. You entered the wrong number, try again." << std::endl;
			std::cout << std::endl;
			continue;
		}
		else if (entered_number < MIN_NUMBER || entered_number > MAX_NUMBER) {
			std::cout << "Oops.. You entered the wrong number, try again." << std::endl;
			std::cout << std::endl;
			continue;
		}

		tries++;

		if (entered_number > hidden_number) {
			std::cout << "Too high!" << std::endl;
			std::cout << std::endl;
		}
		else if (entered_number < hidden_number) {
			std::cout << "Too low!" << std::endl;
			std::cout << std::endl;
		}
		else {
			std::cout << "Excellent! You won!" << std::endl;
			std::cout << "It took you " << tries << " tries." << std::endl;
			std::cout << std::endl;
		}
	} while (entered_number != hidden_number);
	return 0;
}