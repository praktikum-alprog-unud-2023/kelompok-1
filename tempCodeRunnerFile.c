#include "../validasi/utility/utility.h"

char namaProgram[] = "CAESAR CIPHER";

void encryptText(char text[], int shift);
void decryptText(char text[], int shift);
void outputText(const char *format, ...);


void input_binary_str(char *input_param)
{
  char input[100];
  int i = 0, error = 0;

  fflush(stdin);
  fgets(input, sizeof(input), stdin);

  if (input[0] == '\0')
    error = 1;

  while (input[i] != '\0' && input[i] != '\n')
  {
    if (strchr("01", input[i]))
    {
      i++;
    }
    else
    {
      error = 1;
      break;
    }
  }

  if (error == 1)
  {
    printf("\nInvalid binary number!");
    printf("\nSilahkan Masukan Angka Kembali : ");
    return input_binary_str(input_param);
  }
  input[i] = '\0';
  strcpy(input_param, input);
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
  outMsg("< 0 >  keluar                    \0");
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
    outMsg("%s", sourceText);

    break;
  case 2:
    head();
    inputThisAlpha("masukkan text: ", sourceText);
    inputThisInt("masukkan shift: ", &shift);
    decryptText(sourceText, shift);

    head();
    outMsg("%s", sourceText);

    break;

  case 0:
    break;

  default:
    statusMsg("ERROR: PERINTAH YANG ANDA PILIH TIDAK DITEMUKAN");
    pilihan = 0;
    pauseMsg();
    menuUtama();
    break;
  }

  endMsg();
}

char daftarMenu[2][50] = {
    "Enkripsi                  \0",
    "Dekripsi                  \0"};

int main()
{
  startingScreen();
  menuUtama();
  return 0;
}

//Prosedur Enkripsi
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

//Prosedur Dekripsi
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

void outputText(const char *format, ...)
{
  va_list args;
  va_start(args, format);

  // Define a maximum segment size
  int segmentSize = 64;

  // Process the input message
  char outputMessage[2048]; // Increase the buffer size to avoid buffer overflow
  int outputLength = vsnprintf(outputMessage, 2048, format, args);

  va_end(args);

  for (int i = 0; i < outputLength; i += segmentSize)
  {
    int remainingChars = outputLength - i;
    int charsToPrint = (remainingChars < segmentSize) ? remainingChars : segmentSize;

    outMsg("%.*s", charsToPrint, outputMessage + i);
  }
}