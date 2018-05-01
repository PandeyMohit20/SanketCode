archiver: main.o CUArchive.o size.o vlarchive.o 
	gcc main.o CUArchive.o size.o vlarchive.o -o archiver
main.o: main.c
	gcc -c main.c
CUArchive.o: CUArchive.c
	gcc -c CUArchive.c
size.o: size.c
	gcc -c size.c
vlarchive.o: vlarchive.c
	gcc -c vlarchive.c
clean:	
	rm *.o archiver
