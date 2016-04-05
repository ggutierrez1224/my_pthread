all: pthread.o queue.o main.o
	gcc -o mypthread queue.o my_pthread_t.o main.o

queue.o:
	gcc -c queue.c
pthread.o:
	gcc -c my_pthread_t.c
main:
	gcc -c main.c
clean:
	rm -rf *.o
	rm -rf mypthread
