#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
	freopen("in.txt","r",stdin);
	int n;
	cin >> n;char s[15];
	while(n--){
		cin >> s;
		sort(s,s+strlen(s));
		do{
		cout << s << endl;
			}while(next_permutation(s,s+strlen(s)));
	cout << endl;
		}


	return 0;}
