CPPFLAGS = -std=c++11 -Wall
CC = g++

TARGET = a
SOURCE = whatapp

$(TARGET).out: 
	$(CC) $(CPPFLAGS) -o $(TARGET).out $(SOURCE).cpp

clean:
	$(RM) $(TARGET).out


