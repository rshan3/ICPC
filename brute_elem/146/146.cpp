#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char s[100];
char temp[100];
bool flag;

void replace(int cur){
	int min=50;int minp=cur;
	for(int j=cur+1;j<strlen(s);j++){
		if(s[j]-'a'<min&& s[j]>s[cur]) {min=s[j]-'a';minp=j;}
		}
	char t=s[cur];
	s[cur]=s[minp];
	s[minp]=t;int cnt=0;
	memset(temp,'\0',sizeof(temp));
	for(int j=cur+1;j<strlen(s);j++){
		temp[cnt++]=s[j];}
	sort(temp,temp+strlen(temp));
	cnt=0;
	for(int j=cur+1;j<strlen(s);j++){
		s[j]=temp[cnt++];}
}

int main(){
	freopen("in.txt","r",stdin);
	while(cin >> s){
		flag=false;
		if(s[0]=='#') break;
		int i=strlen(s)-1;
		for(;i>0;i--){
			if(s[i-1]-s[i] < 0){
				replace(i-1);
				cout << s << endl;flag=true; break;}
				}
		if(!flag)
		cout << "No Successor" << endl;
		
		}

	return 0;}
