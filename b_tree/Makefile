all:
	gcc -c array.c -o array.o
	gcc -c btree-node.c -o btree-node.o
	gcc -c btree.c -o btree.o
	gcc -c main.c -o main.o
	gcc main.o btree.o btree-node.o array.o -o main
	./main
clean:
	del /s /q *.o || rm -rf *.o