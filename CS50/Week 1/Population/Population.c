#include <stdio.h>

int main(void) {
    int start = 0;
    int end = 0;
    int years = 0;

    while (start < 9) {
        printf("Please enter a start size >= 9: ");
        scanf("%d", &start);
    }

    while (end < start) {
        printf("Please enter an end size which is > the start size: ");
        scanf("%d", &end);
    }

    int pop = start;
    while (pop < end) {
        int born = (pop / 3);
        int die = (pop / 4);
        pop += (born - die);
        years += 1;
    }
    printf("Years: %d", years);
    printf("\n");
}
