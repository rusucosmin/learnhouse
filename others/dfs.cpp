#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

const int maxn = 100005;

int n, m, cntConexe;
vector <int> g[maxn];
bool vizitat[maxn];
vector <int> comp[maxn];

void dfs(int node) {
	vizitat[node] = 1;
	comp[cntConexe].push_back(node);
	for(int i = 0 ; i < int(g[node].size()) ; ++ i) {
		int vecin = g[node][i];
		if(!vizitat[vecin])
			dfs(vecin);
	}
}

int main() {
	ifstream fin("dfs.in");
	ofstream fout("dfs.out");

	fin >> n >> m;
	for(int i = 1 ; i <= m ; ++ i) {
		int x, y;
		fin >> x >> y;
		g[x].push_back(y); /// adaugam in lista lui x elementul y
		g[y].push_back(x); /// adaugam in lista lui y elementul x
	}
	for(int i = 1 ; i <= n ; ++ i)
		if(!vizitat[i]) { 	// daca un nod nu e vizitat, parcurgem toata
							// componentat conexa a nodului resp
			++ cntConexe;
			dfs(i);
		}
	fout << cntConexe << '\n';
	for(int i = 1 ; i <= cntConexe ; ++ i) {
		fout << "componenta conexa #" << i << '\n';
		for(int j = 0 ; j < int(comp[i].size()) ; ++ j)
			fout << comp[i][j] << ' ';
		fout << "\n";
	}
}
