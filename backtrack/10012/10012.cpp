#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;
double minsize;
int m;
double r[10];
int p[10];
double x[10];
double t_left,t_right;

void compute(){
	for(int i=1;i<m;i++){
		x[i]=0;
		for(int j=0;j<i;j++){
			double b=2*sqrt(r[p[i]]*r[p[j]]);
			double X=x[j]+b;
			if(X>x[i]) x[i]=X;
	}
		t_left=(x[i]-r[p[i]])<t_left?(x[i]-r[p[i]]):t_left;
		t_right=(x[i]+r[p[i]])>t_right?(x[i]+r[p[i]]):t_right;
}
	if(t_right-t_left<minsize) minsize=t_right-t_left;	

}


int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int ks;
	cin >> ks;
	while(ks--){
		cin >> m;
		for(int i=0;i<m;i++) cin >> r[i];
		if(m==0) cout << "0.000" << endl;
		else{	
			
		for(int i=0;i<10;i++) p[i]=i;
		minsize=1e9;	
		do{	x[0]=0;t_left=x[0]-r[p[0]];t_right=x[0]+r[p[0]];	
			compute();			
		}while(next_permutation(p,p+m));
		printf("%.3lf\n",minsize);
	}}
	
	return 0;
}
