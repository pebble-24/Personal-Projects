// Libraries
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Constants
const int OFFSET = 'A';

// Prototypes
int CheckKey (int ArgCount, string Key[]);


int main (int argc, string argv[]) 
{   
    string key = argv[1];
    string plaintext = get_string("Plaintext: ");
    int length = strlen(plaintext);
    char ciphertext[length];

    // Check Key Is Valid
    int Check = CheckKey(argc, argv);
    if (Check == 1) {
        return 1;
    }

    for (int i = 0 ; i < length ; i++) {
        char letter = plaintext[i];
        if (isalpha(plaintext[i])) {
            
            char tmp = letter;
            letter = toupper(letter);
            letter -= OFFSET;
            char new = key[letter];

            letter = new;
            if (islower(tmp)) {
                letter = tolower(new);
            }
        }
        ciphertext[i] = letter;
    }
    printf("Ciphertext: %s\n", ciphertext);
}


int CheckKey (int ArgCount, string Key[])
{
    if (ArgCount == 1 || ArgCount > 2) {
        printf("Please enter a key\n");
        return 1;
    } else if (strlen(Key[1]) != 26) {
        printf("Key should be 26 Characters long\n");
        return 1;
    }
    
    int count[26] = {0};
    int letters = 0;

    for (int i = 0, length = strlen(Key[1]) ; i < length ; i++) {
        
        // Checks to see if all characters are alpha
        if (isalpha(Key[1][i])) {
            letters++; 
        }
        // Counts to see if all chars are used only once
        count[toupper(Key[1][i]) - OFFSET]++; 
    }

    // Checks to see if all chars are alpha
    if (letters != strlen(Key[1])) {
        printf("Key is not alphabetical"); 
        return 1;
    }

    // Checks if all chars are used only once
    for (int i = 0; i < 26; i++) {
        if (count[i] != 1) {
            printf("Key shouldn't contain duplicate characters\n"); 
            return 1;
        }
    }
    return 0;
}
