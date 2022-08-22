// AlgorithmPractice.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <cstdio>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(void) 
{
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);

	queue<int> q;

	int a;
	int n;
	cin >> n;

	string s;
	
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		
		if (s.compare("push")==0)
		{
			cin >> a;
			q.push(a);
		}

		else if (s.compare("pop")==0)
		{
			if (q.empty())
				cout << "-1" << "\n";
			else
			{
				cout << q.front() << "\n";
				q.pop();
			}			
		}

		else if (s.compare("size")==0)
		{
			cout << q.size() << "\n";
		}

		else if (s.compare("empty")==0)
		{
			if (q.empty())
				cout << "1" << "\n";
			else
				cout << "0" << "\n";
		}

		else if (s.compare("front")==0)
		{
			if (q.empty())
				cout << "-1" << "\n";
			else
				cout << q.front() << "\n";
		}

		else if (s.compare("back")==0)
		{
			if (q.empty())
				cout << "-1" << "\n";
			else
				cout << q.back() << "\n";
		}
	}

	return 0;
}
