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
	individual card that points to next
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
	int peek(bool);

	/*
	Returns and deletes card from front. Returns card as integer.
	*/
	int pop();

	/**
		Returns current deck size as int.
	*/
	int getSize();

	/**
		Adds card to back of queue

		params:
			int card_value. Must be [1,10]
	*/
	void enqueue(int);
};