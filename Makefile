all:
	gcc -c src/main.c -o dist/main.o
	gcc dist/main.o -o main
clean:
	del /s /q dist/* || rm -rf dist/*