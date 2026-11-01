#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

int recurs_min_max(int a[], int n, int i, int min, int max);

#ifndef UNIT_TEST
int main(){
    const int n = 20;
    int a[n], i, low = -20, high = 34, sum;
    srand((unsigned)time(NULL));

    for(i=0; i < n; i ++){
        a[i] = low + rand() % (high - low + 1);
    }
    cout << "Початковий масив: " << endl;
    for(i=0; i < n; i++){
        cout << setw(4) << a[i];
    }
    cout << endl;

    sum = recurs_min_max(a, n, 0, a[0], a[0]);
    cout << "Сума мінімального та максимального елементів: " << sum << endl;
}
#endif

int recurs_min_max(int a[], int n, int i, int min, int max){
    if (i == n){
        return min + max;
    }

    if (a[i] < min){
        min = a[i];
    }
    if (a[i] > max){
        max = a[i];
    }
    return recurs_min_max(a, n, i + 1, min, max);
}