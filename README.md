# soal-shift-sisop-modul-2-F01-2021

## Source Code
- [Soal 1](https://github.com/azhar416/soal-shift-sisop-modul-2-F01-2021/blob/main/soal1/soal1.c)
- [Soal 2](https://github.com/azhar416/soal-shift-sisop-modul-2-F01-2021/blob/main/soal2/soal2.c)
- [Soal 3]()

## Soal Nomor 1
Pada suatu masa, hiduplah seorang Steven yang hidupnya pas-pasan. Steven punya pacar, namun sudah putus sebelum pacaran. Ketika dia galau memikirkan mantan, ia selalu menonton https://www.youtube.com/watch?v=568DH_9CMKI untuk menghilangkan kesedihannya. 

Di lain hal Steven anak yang tidak amat sangat super membenci matkul sisop, beberapa jam setelah diputus oleh pacarnya dia menemukan wanita lain bernama Stevany, namun Stevany berkebalikan dengan Steven karena menyukai sisop. Steven ingin terlihat jago matkul sisop demi menarik perhatian Stevany.

Pada hari ulang tahun Stevany, Steven ingin memberikan Stevany zip berisikan hal-hal yang disukai Stevany. Steven ingin isi zipnya menjadi rapi dengan membuat folder masing-masing sesuai extensi. (a) Dikarenakan Stevany sangat menyukai huruf Y, Steven ingin nama folder-foldernya adalah Musyik untuk mp3, Fylm untuk mp4, dan Pyoto untuk jpg (b) untuk musik Steven mendownloadnya dari link di bawah, film dari link di bawah lagi, dan foto dari link dibawah juga :). (c) Steven tidak ingin isi folder yang dibuatnya berisikan zip, sehingga perlu meng-extract-nya setelah didownload serta (d) memindahkannya ke dalam folder yang telah dibuat (hanya file yang dimasukkan).

(e) Untuk memudahkan Steven, ia ingin semua hal di atas berjalan otomatis 6 jam sebelum waktu ulang tahun Stevany). (f) Setelah itu pada waktu ulang tahunnya Stevany, semua folder akan di zip dengan nama Lopyu_Stevany.zip dan semua folder akan di delete(sehingga hanya menyisakan .zip).
Kemudian Steven meminta bantuanmu yang memang sudah jago sisop untuk membantunya mendapatkan hati Stevany. Bantu Woy!!

### Penjelasan
Dari soal narasi panjang diatas, kita mengetahui bahwa kita diminta untuk membuat sebuah Daemon Program untuk melakukan banyak hal seperti membuat directory, men-download sebuah zip file yang kemudian akan di-extract, melakukan zip, dan juga menghapus sebuah folder. Terlebih lagi program tersebut akan berjalan pada waktu yang telah ditentukan yaitu untuk membuat directory, men-download file, dan juga meng-extract isinya yang kemudian dipindahkan ke directory yang telah dibuat pada 9 APRIL pukul 16:22 atau 6 jam sebelum ulang tahunnya Stevany. Untuk melakukan zip pada directory yang berisi hasil extract file yang di download dilakukan pada 9 APRIL pukul 22:22 atau tepat pada jam ulang tahunnya. Setelah melakukan zip, directory tersebut akan dihapus.

untuk menjawab permasalahan tersebut, saya membuat banyak fungsi untuk memisahkan setiap kegiatan yang dijalankan.
pada fungsi main-nya sendiri hanya akan berisi template daemon dan fungsi - fungsi dari kegiatan yang akan dijalankan.

```C++
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
```
fungsi `mekdir()` diatas berfungsi untuk membuat directory Pyoto, Myusik, dan juga Fylm.

```C++
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
```
fungsi `donlot()` diatas berfungsi untuk mendownload zip dari yang telah disediakan oleh soal.

```C++
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
```
fungsi `ekstrak()` diatas berfungsi untuk melakukan unzip dari file zip yang telah di-download.

```C++
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
```
```C++
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
```
fungsi `copy()` akan melakukan copy data - data dari folder MUSIK, FILM, FOTO ke directory Myusik, Fylm, dan Pyoto. setelah di copy, folder MUSIK, FILM, dan FOTO akan dihapus oleh fungsi `ngapus()`.

```C++
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
```
fungsi `ngezip()` diatas berfungsi untuk melakukan zip pada 3 directory yaitu Myusik, Fylm, Pyoto. Setelah itu ketiga directory tersebut akan dihapus.

untuk fungsi main nya sendiri
```C++
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
```
pada fungsi main ini setiap ingin melakukan panggilan pada fungsi, akan di fork terlebih dahulu agar program tidak terminate. untuk daemonnya sendiri kami menggunakan template dari github agar dapat berjalan terus pada background.

## Soal Nomor 2
Loba bekerja di sebuah petshop terkenal, suatu saat dia mendapatkan zip yang berisi banyak sekali foto peliharaan dan Ia diperintahkan untuk mengkategorikan foto-foto peliharaan tersebut. Loba merasa kesusahan melakukan pekerjaanya secara manual, apalagi ada kemungkinan ia akan diperintahkan untuk melakukan hal yang sama. Kamu adalah teman baik Loba dan Ia meminta bantuanmu untuk membantu pekerjaannya.

(a) Pertama-tama program perlu mengextract zip yang diberikan ke dalam folder “/home/[user]/modul2/petshop”. Karena bos Loba teledor, dalam zip tersebut bisa berisi folder-folder yang tidak penting, maka program harus bisa membedakan file dan folder sehingga dapat memproses file yang seharusnya dikerjakan dan menghapus folder-folder yang tidak dibutuhkan.

(b) Foto peliharaan perlu dikategorikan sesuai jenis peliharaan, maka kamu harus membuat folder untuk setiap jenis peliharaan yang ada dalam zip. Karena kamu tidak mungkin memeriksa satu-persatu, maka program harus membuatkan folder-folder yang dibutuhkan sesuai dengan isi zip.
Contoh: Jenis peliharaan kucing akan disimpan dalam “/petshop/cat”, jenis peliharaan kura-kura akan disimpan dalam “/petshop/turtle”.

(c) Setelah folder kategori berhasil dibuat, programmu akan memindahkan foto ke folder dengan kategori yang sesuai dan di rename dengan nama peliharaan.
Contoh: “/petshop/cat/joni.jpg”. 

(d) Karena dalam satu foto bisa terdapat lebih dari satu peliharaan maka foto harus di pindah ke masing-masing kategori yang sesuai. Contoh: foto dengan nama “dog;baro;1_cat;joni;2.jpg” dipindah ke folder “/petshop/cat/joni.jpg” dan “/petshop/dog/baro.jpg”.

(e) Di setiap folder buatlah sebuah file "keterangan.txt" yang berisi nama dan umur semua peliharaan dalam folder tersebut. Format harus sesuai contoh.

### Penjelasan
Soal diatas meminta untuk membuat sebuah program untuk membuat directory, mengextract sebuah zip file yang kemudian akan dipindahkan ke directory yang baru dibuat dengan format nama file yang ditentukan setelah diidentifikasi nama file nya, serta membaca dan menyimpan beberapa informasi dari nama file ke dalam sebuah file txt.