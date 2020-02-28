#include "Board.h"

//EKRAMUL SAWRID
//MANCALA GAME

//default constructor
Board::Board(){
	for(size_t i=0; i<cap; i++){			//appropriate indices will be set to 4
		if(i==6 || i==13) rocks[i]=0;
		else rocks[i]=4;
	}
}

//copy constructor
Board::Board(const Board& target){
	for(size_t i=0; i<cap; i++){
		rocks[i]=target.rocks[i];
	}
	turn=target.turn;
}

//PreCondition: num is the number that you want to set at index --> PostCondition: number at index is num
void Board::setNum(size_t num, size_t index){
	assert(index<14);
	rocks[index]=num;
}

//PreCondition: index of the array --> PostCondition: return the number at index of the array
size_t Board::getNum(size_t index){
	assert(index<14);
	return rocks[index];
}

//PostCondition: return turn number
size_t Board::getTurn(){
	return turn;
}

//PreCondition: index of the array --> PostCondition: increment of the number at the index by 1
void Board::add(size_t index){
	size_t temp=rocks[index];
	rocks[index]=++temp;
}

//PreCondition: index of the array --> PostCondition: decrement of the number at the index by 1
void Board::substract(size_t index){
	if(rocks[index]==0) return;
	size_t temp=rocks[index];
	rocks[index]=--temp;
}

//PostCondition: returns if the turn number is odd
bool Board::isOdd(){
	if(turn==1) return true;
	return (turn%2!=0);
}

//PostCondition: increment of the turn number by 1
void Board::addTurn(){
	turn++;
}

//PostCondition: prints the array to look like a board
void Board::print(){
	for(int i=cap-1; i>=0; i--){
		if(i==6) break;
		cout<<rocks[i]<<"  ";
	}
	cout<<"\n   ";
	for(int i=0; i<7; i++) cout<<rocks[i]<<"  ";
	cout<<"\n";
}

//PostCondition: turn=1
void Board::setTurn(){
	turn=1;
}

//PostCondition: countTurn=1;
void Board::setcountTurn(){
	countTurn=1;
}

//PreCondition: pos is the hole you pick to move --> PostCondition: the board after move
//NOTE: I have implemented the rules of the game in this function.
void Board::makeMove(size_t pos){
	assert(0<pos && pos<7);
	size_t looped=0;
	if(this->isOdd()){
		size_t index=pos-1;
		if(rocks[index]==0){
			cout<<"Cannot chose empty hole. Try again.\n";
			return;
		}
		size_t nextIndex=pos;
		while(rocks[index]!=looped){
			if(nextIndex==13){
				nextIndex=0;
			}
			else{	
				substract(index);
				add(nextIndex);
				if(index==nextIndex){
					looped++;
				}
				if(rocks[index]==0 && nextIndex==6){
					cout<<"Go again\n\n";
					this->print();
					return;
				}
				if(rocks[index]==0 && nextIndex!=6 && rocks[nextIndex]==1){
					size_t tempSum;
					if(nextIndex<6){
						size_t j=12;
						for(size_t i=0; i<6; i++){
							if(i==nextIndex){
								tempSum=rocks[nextIndex]+rocks[j]+rocks[6];
								rocks[nextIndex]=0;
								rocks[j]=0;
								rocks[6]=tempSum;
							}	
							j--;
						}
					}
					if(nextIndex>6){
						size_t j=5;
						for(size_t i=7; i<13; i++){
							if(i==nextIndex){
								tempSum=rocks[nextIndex]+rocks[j]+rocks[6];
								rocks[nextIndex]=0;
								rocks[j]=0;
								rocks[6]=tempSum;
							}
							j--;
						}
					}
				}
				nextIndex++;
			}
			
		}
	}
	else{
		size_t index=pos+6;
		if(rocks[index]==0){
			cout<<"Cannot chose empty hole. Try again.\n";
			return;
		}
		size_t nextIndex=index+1;
		while(rocks[index]!=looped){
			if(nextIndex==6){
				nextIndex=7;
			}
			else{
				substract(index);
				add(nextIndex);
				if(index==nextIndex){
					looped++;
				}
				if(rocks[index]==0 && nextIndex==13){
					cout<<"Go again\n\n";
					this->print();
					return;
				}
				if(rocks[index]==0 && nextIndex!=13 && rocks[nextIndex]==1){
					size_t tempSum;
					if(nextIndex>6){
						size_t j=5;
						for(size_t i=7; i<13; i++){
							if(i==nextIndex){
								tempSum=rocks[nextIndex]+rocks[j]+rocks[13];
								rocks[nextIndex]=0;
								rocks[j]=0;
								rocks[13]=tempSum;
							}
							j--;
						}
					}
					if(nextIndex<6){
						size_t j=12;
						for(size_t i=0; i<6; i++){
							if(i==nextIndex){
								tempSum=rocks[nextIndex]+rocks[j]+rocks[13];
								rocks[nextIndex]=0;
								rocks[j]=0;
								rocks[13]=tempSum;
							}	
							j--;
						}
					}
				}
				nextIndex++;
				if(nextIndex==14){
				nextIndex=0;
				}
			}
		}
	}
	turn++;
	if(this->isOdd()) cout<<"PLAYER 1 TURN ("<<countTurn<<")\n\n";
	else cout<<"PLAYER 2 TURN ("<<countTurn<<")\n\n";
	this->print();
	countTurn++;
	cout<<"\n";
}

//PostCondition: board is clear of rocks; moves the remaining rocks at the end game
void Board::moveRemain(){
	size_t sum=0;
	for(size_t i=0; i<6; i++){
		sum+=rocks[i];
		rocks[i]=0;
	}
	sum+=rocks[6];
	rocks[6]=sum;
	sum=0;
	for(size_t i=7; i<13; i++){
		sum+=rocks[i];
		rocks[i]=0;
	}
	sum+=rocks[13];
	rocks[13]=sum;
	this->print();
}

//PostConditoin: return true if each player can move 
bool Board::checkWin(){
	size_t count=0;
	for(size_t i=0; i<6; i++){
		 if(rocks[i]!=0){
			count++;
			break;
		}
	}
	for(size_t i=7; i<13; i++){
		 if(rocks[i]!=0){
			count++;	
			break;
		}
	}
	if(count==2) return false;
	else return true;
}

//PostCondition: returns true if the computer won (Player 1 is conputer)
bool Board::winComputer(){
	if(this->checkWin()){
		this->moveRemain();
		if(rocks[6]>rocks[13]) return true;
	}
	return false;
}

//configure the number of rocks in each hole
void Board::customize(){
	size_t num;
	for(size_t i=0; i<cap; i++){
		cin>>num;
		this->setNum(num, i);
	}
}

//configure the number of rocks in each hole
void Board::customize(size_t n0, size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, size_t n6, size_t n7, size_t n8, size_t n9, size_t n10, size_t n11, size_t n12, size_t n13){
	this->setNum(n0, 0);
	this->setNum(n1, 1);
	this->setNum(n2, 2);
	this->setNum(n3, 3);
	this->setNum(n4, 4);
	this->setNum(n5, 5);
	this->setNum(n6, 6);
	this->setNum(n7, 7);
	this->setNum(n8, 8);
	this->setNum(n9, 9);
	this->setNum(n10, 10);
	this->setNum(n11, 11);
	this->setNum(n12, 12);
	this->setNum(n13, 13);
}
