#include "SidePile.h"
#include <iostream>
#include "Deck.h"

void takeFromPile(Deck& my_deck, SidePile& my_sidepile) {
	if (my_deck.getSize() >= 1) {
		return;
	}
	else if (my_deck.getSize() < 1 && my_sidepile.getSize() > 0) {
		my_deck.enqueue(my_sidepile.pop());
		return;
	}
	throw std::underflow_error("Side Pile Empty!");
}



void playRounds(int my_rounds, Deck& player,
				SidePile& player_pile, Deck& com, 
				SidePile& com_pile) 
{
	int rounds = my_rounds;
	int player_wins{ 0 };
	int com_wins{ 0 };
	int player_val1{ 0 };
	int player_val2{ 0 };

	int com_val{ 0 };

	//see if two cards have be played by player
	bool two_cards_played{ false };

	while ((player.getSize() > 0 || player_pile.getSize() > 0) && (com.getSize() > 0 || com_pile.getSize() > 0) && rounds >0 ) {
		std::cout << "------------------------------------------------------------------\n";
		two_cards_played = false;
		player_val2 = 0;

		int choice;

		std::cout << "Press 1 to peak at first card in deck\nPress 2 to push to sidePile and play new Card\n"
			<< "Press 3 to pull cade from side pile and play both\n"
			<< "Press 4 to play current card in deck\n"
			<< "Press 5 to see amount of cards in your deck and side pile\n"
			<< "Press 6 to see number of cards in opponent deck\n";
		std::cout << std::endl;
		std::cout << "   ENTER CHOICE (1-6): ";
		std::cin >> choice;
		std::cout << std::endl;

		switch (choice) {
		case 1:
			if (player.getSize() == 0) {
				takeFromPile(player, player_pile);
				std::cout << "Deck Empty: Taking Card from Pile\n";
			}
			std::cout << "Current Card: " << player.peek(false);
			std::cout << std::endl;
			continue;
			break;

		case 2:// push card from deck to pile and draw new card from deck
			if (player.getSize() <= 1 && player_pile.getSize() < 1) {
				std::cout << "Insufficent Cards in deck and pile to preform action\n";
				continue;
			}

			try {
				takeFromPile(player, player_pile);
				player_pile.push(player.pop());

			}
			catch (std::overflow_error e) {
				std::cout << e.what();
				std::cout << std::endl;
				std::cout << "Pile Full: Select other option\n";
				continue;
			}

			try {
				takeFromPile(player, player_pile);
			}
			catch (std::underflow_error e) {
				std::cout << e.what();
				std::cout << std::endl;
				std::cout << "Pile Empty: Select other option\n";
				continue;
			}
			player_val1 = player.pop();





			break;

		case 3: // use card from deck and card from side pile 
			if (player.getSize() + player_pile.getSize() < 2) {
				std::cout << "Insuffucent Number of Cards: only 1 in deck and pile\n";
				continue;
			}
			try {

				player_val2 = player_pile.pop();
			}
			catch (std::underflow_error e) {
				std::cout << e.what() << std::endl;
				std::cout << "Choose different option\n";
				continue;
			}
			takeFromPile(player, player_pile);
			player_val1 = player.pop();


			two_cards_played = true;
			break;

		case 4://play
			takeFromPile(player, player_pile);
			player_val1 = player.pop();

			break;

		case 5:
			//std::cout << std::endl;
			std::cout << "# of Cards in deck: " << player.getSize();
			std::cout << std::endl;
			std::cout << "# of Cards in Side Pile: " << player_pile.getSize();

			std::cout << std::endl;
			std::cout << std::endl;
			continue;

		case 6:
			//std::cout << std::endl;
			std::cout << "# of Cards in Opponent's deck: " << com.getSize() << std::endl;
			std::cout << std::endl;

			continue;

		default:
			std::cout << "INVALID CHOICE: Enter valid choice (1-6)\n";
			continue;
		}


		takeFromPile(com, com_pile);
		com_val = com.pop();

		if (!two_cards_played) {
			std::cout << "Player: " << player_val1 <<
				" || COM:  " << com_val << std::endl;
		}
		else {
			std::cout << "Player: " << player_val1 << " & " << player_val2 <<
				" || COM:  " << com_val << std::endl;
		}
		// win check
		if (player_val1 + player_val2 > com_val) {
			std::cout << "Player wins round!: " << com_val << " Added to your Deck\n";
			player.enqueue(com_val);
			player_wins++;
		}
		else {
			std::cout << "COM wins round!: ";
			com.enqueue(player_val1);

			if (two_cards_played) {
				std::cout << player_val1 << " & " << player_val2 << " Added to Opponents Deck\n";
				com.enqueue(player_val2);
			}
			else {
				std::cout << player_val1 << " Added to Opponents Deck\n";
			}
			com_wins++;
		}

		rounds--;
	}
	std::cout << "------------------------------------------------------------------\n";

	/// add comparison to player wins and com_wins
	std::cout << "Results:\n";
	std::cout << "Player wins: " << player_wins <<
		" || Computer wins: " << com_wins << std::endl;

	if (com_wins >= player_wins) {
		std::cout << "Computer Wins!\n";
	}
	else {
		std::cout << "You Win!\n";
	}




}


// untill deck and pile empty
void play(Deck& player,
	SidePile& player_pile, Deck& com,
	SidePile& com_pile) {

	/*/////////////////////////////////////////////////////
	int arr_1[3] = { 1,2,3 }; //hard coded 
	int arr_2[3] = { 10,4,5 };

	int player_pile_arr[2] = { 5,8 };
	int com_pile_arr[2] = { 5,8 };

	Deck player = Deck(arr_1, 3);
	Deck com = Deck(arr_2, 3);

	SidePile player_pile = SidePile(player_pile_arr, 2);
	SidePile com_pile = SidePile(com_pile_arr, 2);
	*///////////////////////////////////////////////////////

	//int player_wins{ 0 };
	//int com_wins{ 0 };

	//Value of P Card 1
	int player_val1{ 0 };
	//Value of P card 2
	int player_val2{ 0 };
	
	//Value of Com card played
	int com_val{ 0 };

	//see if two cards have be played by player
	bool two_cards_played{false};

	while ((player.getSize() > 0|| player_pile.getSize()>0) && (com.getSize() > 0 || com_pile.getSize() > 0)) {
		std::cout << "------------------------------------------------------------------\n";
		two_cards_played = false;
		player_val2 = 0;

		int choice;

		std::cout << "Press 1 to peak at first card in deck\nPress 2 to push to sidePile and play new Card\n"
			<< "Press 3 to pull cade from side pile and play both\n" 
			<< "Press 4 to play current card in deck\n"
			<< "Press 5 to see amount of cards in your deck and side pile\n" 
			<< "Press 6 to see number of cards in opponent deck\n";
		std::cout << std::endl;
		std::cout << "   ENTER CHOICE (1-6): ";
		std::cin >> choice;
		std::cout << std::endl;

		switch (choice) {
		case 1:
			if (player.getSize() == 0) {
				takeFromPile(player, player_pile);
				std::cout << "Deck Empty: Taking Card from Pile\n";
			}
			std::cout << "Current Card: " << player.peek(false);
			std::cout << std::endl;
			continue;
			break;

		case 2:// push card from deck to pile and draw new card from deck
			if (player.getSize() <= 1 && player_pile.getSize() < 1) {
				std::cout << "Insufficent Cards in deck and pile to preform action\n";
				continue;
			}

			try {
				takeFromPile(player, player_pile);
				player_pile.push(player.pop());
				
			}
			catch (std::overflow_error e) {
				std::cout<< e.what();
				std::cout << std::endl;
				std::cout << "Pile Full: Select other option\n";
				continue;
			}
			
			try {
				takeFromPile(player, player_pile);
			}
			catch (std::underflow_error e) {
				std::cout << e.what();
				std::cout << std::endl;
				std::cout << "Pile Empty: Select other option\n";
				continue;
			}
			player_val1 = player.pop();
			
			
			

			
			break;

		case 3: // use card from deck and card from side pile 
			if (player.getSize() + player_pile.getSize() < 2) {
				std::cout << "Insuffucent Number of Cards: only 1 in deck and pile\n";
				continue;
			}
			try {
				
				player_val2 = player_pile.pop();
			}
			catch (std::underflow_error e) {
				std::cout << e.what() << std::endl;
				std::cout << "Choose different option\n";
				continue;
			}
			takeFromPile(player, player_pile);
			player_val1 = player.pop();

			
			two_cards_played = true;
			break;

		case 4://play
			takeFromPile(player,player_pile);
			player_val1 = player.pop();

			break;

		case 5:
			//std::cout << std::endl;
			std::cout << "# of Cards in deck: " << player.getSize();
			std::cout << std::endl;
			std::cout << "# of Cards in Side Pile: " << player_pile.getSize();

			std::cout << std::endl;
			std::cout << std::endl;
			continue;

		case 6:
			//std::cout << std::endl;
			std::cout << "# of Cards in Opponent's deck: " << com.getSize() << std::endl;
			std::cout << std::endl;
			
			continue;
		
		default:
			std::cout << "INVALID CHOICE: Enter valid choice (1-6)\n";
			continue; 
		}


		takeFromPile(com, com_pile);
		com_val = com.pop();

		if (!two_cards_played) {
			std::cout << "Player: " << player_val1 <<
				" || COM:  " << com_val << std::endl;
		}
		else {
			std::cout << "Player: " << player_val1<<" & "<< player_val2 <<
				" || COM:  " << com_val << std::endl;
		}

		if (player_val1 + player_val2 > com_val) {
			std::cout << "Player wins round!: " << com_val << " Added to your Deck\n";
			player.enqueue(com_val);
		}
		else {
			std::cout << "COM wins round!: ";
			com.enqueue(player_val1);

			if (two_cards_played) {
				std::cout << player_val1 << " & " << player_val2 << " Added to Opponents Deck\n";
				com.enqueue(player_val2);
			}
			else {
				std::cout << player_val1 << " Added to Opponents Deck\n";
			}
		}

		
	}
	std::cout << "------------------------------------------------------------------\n";


	if (player.getSize() <= 0 && player_pile.getSize() == 0) {
		std::cout << "Computer Wins! You have run out of cards.\n";
	}
	else {
		std::cout << "You Win! Computer has run out of cards.\n";
	
	}
	

}

void option1() {

	srand(time(0));
	int random_number = rand() % 2;

}

void option2() {

}


int main() {
	srand((unsigned)time(NULL));

	int rounds{ 0 };

	std::cout <<
		"-------Welcome to War----------\n" <<
		"Pick pick a play style (1 or 2)\n" <<
		"1: Play until one participant runs out of cards\n" <<
		"2: Play for a fixed number of rounds." <<
		"The Play with the most cards at the end wins.\n";
	int style;
	std::cin >> style;

	while (!(style == 1 or style == 2)) {
		std::cout << "Please enter 1 or 2:\n";
		std::cin >> style;
	}

	if (style == 2) {
		std::cout << "Please enter desired amout of rounds: ";
		std::cin >> rounds;
		std::cout << std::endl;
	}

	

	int mode;


	///////Mode Menu////
	std::cout << "|-------MODE MENU--------|\n";
	std::cout << "   Press 1 to set values for test case 1 (follow documentation)\n";
	std::cout << "   Press 2 to set values for test case 2 (follow documentation)\n";
	std::cout << "   Press 3 to set values for test case 3 (follow documentation)\n";
	std::cout << "   Press 4 to enter standard mode (7 cards in deck, 3 cards in Pile EACH)\n";

	std::cout << "Enter Value (1-4): ";
	std::cin >> mode;


	Deck player_deck;
	SidePile player_pile;

	Deck computer_dec;
	SidePile computer_pile;



	if (mode == 1) {
		int arr[3] = { 4,5,6 };
		int arr2[3] = { 5,6,2 };
		int pile_arr[2] = { 1,1};

		player_deck = Deck(arr, 3);
		player_pile = SidePile(pile_arr, 2);




		computer_dec = Deck(arr2, 3);
		computer_pile = SidePile(pile_arr, 2);



	}
	else if (mode == 2) {
		int arr[3] = { 1,6,7 };
		int arr2[3] = { 5,6,2 };
		int pile_arr[1] = { 8 };


		player_deck = Deck(arr, 3);
		player_pile = SidePile(pile_arr, 1);




		computer_dec = Deck(arr2, 3);
		computer_pile = SidePile(pile_arr, 1);



	}
	else if (mode == 3) {
		int arr[1] = { 1 };
		int arr2[1] = { 1 };
		int pile_arr[3] = { 1,2,3};


		player_deck = Deck(arr, 1);
		player_pile = SidePile(pile_arr, 3);




		computer_dec = Deck(arr2, 1);
		computer_pile = SidePile(pile_arr, 3);





	}
	else {
		int cards[10] = { 1,2,3,4,5,6,7,8,9,10 };
		int arr[7];
		int arr2[7];
		int side_arr[5];
		int side_arr2[5];

		for (int i = 0; i < 7; i++) {
			

			arr[i] = cards[(rand() % 9) + 1];

		}
		for (int i = 0; i < 7; i++) {
			arr2[i] = cards[(rand() % 9) + 1];

		}

		for (int i = 0; i < 5; i++) {
			side_arr[i] = cards[(rand() % 9) + 1];

		}
		for (int i = 0; i < 5; i++) {
				side_arr2[i] = cards[(rand() % 9) + 1];

		}
			std::cout << std::endl;

			player_deck = Deck(arr, 7);
			player_pile = SidePile(side_arr, 5);
			computer_dec = Deck(arr2, 7);
			computer_pile = SidePile(side_arr2, 5);

	}






		if (style == 2) {
			playRounds(rounds, player_deck, player_pile, computer_dec, computer_pile);
		}
		else {
			play(player_deck, player_pile, computer_dec, computer_pile);
		}

		std::cout << "Thank you for playing!";
}
