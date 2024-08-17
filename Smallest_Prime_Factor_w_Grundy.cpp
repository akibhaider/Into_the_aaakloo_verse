vector<ll> Primes;

vector<ll> Sieve_spf(ll N) // O(log(log N))
{
    ll i, j;    
    vector<bool> is_prime(N+1, 1);
    is_prime[0] = is_prime[1] = 1;

    vector<ll> spf(N+1);
    for(i=0; i<=N; i++) spf[i]=i;
    
    for(i=2; i<=N; i++) if(spf[i]==i)
    {
        if(is_prime[i]){
            Primes.push_back(i);
            for(j=i*i; j<=N; j+=i){
                is_prime[j]=0;
                if(spf[j]==j) spf[j]=i;
            } 
        }
    }
    return spf;
}

vector<ll> calc_Grundy(vector<ll> &spf, ll N){
    vector<ll> g(N+1,0);

    g[1]=1;

    ll i;
    for(i=1; i<Primes.size(); i++){
        g[Primes[i]]=i+1;
    }
    for(i=3; i<N; i++){
        if(g[i]==0){
            g[i]=g[spf[i]];
        }
    }
    return g;
}