#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int main(void)
{
	int x, y, h;
	//vector<vector<vector<int>>> arr3;
	//	vector < vector<int>> arr2;
	//vector<int>arr;

	//vector<vector<vector<int>>> var3;
	//vector < vector<int>> var2;
	//vector<int>var;

	int arr3[100][100][100];
	int var3[100][100][100];

	int dx[6] = { 0, 1, 0, -1 , 0, 0 };
	int dy[6] = { 1, 0, -1, 0 , 0, 0 };
	int dz[6] = { 0, 0, 0, 0 , 1, -1 };
	int mx = 0;

	queue<tuple<int, int, int>> q;

	cin >> x >> y >> h;
	int a;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < y; j++)
		{
			for (int u = 0; u < x; u++)
			{
				cin >> a;
				//arr.push_back(a);
				//var.push_back(0);

				arr3[i][j][u] = a;
				var3[i][j][u] = 0;

				if (a == 1)
					q.push({ i, j, u });
			}

			//arr2.push_back(arr);
			//var2.push_back(var);
		}
		//arr3.push_back(arr2);
		//var3.push_back(var2);
	}

	tuple<int, int, int> d;


	while (!q.empty())
	{
		tuple<int, int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nz = get<0>(cur) + dz[i];
			int ny = get<1>(cur) + dy[i];
			int nx = get<2>(cur) + dx[i];

			if (nx >= x || ny >= y || nz >= h || nx < 0 || ny < 0 || nz < 0)
				continue;

			else if (arr3[nz][ny][nx] == -1 || var3[nz][ny][nx] != 0 || arr3[nz][ny][nx] == 1)
				continue;

			var3[nz][ny][nx] = var3[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;

			if (var3[nz][ny][nx] > mx)
				mx = var3[nz][ny][nx];

			q.push({ nz, ny, nx });
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < y; j++)
		{
			for (int u = 0; u < x; u++)
			{
				if (var3[i][j][u] == 0 && arr3[i][j][u]!=1 && arr3[i][j][u] != -1)
				{
					cout << "-1";
					return 0;
				}
			}
		}
	}

	cout << mx;

	return 0;
}
