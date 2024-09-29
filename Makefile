dsh: dsh.o
	gcc -o dsh dsh.o

dsh.o: dsh.c
	gcc -c dsh.c

clean:
	rm -f dsh dsh.o
