#ifndef __STATE_H__
#define __STATE_H__

//EKRAMUL SAWRID
//MANCALA GAME

#include "Board.h"

//this is the tree class
class tNode{
private:
	Board state;			//this the tNode's board state
	tNode** childern;		//dynamic array of tNode*
	tNode* parent;			//pointer to parent of tNode
	size_t numChildern;		//number of childern tNode has (max is 6 childern)
public:	
	tNode();			//default constructor
	tNode(Board& board);		//contructor: PostCondition: tNode's Board state=board
	tNode(tNode* Parent, Board board, size_t pos);		/*constructor: PreCondition: Parent tNode, board that you want to copy, pos that you want to makeMove the board you just copied 
								--> PostCondition: tNode whose parent is Parent, Board state is the board after makeMove of pos*/
	~tNode();			//destructor
	
	//set functions
	void setParent(tNode* Parent);		//PreCondition: Parent that you want to set tNode --> PostCondition: tNode parent is Parent
	void setNumC();				//PostCondition: numChildern is the number of non-zero indices (holes) of the players side of the board

	//get functions
	tNode* getParent();		//PostCondition: returns pointer to parent
	size_t getNumC();		//PostCondition: returns number of childern
	Board getBoard();		//PostCondition: returns Board state
	tNode* getChild(size_t i);	//PreCondition: i the ith childern of tNode --> PostCondition: returns pointer of ith childern

	//other functions
	void expand();			//PostCondition: tNode has childern of every possible move
	void swapChild(size_t pos1, size_t pos2);	//PreCondition: pos1 and pos2 are pos1th and pos2th (indices) childern of tNode --> PostCondition: childern are swapped to each other indices
	void copyBoard(Board board);			//PreConditoin: board that you want to copy --> PostCondition: tNode's Board state=board

	
};

#endif
