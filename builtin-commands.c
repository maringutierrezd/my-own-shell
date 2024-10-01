#include <stdio.h>
#include <unistd.h>

#include "builtin-commands.h"

char* builtin_str[] = {
    "cd"
};

int (*builtin_func[]) (char**) = {
    &dsh_cd,
};

int N_builtins(void) {
    return sizeof(builtin_str) / sizeof(char*);
}

int dsh_cd(char** args) {
    // Check if an argument for the path or folder to change was given
    if (args[1] == NULL) {
        fprintf(stderr, "dsh: expected argument to \"cd\"\n");
    }
    else {
        // We change to the folder with syscall chdir
        int chdir_ret = chdir(args[1]);
        if (chdir_ret != 0) {
            perror("dsh");
        }
    }
    return 1;
}
