dsh: dsh.o builtin-commands.o
	gcc -o dsh dsh.o builtin-commands.o

dsh.o: dsh.c builtin-commands.h
	gcc -c dsh.c

builtin-commands.o: builtin-commands.c builtin-commands.h
	gcc -c builtin-commands.c

clean:
	rm -f dsh dsh.o builtin-commands.o
