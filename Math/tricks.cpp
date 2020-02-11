ll fexp(ll a, int x, ll mod){		// Fast exponenciation returns a^x % mod
	if(x==0)return 1ll;
	if(x%2==0){
		ll y=fexp(a, x/2, mod);
		return (y*y)%mod;
	}
	return (a*fexp(a, x-1, mod))%mod;
}

ll divv(ll a, ll b, ll mod){	// Division with mod returns a/b % mod
	return (a*fexp(b, mod-2, mod))%mod;
}

ll f[N];

ll fat(ll a, ll mod){		// Calculates factorial and stores in f % mod
	if(a<=1)return 1;
	return f[a]?f[a]:(f[a]=(a*fat(a-1, mod))%mod);
}

ll choose(ll n, ll k, ll mod){	// Returns n choose k % mod
	return divv(fat(n, mod), (fat(k, mod)*fat(n-k, mod))%mod, mod)%mod;
}

ll gcd(ll a, ll b){	// Greatest common divisor
	return b?gcd(b, a%b):a;
}

ll lcm(ll a, ll b){	// Least common multiple
	return (a*b)/gcd(a, b);
}


/* Fast factorization */

int p[N];

void start_fast(int MAX){	// Runs O(nlog(n)) Needs to be called to use fast_fact or ammount_of_divisors.
	for(int i=2; i<=MAX; i++){
		if(p[i]==0){
			for(int j=i; j<=MAX; j+=i){
				p[j]=i;
			}
		}
	}
}

vector<int>fast_fact(int x){	// Fast factorization in O(log2(x))
	vector<int>ret;
	while(x>1){
		ret.pb(p[x]);
		x/=p[x];
	}
	return ret;
}

int amount_of_divisors(int x){	// Calculate the ammount of divisors of a number in O(log2(x)) assume already ran start_fast.
	if(x==1)return 1;
	vector<int>v=fast_fact(x);
	int ret=1, curr=2;
	for(int i=1; i<v.size(); i++){
		if(v[i]==v[i-1])curr++;
		else{
			ret*=curr;
			curr=2;
		}
	}
	return ret*curr;
}
