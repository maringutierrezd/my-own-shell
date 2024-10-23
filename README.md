# my-own-shell
Creating my own, very simplified Shell in C: DummyShell (dsh)

## Features
 * Simple, dummy shell to run all shell programs (and some builtins)

## Limitations
 * No piping
 * No quoting arguments
 * All commands must be one the same, single line
 * No i/o redirection
 * All arguments must be separated by whitespace and by whitespace only
 * All builtins not explicitly mentioned

## Builtins done
 * cd
 * exit

# How to run
Use `make` to compile and `./dsh` to run.
