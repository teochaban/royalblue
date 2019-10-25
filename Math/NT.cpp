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

int main() {
	/*
	mt19937 rrand(time(NULL));
	ll ff = 1e18;
	for (int i = 0; i < 100000; i++){
		ll a = rrand() % ff;
		ll b = rrand() % ff;
		auto g = ex_gcd(a, b);
		cout << g.F << endl;
		assert(g.S.F*a + g.S.S*b == g.F);
	}*/
	return 0;
}
