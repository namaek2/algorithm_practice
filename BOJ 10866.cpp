// AlgorithmPractice.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <cstdio>
#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	deque<int> dq;
	string s;
	int n = 0;
	int num = 0;

	cin >> num;


	for (int i = 0; i < num; i++)
	{
		cin >> s;

		if (s.compare("push_front")==0)
		{
			cin >> n;
			dq.push_front(n);
		}

		else if (s.compare("push_back")==0)
		{
			cin >> n;
			dq.push_back(n);
		}

		else if (s.compare("pop_front")==0)
		{
			if (dq.empty() == 1)
			{
				cout<<"-1" << "\n";
			}

			else
			{
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}

		else if (s.compare("pop_back")==0)
		{
			if (dq.empty() == 1)
			{
				cout << "-1" << "\n";
			}

			else 
			{
				cout << dq.back() << "\n";
				dq.pop_back();
			}			
		}

		else if (s.compare("size")==0)
		{
			cout << dq.size() << "\n";
		}

		else if (s.compare("empty")==0)
		{
			if (dq.empty() == 1)
			{
				cout << "1" << "\n";
			}

			else
			{
				cout << "0" << "\n";
			}
		}

		else if (s.compare("front")==0)
		{
			if (dq.empty() == 1)
			{
				cout << "-1" << "\n";
			}

			else
			{
				cout << dq.front() << "\n";
			}
		}

		else if (s.compare("back")==0)
		{
			if (dq.empty() == 1)
			{
				cout << "-1" << "\n";
			}

			else
			{
				cout << dq.back() << "\n";
			}
		}
	}

	return 0;
}
