#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

int randNew() {
    int big_rand = (rand() << 16 | rand());
    return -32768 + big_rand % 65538;
}

int main() {
    int re[N];
    double energy = 0;
    int maxIndex = 0;
    srand(time(NULL));
    printf("Отсчёты сигнала:\n");
    for (int i = 0; i < N; i += 2){
        re[i] = randNew();
        re[i + 1] = randNew();
        if (re[i] > re[maxIndex]) maxIndex = i;
        energy = energy + re[i] * re[i] + re[i+1] * re[i+1];
        printf("s[%d] = %d.0 + j*(%d.0)\n", i/2, re[i], re[i+1]);
    }
    printf("Энергия сигнала: %.2f\n", energy);
    printf("Макс элемент реальной части: %d, индекс: %d\n", re[maxIndex], maxIndex);
    return 0;
}
