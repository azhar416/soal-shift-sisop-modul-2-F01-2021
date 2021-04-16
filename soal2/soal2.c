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

// char path[1000] = "/Users/inez_amanda/sisop/soal-shift-sisop-modul-2-F01-2021/soal2/petshop",
    //  source[1000] = "/Users/inez_amanda/Downloads/pets.zip";

char path[1000] = "/home/azhar416/soal-shift-sisop-modul-2-F01-2021/soal2/petshop/",
     source[1000] = "/home/azhar416/sisop/modul2/test2c/pets.zip";

void executeRecur (pid_t pid, int status, char script[], char *argv[]){
    pid = fork();
    if (!(pid != 0)) execv(script, argv);
    else while((wait(&status)) > 0);
}

void createFolder(pid_t mkdir, int status){
    mkdir = fork();
    if (!(mkdir != 0)) {
        char *createNewFolder[] = createProcess;
        // executeRecur(mkdir, status, "/usr/bin/mkdir", createNewFolder);
        executeRecur(mkdir, status, "/bin/mkdir", createNewFolder);
    }
    while ((wait(&status)) > 0);
}

void extractFile(pid_t extract, int status) {
    extract = fork();
    if (!(extract != 0)) {
        char *extractZipFile[] = unzipProcess;
        // executeRecur(extract, status, "/usr/bin/unzip", extractZipFile);
        executeRecur(extract, status, "/bin/unzip", extractZipFile);
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

char* cut_four (char* s){
    int n;
    int i;
    char* new;
    for (i = 0; s[i] != '\0'; i++);
    // lenght of the new string
    n = i - 4 + 1;
    if (n < 1)
        return NULL;
    new = (char*) malloc (n * sizeof(char));
    for (i = 0; i < n - 1; i++)
        new[i] = s[i];
    new[i] = '\0';
    return new;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    pid_t child_id;
    int status;

    if ((child_id = fork()) < 0) exit(EXIT_FAILURE);
    if (!(child_id != 0)) unzipFile(child_id, status);
    else 
        // while buat jaga jaga jika ada process yang punya lebih dari satu child
        while((wait(&status)) > 0); 

    DIR *dir = opendir(path);
    struct dirent *dp;

    if (dir)
    {
        while (dp = readdir(dir))
        {
            if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
            {
                char *cut = cut_four(dp->d_name);
                char *token;
                while (token = strtok_r(cut, "_", &cut))
                {
                    char hewan[100], nama[100], umur[100];
                    
                    char *temp = token;
                    char *tttoken;
                    int index = 0;
                    // printf("%s\n", token);

                    while (tttoken = strtok_r(temp, ";", &temp))
                    {
                        if (index == 0)
                        {
                            pid_t anak = fork();
                            int status;
                            
                            if (anak == 0)
                            {
                                printf("%s\n", tttoken);
                                // char temppath[100];
                                // strcpy(temppath, path);
                                // strcat(temppath, ttoken);
                                // char *argv[] = {"mkdir", "-p", temppath, NULL} ;
                                // execv("/bin/mkdir", argv);
                            } 
                            
                                // while(wait(&status) > 0);
                            
                                // strcpy(hewan, ttoken);
                        }
                        // else if (index == 1)
                        // {
                        //     // strcpy(nama, ttoken);
                        // }
                        // else if (index == 2)
                        // {
                        //     // strcpy(umur, ttoken);
                        // }
                        index++;
                    }
                    
                }
            }
        } 
        (void) closedir(dir);
    }
}
