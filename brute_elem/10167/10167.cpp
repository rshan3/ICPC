#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int n,A,B,countup,countdown;
int x[101];
int y[101];


void solve(){
	
	for(int a=0;a<=500;a++){
		
		for(int b=0;b<=500;b++){
			
			int flag=1;countup=0;countdown=0;
			for(int k=0;k<2*n;k++){

				int diff=a*x[k]+b*y[k];
				if(diff<0) countup++;
				else if(diff>0) countdown++;
				else {flag=0;break;}
						}
				
			if(flag==1&&countup==countdown) {A=a;B=b; return;}
						}
		for(int b=0;b<=500;b++){
			int flag=1;countup=0;countdown=0;
			for(int k=0;k<2*n;k++){

				int diff=a*x[k]-b*y[k];
				if(diff<0) countup++;
				else if(diff>0) countdown++;
				else {flag=0;break;}
						}
				
			if(flag==1&&countup==countdown) {A=a;B=-b; return;}
				}

}}
int main(){
	freopen("in.txt","r",stdin);
	while(cin >> n && n!=0)
	{
	
	for(int i=0;i<2*n;i++){

		cin >> x[i];
		cin >> y[i];		
		}
	solve();
	cout << A << ' ' << B << endl;;
		}


	return 0;}

