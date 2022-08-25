// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

using ll = long long;

ll rec(ll a, ll b, ll n)
{
	if (b == 1)
	{
		return a % n;
	}

	else
	{
		if (b % 2 == 0)
		{
			ll k = rec(a, b / 2, n);
			return ((k % n) * k) % n;
		}

		else
		{
			ll k = (rec(a, (b - 1) / 2, n) % n) * rec(a, (b + 1) / 2, n);
			return k % n;
		}
	}
}

int main()
{
	ll a, b, n;

	cin >> a >> b >> n;

	cout << rec(a, b, n);

	return 0;
}
