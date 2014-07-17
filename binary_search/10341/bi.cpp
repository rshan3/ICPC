#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
int p,q,r,s,t,u;
double x;


double Equa(double X){
	return p*exp(-X) + q*sin(X) + r*cos(X) + s*tan(X) + t*X*X + u;

}

int main(){
	freopen("in.txt","r",stdin);
	while(cin >> p >> q >> r >> s >> t >> u){

		if(Equa(1) >0 ||Equa(0)  <0) {cout << "No solution" << endl;continue;}
		double low,mid,high;low=0;high=1;mid=1;
		while(high-low>1e-9){
			mid=(low+high)/2.0;
			
			if(Equa(mid) <0) {high=mid;}
			else {low=mid;}

			
			
		}
		
		printf("%.4lf\n",mid);
	

	}

	return 0;}
