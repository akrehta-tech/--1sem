#include <stdio.h>

int zone(int x) 
    {
        if (x < 100) return 0;
        if ((100 < x) && (x < 139)) return 1;
        if ((140 < x) && (x < 169)) return 2;
        if (x > 170) return 3;
        return -1;
}


void TimingZone(int *ar, int sizeArray) {
    int mode = zone(ar[0]);
    int timing[4] = {0, 0, 0, 0};
    for(int i=1; i < sizeArray; i++) {
        timing[mode] += 1;
        mode = zone(ar[i]);
    }
    printf("Покой: %d с, Разминка: %d с, Кардио: %d с, Пик: %d с\n", timing[0],  timing[1],  timing[2],  timing[3]);
}


void AveragePulse(int *array, int sizeArray) {
    int aver = 0;
    for (int i=0; i < sizeArray; i++) {
        aver += array[i];
    }
    printf("Средний пульс: %d\n", aver / sizeArray);
}


void FinderSeria(int *array, int sizeArray) {
    int newMode = 0;
    int mode = 0;
    int start = 0;
    int timeSeria = 0;
    int stop = 0;
    int maxSeria = 0;
    int startSeria = 0;
    int stopSeria = 0;
    for(int i=1; i < sizeArray; i++) {
        newMode = zone(array[i]);
        if ((newMode == 2) && (mode != newMode)) {
            start = i;
        }
        if ((newMode != 2) && (mode == 2)) {
            stop = i;
            timeSeria = stop - start;
            if (maxSeria < timeSeria) {
                startSeria = start;
                stopSeria = stop;
                maxSeria = timeSeria;
            }
        }
    mode = newMode;
    }
    printf("Начало серии %d c, конец серии %d c, длина серии %d с\n", startSeria, stopSeria, maxSeria);
}


int main() {
    int arr[] = {85, 92, 98, 105, 118, 130, 142, 148, 151, 147, 150, 160, 165, 158, 143, 138, 120, 110, 104, 96, 90, 88, 150, 152};
    int sizeArray = sizeof(arr)/sizeof(int);
    TimingZone(arr, sizeArray);
    FinderSeria(arr, sizeArray);
    AveragePulse(arr, sizeArray);
}
