#include <iostream>
#pragma once
#define MAX 5

class SidePile
{
private:
	int* top;
	int size;
	int deck[MAX] = { -1 };
	
public:
	/***
	* push():
	*	Pushes integer value to top of array 
	*	takes integer arguments from 1-10 (inclusive); 
	*	raises overflow_error if size > max
	*/
	void push(int);

	/***
	* SidePile(int):
	*	constructor for empty side pile
	*/
	SidePile();

	/***
	* SidePile(int):
	*	constructor for SidePile with first element pushed
	*	takes integer argument 1-10 catches error and returns empty
	*	- sidePile if input is invalid;
	*/
	
	SidePile(int);

	/***
	* SidePile(int, int):
	*	constructor for SidePile with first element pushed
	*	takes integer argument 1-10 catches error and returns empty
	*	- sidePile if input is invalid;
	*/
	SidePile(int,int);

	/***
	* Initialize SidePile from array input
	*/
	SidePile(int*, int);
	/***
	* pop():
	*	returns most recent card in stack (n), 
	*	reduces size, and points top to (n-1)
	*	raises underflow_error if size is <= than 0
	*/
	int pop();

	/***
	* getSize():
	*	returns size of list (int)
	*/
	int getSize();
};

