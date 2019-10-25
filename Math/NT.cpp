#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

// The Extended Euclidean Algorithm
// 
// Returns {gcd, {x, y}} where x*a + y*b == gcd
pair<ll, pair<ll, ll>> ex_gcd(ll a, ll b) {
	bool fl = false;
	if (a < b){
		swap(a, b);
		fl = true;
	}

	ll ca[2] = {1, 0};
	ll cb[2] = {0, 1};
	while (b){
		ll t = a / b;
		a = a % b;

		ll newA = ca[0] - t * ca[1];
		ll newB = cb[0] - t * cb[1];
		ca[0] = ca[1];
		ca[1] = newA;
		cb[0] = cb[1];
		cb[1] = newB;

		swap(a, b);
	}

	if (fl)
		swap(ca[0], cb[0]);
	return {a, {ca[0], cb[0]}};
}

// O(n.lg(n))
int phi[1000];
void calcPhiUpTo(int n){
	for (int i = 1; i <= n; i++) phi[i] = i;
	for (int i = 1; i <= n; i++)
		for (int j = i+i; j <= n; j += i)
			phi[j] -= phi[i];
}

// O(sqrt(n))
ll calcPhi(ll n) {
	ll ret = n;

	vector<ll> ps;
	for (ll i = 2; i * i <= n; i++)
		if (n % i == 0){
			ps.push_back(i);
			while (n%i==0)
				n /= i;
		}
	if (n > 1)
		ps.push_back(n);

	for (ll p: ps)
		ret /= p, ret *= (p-1);
	return ret;
}

int main() {
	return 0;
}
