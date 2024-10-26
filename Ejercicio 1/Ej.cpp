#include <stdio.h>

typedef struct {
    int arrInt[10];
    int arrSize;
    int arrAdd;
} arrayLength_t;

int initArray(arrayLength_t *arr) {
    if (!arr) return -1;
    for (int i = 0; i < 10; i++) {
        arr->arrInt[i] = -1;
    }
    arr->arrSize = 0;
    arr->arrAdd = 0;
    return 0;
}

void printArr(const arrayLength_t *arr) {
    printf("{[");
    for (int i = 0; i < 10; i++) {
        printf("%d", arr->arrInt[i]);
        if (i < 9) printf(", ");
    }
    printf("], %d, %d}\n", arr->arrSize, arr->arrAdd);
}

int addElement(arrayLength_t *arr, int value) {
    if (!arr || value < 0 || arr->arrSize >= 10) return -1;
    arr->arrInt[arr->arrSize] = value;
    arr->arrSize++;
    arr->arrAdd += value;
    return 0;
}

int getArrSize(const arrayLength_t *arr) {
    return arr ? arr->arrSize : -1;
}

int getArrAdd(const arrayLength_t *arr) {
    return arr ? arr->arrAdd : -1;
}

int getElement(const arrayLength_t *arr, int pos) {
    if (!arr || pos < 0 || pos >= 10 || arr->arrInt[pos] < 0) return -1;
    return arr->arrInt[pos];
}

int setElement(arrayLength_t *arr, int pos, int value) {
    if (!arr || pos < 0 || pos >= 10 || value < 0 || arr->arrInt[pos] < 0) return -1;
    arr->arrAdd = arr->arrAdd - arr->arrInt[pos] + value;
    arr->arrInt[pos] = value;
    return 0;
}

int resetArr(arrayLength_t *arr) {
    return initArray(arr);
}

int main() {
    arrayLength_t al1, al2;

    initArray(&al1);
    initArray(&al2);

    printArr(&al1);

    for (int i = 0; i <= 9; i++) {
        addElement(&al1, i * 10);
    }
    printArr(&al1);

    for (int i = 1; i < 10; i += 2) {
        setElement(&al1, i, i);
    }
    printArr(&al1);

    for (int i = 0; i < 10; i += 2) {
        addElement(&al2, al1.arrInt[i]);
    }

    for (int i = al2.arrSize; i < 10 && i - al2.arrSize < 5; i++) {
        addElement(&al2, i - al2.arrSize);
    }

    printArr(&al2);

    return 0;
}
