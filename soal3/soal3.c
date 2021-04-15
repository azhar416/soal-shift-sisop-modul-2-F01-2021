#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <wait.h>
#include <sys/prctl.h>
#include <stdbool.h>
#include <syslog.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char* argv[]){
    char curr[40];
    
    while(1){
        pid_t child_id;
        time_t s1 = time(NULL);
        struct tm* t1= localtime(&s1);
        strftime(curr, 40, "%Y-%m-%d_%H:%M:%S" , t1);

        child_id = fork();
        if (child_id < 0){
            exit(0);
        }
        if(child_id==0){
            char *argv[] = {"mkdir", curr, NULL};
            execv("/bin/mkdir", argv);
        }
        sleep(40);
    }
}
