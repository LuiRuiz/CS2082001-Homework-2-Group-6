#include "SidePile.h"
SidePile::SidePile() {
	this->top = nullptr;
	this->size = 0;
}

SidePile::SidePile(int card_1) {
	this->top = nullptr;
	this->size = 0;
	try {
		this->push(card_1);

	}
	catch (std::invalid_argument e) {
		return; //idk if i should pass on the error or nah
	}
	
}

SidePile::SidePile(int card_1, int card_2) {
	this->top = nullptr;
	this->size = 0;

	try {
		this->push(card_1);

	}
	catch (std::invalid_argument e) {
		//return; //idk if i should pass on the error or nah
	}

	try {
		this->push(card_2);

	}
	catch (std::invalid_argument e) {
		//return; //idk if i should pass on the error or nah
	}
	
}

SidePile::SidePile(int* arr , int arr_size) {
	this->top = nullptr;
	this->size = 0;

	for (int i = 0; i < arr_size; i++) {
		this->push(arr[i]);
	}

}

void SidePile::push(int card) {
	if (!(1 <= card and card <= 10)) {
		throw std::invalid_argument("Card must be between 1-10");
	}
	if (this->size < MAX) {
		this->size += 1;
		this->deck[this->size-1] = card;
		this->top = &deck[this->size-1];
		return;
	}
	throw std::overflow_error("Side Pile Full");
}

int SidePile::getSize() {
	return this->size;
}


int SidePile::pop() {
	if (this->size <= 0) {//originally this->top == nullptr no based on size
		this->top = nullptr;
		throw std::underflow_error("Side Pile Empty");
	}
	int top_card = *this->top;
	this->top = 0;
	this->size -= 1;
	this->top = &this->deck[size - 1];
	return top_card;
}