CC = g++
CFLAGS = -W -Wall
TARGET = main
OBJS = main.o makeinputfile.o firstfit.o bestfit.o

$(TARGET): main.o makeinputfile.o firstfit.o bestfit.o
	$(CC) $(CFLAGS) -g -o $(TARGET) $(OBJS)
	rm *.o

makeinputfile.o : makeinputfile.cpp
	$(CC) $(CFLAGS) -g -c -o makeinputfile.o makeinputfile.cpp

firstfit.o : firstfit.cpp
	$(CC) $(CFLAGS) -g -c -o firstfit.o firstfit.cpp

bestfit.o : bestfit.cpp
	$(CC) $(CFLAGS) -g -c -o bestfit.o bestfit.cpp

main.o : main.cpp
	$(CC) $(CFLAGS) -g -c -o main.o main.cpp


clean:
	rm *.o
