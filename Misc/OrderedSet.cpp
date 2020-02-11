#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef pair<int, int> pii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag,
             tree_order_statistics_node_update>
			 OrderedSet;

#define F first
#define S second

int main() {
	OrderedSet st;
	st.insert({1, 22});
	st.insert({1, 33});
	st.insert({1, 44});
	st.insert({1, 55});
	cout << st.order_of_key({1,33}) << endl;
	cout << st.order_of_key({1,35}) << endl; // Where would it be?
	cout << (*st.find_by_order(2)).S << endl;
	return 0;
}
