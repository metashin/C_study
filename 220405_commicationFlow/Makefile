CC = gcc
CFLAGS= -c -g
TARGET = program
OBJECTS = commP.o main.o

.SUFFIXES : .c .o

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC)	-o $@	$^
	
clean :
	rm *.o $(TARGET)