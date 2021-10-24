#include <stdio.h>

int main(void) {

    int i = 0;
    int j = 0;
    char *s = "ceded";

    while (s[i] != '\0') {
      j = j + s[i] - 'a';
      i = i + 1;
    }
    printf("%d %d\n", i, j);

    return 0;
}