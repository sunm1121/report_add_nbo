# Makefile

CC = g++
CFLAGS = -Wall -Wextra -std=c++11

TARGET = add-nbo

SOURCE = add-nbo.cpp

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET)
