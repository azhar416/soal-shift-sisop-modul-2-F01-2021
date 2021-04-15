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
#define DIRECTORY_PATH *directory_path

void executeRecur (char script[], char *argv []){
    pid_t child_id;
    int status;

    child_id = fork();

    if (child_id == 0) execv(script, argv);
    else
        // while buat jaga jaga jika ada process yang punya lebih dari satu child
        // child jalan dluan diikuti parent
        while((wait(&status)) > 0);
}

void unzipFiles () {
    pid_t child_id;
    int status;
    char path[1000] = "/Users/inez_amanda/sisop/p2/soal2/petshop",
        source[1000] = "/Users/inez_amanda/Downloads/pets.zip";
    
    child_id = fork();
    
    if (child_id == 0) {
        // -p path
        char *newFolder[] = {"buat_folder", "-p", path, NULL};
        executeRecur("/usr/bin/mkdir", newFolder);
        
        // -d directory
        char *unzip[] = {"unzip_file", "-d", path, source, NULL};
        executeRecur("/usr/bin/unzip", unzip);
        
        DIR *fd = opendir(path);
        struct dirent DIRECTORY_PATH;
        if (fd != NULL) {
            while (((directory_path) = readdir(fd)) != NULL) { // Loop through each file in the directory
            // Recurse into subdirectory if found
                if ((&DIRECTORY_PATH) -> d_type == DT_DIR){
                    char base[1000] = "/Users/inez_amanda/sisop/p2/soal2/petshop/";
                    strcat(base, (&DIRECTORY_PATH) -> d_name);
                    char *argv3[] = {"remove", "-rf", base, NULL};
                    executeRecur("/usr/bin/rm", argv3);
                }
            }
        }
    }
    else while ((wait(&status)) > 0);
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
        unzipFiles();
    } else {
        // while buat jaga jaga jika ada process yang punya lebih dari satu child
        // child jalan dluan diikuti parent
        while((wait(&status)) > 0);
    }
}
