#include <stdio.h>
#define N 10
int main() {
    int re[N] = {-105, 1111, -10101, 5555, 11, 10, 999, 90, 666, -10};
    int im[N] = {7887, -1111, 526, 9090, 1234, 322, -322, 888, 8181, -1};
    double energy = 0;
    int max_re = re[0];
    int max_index = 0;
    printf("отсчёты сигнала:\n");
    for (int i = 0; i < N; i++){
        printf("s[%d] = %d.0 + j*(%d.0)\n", i, re[i], im[i]);
    }

    for (int i = 0; i < N; i++) {
        energy = energy + re[i] * re[i] + im[i] * im[i];
    }
    printf("Энергия сигнала: %.2f\n", energy);


    for (int i = 1; i < N; i++) {
        if (re[i] > max_re) {
            max_re = re[i];
            max_index = i;
        }
    }
    printf("Макс элемент реальной части: %d, индекс: %d\n", max_re, max_index);
    return 0;
}
