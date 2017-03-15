CC = g++
SRC = ./app/main.cpp
SRC += ./src/*.cpp
LIBS = -lGL -lglut -lGLU -lpthread -lGLEW
EXEC = app.out
INC1 = ./include
INC2 = ./glm
INCDIRS   = -I${INC1} -I${INC2}
CPPFLAGS = -pthread -Wall -g $(INCDIRS)

all:
	$(CC) $(SRC) $(CPPFLAGS) -std=c++11 -o $(EXEC) $(LIBS)
clean:
	rm -rf $(EXEC) *~
