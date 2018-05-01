all: shell402 create list
shell402: shell402.o shellFunctions.o input.o
	gcc shell402.o shellFunctions.o input.o -o shell402
list: list.o listFunctions.o
	gcc list.o listFunctions.o -o list
create: create.o createFunctions.o
	gcc create.o createFunctions.o -o create
clean:
	rm *.o shell402 create list

