#include "Board.h"
#include "State.h"

//EKRAMUL SAWRID
//MANCALA GAME

#include <queue>
#include <stack>

//Breath-First Search
//PreCondition: tNode that you want to preform breath-first search on
//PostCondition: prints all the tNodes that function went through and the number of tNodes it went through
void BFS(tNode* Parent);

//Dept-First Search
//PreCondition: tNode that you want to preform dept-first search on
//PostCondition: prints all the tNodes that function went through and the number of tNodes it went through
//NOTE: These two function work together and DRS_V depends on DFS and vice-versa
void DFS(tNode* Parent);

bool DFS_V(tNode* curr, size_t count);

//Minimax Search
//PreCondition: tNode that you want to preform A-star search on
//PostCondition: prints all the tNode that functions went through and the number of tNodes it went through
//NOTE: These two functions work together and MMS_V depends on ASF and vice-versa
void MMS(tNode* Parent);

bool MMS_V(tNode* curr, size_t count);

//Playing the game, where player 1 is the computer who uses DFS to make move
//NOTE: These three functions depend on each other.
//PreCondition: board that you want as your starting state.
//PostCondition: You  play the game, versing the computer. You are player 2 and the computer is player 1. Computer goes first.
void Play(Board mainBoard);

size_t comDFS(Board mainBoard);

bool comDFS_V(tNode* curr, size_t count);

//Multi Player (Human vs Human)
void MultiPlay(Board board);

