#include <bits/stdc++.h>
#define MAXN 100100
typedef long long ll;

using namespace std;

int n, m, s[MAXN], depth[MAXN], anc[MAXN][40];
vector<int> g[MAXN];
bool vis[MAXN];

int dfs(int x, int d, int p){
	vis[x] = true;
	depth[x] = d;
	s[x] = 1;
	anc[x][0] = p;
	for(int i = 1; pow(2, i) <= d; i++){
		anc[x][i] = anc[anc[x][i - 1]][i - 1];
	}
	for(int i = 0; i < g[x].size(); i++){
		if(vis[g[x][i]]) continue;
		s[x] += dfs(g[x][i], d + 1, x);
	}

	return s[x];
}

int walk(int x, int d){
	int i = 0;
	while(d){
		if(d & 1) x = anc[x][i];
		d /= 2;
		i++;
	}
	//cout << "\n";
	return x;
}

int lca(int x, int y){
	//cout << x<<y;

	if(depth[x] < depth[y]) y = walk(y, depth[y] - depth[x]);
	if(depth[x] > depth[y]) x = walk(x, depth[x] - depth[y]);
	//cout << x<<y;
	if(x == y) return x;
	for(int i = 30; i >= 0; i--){
		if(depth[x] >= pow(2, i) && anc[x][i] != anc[y][i]){
			return lca(anc[x][i], anc[y][i]);
		}
	}
	return anc[x][0];
}

int main(){
	ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n - 1; i++){
    	int a, b;
    	cin >> a >> b;
    	g[a].push_back(b);
    	g[b].push_back(a);
    }
    dfs(1, 0, -1);
    cin >> m;
    for(int i = 0; i < m; i++){
    	int a, b;
    	cin >> a >> b;
    	if(depth[a] > depth[b]) swap(a, b);
    	if(a == b) cout << n;
    	else{
    		int l = lca(a, b);
    		int d = -2 * depth[l] + depth[a] + depth[b];
    		if(d % 2) cout << "0";
    		else{
    			if(depth[a] == depth[b]) cout << s[1] - s[walk(b, d / 2 - 1)] - s[walk(a, d / 2 - 1)];
    			else cout << s[walk(b, d / 2)] - s[walk(b, d / 2 - 1)];
    		}
    	}
    	cout << "\n";
    }

}