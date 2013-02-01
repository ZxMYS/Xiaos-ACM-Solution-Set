#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cassert>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<sstream>
using namespace std;
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define RLOOP(x,y,z) for((x)=(y);(x)>=(z);(x)--)
#define RLOOPB(x,y,z) for((x)=(y);(x)>(z);(x)--)
#define ABS(x) ((x)<0?-(x):(x))
#define PI 3.1415926535898
vector<pair<int,int> > combine[256];
vector<int> opp[256];

int main(){
	int i,j,k,a,m,n,s,t,l,tt,cas;
	int op,bp,ot,bt,ott,btt,last;
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d",&k);
	cas=1;
	
	vector<int> spell;
	/*LOOPB(i,0,256){
		combine[i]=new vector<pair<int,int> >();
		opp[i]=new vector<int>();
	}*/
	bool here[256];
	while(k--){
		memset(here,0,sizeof(here));
		spell.clear();
		LOOPB(i,0,256){
			combine[i].clear();
			opp[i].clear();
		}
		scanf("%d ",&n);
		s=t=l=0;
		LOOPB(i,0,n){
			scanf("%c%c%c ",&s,&t,&l);
			//printf("%d %d %d",s,t,l);
			//fflush(stdout);
			combine[s].push_back(make_pair(t,l));
			combine[t].push_back(make_pair(s,l));
		}
		scanf("%d ",&n);
		LOOPB(i,0,n){
			scanf("%c%c ",&s,&t);
			opp[s].push_back(t);
			opp[t].push_back(s);
		}
		scanf("%d ",&n);
		bool com,op;
		LOOPB(i,0,n){
			op=com=false;
			scanf("%c",&s);
			if(spell.size()){
				t=spell[spell.size()-1];
				LOOPB(j,0,combine[s].size()){
					if(combine[s][j].first==t){
						spell[spell.size()-1]=combine[s][j].second;
						com=true;
						break;
					}
				}
			}
			if(!com){
				LOOPB(j,0,opp[s].size()){
					if(find(spell.begin(),spell.end(),opp[s][j])!=spell.end()){
						spell.clear();
						memset(here,0,sizeof(here));
						op=true;
						break;
					}
				}
			}
			if(!com&&!op){
				spell.push_back(s);
			}
		}
		printf("Case #%d: [",cas++);
		LOOPB(i,0,spell.size()){
			printf("%c",spell[i]);
			if(i!=spell.size()-1){
				printf(", ");
			}
		}
		printf("]\n");
	}
	
	return 0;
}
