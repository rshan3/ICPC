#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int mod=20071027;
int ncnt,n;
char S[300005];
int d[300005];
char sp[4005][105];

struct node{
	//int val;
	bool isword;
	node* next[26];
	void init(){
		//val=-1;
		isword=false;
		memset(next,0,sizeof(next));}
	
}tr[400005];
node* root;

void insert(node* cur,char *s){
	node* p =root;
	int len=strlen(s);int idx;
	for(int i=0;i<len;i++){	
		idx=s[i]-'a';
		if(p->next[idx]==NULL){
			tr[ncnt].init();
			p->next[idx]=tr+ncnt;
			ncnt++;
			}
		p=p->next[idx];		
	}
	p->isword=true;
}

void find(node* cur,int i){
	d[i]=0;
	node* p=root;int idx;
	for(int j=i;S[j];j++){
		idx=S[j]-'a';
		
		if(p->next[idx]==NULL) return;		
		p=p->next[idx];
		if(p->isword) {d[i]=(d[i]+d[j+1])%mod;}
	
		}
}

int main(){
	freopen("in.txt","r",stdin);
	int ks=0;
	while(cin >> S){
		root=tr;
		root->init();
		cin >> n;ncnt=1;
		for(int i=0;i<n;i++) {
			cin >> sp[i];		
			insert(root,sp[i]);}
		
		d[strlen(S)]=1;
		for(int i=strlen(S)-1;i>=0;i--){
			find(root,i);}
		ks++;
		printf("Case %d: %d\n",ks,d[0]);
	}

	return 0;}
