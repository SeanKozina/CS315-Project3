OBJS	= Main.o project3.o
SOURCE	= Main.cpp project3.cpp
HEADER	= project3.hpp
OUT	= exe
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

Main.o: Main.cpp
	$(CC) $(FLAGS) Main.cpp 

project3.o: project3.cpp
	$(CC) $(FLAGS) project3.cpp 


clean:
	rm -f $(OBJS) $(OUT)
