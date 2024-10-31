#pragma once
#include <iostream>
/**
	Stores cards in a linked list queue.
	head -> Card -> Card -> Card (tail) -> nullptr
*/
class Deck
{
protected:
	/**
	individual card hodl
	*/
	struct Card {
		int value;
		Card* next;
		Card(int value) : value(value), next(nullptr) {};
	};

	Card* head;
	Card* tail;

	int size;

	/**
	returing card value
	*/
	void printCard(Card*);
public:
	Deck();
	Deck(int* arr, int size);

	/**
	Returns ptr card in front.

	Params: pop = false. This is helps reduce redundancy in pop function.
	*/
	Card* peek(bool);

	/*
	Returns and deletes ptr card from front
	*/
	Card* pop();
	
	/**
		Returns current size as int.
	*/
	int getSize();

	/**
		Changes count by card_count value.

		params:
			int card_count. Can be negative or positive to function as addCount or subtractCount
	*/
	void enqueue(int);
};