all: quadratka.exe

CC := g++
CXXFLAGS := -Wall  

SRC := quadratka.cpp test.cpp main.cpp
OBJ := $(SRC:.cpp=.o)

%.o: %.c
	$(CC) $(CXXFLAGS) $< -c

quadratka.exe: $(OBJ)
	$(CC) $^ -o $@

clean:
	rm *.o 
