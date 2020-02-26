#ifndef __BOARD_H__
#define __BOARD_H__

//EKRAMUL SAWRID
//MANCALA GAME

#include <iostream>
#include <cassert>
#include <cmath>
#include <cstdlib>

using namespace std;

//This is the board class, which mostly functions around maniplulating an array
class Board{
public:
	typedef size_t board;	
	static const size_t SIZE=14;		//The size of the array never changes
	size_t countTurn=1;			//This is to keep track of the total number of turns
	
	Board();				//default constructor
	Board(const Board& target);		//copy constructor

	//set function
	void setNum(size_t num, size_t index);	//PreCondition: num is the number that you want to set at index --> PostCondition: number at index is num
	
	//get functions	
	size_t getNum(size_t index);		//PreCondition: index of the array --> PostCondition: return the number at index of the array
	size_t getTurn();			//PostCondition: return the turn number

	//other functions
	void add(size_t index);			//PreCondition: index of the array --> PostCondition: increment of the number at the index by 1
	void substract(size_t index);		//PreCondition: index of the array --> PostCondition: decrement of the number at the index by 1
	void addTurn();				//PostCondition: increment of the turn number by 1
	bool isOdd();				//PostCondition: returns if the turn number is odd
	void print();				//PostCondition: prints the array to look like a board
	void setTurn();				//PostCondition: turn=1
	void setcountTurn();			//PostCondition: countTurn=1;

	void makeMove(size_t pos);		//PreCondition: pos is the hole you pick to move (1, 2, 3, 4, 5, or 6) --> PostCondition: the board after move		
	bool checkWin();			//PostConditoin: return true if each player can move 
	void moveRemain();			//PostCondition: board is clear of rocks; moves the remaining rocks at the end game
	bool winComputer();			//PostCondition: returns true if the computer won (Player 1 is conputer)

	void customize();			//configure the number of rocks in each hole
	void customize(size_t n0=4, size_t n1=4, size_t n2=4, size_t n3=4, size_t n4=4, size_t n5=4, size_t n6=0, size_t n7=4, size_t n8=4, size_t n9=4, size_t n10=4, size_t n11=4, size_t n12=4, size_t n13=0);			//configure the number of rocks in each hole		
	
private:
	board rocks[SIZE]; 			//Function: array represents each hole/mancala of the board
	size_t cap=SIZE;			//Function: size if the array is always 14
	size_t turn=1;				//Function: to keep track of whose turn is it to move
};



#endif
