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

char curr[40],curr2[40], curr3[40];

void download()
{
    char link[50];
    pid_t child_id2, child_id3;
    child_id2 = fork();
        if(child_id2<0){
            exit(0);
        }
        if(child_id2 == 0){
            chdir(curr);
            for(int i=0;i<10;i++){
                time_t s2 = time(NULL);
                struct tm* t2= localtime(&s2);
                strftime(curr2, 40, "%Y-%m-%d_%H:%M:%S", t2);
                sprintf(link , "https://picsum.photos/%ld", (s2 % 1000) + 100);
                
                child_id3 = fork();
                if(child_id3<0){
                    exit(0);
                }
                if(child_id3==0){
                    char *argv[]= {"wget", link, "-O", curr2, "-o", "/dev/null", NULL};
                    execv("/usr/bin/wget", argv);
                }
                sleep(5);
            }

        }
}

void zipmode()
{
    pid_t child_id4;
    chdir("..");
    strcpy(curr3, curr);
    strcat(curr3, ".zip");

    child_id4 = fork();
    if(child_id4 < 0) exit(0);
    if(child_id4 == 0)
    {
        char *argv[] = {"zip", "-r", curr3, curr, NULL};
        execv("/usr/bin/zip", argv);
    }
}

void hapus(){
    pid_t child_id5;
    child_id5 = fork();
	if(child_id5 < 0) exit(0);
    if(child_id5 == 0)
    {
        char *argv[] = {"rm", "-r", curr, NULL};
    	execv("/bin/rm", argv);
    }
}

int main(int argc, char* argv[]){

    int status1, status2, status3;

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

        while(wait(&status1)>0);
        download();

        while(wait(&status2)>0);
        zipmode();

        while(wait(&status3) > 0);
        hapus();

        
        sleep(40);
    }
}
