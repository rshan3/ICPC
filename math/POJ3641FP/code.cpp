#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a,p;
bool is_prime(ll n){

	for(ll i=2;i*i<=n;i++){
		if(n%i==0) return false;
		}
	return true;
}


ll mod_pow(ll x,ll n,ll mod){
	ll ans=1;
	while(n>0){

		if(n&1) ans=ans*x%mod;
		x=x*x%mod;
		n>>=1;

		}


	return ans;}

int main(){
	freopen("in.txt","r",stdin);
	while(scanf("%lld%lld",&p,&a)==2){

		if(p==0 && a==0) break;
		if(mod_pow(a,p,p)==a && !is_prime(p)) printf("yes\n");
		else printf("no\n");

	
	}

	return 0;}
