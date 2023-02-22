#include <ctype.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char *word);

int main(void) {
    char word1[15];
    printf("Player 1: ");
    scanf("%s", word1);
    char word2[15];
    printf("Player 2: ");
    scanf("%s", word2);

    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2) {
        printf("Player 1 Wins!\n");
    } else if (score2 > score1) {
        printf("Player 2 Wins!\n");
    } else {
        printf("Tie!\n");
    }
    
}

int compute_score(char *word) {
    int score = 0;
    for (int i = 0, j = strlen(word) ; i < j ; i++) {
        word[i] = toupper(word[i]);
        word[i] -= 65;
        score += POINTS[word[i]];
    }
    return score;

}
