#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define DAY 1
#define NIGHT -1
#define TIME -1
#define HUMAN 1
#define DIVINE 2
#define EVIL 3
#define TYPE 0
#define HONEST 1
using namespace std;
int person[5][4];
int words[52][6]; 
int thetime;
int pcnt;
int n,state;
int occur[5];
int result[5][4];
int resulttime[2];
bool flag;
char name[4][20]={""," is human."," is divine.", " is evil."};

void init(string s,int cur){
	words[cur][0]=s[0]-'A';occur[s[0]-'A']=1;
	if(s[3]=='I'){
		if(s[4]=='t'){
			words[cur][1]=TIME;
			if(s[9]=='d'){words[cur][2]=DAY;}
			else {words[cur][2]=NIGHT;}

					}
		else{
			words[cur][1]=s[0]-'A';
			if(s[8]=='n'){
				if(s[12]=='d'){words[cur][2]=-2;}
				else if(s[12]=='e'){words[cur][2]=-3;}
				else if(s[12]=='h'){words[cur][2]=-1;}
				else {words[cur][3]=1;}		}
			else{
				if(s[8]=='d'){words[cur][2]=2;}
				else if(s[8]=='e'){words[cur][2]=3;}
				else if(s[8]=='h'){words[cur][2]=1;}
				else {words[cur][3]=-1;}	

					}
			}
		}	
	else{ words[cur][1]=s[3]-'A';occur[s[3]-'A']=1;
		if(s[8]=='n'){
				if(s[12]=='d'){words[cur][2]=-2;}
				else if(s[12]=='e'){words[cur][2]=-3;}
				else if(s[12]=='h'){words[cur][2]=-1;}
				else {words[cur][3]=1;}		}
			else{
				if(s[8]=='d'){words[cur][2]=2;}
				else if(s[8]=='e'){words[cur][2]=3;}
				else if(s[8]=='h'){words[cur][2]=1;}
				else {words[cur][3]=-1;}	

					}
}
}

bool check(int i){
		if(person[words[i][0]][HONEST]==1){
			if(words[i][1]==-1){return words[i][2]==thetime;}
			else{
				if(words[i][2]==0){return words[i][3]==person[words[i][1]][HONEST];}
				else{ if(words[i][2]>0) return words[i][2]==person[words[i][1]][TYPE];
					else return words[i][2]+person[words[i][1]][TYPE]!=0;	}
						}
							}

		else{	
				if(words[i][1]==-1){return words[i][2]==-thetime;}
				else{
					if(words[i][2]==0){return words[i][3]==-person[words[i][1]][HONEST];}
					else{ if(words[i][2]>0) return words[i][2]-person[words[i][1]][TYPE]!=0;
					else return words[i][2]==-person[words[i][1]][TYPE];	}
						}
						
					}


}



void combinate(int cur){
	
	if(pcnt==n){
		for(int i=0;i<state;i++){if(!check(i)) return;}
			
			flag=true;
			for(int i=0;i<5;i++) {if(occur[i]) result[i][person[i][TYPE]]=1;}
				if(thetime==DAY) {resulttime[0]=1;}
				else {resulttime[1]=1;}			
			return;
			}
	else{
	if(occur[cur]){pcnt++;
		for(int i=1;i<4;i++){
			person[cur][TYPE]=i;
			if(thetime==DAY)
			person[cur][HONEST]= i==3?-1:1;
			else
			person[cur][HONEST]= i==2?1:-1;
				
			combinate(cur+1);
			
			}
			pcnt--;
		}
	else combinate(cur+1);}
}
int main(){
	freopen("in.txt","r",stdin);
	int cnt=0;string str;
	while(cin >> state && state){
		memset(occur,0,sizeof(occur));
		for(int i=0;i<52;i++){for(int j=0;j<4;j++) words[i][j]=0;}
		getchar();
		n=0;resulttime[0]=0;resulttime[1]=0;pcnt=0;
		
		cout <<"Conversation #" << ++cnt << endl;
		for(int i=0;i<state;i++){
			getline(cin,str);
			init(str,i);

		}
	flag=false;
	for(int i=0;i<5;i++){for(int j=0;j<4;j++) result[i][j]=0;}
	for(int i=0;i<5;i++) {if(occur[i]) n++;}
	thetime=DAY;
	combinate(0);
	thetime=NIGHT;pcnt=0;
	combinate(0);
	if(flag){bool somefact=false;
		for(int i=0;i<5;i++){ int possiblecnt=0;int record=0;
			for(int j=1;j<4;j++){
				if(result[i][j]==1) {possiblecnt++;record=j;}
				}
			if(possiblecnt==1){somefact=true; cout << char('A'+i) << name[record] << endl; }
			}
		if(resulttime[0]==1&&resulttime[1]==0){ cout << "It is day." << endl; somefact=true; }
		else if(resulttime[0]==0&&resulttime[1]==1){ cout << "It is night." << endl; somefact=true; }
		
		if(!somefact){cout << "No facts are deducible." << endl;}
		}
	else cout << "This is impossible." << endl;

	
	
	cout << endl;
		}

	return 0;}
