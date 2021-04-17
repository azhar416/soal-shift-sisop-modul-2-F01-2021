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
int signals;

void daemons()
{
	pid_t pid, sid;
    pid = fork();
    if(pid < 0) exit(EXIT_FAILURE);
    if(pid > 0) exit(EXIT_SUCCESS);
    umask(0);
    sid = setsid();
    if(sid < 0) exit(EXIT_FAILURE);
    //if((chdir("/")) < 0) exit(EXIT_FAILURE);
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
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

void orphan(int signum) {
    signals = 0;
}

int main(int argc, char* argv[])
{
    int killstatus;
    if(strcmp(argv[1],"-z")==0){
        FILE *ptr2 = NULL;
        ptr2 = fopen("killer.sh","w");
        fputs("#!/bin/bash\nkillall soal3\n rm killer.sh",ptr2);
        fclose(ptr2);
    }
    if(strcmp(argv[1],"-x")==0){ 
        FILE *ptr2 = NULL;
        ptr2 = fopen("killer.sh","w");
        fputs("#!/bin/bash\nkillall -15 soal3\n rm killer.sh",ptr2);
        fclose(ptr2);
        signal(SIGTERM,orphan);
     }
    while(wait(&killstatus)>0);

    //awalan
    if(argc != 2 || (argv[1][1] != 'z' && argv[1][1] != 'x')) 
    {
        printf("menu -z atau -x\n");
        exit(0);
    }
    int status, status1, status2, status3;

    daemons();
    signals = 1;
    while(signals)
    {
        // 3a. Membuat mkdir dengan waktu sesuai soal
        pid_t child_id;
        time_t s1 = time(NULL);
        struct tm* t1= localtime(&s1);
        strftime(curr, 40, "%Y-%m-%d_%H:%M:%S" , t1);

        child_id = fork();
        if (child_id < 0)
        {
            exit(0);
        }
        if(child_id==0)
        {
            char *argv[] = {"mkdir", curr, NULL};
            execv("/bin/mkdir", argv);
        }

        //3b download 10 foto dengan ukuran yang sudah ditentukan
        while(wait(&status1)>0);
        int status_id;
        char link[50];
        pid_t child_id2, child_id3;
        child_id2 = fork();
        if(child_id2<0)
        {
            exit(0);
        }
        if(child_id2 == 0)
        {
            if(argv[1][1] == 'z') prctl(PR_SET_PDEATHSIG, SIGHUP);
            chdir(curr);
            for(int i=0;i<10;i++){
                time_t s2 = time(NULL);
                struct tm* t2= localtime(&s2);
                strftime(curr2, 40, "%Y-%m-%d_%H:%M:%S", t2);
                sprintf(link , "https://picsum.photos/%ld", (s2 % 1000) + 50);
                
                child_id3 = fork();
                if(child_id3<0)
                {
                    exit(0);
                }
                if(child_id3==0)
                {
                    char *argv[]= {"wget", link, "-O", curr2, "-o", "/dev/null", NULL};
                    execv("/usr/bin/wget", argv);
                }
                sleep(5);
            }

            while(wait(&status_id)>0);
            char str_message[100] = "Download Success";

            //3c. Caesar cipher shift 5
            for(int j = 0; str_message[j] != '\0'; ++j)
            {
                char ch = str_message[j];

                if(ch >= 'a' && ch <= 'z')
                {
                    ch = ch + 5;
                    if(ch > 'z')
                    {
                        ch = ch - 'z' + 'a' - 1;
                    }
                    str_message[j] = ch;
                }

                else if(ch >= 'A' && ch <= 'Z')
                {
                    ch = ch + 5;
                    if(ch > 'Z')
                    {
                        ch = ch - 'Z' + 'A' - 1;
                    }
                    str_message[j] = ch;
                }
            }
            
            FILE* caesarc = fopen("status.txt", "w");
            fprintf(caesarc,"%s",str_message);
            fclose(caesarc);

            while(wait(&status2)>0);
            zipmode();

            while(wait(&status3) > 0);
            hapus();
        }
        if (signals ==0) {
            break;
        }
        sleep(40);
    }
}
