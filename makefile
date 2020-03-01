runMain:
	g++ main.cpp Board.cpp State.cpp Functions.cpp -o main
	./main
	rm -rf main

deleteAll:
	rm -rf main

