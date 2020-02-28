#include "Functions.h"

//EKRAMUL SAWRID
//MANCALA GAME

//Breath-First Search
//PreCondition: tNode that you want to preform breath-first search on
//PostCondition: prints all the tNodes that function went through and the number of tNodes it went through
void BFS(tNode* Parent){
	size_t count=0;
	queue<tNode*>Q;
	Q.push(Parent);
	while(!Q.empty()){
		count++;
		tNode* curr=Q.front();
		Q.pop();
		if(curr->getBoard().checkWin()){
			cout<<curr->getBoard().winComputer()<<"\n";
			if(curr->getBoard().winComputer()){
				cout<<"Computer Wins. This is winning path.\n";
				cout<<"Nodes went through: "<<count<<"\n";
				cout<<"This is BFS search\n";
				break;
			}
			else{
				cout<<"Player Two Wins\n";
				cout<<"Nodes went through: "<<count<<"\n";
			}
		}
		curr->expand();
		for(size_t i=0; i<6; i++){
			if(i<curr->getNumC()){
				Q.push(curr->getChild(i));
			}
		}
	}
	if(Q.empty()){
		cout<<"NO POSSIBLE WINNING STATES\n";
		cout<<"Nodes went through: "<<count<<"\n";
	}
	
}

//Dept-First Search
//PreCondition: tNode that you want to preform dept-first search on
//PostCondition: prints all the tNodes that function went through and the number of tNodes it went through
//NOTE: These two function work together and DRS_V depends on DFS and vice-versa

//This sets up the recursive DFS_V function
void DFS(tNode* Parent){
	size_t count=1;
	bool over=0;
	tNode* curr=Parent;
	DFS_V(curr, count);
}

//This function uses recursion instead of stack.
bool DFS_V(tNode* curr, size_t count){
	bool W;
	for(size_t i=0; i<6; i++){
		//Stopping case 
		if(curr->getBoard().checkWin()){
			cout<<curr->getBoard().winComputer()<<"\n";
			if(curr->getBoard().winComputer()){
				cout<<"Computer Wins. This is winning path.\n";
				cout<<"Nodes went through: "<<count<<"\n";
				cout<<"This is DFS Search\n";
				return true;
			}
			else{
				cout<<"Player Two Wins\n";
				cout<<"Nodes went through: "<<count<<"\n";
			}
		}
		if(i<curr->getNumC()){
			count++;
			curr->expand();
			W=DFS_V(curr->getChild(i), count);
			if(W==true) return true;
		}
	}
	return false;
}

//Minimax Search
//PreCondition: tNode that you want to preform A-star search on
//PostCondition: prints all the tNode that functions went through and the number of tNodes it went through
//NOTE: These two functions work together and MMS_V depends on ASF and vice-versa

////This sets up the recursive MMS_V function
void MMS(tNode* Parent){
	size_t count=1;
	bool over=0;
	tNode* curr=Parent;
	MMS_V(curr, count);
}

//This function uses recursion
bool MMS_V(tNode* curr, size_t count){
	bool W;
	for(size_t i=0; i<6; i++){
		if(curr->getBoard().checkWin()){
			cout<<curr->getBoard().winComputer()<<"\n";
			if(curr->getBoard().winComputer()){
				cout<<"Computer Wins. This is winning path.\n";
				cout<<"Nodes went through: "<<count<<"\n";
				cout<<"This is MMS Search\n";
				return true;
			}
			else{
				cout<<"Player Two Wins\n";
				cout<<"Nodes went through: "<<count<<"\n";
			}
		}
		if(i<curr->getNumC()){
			count++;
			curr->expand();
			for(size_t i=0; i<curr->getNumC(); i++){
				for(size_t j=i+1; j<curr->getNumC(); j++){
					if(curr->getChild(i)->getBoard().getTurn()>curr->getChild(j)->getBoard().getTurn()){
						curr->swapChild(i, j);
					}
				}
			}
			for(size_t i=0; i<curr->getNumC(); i++){
				size_t diff=0;
				for(size_t j=i+1; j<curr->getNumC(); j++){
					if(curr->getChild(i)->getBoard().getNum(6)>curr->getChild(j)->getBoard().getNum(13)){
						if(curr->getChild(i)->getBoard().getNum(6)-curr->getChild(j)->getBoard().getNum(13)>diff){
						diff=curr->getChild(i)->getBoard().getNum(6)-curr->getChild(j)->getBoard().getNum(13);
						curr->swapChild(i, j);
						}
					}
				}
			}			
			W=MMS_V(curr->getChild(i), count);
			if(W==true) return true;
		}
	}
	return false;
}

//Playing the game, where player 1 is the computer who uses DFS to make move
//NOTE: These three functions depend on each other.
//PreCondition: board that you want as your starting state.
//PostCondition: You  play the game, versing the computer. You are player 2 and the computer is player 1. Computer goes first.

//This is the "main" function
void Play(Board mainBoard){
	cout<<"PLAYER 1 TURN (0)\n";
	cout<<"PICK ONLY POSITIONs 1 TO 6 OF YOUR SIDE\n\n";
	mainBoard.print();
	size_t pos;
	while(!mainBoard.checkWin()){
		if(mainBoard.isOdd()){
			pos=comDFS(mainBoard);
			if(pos==99){
				cout<<"Congradulations, You Won\n";
				break;
			}
			cout<<pos<<endl;
			mainBoard.makeMove(pos+1);
		}
		else{
			cin>>pos;
			mainBoard.makeMove(pos);
		}
	}
	mainBoard.moveRemain();
}

size_t comDFS(Board mainBoard){
	size_t count=1;
	size_t count2=0;
	tNode* curr=new tNode(mainBoard);
	curr->expand();
	for(size_t i=0; i<curr->getNumC(); i++){
		if(comDFS_V(curr->getChild(i), count)) break;
		count2++;
	}
	if(count2==curr->getNumC()) return 99;
	for(size_t i=0; i<6; i++){
		if(curr->getBoard().getNum(i)==0){
			count2++;
		} 
		if(i==count2) break;	
	}
	return count2;
}

bool comDFS_V(tNode* curr, size_t count){
	bool W;
	for(size_t i=0; i<6; i++){
		if(curr->getBoard().checkWin()){
			cout<<curr->getBoard().winComputer()<<"\n";
			if(curr->getBoard().winComputer()){
				cout<<"Computer Wins. This is winning path.\n";
				cout<<"Nodes went through: "<<count<<"\n";
				cout<<"This is DFS Search\n";
				return true;
			}
			else{
				cout<<"Player Two Wins\n";
				cout<<"Nodes went through: "<<count<<"\n";
			}
		}
		if(i<curr->getNumC()){
			count++;
			curr->expand();
			W=DFS_V(curr->getChild(i), count);
			if(W==true) return true;
		}
	}
	return false;
}

//Multi Player (Human vs Human)
void MultiPlay(Board board){
	cout<<"PLAYER 1 TURN (0)\n";
	cout<<"PICK ONLY POSITIONs 1 TO 6 OF YOUR SIDE\n\n";
	board.print();
	size_t pos;
	while(!board.checkWin()){
		cin>>pos;
		board.makeMove(pos);
	}
	board.moveRemain();
}
