# 코드 설명

### cipher.py

먼저, 주어진 파일의 파이썬 코드를 살펴보자. cipher.py를 먼저 살펴보면, 11번 라인에 DES의 블록 크기가 16인걸 알 수 있다. 그리고 14번 라인을 보면 모드 글자열의 길이는 3이여야 한다는 것도 알 수 있다. 그리고 30번 라인을 보면 평문의 길이가 DES블록 크기의 배수여야 한다는 것도 알 수 있다.

```pyhton
# 11번 라인
self._block_size = 16

# 16번 라인
assert len(mode) == 3

# 30번 라인
assert len(plaintext) % self._block_size == 0
```

Triple-DES에서는 키를 두 개 사용하는데, 이 문제에서는 가장 처음에 첫번째 키로 암/복호화, 그 다음에 두 번째 키로 암/복호화, 그리고 마지막에 다시 첫 번째 키로 암/복호화를 한다. EDE방식으로 암호화하면 key1으로 암호화, key2로 복호화, key1으로 암호화하여 총 3번의 DES계산을 한다는 것이다.

나머지 코드는 그냥 Triple-DES의 작동과 테스트 코드라 볼 필요 없다.

### prob.py

그러면 이제 prob.py를 보자. 36번째 라인을 살펴보면 1번 메뉴의 암호화를 입력하는 부분에 DED 모드를 사용할 수 없다고 한다. 왜냐하면 42번째 라인에서 플래그를 암호화 할 때 EDE 암호화 모드를 사용했기 때문에 암호화된 flag문을 DED로 다시 암호화하면 바로 평문 flag가 나와버리기 때문이다.

# 문제 풀이

### 들어가기 전에

역함수의 개념을 활용하면 쉽게 풀 수 있다.
암호화하는 함수를 E, 복호화하는 함수를 D라고 하자. 그리고 키가 두 개 이므로 E1, E2, D1, D2 이렇게 각각 존재한다. 여기서 E1과 D1. E2와 D2는 역함수 관계이다. 평문 d를 E1에 집어넣어 나온 값을 다시 D1에 넣는다면 다시 평문 x가 나온다는 말이다. E(D(1)) = 1 이라는거다.

### 문제 풀이

이 문제에서 플래그는 EDE로 암호화되어있다. 이는 플래그 d를 E1에 넣어 암호화한 값을 다시 D2에 넣고, 이렇게 나온 값을 다시 E1에 넣어 나오는 값이 EDE모드로 암호화된 최종 값이다.

이를 함수로 표현하면 다음과 같다.  
![CodeCogsEqn(2).png](https://dreamhack-media.s3.amazonaws.com/attachments/7a7765262f26d349c6dd5bb5639f0dd5c0cfd46f2189ec88d7823ec31993b275.png)

이 값을 DDD 모드로 암호화 해주고 중간에 인접한 역함수 관계의 함수를 정리해주면 다음과 같이 정리된다.

![CodeCogsEqn(3).png](https://dreamhack-media.s3.amazonaws.com/attachments/afc7ba7901b9651872ec408618d15fd2d58c260291639dee7e55a4eae1e42732.png)

이렇게 나온 값을 EED 암호화를 해주면 다음과 다음과 같이 평문 플래그에 EDD암호화를 한 것과 같은 값이 나온다.
![CodeCogsEqn(4).png](https://dreamhack-media.s3.amazonaws.com/attachments/0d124f0e8eb8b41814543075654792eca32109707168118c3e0c7f48f630cd1b.png)

여기에 EED 암호화를 다시 해주면 다음과 같이 평문 플래그를 얻을 수 있다.
![CodeCogsEqn(5).png](https://dreamhack-media.s3.amazonaws.com/attachments/7ccbcfb375c7d7eb6517f4013057c549dd648f42aecee7aa9daa503d37347ed0.png)

### 플래그 찾기

nc를 통해 주어진 문제 서버에 접속하고, 2번 메뉴에 나온 암호화된 플래그 문을 1번 메뉴에 붙여넣어 DDD, EED, EEd 모드로 차례로 암호화 해주면 플래그를 얻을 수 있다.
