/**
	Union find algorithm
	Complexity O(log n) for Join or Find.
*/

int pai[N];

void init(int n){
	for(int i=1; i<=n; i++){
		pai[i]=i;
	}
}

int find(int i){
	if(pai[i]==i)return i;
	return pai[i]=find(pai[i]);
}

int join(int a, int b){
	a=find(a);
	b=find(b);
	pai[a]=pai[b];
}