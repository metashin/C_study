CC = gcc
CFLAGS= -c -g
TARGET = program
OBJECTS =  timerr.o timerTest.o

.SUFFIXES : .c .o

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC)	-o $@	$^
	
clean :
	rm *.o $(TARGET)