브라우저와 버프수트를 프록시로 연결해야 한다.

![image.png](https://dreamhack-media.s3.amazonaws.com/attachments/524f073d2f16b6ce341b5013a2b90a6d925ce43c717529362d1528a9de465328.png)
다음의 주어진 코드를 보자.
코드는 POST 패킷에서, key 값과 cmd_input을 받아 각각 key와 cmd변수에 저장한다.

그리고 조건문으로 cmd가 비어있고 key가 플래그를 해시화한 Key값인 경우, cmd가 비어있고 key가 guest_key인 경우, cmd가 비어있지 않거나(중요!) key가 플래그를 해시화한 Key인 경우를 검사한다.

guest_key를 비교하는 조건문은 의미가 없다.
그리고 우리는 Key값이 무엇인지 모르니 첫 번째 조건문도 미뤄두자. 그러면 가장 마지막 조건문의 조건인 cmd가 비어있지 않거나, key=Key 이거나 인데, Key 값을 모르므로 cmd가 비어있지 않게 해야한다.

자, 그럼 조건문을 파악했으니 보내지는 POST 패킷을 캡쳐해보자.

가장 먼저 your key에 아무 문자열 (ex: "aa")를 입력하고, submit을 누르면 전달되는 패킷을 버프수트로 인터셉트 한다.

POST /flag HTTP/1.1
Host: host3.dreamhack.games:24204
.
.
.
.
....
Upgrade-Insecure-Requests: 1
Priority: u=1

key=aa

그럼 다음과 같은 패킷이 뜬다. 가장 마지막에 우리가 입력한 aa가 key라는 변수에 들어가있다. 하지만 cmd가 저장되는 cmd_input은 없다! 우리가 직접 넣어주자.

POST /flag HTTP/1.1
Host: host3.dreamhack.games:24204
.
.
.
.
....
Upgrade-Insecure-Requests: 1
Priority: u=1

key=aa
cmd_input=11

다음과 같이 11을 넣어주었다.

![image.png](https://dreamhack-media.s3.amazonaws.com/attachments/3f55aac8c329de8f64d86e15d4a1d810aa8994499909e258dddd457b40d7d904.png)

다음과 같이 코드를 보면 cmd에 command_list에 들어가는 단어들은 필터링이 되었다는 true를 반환하고, 알파벳 소문자, 공백, 숫자를 제외한 다른 문자들도 true를 반환한다. 그래서 일단 아무렇게 11 넣어주었다.

그러면 다음과 같은 화면이 렌더링 된다.

![image.png](https://dreamhack-media.s3.amazonaws.com/attachments/2d7c65d3df563f5023cff991c914678797b8e9cd9482a58a8e9194217f0cb92c.png)

다음의 화면에 ls를 입력하라고 하는데 ls를 입력하면 리눅스 콘솔의 ls 명령어가 실행이 되는 모습을 볼 수 있다. 그럼 다시 flag 코드를 보자.

![image.png](https://dreamhack-media.s3.amazonaws.com/attachments/92bfe754c01436b01d65cac1162faab570ed0c0ea16a8f9e2f018005b7a83127.png)

우리는 아까의 세 번째 조건문을 이미 통과했다. 그리고 필터링에 걸리지 않게 11도 입력해줘서 필터링 구문도 통과했다. 그럼 바로 try를 확인해보자. try를 보니 cmd 명령어를 실행하는 코드이다. 이 때 예외상황이 두 가지 있다. 시간초과와(5초 이상) 그리고 무언가 프로세스가 잘못 실행되었을 때이다. 시간초과 예외상황이 발생했을 때 Key를 렌더링 하므로 우리는 시간초과 예외상황을 발생시켜야 한다. 아까의 ls를 입력했던 화면에 리눅스 콘솔에서 6초동안 동작을 멈추는 sleep 6를 입력해주자. 그러면 6초간의 기다림과 함께... 다음과 같이 Key가 뜬다!

![image.png](https://dreamhack-media.s3.amazonaws.com/attachments/5bdcaf6171a847d9a75ddc0d11d2d7c400c0342d1d9505648d004067c3a81da7.png)

그러면 아까 첫 번째 조건문에서 Key를 입력하면 flag를 반환해준다고 했으니 index페이지로 돌아가 Key값을 복사 붙여넣기 해주자.

![image.png](https://dreamhack-media.s3.amazonaws.com/attachments/1d20aeaed2e99b7d4dd62980ee64b0d3a94594e899c20417b1c4b66cf7d2ed92.png)

그럼 다음과 같이 플래그가 뜬다! 

-끝-
