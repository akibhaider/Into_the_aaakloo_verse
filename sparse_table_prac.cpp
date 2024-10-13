    ll n, l, r, q; cin>>n>>q;
    vll v(n);
    for(auto &c:v)cin>>c;

    vector<vll> SpT(26, vll(n+3, 0ll));
    
    rep(i, 0, n){
        SpT[0][i]=v[i];
    }

    rep(i, 1, 26){
        rep(j, 0, (n+1-(1<<i))){
            SpT[i][j] = max(SpT[i-1][j] , SpT[i-1][j+(1<<(i-1))]);
        }
    }
    // rep(i, 0, 6){
    //     rep(j, 0, (n+1-(1<<i))){
    //         cout<<SpT[i][j]; spc;
    //     }ln;
    // }

    while(q--){
        cin>>l>>r;
        ll rng = r-l+1;
        rng = (ll)floor(log2((double)rng));
        l--; r--;
        cout<<max(SpT[rng][l], SpT[rng][r-(1<<rng)+1]);
    }
