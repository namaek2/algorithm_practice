#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    unsigned int v6;             // 랜덤 숫자 (사용자 입력)
    int v7;                      // 필요한 입력값
    unsigned int v11;            // XOR 결과
    char s[9];                   // 결과를 저장할 문자열
    char s1[9] = {0};            // 뒤집힌 문자열 결과
    const char *s2 = "a0b4c1d7"; // 목표 문자열
    char reversed_s2[9] = {0};   // 목표 문자열의 역순
    char buf[50] = "Here is a secret message!"; // 보상 메시지

    // 목표 문자열 뒤집기
    for (int i = 0; i < 8; ++i) {
        reversed_s2[i] = s2[7 - i];
    }

    // 사용자로부터 랜덤 숫자 입력 받기
    printf("Enter the random number: ");
    scanf("%x", &v6); // 16진수 입력

    // 목표 문자열을 역순으로 변경 후 XOR 연산을 통해 필요한 입력값 계산
    sscanf(reversed_s2, "%08x", &v11);
    v7 = v11 ^ v6;

    // 결과 출력
    printf("To achieve the target result '%s', you need to input: %d\n", s2,
           v7);

    return 0;
}
