#include <bits/stdc++.h>
#include <utility>
#define MAXN 505

using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
int n;

vector<pair<int, int> > g[MAXN];
int dist[MAXN];

void dijkstra(int x){
	for(int i = 0; i < n; i++){
		dist[i] = 99999999;
	}
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push({0, x});
	dist[x] = 0;
	while(!pq.empty()){
		pair<int, int> v = pq.top();
		pq.pop();
		for(int i = 0; i < g[v.second].size(); i++){
			pair<int, int> u = g[v.second][i];
			if(dist[v.second] + u.second < dist[u.first])
				pq.push({dist[u.first] = dist[v.second] + u.second, u.first});
		}
	}
}

int main(){
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
    //cin >> n;
}
