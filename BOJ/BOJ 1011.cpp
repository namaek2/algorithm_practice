// 1011

#include <iostream>

using namespace std;

int main(void) {
    int m = 0;
    scanf("%d", &m);

    unsigned int x, y;
    for (int i = 0; i < m; i++) {
        scanf("%u %u", &x, &y);

        unsigned int n = y - x;
        unsigned int k = 1;

        if (n == 1) {
            printf("1\n");
            continue;
        }

        // 시간복잡도 O(log2 n)
        for (unsigned int j = 2; j * j < n + j; ++j) {
            if (j * (j + 1) < n)
                continue;
            else if (j * (j + 1) > n) {
                k = j - 1;
                break;
            } else if (j * (j + 1) == n) {
                k = j;
                break;
            }
        }

        // 시간복잡도 O(n)
        // for (k = 0; k * (k + 1) < d; ++k) {}

        unsigned int calc = n - k * (k + 1);
        unsigned int r;
        if (calc == 0)
            r = 2 * k;
        else if (calc > k + 1)
            r = 2 * k + 2;
        else
            r = 2 * k + 1;

        printf("%u\n", r);
    }
}