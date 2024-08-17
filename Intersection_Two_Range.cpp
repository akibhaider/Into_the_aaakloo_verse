vector<ll> findIntersection(ll s1, ll e1, ll s2, ll e2){
    vector<ll> v(2);
    v[0]=max(s1, s2); 
    v[1]=min(e1, e2);
    if(v[0]<=v[1]){
        return v;
    }else{
        v[0]=v[1]=0;
        return v;
    } 
}
