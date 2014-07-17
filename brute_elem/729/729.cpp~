#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,h,zero,one;
int c[20]; 

void comb(int cur){
	if(cur==n){
		for(int i=0;i<n;i++) cout << c[i];
		cout << endl; }

	else{
		if(zero){
				c[cur]=0;zero--;
				comb(cur+1);zero++; }
		if(one){
				c[cur]=1;one--;
				comb(cur+1);one++;
			}
		}
}

int main(){
	freopen("in.txt","r",stdin);
	int ds;
	cin >> ds;
	while(ds--){
		cin >> n; cin >> h;
		zero=n-h;one=h;
		comb(0);
		if(ds) cout << endl;

	}

}
