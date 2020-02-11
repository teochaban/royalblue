#include <bits/stdc++.h>
#define MAXN 100100
typedef long long ll;

using namespace std;

int n, sz[MAXN];
bool deleted[MAXN], vis[MAXN];
char ch[MAXN];
vector<int> g[MAXN];

void dfs(int x, int p){
	if(vis[x]) return;
	vis[x] = true;
	sz[x] = 1;
	for(auto i : g[x]){
		if(i == p || deleted[i]) continue;
		dfs(i, x);
		sz[x] += sz[i];
	}
	//cout << x << " " << sz[x] << "\n";
}

int findCentroid(int x){
	memset(vis, 0, sizeof(vis));
	dfs(x, -1);
	int p = -1, c = sz[x] / 2;
	while(true){
		bool found = false;
		for(auto i : g[x]){
			if(!deleted[i] && i != p && sz[i] > c){
				found = true;
				p = x;
				x = i;
				break;
			}
		}
		if(!found) return x;
	}	
}

void decomp(int x, char c){
	int cen = findCentroid(x);
	ch[cen] = c;
	deleted[cen] = true;
	for(auto i : g[cen]){
		if(deleted[i]) continue;
		decomp(i, c + 1);
	}
}

int main(){
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(deleted, 0, sizeof(deleted));
    cin >> n;
    for(int i = 0; i < n - 1; i++){
    	int a, b;
    	cin >> a >> b;
    	g[a].push_back(b);
    	g[b].push_back(a);
    }
    //cout << findCentroid(1);
    decomp(1, 'A');
    for(int i = 1; i <= n; i++){
    	cout << ch[i] << " ";
    }
}