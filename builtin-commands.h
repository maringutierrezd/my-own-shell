#ifndef BUILTIN_COMMANDS_H
#define BUILTIN_COMMANDS_H

extern char* builtin_str[];
extern int (*builtin_func[]) (char **);
int N_builtins(void);

int dsh_cd(char** args);

#endif
