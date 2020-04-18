vector<pii> g[MAXN];
ll dist[MAXN];
bool vis[MAXN];

void dijkstra(int x){
    fill(dist, dist + MAXN, inf);
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, x});
    dist[x] = 0;
    while(!q.empty()){
        pii v = q.top();
        q.pop();
        if(vis[v.se]) continue;
        vis[v.se] = true;
        for(pii u : g[v.se]){
            if(dist[v.se] + u.se < dist[u.fi]){
                dist[u.fi] = dist[v.se] + u.se;
                q.push({dist[u.fi], u.fi});
            }
        }
    }
}
