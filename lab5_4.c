#include <stdio.h>
#define N 10

int main() {
    int re[N] = {-105, 1111, -10101, 5555, 11, 10, 9999, 90, 666, -10};
    double energy = 0;
    int maxIndex = 0;
    printf("Отсчёты сигнала:\n");
    for (int i = 0; i < N; i += 2){
        if (re[i] > re[maxIndex]) maxIndex = i;
        energy = energy + re[i] * re[i] + re[i+1] * re[i+1];
        printf("s[%d] = %d.0 + j*(%d.0)\n", i, re[i], re[i+1]);
    }
    printf("Энергия сигнала: %.2f\n", energy);
    printf("Макс элемент реальной части: %d, индекс: %d\n", re[maxIndex], maxIndex);
    return 0;
}
