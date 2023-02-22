#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    string text = get_string("Text: ");
    int words = 0;
    int sentences = 0;
    int letters = 0;

    for (int i = 0, length = strlen(text); i < length ; i++) {
        switch (text[i]) {
        case 32:
        // 32 - Space
            words += 1;
            break;

        case 46: case 33: case 63: 
        // 46 - Full Stop, 33 - Exclamation Mark, 63 - Question Mark 
            sentences += 1;
            break;
        
        default:
            break;
        }

        if (isalnum(text[i])) {
            letters += 1;
        }
        if (i == length - 1) {
            words += 1;
        }
    }

    /*
    L is average number of letters per 100 words.
    S is average number of sentences per 100 words.
    */
    
    double index;
    float L;
    float S;
    int grade;
    L = (letters * 100) / words;
    S = (sentences * 100) / words;

    index = 0.0588 * L - 0.296 * S - 15.8 ;
    grade = round(index);

    if (grade < 1) {
        printf("Before Grade 1\n");
    } else if (grade >= 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %d\n", grade);
    }
}