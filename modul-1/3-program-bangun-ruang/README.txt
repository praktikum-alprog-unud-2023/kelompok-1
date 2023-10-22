==================================================================
*************************DEVELOPER MANUAL*************************
==================================================================

I. DESKRIPSI PROGRAM
Program "Menghitung Volume dan Luas Permukaan Bangun Ruang" dirancang untuk melakukan perhitungan volume dan luas permukaan berbagai bentuk tiga dimensi. Bentuk-bentuk yang tersedia dalam program ini termasuk Tabung, Bola, Limas Segiempat, Prisma Segitiga, dan Kerucut.

==================================================================

II. FITUR
- Menghitung volume dan luas permukaan berbagai bentuk tiga dimensi.
- Antarmuka berbasis menu yang ramah pengguna.
- Validasi input untuk memastikan input numerik yang benar dan positif.
- Output terperinci dengan hasil perhitungan.

==================================================================

III. STRUKTUR PROGRAM

Alur Eksekusi Program:
- Program dimulai dengan fungsi main(), yang menampilkan menu utama.
- Pengguna memilih bentuk bangun ruang yang ingin dihitung.
- Program memanggil fungsi menu yang sesuai untuk bentuk bangun ruang yang dipilih.
- Fungsi menu mengambil input dari pengguna, memvalidasi input, dan menghitung volume serta luas permukaan berdasarkan rumus yang sesuai.
- Hasil perhitungan ditampilkan ke layar.
- Pengguna diberi opsi untuk melakukan perhitungan tambahan atau keluar dari program.

1. Main Function:
   - main(): Fungsi utama yang menjadi titik awal eksekusi program. Menginisialisasi tampilan program dan memanggil menu utama.

2. Menu Functions:
   - menuTabung(): Fungsi untuk menghitung tabung.
   - menuBola(): Fungsi untuk menghitung bola.
   - menuLimasSegiempat(): Fungsi untuk menghitung limas segiempat.
   - menuPrismaSegitiga(): Fungsi untuk menghitung prisma segitiga.
   - menuKerucut(): Fungsi untuk menghitung kerucut.

3. Utility Functions:
   - outMsg(): Menampilkan pesan pada layar dengan rapi dan pusatkan.
   - inputThisInt(): Meminta input integer dari pengguna dan memvalidasi masukan.
   - inputThisDouble(): Meminta input angka desimal dari pengguna dan memvalidasi masukan.
   - statusMsg(): Menampilkan pesan status pada layar.
   - pauseMsg(): Memberikan pesan untuk memberi tahu pengguna untuk menekan tombol Enter.

4. Calculation Functions:
   - tabungVolume(): Menghitung volume tabung.
   - tabungLuasPermukaan(): Menghitung luas permukaan tabung.
   - bolaVolume(): Menghitung volume bola.
   - bolaLuasPermukaan(): Menghitung luas permukaan bola.
   - Fungsi-fungsi serupa digunakan untuk bentuk bangun ruang lainnya.

5. Input Validation:
   - validateInputInteger(): Fungsi untuk memvalidasi input integer.
   - validateInputDouble(): Fungsi untuk memvalidasi input angka desimal.