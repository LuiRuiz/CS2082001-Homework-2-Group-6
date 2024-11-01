#include "Deck.h"
Deck::Deck() {
	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0;
}

Deck::Deck(int* arr, int size) {
	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0;

	for (int i = 0; i < size; i++) {
		try {
			this->enqueue(arr[i]);
		}
		catch (std::invalid_argument) {
			throw std::invalid_argument("Number must be an integer 1-10");
		}
	}
}

int Deck::getSize() {
	return this->size;
}

void Deck::enqueue(int value) {
	if (!(1 <= value and value <= 10)) {
		throw std::invalid_argument("Number must be an integer 1-10");
	}

	Deck::Card* new_card = new Deck::Card(value);
	if (!this->head) {
		this->head = new_card;
	}
	else {
		this->tail->next = new_card;
	}
	this->tail = new_card;
	this->size += 1;
}

int Deck::peek(bool pop = false) {
	if (this->head) {
		return this->head->value;
	}
	return 0;
}

int Deck::pop() {
	Deck::Card* top = nullptr;

	if (!this->head) {
		throw std::underflow_error("Deck is empty");
	}

	top = this->head;

	this->head = top->next;
	top->next = nullptr;

	int card_number = top->value;
	delete top;
	size--;

	return card_number;

}

void Deck::printCard(Deck::Card* card) {
	std::cout << card->value;
}