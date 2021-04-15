//
//  main.c
//  soal2
//
//  Created by Inez Amanda on 13/04/21.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <syslog.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <unistd.h>
#define createProcess {"buat_folder", "-p", path, NULL}
#define unzipProcess {"unzip_file", "-qq", source, "-x", "*/*", "-d", path, NULL}

void executeRecur (char script[], char *argv[]){
    pid_t child_id;
    child_id = fork();

    int status;

    if (child_id == 0) execv(script, argv);
    else while((wait(&status)) > 0);
}

void createFolder(char path[]){
    char *createNewFolder[] = createProcess;
    executeRecur("/usr/bin/mkdir", createNewFolder);
}

void unzip(char source[], char path[]) {
    char *unzipTheZipFile[] = unzipProcess;
    executeRecur("/usr/bin/unzip", unzipTheZipFile);
}

void unzipFile(){
    pid_t child_id;
    child_id = fork();

    char path[1000] = "/Users/inez_amanda/sisop/soal-shift-sisop-modul-2-F01-2021/soal2/petshop",
         source[1000] = "/Users/inez_amanda/Downloads/pets.zip";
         
    int status;

    if (!(child_id != 0)) createFolder(path);
    while((wait(&status)) > 0);

    if (!(child_id != 0)) unzip(source, path);
    while((wait(&status)) > 0);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    pid_t child_id;
    int status;

    child_id = fork();

    if (child_id < 0) {
      exit(EXIT_FAILURE);
    }

    if (child_id == 0) {
        unzipFile();
    } else
        // while buat jaga jaga jika ada process yang punya lebih dari satu child
        // child jalan dluan diikuti parent
        while((wait(&status)) > 0);
}
