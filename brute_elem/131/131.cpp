#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
using namespace std;

int handv[5];
int handc[5];
int deckv[5];
int deckc[5];
int paizu[9];
int fv[5];
int fc[5];
int dis[5];
int k;
string name[9]={"straight-flush","four-of-a-kind","full-house","flush","straight","three-of-a-kind","two-pairs","one-pair","highest-card"};

int init(){
	char s[4];int count=0;
	if(cin >> s) {cout << "Hand: "<< s << ' ';
		if(s[0]=='A'){handv[count]=14;}
		else if(s[0]=='T'){handv[count]=10;}
		else if(s[0]=='J'){handv[count]=11;}
		else if(s[0]=='Q'){handv[count]=12;}
		else if(s[0]=='K'){handv[count]=13;}
		else handv[count]=s[0]-'0';
		
		if(s[1]=='C') handc[count]=1;
		else if(s[1]=='D') handc[count]=2;
		else if(s[1]=='H') handc[count]=3;
		else handc[count]=4;		

		count++;	}
	else return 0;
	while(count<5){
		cin >> s;
		cout << s << ' ';
		if(s[0]=='A'){handv[count]=14;}
		else if(s[0]=='T'){handv[count]=10;}
		else if(s[0]=='J'){handv[count]=11;}
		else if(s[0]=='Q'){handv[count]=12;}
		else if(s[0]=='K'){handv[count]=13;}
		else handv[count]=s[0]-'0';
		
		if(s[1]=='C') handc[count]=1;
		else if(s[1]=='D') handc[count]=2;
		else if(s[1]=='H') handc[count]=3;
		else handc[count]=4;		

		count++;		}
		
	
	cout << "Deck: ";
		count=0;
		while(count<5){
			cin >> s;
			cout << s << ' ';
			if(s[0]=='A'){deckv[count]=14;}
			else if(s[0]=='T'){deckv[count]=10;}
			else if(s[0]=='J'){deckv[count]=11;}
			else if(s[0]=='Q'){deckv[count]=12;}
			else if(s[0]=='K'){deckv[count]=13;}
			else deckv[count]=s[0]-'0';
		
			if(s[1]=='C') deckc[count]=1;
			else if(s[1]=='D') deckc[count]=2;
			else if(s[1]=='H') deckc[count]=3;
			else deckc[count]=4;		

	
			count++;	}
			

	
}

int tonghuashun(){
		for(int i=0;i<4;i++) {
			if(fc[i]!=fc[i+1]) return 0;
			}
	
		int a[5];int b[5];bool flag=true;
		for(int i=0;i<5;i++){ if(fv[i]!=14) b[i]=fv[i]; else b[i]=1;}
		for(int i=0;i<5;i++){ a[i]=fv[i];}
		sort(a,a+5);sort(b,b+5);
		for(int i=0;i<4;i++){
			if(a[i]!=a[i+1]-1) {flag=false;break;}
			}
		if(flag){
		paizu[0]=1;
		return 1;}
		for(int i=0;i<4;i++){
			if(b[i]!=b[i+1]-1) return 0;
			}
		paizu[0]=1;
		return 1;
		
}

int sitiao(){
	int a[15];
	memset(a,0,sizeof(a));
	for(int i=0;i<5;i++){
		a[fv[i]-1]++;		
		}
	for(int i=0;i<15;i++){
		if(a[i]==4) {
			paizu[1]=1;
			return 1;	
			}
	}
	return 0;
	}

int saner(){
	int a[15];
	memset(a,0,sizeof(a));
	for(int i=0;i<5;i++){

		a[fv[i]-1]++;
			}
	int c1=0;int c2=0;
	for(int i=0;i<15;i++){
		if(a[i]==2) c1++;
		if(a[i]==3) c2++;
			}
	if(c1&&c2){paizu[2]=1;return 1;}
	else {return 0;}
}

int tonghua(){
	for(int i=0;i<4;i++){
		if(fc[i]!=fc[i+1]) return 0;
		}
	paizu[3]=1;
	return 1;

}

int yitiaolong(){
	int a[5];int b[5];bool flag=true;
		for(int i=0;i<5;i++){ if(fv[i]!=14) b[i]=fv[i]; else b[i]=1;}
		for(int i=0;i<5;i++){ a[i]=fv[i];}
		sort(a,a+5);sort(b,b+5);
		for(int i=0;i<4;i++){
			if(a[i]!=a[i+1]-1) {flag=false;break;}
			}
		if(flag){
		paizu[4]=1;
		return 1;}
		for(int i=0;i<4;i++){
			if(b[i]!=b[i+1]-1) return 0;
			}
		paizu[4]=1;
		return 1;
		
	}

int hulu(){
	int a[15];
	memset(a,0,sizeof(a));
	for(int i=0;i<5;i++){
		a[fv[i]-1]++;
		if(a[fv[i]-1]==3) {paizu[5]=1;return 1;	}	
		}
	return 0;
}

int liangdui(){
	int a[15];
	memset(a,0,sizeof(a));
	for(int i=0;i<5;i++){

		a[fv[i]-1]++;
			}
	int cc=0;
	for(int i=0;i<15;i++){
		if(a[i]==2) cc++;
			}
	if(cc==2){paizu[6]=1;return 1;}
	else {return 0;}

	}

int yidui(){
	int a[15];
	memset(a,0,sizeof(a));
	for(int i=0;i<5;i++){
		a[fv[i]-1]++;
		if(a[fv[i]-1]==2) {paizu[7]=1;return 1;	}	
		}
	return 0;
}

int gaopai(){
	paizu[8]=1; return 1;
}


void calc(){
		int curc=0;	
	for(int i=0;i<5;i++) {
		if(dis[i]==1){
			fv[curc]=handv[i];
			fc[curc]=handc[i];
			curc++;
				}
		}			
	for(int i=0;curc<5;curc++){
		fv[curc]=deckv[i];
		fc[curc]=deckc[i];
		i++;
			}

		if(tonghuashun()) return;	
		
		if(sitiao()) return;
		
		if(saner()) return;
		
		if(tonghua()) return;
		
		if(yitiaolong()) return;
		
		if(hulu()) return;
		
		if(liangdui()) return;
		
		if(yidui()) return;
		
		else gaopai();
		
		

	}







int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(init()){
		
		memset(paizu,0,sizeof(paizu));
	

		for(int i=0;i< (1 << 5);i++){
			for(int j=0;j<5;j++){
				if((1 << j) & i){
					dis[j]=1;
							}
				else dis[j]=0;
				}
		calc();
			}
		for(int i=0;i<9;i++){
			if(paizu[i]!=0) {
				cout << "Best hand: ";
				cout << name[i] << endl;
				break;}	}	
	}
	return 0;
}
