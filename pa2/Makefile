# July 23, 2008
# Name: Mark Redekopp
# email: redekopp@usc.edu

CC = g++
CFLAGS = -g -Wall
LDFLAGS =
SRCS =  chromakey.cpp bmplib.cpp
OBJ = $(SRCS:.cpp=.o)
TARGET = chromakey


all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

.cpp.o:
	$(CC) $(CFLAGS) -c $<

bmplib.o : bmplib.h

clean:
	rm -f *.o $(TARGET) *~

