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
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<int> st;
	string s;

	int part = 0;
	int arr[50001];
	memset(arr, 0, sizeof(arr));

	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
			st.push(1);

		else
		{
			if (s[i - 1] == '(')
			{
				st.pop();
				if (st.size() != 0)
					arr[st.size()]++;					
			}

			else
			{
				part += arr[st.size()] + 1;
				arr[st.size() - 1] += arr[st.size()];
				arr[st.size()] = 0;
				st.pop();
			}
		}
	}

	cout << part;

	return 0;
}
