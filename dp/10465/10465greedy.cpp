#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int t,m,n;

void search(){
		int temp=t;
		while(temp>=0){

		
			int cnt=0;int temp2=temp;
			while(temp2>=0){
				if(temp2%m==0){cout << cnt+temp2/m; if(t!=temp) cout << ' ' << t-temp; cout << endl;  return;}
				cnt++;			
				temp2-=n;	
				}
		
		temp--;
	}

}



int main(){
	freopen("in.txt","r",stdin);
	while(cin >> m >> n >> t){

		if(m > n) swap(m,n);


		search();
}


}
