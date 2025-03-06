import requests

def send_get_request():
    url = "http://webhacking.kr/challenge/web-16/?server=1.233.148.75"
    
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
        "PHPSESSID":"752rcqm6dc16esi752lefgk09c",
    }



    # GET 요청 보내기
    response = requests.get(url, headers=headers, cookies=cookies)
    
    # 응답 상태 코드 확인
    if response.status_code == 200:
        print("Request successful!")
    else:
        print(f"Request failed with status code: {response.status_code}")

start_port = 0
end_port = 100

for port in range(start_port, end_port + 1):
    url = f'http://webhacking.kr/challenge/web-16/?server=1.233.148.75'
    try:
        response = requests.get(url)
        # 응답 상태 코드 확인
        print(response.text)
        print(f'{port}: Status Code {response.status_code}')
    except requests.exceptions.RequestException as e:
        # 예외 처리 (연결 실패 등)
        print(f'Error {e}')
