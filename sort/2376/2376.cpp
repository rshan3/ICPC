#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,t;

struct COW{
	int start;int end;

}cow[25004];

bool cmp(const COW & a,const COW & b){

	if(a.start!=b.start) return a.start<b.start;
	else return a.end<b.end;
}



int main(){
	freopen("in.txt","r",stdin);
	while(cin >> n >> t){

		for(int i=0;i<n;i++) cin >> cow[i].start >> cow[i].end;	
		

	sort(cow,cow+n,cmp);int tm=1;int idx=0;bool flag=true;int cnt=0;int maxium;
	while(tm<=t){
		
		int maxium=-1;
		for(;idx<n && cow[idx].start<=tm;idx++) {maxium=max(maxium,cow[idx].end);}
		if(maxium<tm) {flag=false;break;}
		tm=maxium+1;cnt++;
	
}
	if(flag) cout << cnt << endl;
	else cout << -1 << endl;}

	return 0;}
