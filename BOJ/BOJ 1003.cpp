
#include <iostream>

using namespace std;

int t0 = 0;
int t1 = 0;

int arr0[41] = {
    1,
    0,
};
int arr1[41] = {
    0,
    1,
};

int arrf[41] = {
    0,
};

int fibonacci(int n) {
    if (n == 0) {
        ++t0;
        return 0;
    } else if (n == 1) {
        ++t1;
        arrf[1] = 1;
        return 1;
    } else if (arrf[n] != 0) {
        t0 += arr0[n];
        t1 += arr1[n];
        return arrf[n];
    }

    arrf[n] = fibonacci(n - 1) + fibonacci(n - 2);

    arr0[n] = t0;
    arr1[n] = t1;
    return arrf[n];
}

int main() {
    int a, b;
    scanf("%d", &a);

    for (int i = 0; i < a; i++) {
        scanf("%d", &b);
        fibonacci(b);
        // printf("%d,", );
        printf("%d %d\n", arr0[b], arr1[b]);
        t0 = 0;
        t1 = 0;
    }
    return 0;
}
