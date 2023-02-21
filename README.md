# TUGAS 1 PPLJ1

Membuat aplikasi untuk server dan client dengan menggunakan socket dimana antara server dan client dengan menggunakan bahasa pemograman yang berbeda.

Dikerjakan secara kelompok yang terdiri dari 2 orang: 1 orang mengerjakan bagian server; 1 orang mengerjakan bagian client.

Pesan yang dikirim antara client-server:

- client mengirimkan pesan nama lengkap, server membalas dengan nama lengkap juga
- client menanyakan apakah sehat?, server menjawab sehat
- client memberikan pesan menyudahi komunikasi, server menutup koneksi (silahkan pilih kata yang menandakan komunikasi selesai)
- Apabila ada pesan diluar dari client di luar dari yang diakomdir, server manjawab pesan tidak dikenal.

NOTE:
compile winsock: gcc nama.c -lws2_32 -o nama
