vector<ll> dijkstra(vector<vector<pii>> &G, int v) {
    vector<ll> ans(G.size() + 1, inf);
    ans[v] = 0;
    auto cmp = [&](int i, int j) { return ans[i] > ans[j]; };
    priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
    q.push(v);
    while(!q.empty()) {
        auto f = q.top();
        q.pop();
        for(auto i : G[f]){
            if (ans[i.fi] > ans[f] + i.se){
            	ans[i.fi] = ans[f] + i.se;
                q.push(i.fi);
            }
        }
    }
    return ans;
}
