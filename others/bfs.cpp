#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

const int maxn = 100005;

int n, m, s;
int dist[maxn];
vector <int> g[maxn];

void bfs(int st) {
	for(int i = 1 ; i <= n ; ++ i)
		dist[i] = -1;
	/// echivalenta cu memset(dist, -1, sizeof(dist));
	queue <int> q;
	dist[st] = 0;
	q.push(st);
	while(!q.empty()) {
		int node = q.front();
		q.pop();
		for(int i = 0 ; i < int(g[node].size()) ; ++ i) {
			int vecin = g[node][i];
			if(dist[vecin] == -1) {
				dist[vecin] = dist[node] + 1;
				q.push(vecin);
			}
		}
	}
}

int main() {
	ifstream fin("bfs.in");
	ofstream fout("bfs.out");

	fin >> n >> m >> s;
	for(int i = 1 ; i <= m ; ++ i) {
		int x, y;
		fin >> x >> y;
		g[x].push_back(y); /// x -> y
	}

	bfs(s);

	for(int i = 1 ; i <= n ; ++ i)
		fout << dist[i] << ' ';
}
