#include <bits/stdc++.h>
#define MAXN 100100
#define DIM 2
#define pii pair<int, int>
#define pb push_back
typedef long long ll;

using namespace std;

ll mod = 1e9 + 7;
struct matrix{
	ll a[DIM][DIM];
	matrix(){
		memset(a, 0, sizeof(ll) * DIM * DIM);
	}

	void init(){
		a[0][0] = 0; a[0][1] = 1;
		a[1][0] = 1; a[1][1] = 1;
	}

	matrix operator*(matrix b){
		matrix c;
		for(int k = 0; k < DIM; k++) { 
			for(int i = 0; i < DIM; i++) {
				for(int j = 0; j < DIM; j++) {
					c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j]) % mod;
				}
			}
		}
		return c;
	}
	vector<ll> times(vector<ll> v){
		vector<ll> c(DIM, 0);
		for(int i = 0; i < DIM; i++){
			for(int j = 0; j < DIM; j++){
				c[i] += v[j] * a[i][j];
				c[i] %= mod;
			}
		}
		return c;
	}


};

matrix pow_matrix(matrix a, ll n) {
	if (n == 1) return a;
	matrix b = pow_matrix(a, n / 2);
	b = b * b;
	if (n & 1) b = b * a;
	return b;
}

int n;

int main(){
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    n = 10;
    vector<ll> base = {1, 1}, v;
    matrix m;
    m.init();
    m = pow_matrix(m, 4);
    v = m.times(base);
    cout << v[0];
}