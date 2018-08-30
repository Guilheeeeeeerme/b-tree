all:
	gcc -c src/array.c -o array.o
	gcc -c src/btree-node.c -o btree-node.o
	gcc -c src/btree.c -o btree.o
	gcc -c src/main.c -o main.o
	gcc main.o btree.o btree-node.o array.o -o main
	main.exe > result.js
clean:
	del /s /q *.o || rm -rf *.o