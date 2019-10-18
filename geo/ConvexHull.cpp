vector<pt> convexhull(vector<pt> p){	//counterclockwise, no collinear points
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());
	vector<pt> up, dn;
	for(pt i : p){
		while(up.size() > 1 and orient(up[up.size() - 2], up.back(), i) >= 0) up.pop_back();
		while(dn.size() > 1 and orient(dn[dn.size() - 2], dn.back(), i) <= 0) dn.pop_back();
		up.pb(i);
		dn.pb(i);
	}
	for(int i = (int) up.size() - 2; i >= 1; i--)
		dn.pb(up[i]);
	return dn;
}