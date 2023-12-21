#include "../../validasi/utility/utility.h"

char namaProgram[] = "PROGRAM ZODIAK";
int validasiBulan(char *input, int *output);
void menuBulan();
void inputPilihan(char *inputText, int *inputVariable);
void inputTanggal(char *inputText, int *inputVariable);
void inputBulan(char *inputText, int *inputVariable);

// main
int main()
{
  startingScreen();
  menuUtama();
  system("pause");
  endMsg();
}

// validasi
int validasiBulan(char *input, int *output)
{
  int bulan_angka;
  if (validateInputInteger(input, &bulan_angka) && bulan_angka >= 1 && bulan_angka <= 12)
  {
    *output = bulan_angka;
    return 1;
  }
  char bulan_buffer[BUFFER_SIZE];

  int i = 0;
  while (isspace(input[i]))
  {
    i++;
  }

  int length = strlen(input);

  if (length == i)
  {
    return 0;
  }

  int bulan_chars = 0;
  while (i < length && !isspace(input[i]))
  {
    bulan_buffer[bulan_chars] = input[i];
    bulan_chars++;
    i++;
  }

  bulan_buffer[bulan_chars] = '\0';

  while (isspace(input[i]))
  {
    i++;
  }

  if (input[i] != '\0')
  {
    return 0;
  }

  if (strcasecmp(bulan_buffer, "Januari") == 0)
  {
    *output = 1;
    return 1;
  }
  else if (strcasecmp(bulan_buffer, "Februari") == 0)
  {
    *output = 2;
    return 1;
  }
  else if (strcasecmp(bulan_buffer, "Maret") == 0)
  {
    *output = 3;
    return 1;
  }
  else if (strcasecmp(bulan_buffer, "April") == 0)
  {
    *output = 4;
    return 1;
  }
  else if (strcasecmp(bulan_buffer, "Mei") == 0)
  {
    *output = 5;
    return 1;
  }
  else if (strcasecmp(bulan_buffer, "Juni") == 0)
  {
    *output = 6;
    return 1;
  }
  else if (strcasecmp(bulan_buffer, "Juli") == 0)
  {
    *output = 7;
    return 1;
  }
  else if (strcasecmp(bulan_buffer, "Agustus") == 0)
  {
    *output = 8;
    return 1;
  }
  else if (strcasecmp(bulan_buffer, "September") == 0)
  {
    *output = 9;
    return 1;
  }
  else if (strcasecmp(bulan_buffer, "Oktober") == 0)
  {
    *output = 10;
    return 1;
  }
  else if (strcasecmp(bulan_buffer, "November") == 0)
  {
    *output = 11;
    return 1;
  }
  else if (strcasecmp(bulan_buffer, "Desember") == 0)
  {
    *output = 12;
    return 1;
  }
  else
  {
    return 0;
  }
}

void inputBulan(char *inputText, int *inputVariable)
{
  int parsed_correct = 1;
  char buffer[BUFFER_SIZE];

  do
  {
    if (inputText != NULL)
    {
      printf("%s", inputText);
    }
    fgets(buffer, BUFFER_SIZE, stdin);

    if (validasiBulan(buffer, inputVariable) == 0)
    {
      statusMsg("ERROR: BULAN YANG ANDA MASUKKAN TIDAK VALID");
    }
  } while (*inputVariable < 1 || *inputVariable > 12);
}

void inputPilihan(char *inputText, int *inputVariable)
{
  int parsed_correct = 1;
  char buffer[BUFFER_SIZE];
  do
  {
    if (inputText != NULL)
    {
      printf("%s", inputText);
    }
    fgets(buffer, BUFFER_SIZE, stdin);

    if (validateInputInteger(buffer, inputVariable) == 0)
    {
      statusMsg("ERROR: ANDA TIDAK MEMASUKKAN NOMOR PERINTAH");
    }

    if (*inputVariable < 0)
    {
      statusMsg("ERROR: PERINTAH YANG DIMASUKKAN BUKAN BILANGAN POSITIF");
    }
  } while (validateInputInteger(buffer, inputVariable) == 0 || *inputVariable < 0);
}

void inputTanggal(char *inputText, int *inputVariable)
{
  int parsed_correct = 1;
  char buffer[BUFFER_SIZE];

  do
  {
    if (inputText != NULL)
    {
      printf("%s", inputText);
    }
    fgets(buffer, BUFFER_SIZE, stdin);

    if (validateInputInteger(buffer, inputVariable) == 0)
    {
      statusMsg("ERROR: TANGGAL YANG ANDA MASUKKAN TIDAK VALID");
    }
    else if (*inputVariable >= 32 || *inputVariable < 1)
    {
      statusMsg("ERROR: TANGGAL YANG ANDA MASUKKAN TIDAK VALID");
    }
  } while (*inputVariable < 1 || *inputVariable >= 32);
}

void menuBulan()
{
  outLine();
  outMsg("MENU BULAN ");
  outLine();
  outMsg("1 = januari      2 = Februari     3 = Maret     4 = April");
  outMsg(" 5 = Mei          6 = Juni         7 = Jul1      8 = Agustus");
  outMsg("  9 = September   10 = Oktober     11 = November 12 = Desember");
  outLine();
}

void menuUtama()
{
  int tanggal, bulan;
  head();
  statusMsg("MASUKKAN TANGGAL LAHIR ");
  inputTanggal("Masukkan tanggal: ", &tanggal);
  system("pause");
  head();
  menuBulan();
  outMsg("MASUKKAN BULAN LAHIR");
  outLine();
  inputBulan("Masukkan bulan: ", &bulan);

  if ((bulan == 3 && tanggal >= 21 && tanggal <= 31) || (bulan == 4 && tanggal <= 19))
    statusMsg("Zodiak Anda adalah Aries.");
  else if ((bulan == 4 && tanggal >= 20 && tanggal <= 30) || (bulan == 5 && tanggal <= 20))
    statusMsg("Zodiak Anda adalah Taurus.");
  else if ((bulan == 5 && tanggal >= 21 && tanggal <= 31) || (bulan == 6 && tanggal <= 20))
    statusMsg("Zodiak Anda adalah Gemini.");
  else if ((bulan == 6 && tanggal >= 21 && tanggal <= 30) || (bulan == 7 && tanggal <= 22))
    statusMsg("Zodiak Anda adalah Cancer.");
  else if ((bulan == 7 && tanggal >= 23 && tanggal <= 31) || (bulan == 8 && tanggal <= 22))
    statusMsg("Zodiak Anda adalah Leo.");
  else if ((bulan == 8 && tanggal >= 23 && tanggal <= 31) || (bulan == 9 && tanggal <= 22))
    statusMsg("Zodiak Anda adalah Virgo.");
  else if ((bulan == 9 && tanggal >= 23 && tanggal <= 30) || (bulan == 10 && tanggal <= 22))
    statusMsg("Zodiak Anda adalah Libra.");
  else if ((bulan == 10 && tanggal >= 23 && tanggal <= 31) || (bulan == 11 && tanggal <= 21))
    statusMsg("Zodiak Anda adalah Scorpio.");
  else if ((bulan == 11 && tanggal >= 22 && tanggal <= 30) || (bulan == 12 && tanggal <= 21))
    statusMsg("Zodiak Anda adalah Sagitarius.");
  else if ((bulan == 12 && tanggal >= 22 && tanggal <= 31) || (bulan == 1 && tanggal <= 19))
    statusMsg("Zodiak Anda adalah Capricorn.");
  else if ((bulan == 1 && tanggal >= 20 && tanggal <= 31) || (bulan == 2 && tanggal <= 18))
    statusMsg("Zodiak Anda adalah Aquarius.");
  else if ((bulan == 2 && tanggal >= 19 && tanggal <= 29) || (bulan == 3 && tanggal <= 20))
    statusMsg("Zodiak Anda adalah Pisces.");
  else
    statusMsg("TANGGAL LAHIR TIDAK VALID");
}