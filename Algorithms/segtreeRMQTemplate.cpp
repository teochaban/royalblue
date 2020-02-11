#include <bits/stdc++.h>
#define MAXN 505
typedef long long ll;

using namespace std;

int n; // Range query, range update w/ lazy

int lo[4 * MAXN + 1], hi[4 * MAXN + 1], tree[4 * MAXN + 1], delta[4 * MAXN + 1];

void init(int i, int l, int r){
	lo[i] = l;
	hi[i] = r;
	if(l == r) return;
	int m = (l + r) / 2;
	init(2 * i, l, m);
	init(2 * i + 1, m + 1, r);
}

void prop(int i){
	delta[2 * i] += delta[i];
	delta[2 * i + 1] += delta[i];
	delta[i] = 0;
}

void update(int i){
	tree[i] = min(tree[2 * i] + delta[2 * i], tree[2 * i + 1] + delta[2 * i + 1]);
}

void inc(int i, int l, int r, int val){
	if(r < lo[i] || hi[i] < l) return;
	if(hi[i] <= r && lo[i] >= l){
		delta[i] += val;
		return;
	}
	//partial cover case
	prop(i);
	inc(2 * i, l, r, val);
	inc(2 * i + 1, l, r, val);
	update(i);
}

int query(int i, int l, int r){
	if(r < lo[i] || hi[i] < l) return INT_MAX;	//not in range
	if(hi[i] <= r && lo[i] >= l) return tree[i] + delta[i];	//completely in range
	prop(i);
	int minLeft = query(2 * i, l, r);
	int minRight = query(2 * i + 1, l, r);
	update(i);
	return min(minLeft, minRight);
}
int main(){
	init(1, 0, n - 1);
}
