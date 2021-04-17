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

## Soal Nomor 3
Ranora adalah mahasiswa Teknik Informatika yang saat ini sedang 
menjalani magang di perusahan ternama yang bernama “FakeKos Corp.”
,perusahaan yang bergerak dibidang keamanan data. Karena Ranora 
masih magang, maka beban tugasnya tidak sebesar beban tugas pekerja 
tetap perusahaan. Di hari pertama Ranora bekerja, pembimbing magang
Ranora memberi tugas pertamanya untuk membuat sebuah program.

### A. Ranora harus membuat sebuah program C yang dimana setiap 40 
detik membuat sebuah direktori dengan nama sesuai timestamp 
[YYYY-mm-dd_HH:ii:ss].

Pada kasus ini menggunakan fungsi `strftime` dan menggunakan `fork` 
dan `execv` untuk membuat directory. Selang waktu yang diberikan
yaitu 40 detik maka `sleep(40)`.

```
s = 1;
    while(s)
    {
        // 3a. Membuat mkdir dengan nama waktu sesuai soal
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
                sleep(40);
    }
```

### B. Setiap direktori yang sudah dibuat diisi dengan 10 gambar yang
didownload dari https://picsum.photos/, dimana setiap gambar akan
didownload setiap 5 detik. Setiap gambar yang didownload akan diberi 
nama dengan format timestamp [YYYY-mm-dd_HH:ii:ss] dan gambar tersebut 
berbentuk persegi dengan ukuran (n%1000) + 50 pixel dimana n adalah 
detik Epoch Unix.

Pada kasus ini akan mendownload 10 foto menggunakan looping `for`
untuk jeda `sleep(5)`. Penamaan file menggunakan waktu dan memakai 
`strftime`. 

```
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
```

### C. Setelah direktori telah terisi dengan 10 gambar, program tersebut 
akan membuat sebuah file “status.txt”, dimana didalamnya berisi pesan 
“Download Success” yang terenkripsi dengan teknik Caesar Cipher dan dengan
shift 5. Caesar Cipher adalah Teknik enkripsi sederhana yang dimana dapat 
melakukan enkripsi string sesuai dengan shift/key yang kita tentukan. Misal 
huruf “A” akan dienkripsi dengan shift 4 maka akan menjadi “E”. Karena Ranora 
orangnya perfeksionis dan rapi, dia ingin setelah file tersebut dibuat, 
direktori akan di zip dan direktori akan didelete, sehingga menyisakan hanya 
file zip saja.

Ada 2 kasus yang pertama yaitu setelah melakukan proses `download` akan membuat 
status.txt dimana akan menampilkan hasil `Download Success` dengan menggunakan
Caesar Cipher Shift 5
```
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
```
Setelah itu semua foto beserta status.txt akan dibuat zip dan direktori akan
terhapus.Berikut implementasi nya
```
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
```

Untuk menghapus direktori
```
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
```

### D. Untuk mempermudah pengendalian program, pembimbing magang Ranora 
ingin program tersebut akan men-generate sebuah program “Killer” yang 
executable, dimana program tersebut akan menterminasi semua proses program 
yang sedang berjalan dan akan menghapus dirinya sendiri setelah program 
dijalankan. Karena Ranora menyukai sesuatu hal yang baru, maka Ranora 
memiliki ide untuk program “Killer” yang dibuat nantinya harus merupakan 
program bash.

Pada proses ini akan membuat file menggunakan program bash dengan nama `killer.sh`.
Pada killer.sh akan berisi kill pid() dan `rm` pada file itu sendiri
```
        FILE *new;
        new = fopen("killer.sh","w");
        fputs("#!/bin/bash\nkillall soal3\n rm killer.sh\necho \'Berhasil\'",new);
        fclose(new);
```

### E. Pembimbing magang Ranora juga ingin nantinya program utama yang 
dibuat Ranora dapat dijalankan di dalam dua mode. Untuk mengaktifkan mode 
pertama, program harus dijalankan dengan argumen -z, dan Ketika dijalankan 
dalam mode pertama, program utama akan langsung menghentikan semua operasinya 
Ketika program Killer dijalankan. Sedangkan untuk mengaktifkan mode kedua, 
program harus dijalankan dengan argumen -x, dan Ketika dijalankan dalam mode 
kedua, program utama akan berhenti namun membiarkan proses di setiap direktori 
yang masih berjalan hingga selesai (Direktori yang sudah dibuat akan mendownload 
gambar sampai selesai dan membuat file txt, lalu zip dan delete direktori).

Pada kasus ini untuk pembuatan file `killer.sh` menggunakan kondisi if else
```
    if(argv[1][1]=='z'){
        FILE *new;
        new = fopen("killer.sh","w");
        fputs("#!/bin/bash\nkillall soal3\n rm killer.sh\necho \'Berhasil\'",new);
        fclose(new);
    }
    if(argv[1][1]=='x'){ 
        FILE *new;
        new = fopen("killer.sh","w");
        fputs("#!/bin/bash\nkillall -15 soal3\n rm killer.sh\necho \'Menunggu proses\'",new);
        fclose(new);

        // memberi signal dan mengisi signal jadi 0
        signal(SIGTERM,op);
     }
```
signal(SIGTERM,op) yaitu penggunaan ophran dimana proses akan dihentikan setelah 
semua proses for dan zip dilakukan. Pada kasus ini diberikan
```
    if (s ==0) 
    {
        break;
    }

``` 
Dimana pada akhir process akan dilakukan pengecekan. Jika s == 0 maka process akan
berhenti.
