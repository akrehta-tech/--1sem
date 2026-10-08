//16
#include <stdio.h>

int invert(int a, int y) {
    a = a ^ (1 << y);
    return a;
}

int main() {
    int n;
    int i;
    int rez;
    scanf("%d", &n); // 1100
    scanf("%d", &i); // 0010
    rez = invert(n, i); 
    printf("Результат: %d\n", rez);
    return 0;
}
