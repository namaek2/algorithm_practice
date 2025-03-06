// AlgorithmPractice.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
/*1.
list.erase(iterator); 을 사용하면 오류가 난다.
이는 iterator가 가리키는 주소가 erase로 인해 유요하지 않게 된 채로 다음 명령을 실행했기 때문인 것으로 보여진다.
erase가 삭제한 것의 다음 iterator 값을 반환해주기 때문에
iterator = list.erase(iterator); 로 작성해주면 문제 해결
*/

/*2.
코드 실행시간을 줄여주기 위해 사용하는
ios::sync_with_stdio(false);
cin.tie(NULL);
을 list.end();와 사용하면 오류가 났었다. 이상하게 list.begin();과는 오류가 나지 않았는데 아마 list.erase(iterator); 과의 충돌 때문이었던 것으로 추측된다.
*/

#include <cstdio>
#include <iostream>
#include <string>
#include <list>

using namespace std;

int main(void) 
{
	string s;
	list<char> sl;

	char a;
	char b;


	cin >> s;

	for (auto c : s)
	{
		sl.push_back(c);
	}

	int n;

	cin >> n;


	list<char>::iterator iter = sl.end();

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		cin.ignore();

		if (a == 'L')
		{
			if(iter != sl.begin())
				iter--;
		}

		else if (a == 'D')
		{
			if(iter != sl.end())
				iter++;
		}

		else if (a == 'B')
		{
			if (iter != sl.begin())
			{
				iter--;
				iter = sl.erase(iter);
			}
		}

		else if (a == 'P')
		{
			cin >> b;
			sl.insert(iter, b);
		}
	}

	for (auto c : sl)
	{
		cout << c;
	}

	return 0;
}

