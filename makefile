#Compiler to use 
CC=g++

binarytree:
	g++ -o main main.cpp binarytree.cpp test1.cpp
	./main.exe
	
clean:
	\rm *.exe
	
