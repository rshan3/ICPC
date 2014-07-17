#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char s[100];
int alph[26];
int leng;
bool finded;
bool orig;
char p[100];

void check(){
	if(!orig){
		for(int i=0;i<leng;i++){
			if(p[i]!=s[i]) return;}
		orig=true;
		}
	else{
		finded=true;
		cout << p << endl;
		}

}

void permutate(int cur){
	if(!finded){
		if(cur==leng){
			check();	}
		for(int i=0;i<26;i++){
			if(alph[i]){
				p[cur]='a'+i;
				alph[i]--;
				permutate(cur+1);
				alph[i]++;}
			}

}
	}

int main(){
	freopen("in.txt","r",stdin);
	while(cin >> s){

		if(s[0]=='#') break;
		memset(alph,0,sizeof(alph));
		memset(p,0,sizeof(p));
		finded=false;orig=false;		
		int i;		
		for(i=0;s[i]!='\0';i++){
			alph[s[i]-'a']++;
				}
		leng=i;
		permutate(0);
		if(!finded) cout << "No Successor\n"; 
		}
	return 0;
}
