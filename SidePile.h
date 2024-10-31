#include <iostream>
#pragma once
#define MAX 5

class SidePile
{
private:
	int* top;
	int size;
	int deck[MAX];
	void push(int);
public:
	SidePile();
	SidePile(int);
	SidePile(int,int);
	int pop();
	int getSize();
};

