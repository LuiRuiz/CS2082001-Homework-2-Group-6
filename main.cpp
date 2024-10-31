#include "SidePile.h"
#include "Deck.h"

void play() {
	return;
}

void option1() {

	srand(time(0));
	int random_number = rand() % 2;

}

void option2() {

}


int main() {
	std::cout <<
		"-------Welcome to War----------\n"<<
		"Pick pick a play style (1 or 2)\n"<<
		"1: Play until one participant runs out of cards\n"<< 
		"2: Play for a fixed number of rounds."<<
		"The Play with the most cards at the end wins.\n";
	int style;
	std::cin >> style;

	while (!(style == 1 or style == 2)) {
		std::cout << "Please enter 1 or 2:\n";
		std::cin >> style;
	}
	
	std::cout <<
		"Choose to initialize each deck/side pile (1)\n" <<
		"Or have a set number of cards per person (2)";
	
	int card_type;
	std::cin >> card_type;

	while (!(card_type == 1 or card_type == 2)) {
		std::cout << "Please enter 1 or 2:\n";
		std::cin >> card_type;
	}

	Deck player_deck;
	SidePile player_pile;
	
	Deck computer_deck;
	SidePile computer_pile;

	if (card_type == 1) {
		int card;
		while (true) {
			std::cout << "Enter Cards for Player deck (valid on range [1,10]. Break with \'-1\'): ";
			std::cin >> card;
			if (card == -1) {
				break;
			}
			player_deck.enqueue(card);
		}
		while (true) {
			std::cout << "Enter Cards for Computer deck (valid on range [1,10]. Break with \'-1\'): ";
			std::cin >> card;
			if (card == -1) {
				break;
			}
			computer_deck.enqueue(card);
		}
	}
	else {

	}

	play();
}