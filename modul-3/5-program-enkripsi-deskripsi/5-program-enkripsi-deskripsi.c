#include "../../validasi/utility/utility.h"

char namaProgram[] = "CAESAR CIPHER";
char daftarMenu[2][50] = {
    "Enkripsi                  \0",
    "Dekripsi                  \0"};
void encryptText(char text[], int shift);
void decryptText(char text[], int shift);
void outputText(const char *format, ...);
void thankYouAndExit() {
    outLine();
    outMsg("TERIMAKASIH TELAH MENGGUNAKAN PROGRAM INI");
}
void endMsgthankyou()
{
    int pilihan;
    int exitLoop = 0;

    do
    {
        outLine();
        outMsg("PROGRAM SELESAI");
        outMsg("< 1 > Ulangi            < 2 > Keluar");
        inputThisInt("Masukkan perintah : ", &pilihan);

        switch (pilihan)
        {
        case 1:
            menuUtama();
            exitLoop = 1;
            break;

        case 2:
            thankYouAndExit();
            exitLoop = 1;
            break;

        default:
            statusMsg("ERROR: PERINTAH YANG ANDA PILIH TIDAK DITEMUKAN");
            break;
        }
    } while (!exitLoop);
}
void menuUtama()
{
    char sourceText[2046];
    int shift;
    head();

    // menu
    outMsg("Pilih prosedur yang ingin dilakukan dilakukan:");
    for (int i = 0; i < 2; i++)
    {
        outMsg("< %d >  %s", i + 1, daftarMenu[i]);
    }
    outLine();
    inputThisInt("masukkan pilihanmu: ", &pilihan);

    switch (pilihan)
    {
    case 1:
        head();
        inputThisAlpha("masukkan text: ", sourceText);
        inputThisInt("masukkan shift: ", &shift);
        encryptText(sourceText, shift);

        head();
        outMsg("Hasil: %s", sourceText);

        break;
    case 2:
        head();
        inputThisAlpha("masukkan text: ", sourceText);
        inputThisInt("masukkan shift: ", &shift);
        decryptText(sourceText, shift);

        head();
        outMsg("Hasil: %s", sourceText);

        break;

    default:
        statusMsg("ERROR: PERINTAH YANG ANDA PILIH TIDAK DITEMUKAN");
        pilihan = 0;
        pauseMsg();
        menuUtama();
        break;
    }

    endMsgthankyou();
}
int main()
{
    startingScreen();
    menuUtama();
    return 0;
}
// Prosedur Enkripsi
void encryptText(char text[], int shift)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        char ch = text[i];
        if (ch >= 'a' && ch <= 'z')
        {
            text[i] = (char)(((ch - 'a' + shift) % 26) + 'A');
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            text[i] = (char)(((ch - 'A' + shift) % 26) + 'A');
        }
    }
}
// Prosedur Dekripsi
void decryptText(char message[], int shift)
{
    for (int i = 0; message[i] != '\0'; i++)
    {
        char ch = message[i];
        if (ch >= 'a' && ch <= 'z')
        {
            message[i] = (char)(((ch - 'a' - shift + 26) % 26) + 'a');
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            message[i] = (char)(((ch - 'A' - shift + 26) % 26) + 'A');
        }
    }
}