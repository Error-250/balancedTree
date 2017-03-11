all : tree.o adjusttree.o queue.o main.o
	gcc -o main tree.o adjusttree.o queue.o main.o

main.o : main.c
	gcc -c main.c
tree.o : tree.c tree.c
	gcc -c tree.c
adjusttree.o : adjusttree.c adjusttree.h
	gcc -c adjusttree.c
queue.o : util/queue.c util/queue.h
	gcc -c util/queue.c

clean : tree.o adjusttree.o queue.o main.o
	rm tree.o adjusttree.o queue.o main.o