# give_me_my_gems

## Author

Ekramul Sawrid

# Contributors

Prof. Chi-Him "Timmy" Liu

# Operating System

Ubuntu

# Summery 

This program is based of the board game Mancala. The rules are the same. There is multiple modes: multiplayer and playing against computer (breath-first search, dept-first search, and min-max search modes). The games stops once a player wins.

# Code Summery

There is a board, state, and tree class. The state class has a has-a relation with the board class and this enables the  board to have different "states". The tree class has a has-as relation with the state class. Using all this, the tree will grow so graph search can be used to find a winning state. 