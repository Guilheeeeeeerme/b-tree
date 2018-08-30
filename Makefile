all:
	gcc -c src/array.c -o dist/array.o
	gcc -c src/btree-node.c -o dist/btree-node.o
	gcc -c src/btree.c -o dist/btree.o
	gcc -c src/main.c -o dist/main.o
	gcc dist/main.o dist/btree.o dist/btree-node.o dist/array.o -o main
	main.exe > result.js
clean:
	del /s /q dist\*.o || rm -rf dist/*.o