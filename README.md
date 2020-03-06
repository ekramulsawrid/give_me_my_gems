# Give Me My Gems
<!-- # give_me_my_gems -->

Game based of the board game Mancala. The rules are the same. There is multiple modes: multiplayer and playing against computer (breath-first search, dept-first search, and min-max search modes). The games stops once a player wins.

## Author

Ekramul Sawrid

## Contributors

Prof. Chi-Him Liu

## Operating System

Ubuntu

## Language

C++

## Code Summery

There is a board, state, and tree class. The state class has a has-a relation with the board class and this enables the  board to have different "states". The tree class has a has-as relation with the state class. Using all this, the tree will grow so graph search can be used to find a winning state. 

### Code Snippets

#### Board Class Declaration

<details>
<p>

```cpp
class Board{
public:
	typedef size_t board;	
	static const size_t SIZE=14;		//The size of the array never changes
	size_t countTurn=1;			//This is to keep track of the total number of turns
	
	Board();				//default constructor
	Board(const Board& target);		//copy constructor

	//set function
	void setNum(size_t num, size_t index);	
	
	//get functions	
	size_t getNum(size_t index);	
	size_t getTurn();			

	//other functions
	void add(size_t index);			
	void substract(size_t index);		
	void addTurn();				
	bool isOdd();				
	void print();				
	void setTurn();				
	void setcountTurn();			
	void makeMove(size_t pos);				
	bool checkWin();			
	void moveRemain();			
	bool winComputer();			

    // functions for customization of board. 
	void customize();			
	void customize(size_t n0=4, size_t n1=4, size_t n2=4, size_t n3=4, size_t n4=4, size_t n5=4, size_t n6=0, size_t n7=4, size_t n8=4, size_t n9=4, size_t n10=4, size_t n11=4, size_t n12=4, size_t n13=0);					
	
private:
	board rocks[SIZE]; 			// array represents each hole/mancala of the board
	size_t cap=SIZE;			// Size if the array is always 14
	size_t turn=1;				// keepS track of whose turn is it to move
};
```
</p>
</details>

#### State Class Declaration

<details>
<p>

```cpp
class tNode{
private:
	Board state;			// this the tNode's board state
	tNode** childern;		// dynamic array of tNode*
	tNode* parent;			// pointer to parent of tNode
	size_t numChildern;		// number of childern tNode has (max is 6 childern)
public:	
	tNode();			//default constructor
	tNode(Board& board);		//contructor
	tNode(tNode* Parent, Board board, size_t pos);		
	~tNode();			//destructor
	
	//set functions
	void setParent(tNode* Parent);		
	void setNumC();				

	//get functions
	tNode* getParent();		
	size_t getNumC();		
	Board getBoard();		
	tNode* getChild(size_t i);	

	//other functions
	void expand();			
	void swapChild(size_t pos1, size_t pos2);	
	void copyBoard(Board board);			
};
```
</p>
</details>

#### Search Functions and Mode Declarations

<details>
<p>

```cpp
//Breath-First Search
void BFS(tNode* Parent);

//Dept-First Search
void DFS(tNode* Parent);

bool DFS_V(tNode* curr, size_t count);

//Minimax Search
void MMS(tNode* Parent);

bool MMS_V(tNode* curr, size_t count);

//Playing the game, where player 1 is the computer who uses DFS to make move
void Play(Board mainBoard);

size_t comDFS(Board mainBoard);

bool comDFS_V(tNode* curr, size_t count);

//Multi Player (Human vs Human)
void MultiPlay(Board board);
```
</p>
</details>