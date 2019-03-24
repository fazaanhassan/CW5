## COMP0019 CW5 Grade Report
Report for commit SHA: 6441e13a3fdb2a212c582400f4afbeb3188ebef3

### Output


    
      CLEAN 
      COMPILE sh0019.c
    sh0019.c: In function command_free:
    sh0019.c:54:14: warning: unused variable nextSaved [-Wunused-variable]
         command *nextSaved;
                  ^
    sh0019.c: In function run_list:
    sh0019.c:143:24: warning: declaration of c shadows a parameter [-Wshadow]
     void run_list(command* c) {
                            ^
    sh0019.c:99:30: note: shadowed declaration is here
     pid_t start_command(command* c, pid_t pgid) {
                                  ^
    sh0019.c:144:9: warning: declaration of status shadows a previous local [-Wshadow]
         int status;
             ^
    sh0019.c:103:9: note: shadowed declaration is here
         int status;
             ^
    sh0019.c:145:9: warning: declaration of childFork shadows a previous local [-Wshadow]
         int childFork;
             ^
    sh0019.c:102:11: note: shadowed declaration is here
         pid_t childFork;
               ^
    sh0019.c:145:9: warning: unused variable childFork [-Wunused-variable]
         int childFork;
             ^
    sh0019.c: In function eval_line:
    sh0019.c:232:14: warning: declaration of c shadows a parameter [-Wshadow]
         command* c = command_alloc();
                  ^
    sh0019.c:99:30: note: shadowed declaration is here
     pid_t start_command(command* c, pid_t pgid) {
                                  ^
    sh0019.c:235:14: warning: unused variable myHead [-Wunused-variable]
         command* myHead = c;
                  ^
    sh0019.c:230:9: warning: unused variable flag [-Wunused-variable]
         int flag = 0;
             ^
    sh0019.c: In function start_command:
    sh0019.c:286:5: warning: main is normally a non-static function [-Wmain]
     int main(int argc, char* argv[]) {
         ^
    sh0019.c:352:1: error: expected declaration or statement at end of input
     }
     ^
    sh0019.c:104:9: warning: unused variable pipeCounter [-Wunused-variable]
         int pipeCounter = 0;
             ^
    sh0019.c:103:9: warning: unused variable status [-Wunused-variable]
         int status;
             ^
    GNUmakefile:9: recipe for target 'sh0019.o' failed
    make: *** [sh0019.o] Error 1


### Marking

Bad format

