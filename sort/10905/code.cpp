#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int N;

struct numb{
	string digit;
	}num[55];

bool cmp(const numb & a,const numb & b){
		return a.digit+b.digit>b.digit+a.digit;
}

int main(){
	freopen("in.txt","r",stdin);
	while(cin >> N && N){

		for(int i=0;i<N;i++) 
		cin>>num[i].digit;
		
		sort(num,num+N,cmp);
		
		for(int i=0;i<N;i++) cout << num[i].digit;
		cout << endl;
		}
	return 0;
}
