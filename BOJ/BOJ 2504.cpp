// AlgorithmPractice.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
#include <memory.h>

using namespace std;

int main(void)
{
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);

	stack<int> st;
	stack<int> t;
	stack<int> c;
	string s;

	bool temp = true;

	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
			st.push(1);

		else if (s[i] == '[')
			st.push(3);

		else if (s[i] == ')')
		{
			if (st.empty() || st.top() != 1)
			{
				temp = false;
				break;
			}

			else
				st.pop();
		}

		else if (s[i] == ']')
		{
			if (st.empty() || st.top() != 3)
			{
				temp = false;
				break;
			}

			else
				st.pop();
		}
	}

	if (!temp || !st.empty())
	{
		cout << "0\n";
		return 0;
	}

	while (!st.empty())st.pop();

	int a = 0;
	int b = 0;
	int fsum = 0;
	int sum = 0;
	int num = 0;

	int arr[31];

	memset(arr, 0, sizeof(arr));

	//곱셈 : 0, 덧셈 : 1
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
		{
			st.push(0);
		}
			

		else if (s[i] == '[')
		{
			st.push(0);
		}

		else if (s[i] == ')')
		{
			if (s[i - 1] == ')' || s[i - 1] == ']')
			{
				while (st.top() != 0)
				{
					num = st.top();
					st.pop();
					if (st.top() == 0)
					{
						st.top() = num;
						break;
					}
					st.top() += num;
				}

				if(st.top() != 0)
					st.top() = st.top() * 2;

				else
					st.top() = 1 * 2;
			}

			else
			{
				st.top() = 2;
			}
		}



		else if (s[i] == ']')
		{
			if (s[i - 1] == ')' || s[i - 1] == ']')
			{
				while (st.top() != 0)
				{
					num = st.top();
					st.pop();
					if (st.top() == 0)
					{
						st.top() = num;
						break;
					}						
					st.top() += num;
				}				

				if (st.top() != 0)
					st.top() = st.top() * 3;

				else
					st.top() = 1 * 3;
			}

			else
			{
				st.top() = 3;
			}
		}
	}
	while (!st.empty())
	{
		fsum += st.top();
		st.pop();
	}


	cout << fsum;
	return 0;
}

//	(()[(((([])()[(())])))]())

// 20 * 24 = 480
// 480 + 4
// 484 * 2 = 968
