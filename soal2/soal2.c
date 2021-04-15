//
//  soal2.c
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

// -p (parent) buat parent direktori jika dibutuhkan, klo sudah ada aman kok
#define createProcess {"buat_folder", "-p", path, NULL}

// -x (exclude) */* -d (cth : /petshop/apex) jadi mengecualikan folder dalam source
#define unzipProcess {"unzip_file", "-qq", source, "-x", "*/*", "-d", path, NULL}

char path[1000] = "/Users/inez_amanda/sisop/soal-shift-sisop-modul-2-F01-2021/soal2/petshop",
     source[1000] = "/Users/inez_amanda/Downloads/pets.zip";

void executeRecur (pid_t pid, int status, char script[], char *argv[]){
    pid = fork();
    if (!(pid != 0)) execv(script, argv);
    else while((wait(&status)) > 0);
}

void createFolder(pid_t mkdir, int status){
    mkdir = fork();
    if (!(mkdir != 0)) {
        char *createNewFolder[] = createProcess;
        executeRecur(mkdir, status, "/usr/bin/mkdir", createNewFolder);
    }
    while ((wait(&status)) > 0);
}

void extractFile(pid_t extract, int status) {
    extract = fork();
    if (!(extract != 0)) {
        char *extractZipFile[] = unzipProcess;
        executeRecur(extract, status, "/usr/bin/unzip", extractZipFile);
    }
    while ((wait(&status)) > 0);
}

void unzipFile(pid_t child_id, int status){
    child_id = fork();
    if (!(child_id != 0)) createFolder(child_id, status); // buat folder baru di path yang ditentukan
    else {
        while((wait(&status)) > 0);
        extractFile(child_id, status);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    pid_t child_id;
    int status;

    if ((child_id = fork()) < 0) exit(EXIT_FAILURE);
    if (!(child_id != 0)) unzipFile(child_id, status);
    else while((wait(&status)) > 0); // while buat jaga jaga jika ada process yang punya lebih dari satu child
}
