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

#define copyProcess {"cp", source, path, NULL};

// char path[1000] = "/Users/inez_amanda/sisop/soal-shift-sisop-modul-2-F01-2021/soal2/petshop",
    //  source[1000] = "/Users/inez_amanda/Downloads/pets.zip",
    //  destFolder[1000] = "/Users/inez_amanda/sisop/soal-shift-sisop-modul-2-F01-2021/soal2/petshop/",
    //  fileOutput[1000] = "/Users/inez_amanda/sisop/soal-shift-sisop-modul-2-F01-2021/soal2/petshop/",
    //  destination[1000] =  "/Users/inez_amanda/sisop/soal-shift-sisop-modul-2-F01-2021/soal2/petshop/",
    //  source1[1000] = "/Users/inez_amanda/sisop/soal-shift-sisop-modul-2-F01-2021/soal2/petshop/",
    //  source2[1000] = "/Users/inez_amanda/sisop/soal-shift-sisop-modul-2-F01-2021/soal2/petshop/";

char path[1000] = "/home/azhar416/soal-shift-sisop-modul-2-F01-2021/soal2/petshop/",
     source[1000] = "/home/azhar416/Downloads/pets.zip";

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
        // executeRecur(mkdir, status, "/bin/mkdir", createNewFolder);
    }
    while ((wait(&status)) > 0);
}

void extractFile(pid_t extract, int status) {
    extract = fork();
    if (!(extract != 0)) {
        char *extractZipFile[] = unzipProcess;
        executeRecur(extract, status, "/usr/bin/unzip", extractZipFile);
        // executeRecur(extract, status, "/bin/unzip", extractZipFile);
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

int isFolder(char* path){
    DIR *folder = opendir(path);
    if(folder){
        closedir(folder);
        return 1;
    }
    return 0;
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
    // char destFolder[1000] = "/Users/inez_amanda/sisop/soal-shift-sisop-modul-2-F01-2021/soal2/petshop/";
    if (dir)
    {
        while (dp = readdir(dir))
        {
            if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
            {
                if (fork() == 0) continue;
                
                // char cekfolder[1000];
                // strcpy(cekfolder, path);
                // strcat(cekfolder, dp->d_name);
                // // printf("%d\n", isFolder(cekfolder));
                // if(isFolder(cekfolder)) exit(EXIT_SUCCESS);

                if (dp->d_type & DT_DIR) exit(EXIT_SUCCESS);                

                char *cut = strtok(dp->d_name, ";");
                char folder[1000];
                char *token;
                strcpy(folder, path);
                strcat(folder, "/");
                strcat(folder, cut);

                pid_t anak = fork();
                if(anak==0){
                    char *newFolder[] = {"mkdir", "-p", folder, NULL};
                    execv("/usr/bin/mkdir", newFolder);
                }
                else
                {
                    while (wait(NULL) > 0);
                }
                
                char *cutt = cut_four(dp->d_name);
                // while(wait(NULL) > 0);
                while (token = strtok_r(cutt, "_", &cutt))
                {
                    // printf("%s\n", token);

                    char hewan[100], nama[100], umur[100];
                    
                    char *temp = token;
                    char *ttoken;
                    int index = 0;


                    while (ttoken = strtok_r(temp, ";", &temp))
                    {
                        if (index == 0)
                        {
                            // printf("%s\n", ttoken);
                            strcpy(hewan, ttoken);
                        }
                        else if (index == 1)
                        {
                            strcpy(nama, ttoken);
                        }
                        else if (index == 2)
                        {
                            strcpy(umur, ttoken);
                        }
                        index++;
                    }

                    pid_t anaknyalagi = fork();
                    if(anaknyalagi == 0)
                    {
                        // printf("MASUK ANYING!\n");
                        // path/petshop/[file].jpg
                        char source[1000];
                        strcpy(source, path);
                        strcat(source, dp->d_name);
                        printf("%s\n", dp->d_name);

                        // path/petshop/[jenishewan]/[namahewan].jpg
                        char dest[1000];
                        strcpy(dest, path);
                        strcat(dest, hewan);
                        strcat(dest, ".jpg");

                        char *argcp[] = {"cp", source, dest, NULL};
                        execv("/bin/cp", argcp);

                    }
                    while (wait(NULL) > 0);
                    char text[1000] = "Nama : "; strcat(text, nama);
                    strcat(text, "\nUmur : "); strcat(text, umur);
                    strcat(text, " Tahun\n\n");

                    char f[1000];
                    strcpy(f, path);
                    strcat(f, hewan);
                    strcat(f, "/keterangan.txt");
                    FILE* files = fopen(f, "a");
                    fputs(text, files);
                    fclose(files);
                    exit(EXIT_SUCCESS);
                }  
            }
        } 
        (void) closedir(dir);
    }
}
