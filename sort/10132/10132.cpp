#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int n,mincnt,maxcnt,minl,maxl;
int l;
bool thefind;
int vis[300];
string seg[300];
string ans;
string minseg[2];string maxseg[2];

bool cmp(const string & s1,const string & s2)  {
	
	if(s1.size()!=s2.size()) return s1.size()<s2.size();
	return s1<s2;

}


void search(string s){
	bool ok=true;
	
	memset(vis,0,sizeof(vis));
	
	for(int i=0;i<n/2 && ok;i++){
		for(int j=n-1;j>i;j--){
			if(vis[i]==1 || vis[j]==1 ||seg[i].size()+seg[j].size()!=l) continue;
	
			if(seg[i]+seg[j]==s) {vis[i]=1;vis[j]=1;break;}
			else if(seg[j] + seg[i] ==s) { vis[i]=1;vis[j]=1;break;}
				
		}
		if(vis[i]==0) {ok=false;break;}	
	}
	if(ok) {ans=s;thefind=true;}
	
}


void solve(){
	thefind=false;
	for(int i=0;i<mincnt;i++){
		for(int j=0;j<maxcnt;j++){
			if(!thefind) search(minseg[i]+maxseg[j]);
			if(!thefind) search(maxseg[j]+minseg[i]);
			}
		}

}


int main(){
	freopen("in.txt","r",stdin);
	int ks;
	cin >> ks;getchar();getchar();
	while(ks--){

	
		n=0;
		while(getline(cin,seg[n]) && seg[n].size()){

			n++;
		
		}

		sort(seg,seg+n,cmp);
		minl=seg[0].size();maxl=seg[n-1].size();l=minl+maxl;
		mincnt=1;minseg[0]=seg[0];
		for(int i=1;i<n&&seg[i].size()==minl&&mincnt<2;i++){if(seg[i]!=minseg[mincnt-1]) {minseg[mincnt++]=seg[i];}}
		maxcnt=1;maxseg[0]=seg[n-1];
		for(int i=n-2;i>-1&&seg[i].size()==maxl&&maxcnt<2;i--){if(seg[i]!=maxseg[maxcnt-1]) {maxseg[maxcnt++]=seg[i];}}
		
		solve();
		 cout<< ans << endl;
		if(ks) cout << endl;
			}
		return 0;

}
