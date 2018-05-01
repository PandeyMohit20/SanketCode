organizer: main.o Organize.o DestinationName.o
	gcc main.o Organize.o DestinationName.o -o organizer
main.o: main.c
	gcc -c main.c
Organize.o: Organize.c
	gcc -c Organize.c
DestinationName.o: DestinationName.c
	gcc -c DestinationName.c
clean:
	rm *.o organizer
