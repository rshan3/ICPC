#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MISS 1e-9
using namespace std;

int p,q,r,s,t,u;
double x;


double Equa(double X){
	return p*exp(-X) + q*sin(X) + r*cos(X) + s*tan(X) + t*X*X + u;

}

double slope(double X){

	return -p*exp(-X) + q*cos(X) - r*sin(X) + s*(1.0/cos(X)*cos(X)) + 2*t*X;
}

int main(){
	freopen("in.txt","r",stdin);
	while(cin >> p >> q >> r >> s >> t >> u){

		if(Equa(1) >0 ||Equa(0)  <0) {cout << "No solution" << endl;continue;}
		double ans=1;double pre=0;
		while(abs(ans-pre)>MISS){
			

			pre=ans;
			ans=ans-Equa(ans)/slope(ans);
			
		}
		
		printf("%.4lf\n",abs(ans));
	

	}


	return 0;}
