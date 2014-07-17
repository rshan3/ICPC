#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
int theX[250000];
char s[100];
struct KB{
		double k;double b;
	
}kb[250000];

struct point{
	int x;int y;
}pts[710];


bool cmp(const KB & A,const KB & B) {

	if(abs(A.k-B.k) < 1e-7) return A.b<B.b;
	return A.k<B.k;

}


int main(){
	freopen("in.txt","r",stdin);
	int ks;
	cin >> ks;
	getchar();getchar();
	while(ks--){
		
		n=0;
		while(cin.getline(s,sizeof(s)) && strlen(s)!=0){
		
		sscanf(s,"%d%d",&pts[n].x,&pts[n].y);
		n++;}
		if(n==1) {cout << 1 << endl;if(ks) cout << endl; continue;}
		int kbcnt=0;int xcnt=0;int A,B,C;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				A=pts[i].y-pts[j].y;B=pts[j].x-pts[i].x;C=pts[i].x*pts[j].y-pts[i].y*pts[j].x;
				if(B==0) {theX[xcnt++]=pts[i].x;}
				else { kb[kbcnt].k=((double)-A)/B;kb[kbcnt].b=((double)C)/B;kbcnt++;}
	
				}
		}

		
		sort(kb,kb+kbcnt,cmp);
		int cnt=1;double lastk=kb[0].k;double lastb=kb[0].b; int tmax=1;
		for(int i=1;i<kbcnt;i++){
			if(abs(kb[i].k-lastk)<1e-7 && abs(kb[i].b-lastb)<1e-7) {cnt++;}
			else {lastk=kb[i].k;lastb=kb[i].b;if(cnt>tmax) tmax=cnt;cnt=1;}
			}
		tmax=max(tmax,cnt);

		sort(theX,theX+xcnt);
	int lastx=theX[0];cnt=1;
		for(int i=1;i<xcnt;i++){
			if(theX[i]==lastx){cnt++;}
			else {lastx=theX[i];tmax=max(cnt,tmax); cnt=1;}
			}
		tmax=max(cnt,tmax);
		
		int sum=0;int ans;
		for(ans=1;sum<tmax;ans++) {sum+=ans;}
		
			
	
		cout << ans <<endl;
		if(ks) cout << endl;
}

	return 0;}
