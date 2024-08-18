STL hacks:
copying set to vector : set<> s; vector<> v(all(s));

array to unique array(unique fn on array): ll n=unique(a, a+n)-a; (returns size of new array where all elements are unique (not sorted))