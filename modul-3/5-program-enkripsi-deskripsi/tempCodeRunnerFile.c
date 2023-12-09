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