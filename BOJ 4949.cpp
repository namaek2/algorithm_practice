// AlgorithmPractice.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <cstdio>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) 
{
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);

	stack<int> st;
	string s;

	bool temp = true;

	while (1)
	{
		getline(cin, s);

		if (s.compare(".") == 0)
			return 0;

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

			else if (s[i] == '.')
			{
				break;
			}
		}

		if (!temp || !st.empty())
		{
			cout << "no\n";
			temp = true;
			while (!st.empty()) st.pop();
		}		

		else
			cout << "yes\n";		
	}

	return 0;
}
