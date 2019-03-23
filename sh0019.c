#include "sh0019.h"
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/wait.h>


// struct command
//    Data structure describing a command. Add your own stuff.

typedef struct command command;
struct command {
    int argc;      // number of arguments
    char** argv;   // arguments, terminated by NULL
    pid_t pid;     // process ID running this command, -1 if none
    int backgroundProcess;
    int chainCommandWithSemi;
    int commandStatus;
    int middleOperator;
    int nextOperator;
    command* nextCommand;
};
command *listHead=NULL;
command *listTail=NULL;

// command_alloc()
//    Allocate and return a new command structure.

static command* command_alloc(void) {
    command* c = (command*) malloc(sizeof(command));
    c->argc = 0;
    c->argv = NULL;
    c->pid = -1;
    c->backgroundProcess = 0;
    c->chainCommandWithSemi = 0;
    c->commandStatus = -1;
    if(listHead==NULL) {
        listHead=c;
        listTail=c;
    }
    else {
        listTail->nextCommand=c;
        listTail=c;
    }

    return listTail;
}


// command_free(c)
//    Free command structure `c`, including all its words.

static void command_free(command* c) {
    command *nextSaved;
    while (listHead != NULL) {
        for (int i = 0; i != listHead->argc; ++i) {
            free(listHead->argv[i]);
            }
        listHead = listHead -> nextCommand;

        free(c->argv);
        free(c);
        c = listHead;
    }

}


// command_append_arg(c, word)
//    Add `word` as an argument to command `c`. This increments `c->argc`
//    and augments `c->argv`.

static void command_append_arg(command* c, char* word) {
    c->argv = (char**) realloc(c->argv, sizeof(char*) * (c->argc + 2));
    c->argv[c->argc] = word;
    c->argv[c->argc + 1] = NULL;
    ++c->argc;
}


// COMMAND EVALUATION

// start_command(c, pgid)
//    Start the single command indicated by `c`. Sets `c->pid` to the child
//    process running the command, and returns `c->pid`.
//
//    PART 1: Fork a child process and run the command using `execvp`.
//    PART 5: Set up a pipeline if appropriate. This may require creating a
//       new pipe (`pipe` system call), and/or replacing the child process's
//       standard input/output with parts of the pipe (`dup2` and `close`).
//       Draw pictures!
//    PART 7: Handle redirections.
//    PART 8: The child process should be in the process group `pgid`, or
//       its own process group (if `pgid == 0`). To avoid race conditions,
//       this will require TWO calls to `setpgid`.



pid_t start_command(command* c, pid_t pgid) {
    //testing stuff
    (void) pgid;
    pid_t childFork;
    int status;

        childFork = fork();
        if (childFork == 0) {
             execvp(c->argv[0], c->argv);
         }
         else if (childFork < 0) {
            exit(-1);
        }

        
            // waitpid(c->pid, &status, 0);
            // c->commandStatus = status;
    // Your code here!
    // fprintf(stderr, "start_command not done yet\n");
    return c->pid;
   }



// run_list(c)
//    Run the command list starting at `c`.
//
//    PART 1: Start the single command `c` with `start_command`,
//        and wait for it to finish using `waitpid`.
//    The remaining parts may require that you change `struct command`
//    (e.g., to track whether a command is in the background)
//    and write code in run_list (or in helper functions!).
//    PART 2: Treat background commands differently.
//    PART 3: Introduce a loop to run all commands in the list.
//    PART 4: Change the loop to handle conditionals.
//    PART 5: Change the loop to handle pipelines. Start all processes in
//       the pipeline in parallel. The status of a pipeline is the status of
//       its LAST command.
//    PART 8: - Choose a process group for each pipeline.
//       - Call `claim_foreground(pgid)` before waiting for the pipeline.
//       - Call `claim_foreground(0)` once the pipeline is complete.

void run_list(command* c) {
    int status;
    int childFork;
    command* traverseList = c;
    pid_t childID;
    int runningStatus;
    //asdasd
    while (traverseList != NULL) {
        if (traverseList->backgroundProcess == 1) {
             start_command(traverseList, 0);

            if(traverseList->middleOperator == TOKEN_AND) {
                if( WEXITSTATUS(traverseList->commandStatus) == 0) traverseList = traverseList->nextCommand;
                else {
                    traverseList = traverseList->nextCommand->nextCommand;

                }
            }
            else if (traverseList->middleOperator == TOKEN_OR) {
                if (WEXITSTATUS(traverseList->commandStatus) != 0) traverseList = traverseList->nextCommand;
                else {
                    traverseList = traverseList->nextCommand->nextCommand;
                }
            }
            else {
                traverseList = traverseList->nextCommand;
            }

        }
        else {
            childID = start_command(traverseList, 0);
            waitpid(childID, &status, 0);

            traverseList->commandStatus = status;
            if(traverseList->middleOperator == TOKEN_AND) {
                if(traverseList->commandStatus == 0) traverseList = traverseList->nextCommand;
                else {
                    traverseList = traverseList->nextCommand->nextCommand;

                }

            }
            else if (traverseList->middleOperator == TOKEN_OR) {
                if (traverseList->commandStatus != 0) traverseList = traverseList->nextCommand;
                else {
                    traverseList = traverseList->nextCommand->nextCommand;
                }
            }
            else {
                traverseList = traverseList->nextCommand;
            }


        }
    }
    // fprintf(stderr, "run_command not done yet\n");
}



// eval_line(c)
//    Parse the command list in `s` and run it via `run_list`.

void eval_line(const char* s) {
    int type;
    char* token;
    int flag = 0;
    // fprintf(stderr, "current test string is %s\n", s );
    command* c = command_alloc();
    listTail->nextOperator = 10000;
    command* innerHead;
    command* myHead = c;
    while ((s = parse_shell_token(s, &type, &token)) != NULL) {
        // printf("token is %s \n", token);

        if (type == TOKEN_BACKGROUND || type == TOKEN_SEQUENCE || type == TOKEN_OR || type == TOKEN_AND) {
            // listTail->chainCommandWithSemi = 1;

            if (type == TOKEN_OR || type == TOKEN_AND) listTail->middleOperator = type;

            if (type == TOKEN_BACKGROUND) {
             // command_alloc();

                listTail->backgroundProcess = 1;
                innerHead = listHead;
                 while (innerHead != NULL) {

                        innerHead->backgroundProcess = 1;
                        innerHead = innerHead ->nextCommand;
                    }
             }
            command_alloc();
            if (type == TOKEN_OR || type == TOKEN_AND) listTail->nextOperator = type;

        }
        else {
            command_append_arg(listTail, token);
        }


    }
    listTail->nextOperator = 10000;

    //execute it
    // int nodeCounter = 0;
    // while (myHead != NULL) {
    //     int counter = 0;

    //     fprintf(stderr, "\nnode:%d ",nodeCounter);
    //     while(counter < myHead->argc) {
    //         fprintf(stderr, "%s",myHead->argv[counter]);
    //         counter++;
    //     }
    //     nodeCounter = nodeCounter + 1;
    //     myHead = listHead->nextCommand;
    // }

    run_list(listHead);
    command_free(listHead);
}


int main(int argc, char* argv[]) {
    FILE* command_file = stdin;
    int quiet = 0;

    // Check for '-q' option: be quiet (print no prompts)
    if (argc > 1 && strcmp(argv[1], "-q") == 0) {
        quiet = 1;
        --argc, ++argv;
    }

    // Check for filename option: read commands from file
    if (argc > 1) {
        command_file = fopen(argv[1], "rb");
        if (!command_file) {
            perror(argv[1]);
            exit(1);
        }
    }

    // - Put the shell into the foreground
    // - Ignore the SIGTTOU signal, which is sent when the shell is put back
    //   into the foreground
    claim_foreground(0);
    set_signal_handler(SIGTTOU, SIG_IGN);

    char buf[BUFSIZ];
    int bufpos = 0;
    int needprompt = 1;

    while (!feof(command_file)) {
        // Print the prompt at the beginning of the line
        if (needprompt && !quiet) {
            printf("sh0019[%d]$ ", getpid());
            fflush(stdout);
            needprompt = 0;
        }

        // Read a string, checking for error or EOF
        if (fgets(&buf[bufpos], BUFSIZ - bufpos, command_file) == NULL) {
            if (ferror(command_file) && errno == EINTR) {
                // ignore EINTR errors
                clearerr(command_file);
                buf[bufpos] = 0;
            } else {
                if (ferror(command_file)) {
                    perror("sh0019");
                }
                break;
            }
        }

        // If a complete command line has been provided, run it
        bufpos = strlen(buf);
        if (bufpos == BUFSIZ - 1 || (bufpos > 0 && buf[bufpos - 1] == '\n')) {
            eval_line(buf);
            bufpos = 0;
            needprompt = 1;
        }

        waitpid(-1, 0, WNOHANG);

        // Handle zombie processes and/or interrupt requests
        // Your code here!
    }

    return 0;
}