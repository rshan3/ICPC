#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int n,a,cnt1,cnt2;
int c[1000005];

int main(){
	freopen("in.txt","r",stdin);

	while(cin >> n){

		for(int i=1;i<=n;i++) cin >> c[i];
	
		sort(c,c+n);
	
		if(n%2){ a=c[n/2+1];cnt1=1;cnt2=1;
			for(int i=n/2+2;i<=n && c[i]==a;i++) {cnt2++;} 
			for(int i=n/2;i>=1 && c[i]==a;i--) {cnt2++;}
			cout << a << ' ' << cnt2<<  ' ' << cnt1 << endl;
			}
		else{
			int l=c[n/2];int r=c[n/2+1];
			cnt1=r-l+1;
			
			cnt2=2;a=l;
			for(int i=n/2+2;i<=n && c[i]==r;i++) {cnt2++;} 
			for(int i=n/2-1;i>=1 && c[i]==l;i--) {cnt2++;}
			cout << a << ' ' << cnt2<<  ' ' << cnt1 << endl;
	}

}


	return 0;}
