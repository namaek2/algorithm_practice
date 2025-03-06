// AlgorithmPractice.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <cstdio>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<int> st;

	int num = 0;
	int a;

	cin >> num;

	string s;

	for (int i = 0; i < num; i++)
	{
		cin >> s;
		
		if (s.compare("push")==0)
		{
			cin >> a;
			st.push(a);
		}

		else if (s.compare("pop") == 0)
		{
			if (st.empty() == 1)
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << st.top() << "\n";
				st.pop();
			}
				
		}

		else if (s.compare("top") == 0)
		{
			if (st.empty() == 1)
			{
				cout << "-1" << "\n";
			}
			else
				cout<<st.top()<<"\n";
		}

		else if (s.compare("empty") == 0)
		{
			cout<<st.empty() << "\n";
		}

		else if (s.compare("size") == 0)
		{
			cout << st.size() << "\n";
		}
	}

	return 0;
}
