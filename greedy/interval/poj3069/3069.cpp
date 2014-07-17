#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int r,n;
int p[1005];

int main(){

	freopen("in.txt","r",stdin);
	while(cin >> r >> n){

		if(r==-1 && n==-1) break;

		for(int i=0;i<n;i++) cin >> p[i];
		sort(p,p+n);
		
		int i=0;int count=0;
		while(i<n){
			int pivot=i;
			for(;pivot<n && p[i]+r>=p[pivot];pivot++);
			pivot=pivot-1;count++;
			for(i=pivot;i<n && p[pivot]+r>=p[i];i++);	
			
			}
		cout << count << endl;
	}
	
}
