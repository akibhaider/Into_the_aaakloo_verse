//Random Test case generator 
#include<bits/stdc++.h>
#define ll long long
#define nl "\n"
using namespace std;

int main(){
	srand(time(0));
	ll t=rand()%10 +1;
	cout<<t<<nl;
	for(ll i=0; i<t; i++){
		ll n=rand()%10+1;
		ll m=rand()%10+1;
		cout<<n<<" "<<m<<"\n";
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				ll x =rand()%10+1;
				cout<<x<<" ";
			}
			cout<<nl;
		}



		// cout<<n<<nl;

		// for(ll i=0; i<n; i++){
		// 	ll a=rand()%10+1;
			
		// 	cout<<a<<" ";
		// }
		// ll q=rand()%10+1;
		// cout<<q<<nl;
		// for(ll i=0; i<q; i++){
		// 	ll a=rand()%10+1;
		// 	ll b=rand()%10+1;
		// 	cout<<a<<" "<<b<<" ";
		// 	cout<<nl;
		// }
	}
	cout<<endl;
}