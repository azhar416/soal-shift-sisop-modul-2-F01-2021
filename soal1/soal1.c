#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>

void mekdir()
{
    pid_t mkdir3;
    int status;

    mkdir3 = fork();
    if (mkdir3 == 0) {
        pid_t mkdir2;
        int status;

        mkdir2 = fork();
        if (mkdir2 == 0) 
        {
            char *argv2[] = {"mkdir", "-p", "/home/azhar416/soal-shift-sisop-modul-2-F01-2021/soal1/Pyoto", NULL};
            execv("/bin/mkdir", argv2);
        } 
        else 
        {
            while (wait(&status) > 0);
            char *argv1[] = {"mkdir", "-p", "/home/azhar416/soal-shift-sisop-modul-2-F01-2021/soal1/Myusik", NULL};
            execv("/bin/mkdir", argv1);
        }
    } 
    else 
    {
        while (wait(&status) > 0);
        char *argv3[] = {"mkdir", "-p", "/home/azhar416/soal-shift-sisop-modul-2-F01-2021/soal1/Fylm", NULL};
        execv("/bin/mkdir", argv3);
    }
}

void donlot()
{
    pid_t donlot3;
    int status;

    donlot3 = fork();
    if (donlot3 == 0) {
        pid_t donlot2;
        int status;

        donlot2 = fork();
        if (donlot2 == 0) 
        {
            char *argv2[] = {"wget", "-q", "--no-check-certificate", "https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download", "-O", "Foto_for_Stevany.zip", NULL};
            execv("/bin/wget", argv2);
        } 
        else 
        {
            while (wait(&status) > 0);
            char *argv1[] = {"wget", "-q", "--no-check-certificate", "https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download", "-O", "Musik_for_Stevany.zip", NULL};
            execv("/bin/wget", argv1);
        }
    } 
    else 
    {
        while (wait(&status) > 0);
        char *argv3[] = {"wget", "-q", "--no-check-certificate", "https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download", "-O", "Film_for_Stevany.zip", NULL};
        execv("/bin/wget", argv3);
    }
}

void ekstrak()
{
    pid_t eks3;
    int status;

    eks3 = fork();
    if (eks3 == 0) {
        pid_t eks2;
        int status;

        eks2 = fork();
        if (eks2 == 0) 
        {
            char *argv2[] = {"unzip", "-qq", "Foto_for_Stevany.zip", "-d", "/home/azhar416/soal-shift-sisop-modul-2-F01-2021/soal1/Pyoto/", NULL};
            execv("/bin/unzip", argv2);
        } 
        else 
        {
            while (wait(&status) > 0);
            char *argv1[] = {"unzip", "-qq", "Musik_for_Stevany.zip", "-d", "/home/azhar416/soal-shift-sisop-modul-2-F01-2021/soal1/Myusik/", NULL};
            execv("/bin/unzip", argv1);
        }
    } 
    else 
    {
        while (wait(&status) > 0);
        char *argv3[] = {"unzip", "-qq", "Film_for_Stevany.zip", "-d", "/home/azhar416/soal-shift-sisop-modul-2-F01-2021/soal1/Fylm/", NULL};
        execv("/bin/unzip", argv3);;    
    }
}

void copy()
{
    pid_t cp3;
    int status;

    cp3 = fork();
    if (cp3 == 0) {
        pid_t cp2;
        int status;

        cp2 = fork();
        if (cp2 == 0) 
        {
            char *argv2[] = {"cp", "-r", "/home/azhar416/soal-shift-sisop-modul-2-F01-2021/soal1/Pyoto/FOTO/.", "/home/azhar416/soal-shift-sisop-modul-2-F01-2021/soal1/Pyoto/", NULL};
            execv("/bin/cp", argv2);
        } 
        else 
        {
            while (wait(&status) > 0);
            char *argv1[] = {"cp", "-r", "/home/azhar416/soal-shift-sisop-modul-2-F01-2021/soal1/Myusik/MUSIK/.", "/home/azhar416/soal-shift-sisop-modul-2-F01-2021/soal1/Myusik/", NULL};
            execv("/bin/cp", argv1);
        }
    } 
    else 
    {
        while (wait(&status) > 0);
        char *argv3[] = {"cp", "-r", "/home/azhar416/soal-shift-sisop-modul-2-F01-2021/soal1/Fylm/FILM/.", "/home/azhar416/soal-shift-sisop-modul-2-F01-2021/soal1/Fylm/", NULL};
        execv("/bin/cp", argv3); 
    }
}

void ngapus()
{
    pid_t rm3;
    int status;

    rm3 = fork();
    if (rm3 == 0) {
        pid_t rm2;
        int status;

        rm2 = fork();
        if (rm2 == 0) 
        {
            char *argv2[] = {"rm", "-rf", "/home/azhar416/soal-shift-sisop-modul-2-F01-2021/soal1/Pyoto/FOTO", NULL};
            execv("/bin/rm", argv2);
        } 
        else 
        {
            char *argv1[] = {"rm", "-rf", "/home/azhar416/soal-shift-sisop-modul-2-F01-2021/soal1/Myusik/MUSIK", NULL};
            execv("/bin/rm", argv1);
        }
    } 
    else 
    {
        while (wait(&status) > 0);
        char *argv3[] = {"rm", "-rf", "/home/azhar416/soal-shift-sisop-modul-2-F01-2021/soal1/Fylm/FILM", NULL};
        execv("/bin/rm", argv3);    
    }
}

void ngezip()
{
    pid_t zip3;
    int status;

    zip3 = fork();
    if (zip3 == 0) {
        
        char *argv0[] = {"zip", "-qr", "Lopyu_Stevany.zip", "/home/azhar416/soal-shift-sisop-modul-2-F01-2021/soal1/Fylm/", "/home/azhar416/soal-shift-sisop-modul-2-F01-2021/soal1/Myusik/", "/home/azhar416/soal-shift-sisop-modul-2-F01-2021/soal1/Pyoto/", NULL};
        execv("/bin/zip", argv0);
    } 
    else 
    {
        while (wait(&status) > 0);
        pid_t rem3;
        int status;

        rem3 = fork();
        if (rem3 == 0) 
        {
            pid_t rem2;
            int status;

            rem2 = fork();
            if (rem2 == 0) 
            {
                // remove Pyoto
                while (wait(&status) > 0);
                char *argv2[] = {"rm", "-rf", "/home/azhar416/soal-shift-sisop-modul-2-F01-2021/soal1/Pyoto", NULL};
                execv("/bin/rm", argv2);
            } 
            else 
            {
                // remove Myusik
                while (wait(&status) > 0);
                char *argv1[] = {"rm", "-rf", "/home/azhar416/soal-shift-sisop-modul-2-F01-2021/soal1/Myusik", NULL};
                execv("/bin/rm", argv1);
            }
        } 
        else 
        {
            // remove Fylm
            while (wait(&status) > 0);
            char *argv3[] = {"rm", "-rf", "/home/azhar416/soal-shift-sisop-modul-2-F01-2021/soal1/Fylm", NULL};
            execv("/bin/rm", argv3);  
        }
    }
}

int main() 
{
    pid_t pid, sid;        
    pid = fork();     

    if (pid < 0) {
        exit(EXIT_FAILURE);
    }

    /* Keluar saat fork berhasil
    * (nilai variabel pid adalah PID dari child process) */
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    umask(0);

    sid = setsid();
    if (sid < 0) {
        exit(EXIT_FAILURE);
    }

    if ((chdir("/home/azhar416/soal-shift-sisop-modul-2-F01-2021/soal1/")) < 0) 
    {
        exit(EXIT_FAILURE);
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    while (1) 
    {
        char tgl[100];
        time_t sekon = time(NULL);
        struct tm time = *localtime(&sekon);
        strftime(tgl, sizeof(tgl), "%d-%m_%H:%M", &time);
        // Tulis program kalian di sini
        if (strcmp(tgl, "09-04_16:22") == 0)
        {
            pid_t child1;
            int status;
    
            child1 = fork();
    
            if (child1 < 0) {
                exit(EXIT_FAILURE); 
            }
    
            if (child1 == 0) 
            {
                id_t child2;
                int status;
    
                child2 = fork();
                if (child2 == 0) 
                {
                    id_t child3;
                    int status;
    
                    child3 = fork();
                    if (child3 == 0) 
                    {
                        id_t child4;
                        int status;
    
                        child4 = fork();
                        if (child4 == 0)
                        {
                            mekdir();
                        } 
                        else 
                        {
                            while (wait(&status) > 0);
                            donlot();
                        }
                    } 
                    else 
                    {
                        while (wait(&status) > 0);
                        sleep(10);
                        ekstrak();
                    }
                } 
                else 
                {
                    while (wait(&status) > 0);
                    copy();
                }
            } 
            else
            {
                while (wait(&status) > 0);
                
                pid_t debug = fork();
                int status;

                if (debug == 0)
                {
                    ngapus();
                }
                else
                {
                    while (wait(&status) > 0);
                }
            }
        }
        else if (strcmp(tgl, "09-04_22:22") == 0)
        {
            pid_t debug = fork();
            int status;

            if (debug == 0)
            {
                ngezip();
            }
            else
            {
                while (wait(&status) > 0);
            }
        }
        sleep(1);
    }
}