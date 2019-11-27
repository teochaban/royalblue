#include<bits/stdc++.h>

using namespace std;

const int MAXN=1000000,    // maximum possible number of nodes in suffix tree
    INF=1000000000; // infinity constant
string s;       // input string for which the suffix tree is being built
int t[MAXN][26],   // array of transitions (state, letter)
    l[MAXN],   // left...
    r[MAXN],   // ...and right boundaries of the substring of a which correspond to incoming edge
    p[MAXN],   // parent of the node
    link[MAXN],   // suffix link
    tv,     // the node of the current suffix (if we're mid-edge, the lower node of the edge)
    tp,     // position in the string which corresponds to the position on the edge (between l[tv] and r[tv], inclusive)
    sz,     // the number of nodes
    la;     // the current character in the string

void ukkadd(int c) { // add character s to the tree
    suff:;      // we'll return here after each transition to the suffix (and will add character again)
    if (r[tv]<tp) { // check whether we're still within the boundaries of the current edge
        // if we're not, find the next edge. If it doesn't exist, create a leaf and add it to the tree
        if (t[tv][c]==-1) {t[tv][c]=sz;l[sz]=la;p[sz++]=tv;tv=link[tv];tp=r[tv]+1;goto suff;}
        tv=t[tv][c];tp=l[tv];
    } // otherwise just proceed to the next edge
    if (tp==-1 || c==s[tp]-'a')
        tp++; // if the letter on the edge equal c, go down that edge
    else { 
        // otherwise split the edge in two with middle in node sz
        l[sz]=l[tv];r[sz]=tp-1;p[sz]=p[tv];t[sz][s[tp]-'a']=tv;
        // add leaf sz+1. It corresponds to transition through c.
        t[sz][c]=sz+1;l[sz+1]=la;p[sz+1]=sz;
        // update info for the current node - remember to mark sz as parent of tv
        l[tv]=tp;p[tv]=sz;t[p[sz]][s[l[sz]]-'a']=sz;sz+=2;
        // prepare for descent
        // tp will mark where are we in the current suffix
        tv=link[p[sz-2]];tp=l[sz-2];
        // while the current suffix is not over, descend
        while (tp<=r[sz-2]) {tv=t[tv][s[tp]-'a'];tp+=r[tv]-l[tv]+1;}
        // if we're in a node, add a suffix link to it, otherwise add the link to sz
        // (we'll create sz on next iteration).
        if (tp==r[sz-2]+1) link[sz-2]=tv; else link[sz-2]=sz; 
        // add tp to the new edge and return to add letter to suffix
        tp=r[tv]-(tp-r[sz-2])+2;goto suff;
    }
}

void build() {
    sz=2;
    tv=0;
    tp=0;
    fill(r,r+MAXN,(int)s.size()-1);
    // initialize data for the root of the tree
    link[0]=1;
    l[0]=-1;
    r[0]=-1;
    l[1]=-1;
    r[1]=-1;
    memset (t, -1, sizeof t);
    fill(t[1],t[1]+26,0);
    // add the text to the tree, letter by letter
    for (la=0; la<(int)s.size(); ++la)
        ukkadd (s[la]-'a');
}

int main() {
	cin >> s;
	build();
	cout << sz << endl;
	cout << t[0][0] << endl;
	cout << t[1][0] << endl;
	return 0;
}
