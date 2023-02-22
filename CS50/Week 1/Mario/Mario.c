#include <stdio.h>

int getInt() {
  int rows = 0;
  while (rows < 1 || rows > 8) {
    printf("Please enter a number between 1 and 8\n");
    scanf("%d", &rows);
  }
  return rows;
}

int main() {
  int rows = getInt();

  for (int j = 0; j < rows; j++) {
    for (int i = 0; i < (rows - j - 1); i++) {
      printf(" ");
    }
    for (int i = 0; i < (j + 1); i++) {
      printf("#");
    }
    printf("  ");
    for (int i = 0; i < (j + 1); i++) {
      printf("#");
    }
    printf("\n");
  }
  return 0;
}

