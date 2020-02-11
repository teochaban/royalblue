int t[2*N], n; // When debugging, the prob is most likely that you have multiple n's. need this one here!

int query(int l, int r){ // This r is exclusive!
	int ans=0;
	for(l+=n, r+=n; l<r; l>>=1, r>>=1){
		if(l&1)ans+=t[l++];
		if(r&1)ans+=t[--r];
	}
	return ans;
}

void update(int p, int v){
	for(t[p+=n]+=v; p>1; p>>=1){
		t[p>>1]=t[p]+t[p^1];
	}
}