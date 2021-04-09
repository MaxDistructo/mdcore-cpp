SOURCE	= mdcore/obj/*.cpp
HEADER	= mdcore/obj/*.h
OUT	= mdcore.o
CC	 = g++-10
FLAGS	 = -g -c -Wall
LFLAGS	 = -lpthread

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

mdcore/obj/*.o: mdcore/obj/*.cpp
	$(CC) $(FLAGS) mdcore/obj/*.cpp -Ilib -std=c++17 -pthread -lz -lssl -lcrypto


clean:
	rm -f $(OBJS) $(OUT)