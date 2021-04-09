# soal-shift-sisop-modul-2-F01-2021

## Source Code
- [Soal 1](https://github.com/azhar416/soal-shift-sisop-modul-2-F01-2021/blob/main/soal1/soal1.c)
- [Soal 2]()
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
