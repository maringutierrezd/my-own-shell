#include <stdio.h>
#include <stdlib.h>


#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"
char** split_line(char* line) {
    // Variable declaration
    int bufsize = TOK_BUFSIZE;
    int position = 0;
    char** tokens = malloc(bufsize * sizeof(char*));
    char* token;

    if (!tokens) {
        fprintf(stderr, "dsh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, TOK_DELIM);
    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += TOK_BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char*));

            if (!tokens) {
                fprintf(stderr, "dsh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, TOK_DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}

#define RL_BUFSIZE 256
char* read_line(void) {
    // Variable declaration
    int bufsize = RL_BUFSIZE;
    int position = 0;
    char *buffer = malloc(sizeof(char) * bufsize);
    int c;  // The char that we will read. It has to be of type int, not char, because EOF is an int, and we want to be able to detect it

    if (!buffer) {
        fprintf(stderr, "dsh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Read a char (as an int)
        c = getchar();

        // If we hit EOF, replace it with the null char and return the buffer
        if (c == EOF || c == '\n') {
            buffer[position] = '\0';
            return buffer;
        }
        else {
            buffer[position] = c;
        }
        position++;

        // Check if we have exceeded the buffer size, and reallocate memory if needed
        if (position >= bufsize) {
            bufsize += RL_BUFSIZE;
            buffer = realloc(buffer, bufsize);

            // Check again for memory allocation errors
            if (!buffer) {
                fprintf(stderr, "dsh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

void dsh_loop(void) {
    // Variable declaration
    char* line;
    char** args;
    int status;

    // Main loop of the shell
    do {
        printf("dsh> ");
        line = read_line();
        args = split_line(line);
        status = execute_line(args);

        free(line);
        free(args);
    } while (status);
}


int main(int argc, char** argv) {
    // Execute the main loop of the shell
    dsh_loop();

    return EXIT_SUCCESS;
}