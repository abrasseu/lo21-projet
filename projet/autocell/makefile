all: edit

edit: SimulatorException.o Simulator.o Simulator1D.o Simulator2D.o SimulatorManager.o State.o Rule.o main.o
	g++ -g -std=c++11 -Wall -Wextra -Werror -o main SimulatorException.o Simulator.o Simulator1D.o Simulator2D.o SimulatorManager.o State.o Rule.o main.o

main.o: main.cpp
	g++ -g -std=c++11 -Wall -Wextra -Werror -c main.cpp

%.o: %.cpp %.h
	g++ -g -std=c++11 -c $*.cpp

.PHONY: clean
clean:
	$(RM) *.o *.ghb main
