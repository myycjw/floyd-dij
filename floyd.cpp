/*
输入一张图（点数，边数，边的信息）后，直接输出图的最短路径。 
*/ 
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
typedef int long long ll;
const int inf = 0x3f3f3f3f;
const int maxm = 110;
#define pi 3.141592653589794626
const int maxn = 1010;
int mp[maxn][maxn];
int dis[maxn];
bool vis[maxn];
int n, m;
int main() {
	while (scanf("%d %d", &n, &m) != EOF && !(n == 0 && m == 0)) {
		memset(mp, inf, sizeof mp);
		for (int i = 1; i <= n; i++)
			mp[i][i] = 0;
		while (m--) {
			int a, b, w;
			scanf("%d %d %d", &a, &b, &w);
			mp[a][b] = w;
		}
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					if (mp[i][j] > mp[i][k] + mp[k][j])
						mp[i][j] = mp[i][k] + mp[k][j];
		printf("%d\n", mp[1][n]);
	}
	return 0;
}
