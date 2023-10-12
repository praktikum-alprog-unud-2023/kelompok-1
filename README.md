# kelompok-1

# Panduan Penggunaan Git dan GitHub

Git adalah sistem kontrol versi yang sangat populer yang digunakan untuk mengelola kode sumber, sedangkan GitHub adalah platform hosting yang memungkinkan kolaborasi dan berbagi proyek dengan orang lain.

## Daftar Isi

1. [Apa itu Git dan GitHub?](#apa-itu-git-dan-github)
2. [Instalasi Git](#instalasi-git)
3. [Mengelola Repository Git](#mengelola-repository-git)
   - Clone Repository
   - Menambahkan Perubahan (Git Add)
   - Membuat Commit (Git Commit)
   - Melihat Status (Git Status)
   - Mengirim Perubahan (Git Push)
   - Mendapatkan Perubahan Terbaru (Git Fetch dan Git Pull)
4. [Branching](#branching)
5. [Menggabungkan Perubahan (Merge)](#menggabungkan-perubahan-merge)
6. [Bekerja dengan Remote Repository](#bekerja-dengan-remote-repository)
7. [Mengatasi Konflik](#mengatasi-konflik)
8. [Menggunakan GitHub](#menggunakan-github)
   - Membuat Repository di GitHub
   - Push ke Repository di GitHub
   - Mengirim Pull Request
   - Menggabungkan Pull Request
9. [Catatan Penting](#catatan-penting)

## Apa itu Git dan GitHub? <a name="apa-itu-git-dan-github"></a>

**Git** adalah sistem kontrol versi yang memungkinkan Anda melacak perubahan dalam kode sumber Anda. Ini memungkinkan Anda untuk berkolaborasi dengan orang lain dan mengelola riwayat proyek Anda.

**GitHub** adalah platform hosting yang memungkinkan Anda untuk menyimpan, berbagi, dan berkolaborasi dalam proyek Git. GitHub menyediakan alat yang kuat untuk kolaborasi tim dan pengelolaan proyek.

## Instalasi Git <a name="instalasi-git"></a>

Anda dapat mengunduh dan menginstal Git dari situs web resmi [Git](https://git-scm.com/downloads) sesuai dengan sistem operasi yang Anda gunakan.

## Mengelola Repository Git <a name="mengelola-repository-git"></a>

### Clone Repository

Untuk mengambil salinan (clone) repository yang sudah ada, gunakan perintah:

```shell
git clone <URL-Repository>
```

### Menambahkan Perubahan (Git Add)

Tambahkan perubahan yang ingin Anda sertakan dalam commit dengan perintah:

```shell
git add <nama-file>
```

Atau bisa juga menambahkan perubahan pada semua file dengan perintah:

```shell
git add .
```

### Membuat Commit (Git Commit)

Setelah menambahkan perubahan, buat commit untuk menyimpan perubahan dengan pesan deskripsi:

```shell
git commit -m "Pesan commit Anda di sini"
```

### Melihat Status (Git Status)

Untuk melihat status perubahan di repository Anda, gunakan perintah:

```shell
git status
```

### Mengirim Perubahan (Git Push)

Kirim perubahan lokal ke repository remote dengan perintah:

```shell
git push
```

### Mendapatkan Perubahan Terbaru (Git Fetch dan Git Pull)

Untuk mendapatkan perubahan terbaru dari repository remote, gunakan:

```shell
git push fetch
```

Untuk mengambil perubahan terbaru dan menggabungkannya dengan cabang lokal saat ini, gunakan:

```shell
git pull
```

## Branching <a name="branching"></a>

Branching memungkinkan Anda untuk bekerja pada fitur atau perbaikan bug dalam cabang terpisah tanpa memengaruhi cabang utama (biasanya disebut "master").

## Menggabungkan Perubahan (Merge) <a name="menggabungkan-perubahan-merge"></a>

Gunakan perintah git merge untuk menggabungkan perubahan dari satu branch ke branch lain.

```shell
git merge
```

## Bekerja dengan Remote Repository <a name="bekerja-dengan-remote-repository"></a>

### Menambahkan Remote Repository

Anda dapat menambahkan remote repository dengan perintah:

```shell
git remote add origin <URL-Repository-Remote>
```

### Mengirim Perubahan ke Remote Repository

Kirim perubahan lokal ke remote repository dengan perintah:

```shell
git push -u origin <nama-branch>
```

## Mengatasi Konflik <a name="mengatasi-konflik"></a>

Konflik terjadi ketika dua perubahan bertentangan dalam file. Anda perlu memecahkan konflik secara manual dan membuat commit baru.

## Menggunakan GitHub <a name="menggunakan-github"></a>

### Membuat Repository di GitHub

Anda dapat membuat repository di GitHub dengan mengklik tombol "New" di akun GitHub Anda.

### Push ke Repository di GitHub

Untuk mengirim perubahan ke repository di GitHub, gunakan perintah git push ke remote repository GitHub.

### Mengirim Pull Request

Jika Anda ingin berkontribusi ke proyek lain di GitHub, buat Pull Request untuk mengajukan perubahan Anda.

### Menggabungkan Pull Request

Pemilik proyek dapat menggabungkan Pull Request setelah memeriksa perubahan.

## Catatan Penting <a name="catatan-penting"></a>

- Selalu gunakan pesan commit yang deskriptif.
- Jangan lupa untuk sering mengirimkan perubahan Anda ke remote repository.
- Pelajari lebih lanjut tentang Git dan GitHub dengan dokumentasi resmi dan sumber daya online lainnya.

Terima kasih telah menggunakan Git dan GitHub!
