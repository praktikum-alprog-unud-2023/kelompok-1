#include <stdio.h>

int main()
{
  printf("Hello World!");
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