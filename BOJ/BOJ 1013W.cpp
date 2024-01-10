#include <iostream>
#include <string>

using namespace std;

bool func0(string s, int num) {
    if (s[num] != '1') {
        return false;
    }
    return true;
}

int func1(string s, int num) {
    if (s[num] != '0' || s[num + 1] != '0') {
        return -1;
    }

    for (int i = num + 2; i < s.length(); i++) {
        if (s[i] != '0') {
            num = i;
            break;
        }
    }

    int c = 0;
    for (int i = num; i < s.length(); i++) {
        if (s[i] != '1') {
            if (s[i + 1] == '0') {
                return i - 2;
            } else if (s[i + 1] == '1') {
                return i - 1;
            }
            return -1;
        }
        c++;
        num = i;
    }

    if (c == 0)
        return -1;
    else
        return num;
}

bool func(string s) {
    for (int i = 0; i < s.length(); ++i) {
        int num;
        if (s[i] == '0') {
            if (!func0(s, i + 1)) {
                return false;
            }

            ++i;
        } else if (s[i] == '1') {
            num = func1(s, i + 1);
            if (num == -1) {
                return false;
            }
            i = num;
        }
    }
    return true;
}

int main(void) {
    int m;

    scanf("%d", &m);

    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;

        if (func(s)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}