all: edit
	./main

edit: State.o Rule.o main.o
	g++ -Wall -Wextra -Werror -o main State.o Rule.o main.o

main.o: main.cpp
	g++ -Wall -Wextra -Werror -c main.cpp

%.o: %.cpp %.h
	g++ -c $*.cpp

.PHONY: clean
clean:
	$(RM) *.o main
