/*
    This will take a matrix a[N][N] and choose one item for each row such that the sum of all items
    is minimized.
    O(n^3)
*/
#define N 107 

ll INF = 1000000000000000000ll;
int n;

ll a[N][N];
 
void hungarian(){
    vector<ll> u(n+1), v(n+1), p(n+1), way(n+1);
    for(int i=1; i<=n; i++){
        p[0] = i;
        ll j0 = 0;
        vector<ll> minv(n+1, INF);
        vector<char> used(n+1, false);
        do {
            used[j0] = true;
            ll i0 = p[j0],  delta = INF,  j1;
            for(int j=1; j<=n; j++){
                if(!used[j]) {
                    ll cur = a[i0][j]-u[i0]-v[j];
                    if(cur < minv[j])
                        minv[j] = cur,  way[j] = j0;
                    if(minv[j] < delta)
                        delta = minv[j],  j1 = j;
                }
            }
            for(int j=0; j<=n; j++){
                if(used[j])
                    u[p[j]] += delta,  v[j] -= delta;
                else
                    minv[j] -= delta;
            }
            j0 = j1;
        } while(p[j0] != 0);
        do {
            ll j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while(j0);
    }
    
    vector<int> ans(n+1);
    for(int j=1; j<=n; j++)
        ans[p[j]] = j;

}