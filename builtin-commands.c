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
}
