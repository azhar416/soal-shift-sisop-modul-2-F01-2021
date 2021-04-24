//
//  soal2.c
//  soal2
//
//  Created by Inez Amanda on 13/04/21.
//  sama Daffa M Azhar jgn lupa.
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
#define unzipProcess {"unzip_file", "-qq", source, "-x", "*/*", "-d", path, NULL};

// char path[1000] = "/Users/inez_amanda/sisop/soal-shift-sisop-modul-2-F01-2021/soal2/petshop/",
//      source[1000] = "/Users/inez_amanda/Downloads/pets.zip";

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
    else {
        // while buat jaga jaga jika ada process yang punya lebih dari satu child
        while((wait(&status)) > 0); 
        DIR *dir = opendir(path);
        struct dirent *dp;
        if (dir){
            while ((dp = readdir(dir)) != NULL){
                // while(wait(NULL) > 0);
                // ini buat bolak balik masuk folder sama keluar
                if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0){
                    // if (fork() == 0) continue;

                    char namafile[1000];
                    // dp -> d_name masih nama file yg cat;ava;6_dog;joni;8.jpg
                    strcpy(namafile, dp->d_name);
                    // buat token untuk setiap jenis hewan
                    char *cut = strtok(namafile, ";");
                    // printf("%s\n", namafile);
                    char folder[100];
                    strcpy(folder, path);
                    strcat(folder, "/");
                    strcat(folder, cut);

                    // FORK 1
                    pid_t anak = fork();
                    if(anak<0) exit(EXIT_FAILURE);
                    if(anak==0){
                        char *newFolder[] = {"mkdir", "-p", folder, NULL};
                        execv("/usr/bin/mkdir", newFolder);
                    }
                    else{
                        while(wait(NULL) > 0);
                        char namadir[1000];
                        strcpy(namadir, dp->d_name);
                        char *anothercut = cut_four(namadir);
                        char *token;
                        while (token == strtok_r(anothercut, "_", &anothercut)){
                            while(wait(NULL) > 0);
                            char *temp = token;
                            char *token2;
                            int i = 0;
                            char jenis[100], nama[100], umur[100];
                            while (token2 == strtok_r(temp, ";", &temp)){
                                while(wait(NULL) > 0);
                                if (i == 0){
                                    strcpy(jenis, token2);
                                }
                                if (i == 1){
                                    strcpy(nama, token2);
                                }
                                if (i == 2){
                                    strcpy(umur, token2);
                                }
                                i++;
                            }
                            // while(wait(NULL) > 0);

                            //FORK 2
                            if (fork() == 0){
                                // while(wait(NULL) > 0);
                                // path/petshop/[file].jpg
                                char sc[1000];
                                strcpy(sc, path);
                                strcat(sc, dp->d_name);
                                // printf("SC : %s\n", sc);
        
                                // path/petshop/[jenishewan]/[namahewan].jpg
                                char dest[1000];
                                strcpy(dest, path);
                                strcat(dest, jenis);
                                strcat(dest, "/");
                                strcat(dest, nama);
                                strcat(dest, ".jpg");
                                // printf("DEST : %s\n", dest);
        
                                char *argcp[] = {"cp", sc, dest, NULL};
                                execv("/bin/cp", argcp); 
                            }
                            else{
                                while(wait(NULL) > 0);
                                char isi[1000] = "Nama : ";
                                strcat(isi, nama);
                                strcat(isi, "\nUmur : ");
                                strcat(isi, umur);
                                strcat(isi, " tahun\n\n");

                                char f[1000];
                                strcpy(f, path);
                                strcat(f, jenis);
                                strcat(f, "/keterangan.txt");
                                // printf("%s\n", f);
                                FILE* files = fopen(f, "a");
                                fputs(isi, files);
                                fclose(files);
                            }
                            // end while
                            // exit(EXIT_SUCCESS);
                        }
                        // exit(EXIT_SUCCESS);
                        while(wait(NULL) > 0);
                        char erase[1000];
                        strcpy(erase, path);
                        strcat(erase, dp->d_name);
        
                        if(fork() == 0) {
                            while(wait(NULL) > 0);
                            char *arge[] = {"rm", erase, NULL};
                            execv("/usr/bin/rm", arge);
                        }
                        else{
                            while(wait(NULL) > 0);
                        }
                        //end if
                    }
                }
                else
                    continue;
            } 
            (void) closedir(dir);
        }
    }
}