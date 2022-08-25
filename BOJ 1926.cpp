// AlgorithmPractice.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

bool vis[502][502];

int arr[502][502];
int bq = 0;

int ax, by;

void BFS(int a, int b)
{
	queue<pair<int, int>> q;
	q.push({ a, b });
	vis[a][b] = true;

	int da[4] = { 1, 0, -1, 0 };
	int db[4] = { 0, 1, 0, -1 };
	
	int temp = 0;

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();
		temp++;

		for (int i = 0; i < 4; i++)
		{
			int x = cur.first + da[i];
			int y = cur.second + db[i];

			if (x < 0 || y < 0)
				continue;
			else if (x >= ax || y >= by)
				continue;

			if (arr[x][y] == 1 && vis[x][y] == false)
			{
				vis[x][y] = true;
				q.push({ x, y });
			}

		}
	}
	
	if (temp > bq)
		bq = temp;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int count = 0;

	cin >> ax >> by;

	
	for (int i = 0; i < ax; i++)
	{
		for (int j = 0; j < by; j++)
		{
			cin >> arr[i][j];
			vis[i][j] = false;
		}
	}

	for (int i = 0; i < ax; i++)
	{
		for (int j = 0; j < by; j++)
		{
			if (arr[i][j] == 1 && vis[i][j] == false) 
			{
				BFS(i, j);
				count++;
			}

			else
				continue;
		}
	}
	
	cout << count << "\n";
	cout << bq <<"\n";

	return 0;
}
