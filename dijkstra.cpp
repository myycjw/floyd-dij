/*
输入一张图（点数，边数，边的信息）后将直接输出点a-h的最短路 
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
int i, j, k;
int dijkstra(int s, int t) {
	for (i = 1; i <= n; i++) {
		dis[i] = inf;
		vis[i] = 0;
	}
	dis[s] = 0;
	for (i = 1; i <= n; i++) {
		k = -1;
		int min = inf;
		for (j = 1; j <= n; j++) {
			if (!vis[j] && min > dis[j]) {
				min = dis[j];
				k = j;
			}
		}
		if (k == -1) break;
		vis[k] = 1;
		for (j = 1; j <= n; j++)
			if (dis[j] > dis[k] + mp[k][j])
				dis[j] = dis[k] + mp[k][j];
	}
	return dis[t];
}
int main() {
	char a, b;
	int w;
	while (scanf("%d %d", &n, &m) != EOF) {
		for (i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				mp[i][j] = inf;
		}
		int x, y;
		for (i = 1; i <= m; i++) {
		    getchar();
			scanf("%c %c %d", &a, &b, &w);
			x = a - 96, y = b - 96;
			mp[x][y] = w;
		}
		int ans = dijkstra(1, 8);
		printf("%d\n", ans);
	}
	return 0;
}
