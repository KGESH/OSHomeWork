CC = g++
CFLAGS = -W -Wall
TARGET = main
OBJS = main.o makeinputfile.o firstfit.o bestfit.o nextfit.o
 
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -g -o $(TARGET) $(OBJS)
	rm *.o

makeinputfile.o : makeinputfile.cpp
	$(CC) $(CFLAGS) -g -c -o makeinputfile.o makeinputfile.cpp

firstfit.o : firstfit.cpp
	$(CC) $(CFLAGS) -g -c -o firstfit.o firstfit.cpp

bestfit.o : bestfit.cpp
	$(CC) $(CFLAGS) -g -c -o bestfit.o bestfit.cpp

nextfit.o : nextfit.cpp
	$(CC) $(CFLAGS) -g -c -o nextfit.o nextfit.cpp



main.o : main.cpp
	$(CC) $(CFLAGS) -g -c -o main.o main.cpp


clean:
	rm *.o
