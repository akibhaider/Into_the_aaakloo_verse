#include<bits/stdc++.h>
#define vi vector<int>
#define vb vector<bool>
#define vll vector<long long>
#define vip vector<pair<int, int>>
#define M 1000000007
#define pb push_back 
#define ll long long
using namespace std;

void solve(){
    int n, m, cntA, cntC, cntT, cntG, res;
    string s;
    vector<pair<int, string>> ans;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>s;
        cntA=cntC=cntT=cntG=res=0;
        for(int i=n-1; i>=0; i--){
            if(s[i]=='T'){
                res+=(cntA+cntC+cntG);
                cntT++;
            }else if(s[i]=='G'){
                res+=(cntA+cntC);  
                cntG++;              
            }else if(s[i]=='C'){
                res+=(cntA);
                cntC++;
            }else{
                cntA++;
            }
        }
        ans.pb({res, s});
    }
    sort(ans.begin(), ans.end());
    for(auto c:ans){
        cout<<c.second<<endl;
    }
}

int main(){
    int t=1;
    string s;
    cin>>t;
    while(t--){
        solve();
        if(t)
            cout<<endl;
    }
    return 0;
}

