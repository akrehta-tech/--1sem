#include <stdio.h>

int check_16(int n) {
    if ((n & 15) == 0) return 1;
    else return 0;

}

int main() {
    int num;
    scanf("%d", &num);
    if (check_16(num) == 1) {
        printf("кратно");
    } else {
        printf("НЕ кратно");
    }

    return 0;


}
