# Fungsi Utility dalam utility.h

**Desclimer:**
**File utility.h hanya untuk catatan/ template, bukan untuk di-run**

Cara Menggunakan file (`utility.h`) dengan meng-copy file ini pada folder yang sama dengan program atau memanggilnya dengan path yang benar jika berada dalam folder yang berbeda.

Tambahkan header **<include> "utility.h"** pada bagian atas program C jika file (`utility.h`) di-copy pada folder yang sama dengan program C. Maka semua fungsi yang ada dalam file (`utility.h`) dapat digunakan dalam program C tanpa perlu menuliskannya ulang.

Bisa juga kita menggunakan file (`utility.h`) yang tersimpan dalam folder (`validasi/utility/utility.h`) tanpa harus meng-copynya pada folder yang sama dengan program C. Namun harus disesuaikan path file-nya agar sesuai dengan lokasi yang dituju. Path yang dapat digunakan yaitu **#include "../../validasi/utility/utility.h"**, yang mana **../** berarti keluar dari folder.

File C ini (`utility.h`) berisi kumpulan fungsi dan prosedur utilitas yang dapat digunakan dalam berbagai bagian program Anda. Fungsi-fungsi ini dirancang untuk mempermudah tugas-tugas umum seperti menampilkan pesan, memvalidasi input pengguna, dan mengelola alur program.

## Daftar Isi

- [Tampilan Awal Program](#tampilan-awal-program)
- [Tampilan Judul](#tampilan-judul)
- [Pesan dan Tampilan Garis](#pesan-dan-tampilan-garis)
- [Pesan Status](#pesan-status)
- [Pesan Akhir Program](#pesan-akhir-program)
- [Pesan Jeda](#pesan-jeda)
- [Validasi Input Bilangan Bulat](#validasi-input-bilangan-bulat)
- [Validasi Input Bilangan Desimal](#validasi-input-bilangan-desimal)

## Tampilan Awal Program <a name="tampilan-awal-program"></a>

- **Prosedur:** `startingScreen()`
- **Deskripsi:** Menampilkan tampilan pengantar saat program pertama kali dibuka, memberikan informasi tentang program dan para pengembangnya.
- **Penggunaan:** Biasanya digunakan di awal program untuk memberikan pengantar.

## Tampilan Judul <a name="tampilan-judul"></a>

- **Prosedur:** `head()`
- **Deskripsi:** Menampilkan judul program di bagian atas layar.
- **Penggunaan:** Dapat digunakan untuk menampilkan judul dari bagian program saat ini.

## Pesan dan Tampilan Garis <a name="pesan-dan-tampilan-garis"></a>

- **Prosedur:** `outLine()`
- **Prosedur:** `outMsg(const char *format, ...)`
- **Deskripsi:** `outLine` menampilkan garis horizontal di layar, sedangkan `outMsg` menampilkan pesan yang berada di tengah layar.
- **Penggunaan:** Fungsi-fungsi ini digunakan untuk format dan gaya pesan yang konsisten.

## Pesan Status <a name="pesan-status"></a>

- **Prosedur:** `statusMsg(char *inputText)`
- **Deskripsi:** Menampilkan pesan status yang dikelilingi oleh garis horizontal.
- **Penggunaan:** Digunakan untuk menampilkan pesan kesalahan atau status dalam program.

## Pesan Akhir Program <a name="pesan-akhir-program"></a>

- **Prosedur:** `endMsg()`
- **Deskripsi:** Menampilkan pesan penyelesaian program dan menawarkan opsi kepada pengguna untuk mengulangi atau keluar dari program.
- **Penggunaan:** Biasanya digunakan untuk mengakhiri program dan mengelola pilihan pengguna.

## Pesan Jeda <a name="pesan-jeda"></a>

- **Prosedur:** `pauseMsg()`
- **Deskripsi:** Menampilkan pesan dan menunggu pengguna menekan Enter sebelum melanjutkan.
- **Penggunaan:** Berguna untuk memberikan jeda selama eksekusi program.

## Validasi Input Bilangan Bulat <a name="validasi-input-bilangan-bulat"></a>

- **Prosedur:** `validateInputInteger(char *string, int *integer)`
- **Deskripsi:** Memvalidasi input pengguna untuk memastikan itu adalah bilangan bulat. Mengembalikan `1` jika valid, `0` jika tidak.
- **Penggunaan:** Digunakan untuk memvalidasi dan menyimpan input bilangan bulat dari pengguna.

## Validasi Input Bilangan Desimal <a name="validasi-input-bilangan-desimal"></a>

- **Prosedur:** `validateInputDouble(char *string, double *floating_point)`
- **Deskripsi:** Memvalidasi input pengguna untuk memastikan itu adalah bilangan desimal (floating-point). Mengembalikan `1` jika valid, `0` jika tidak.
- **Penggunaan:** Digunakan untuk memvalidasi dan menyimpan input bilangan desimal dari pengguna.

Fungsi-fungsi utilitas ini dapat dimasukkan ke dalam program C Anda untuk menyederhanakan tugas-tugas umum dan meningkatkan pengalaman pengguna. Silakan manfaatkan fungsi-fungsi ini dan sesuaikan dengan kebutuhan khusus program Anda.
