#include "State.h"

//EKRAMUL SAWRID
//MANCALA GAME

//default constructor
tNode::tNode(){
	childern=NULL;
	parent=NULL;
	size_t numChildern=0;
}

//contructor: PostCondition: tNode's Board state=board
tNode::tNode(Board& board){
	childern=NULL;
	parent=NULL;
	this->copyBoard(board);
	this->setNumC();
}

//destructor
tNode::~tNode(){
	for(size_t i=0; i<numChildern; i++) delete [] childern[i];
	delete [] childern;
	childern=NULL;
	parent=NULL;
	size_t numChildern=0;
}

/*constructor: PreCondition: Parent tNode, board that you want to copy, pos that you want to makeMove the board you just copied 
--> PostCondition: tNode whose parent is Parent, Board state is the board after makeMove of pos*/
tNode::tNode(tNode* Parent, Board board, size_t pos){
	this->setParent(Parent);
	state=board;
	/* 
	//Optional code to see board before move
	cout<<"PARENT BOARD\n";
	board.print(); 
	*/
	state.makeMove(pos);
	this->setNumC();
	childern=NULL;
}

//PreCondition: Parent that you want to set tNode --> PostCondition: tNode parent is Parent
void tNode::setParent(tNode* Parent){
	parent=Parent;
}

//PostCondition: numChildern is the number of non-zero indices (holes) of the players side of the board
void tNode::setNumC(){
	numChildern=0;
	if(state.isOdd()){
		for(size_t i=0; i<6; i++){
			if(state.getNum(i)!=0) numChildern++;	
		}
	}
	else{
		 for(size_t i=7; i<13; i++){
			 if(state.getNum(i)!=0) numChildern++;
		}
	}
}

//PostCondition: returns pointer to parent
tNode* tNode::getParent(){
	return parent;
}

//PostCondition: returns number of childern
size_t tNode::getNumC(){
	return numChildern;
}

//PostCondition: returns Board state
Board tNode::getBoard(){
	return state;
}

//PreCondition: i the ith childern of tNode --> PostCondition: returns pointer of ith childern
tNode* tNode::getChild(size_t i){
	assert(0<=i<6);
	return childern[i];
}

//PostCondition: tNode has childern of every possible move
void tNode::expand(){
	size_t count=0;
	childern=new tNode*[numChildern];
	if(state.isOdd()){
		tNode* newChild;
		for(size_t i=0; i<6; i++){
			if(state.getNum(i)!=0){
				newChild=new tNode(this, state, i+1);
				childern[count]=newChild;
				count++;
			}	
		}
	
	}
	else{
		tNode* newChild;
		for(size_t i=7; i<13; i++){
			if(state.getNum(i)!=0){
				newChild=new tNode(this, state, i-6);
				childern[count]=newChild;
				count++;
			}
		}
	}
	
}

//PreCondition: pos1 and pos2 are pos1th and pos2th (indices) childern of tNode --> PostCondition: childern are swapped to each other indices
void tNode::swapChild(size_t pos1, size_t pos2){
	tNode* temp=this->getChild(pos1);
	tNode* temp2=this->getChild(pos2);
	this->childern[pos1]=temp2;
	this->childern[pos2]=temp;
}

//PreConditoin: board that you want to copy --> PostCondition: tNode's Board state=board
void tNode::copyBoard(Board board){
	for(size_t i=0; i<14; i++) state.setNum(board.getNum(i), i);
}


