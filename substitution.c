#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Usage errors:
    // Braindead
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // Lower than average IQ
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    for (int k = 0; k < 26; k++)
    {
        for (int l = 0; l < 26; l++)
        {
            if ((argv[1][k] == argv[1][l] || tolower(argv[1][k]) == argv[1][l] ||
                 toupper(argv[1][k]) == argv[1][l]) &&
                l != k)
            {
                printf("Key must contain 26 unique characters\n");
                return 1;
            }
        }
        if (argv[1][k] < 65 || argv[1][k] > 90)
        {
            if (argv[1][k] < 97 || argv[1][k] > 122)
            {
                printf("Key must contain 26 characters\n");
                return 1;
            }
        }
    }
    // The actual program:
    string alphacap = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string alphalow = "abcdefghijklmnopqrstuvwxyz";
    string plain = get_string("plaintext:  ");
    int plainlen = strlen(plain);
    for (int i = 0; i < plainlen; i++)
    {
        for (int j = 0; j < 26; j++)
            if (plain[i] == alphacap[j])
            {
                plain[i] = toupper(argv[1][j]);
                break;
            }
            else if (plain[i] == alphalow[j])
            {
                plain[i] = tolower(argv[1][j]);
                break;
            }
    }
    printf("ciphertext: %s\n", plain);
}
