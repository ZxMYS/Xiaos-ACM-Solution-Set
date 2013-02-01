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
int i,j,k,m,n,s,t,l,tt,cas;
const int oo=1<<29;
vector<int> p[1001];
int h[1001]; 

typedef struct {
	int v;
	int id;
} node;

map<int,int>::iterator iter;
set<int> al;
vector<node> wtf;
vector<int> r;

inline bool cmp(const node& a,const node& b){
	return a.v<b.v;
}


inline void calh(){
	queue<int> qu;
	vector<int>::iterator gaiter;
    h[t]=0;
    qu.push(t);
    while(!qu.empty()){
        tt=qu.front();
        qu.pop();
        gaiter=p[tt].begin();
        while(gaiter!=p[tt].end()){
            if(al.find(*gaiter)==al.end()&&h[*gaiter]>h[tt]+1){
                qu.push(*gaiter);
                h[*gaiter]=h[tt]+1;
            }
            gaiter++;
        }
    }
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d%d%d",&n,&s,&t);
	LOOPB(i,0,n){
		scanf("%d",&m);
		LOOPB(j,0,m){
			scanf("%d",&l);
			p[i].push_back(l);
			p[l].push_back(i);//youdao sucks! 
		}
		h[i]=oo;
	}
	calh();
	LOOPB(i,0,n){
		if(al.find(i)==al.end())
			wtf.push_back((node){h[i],i});
	}
	al.insert(s);
	r.push_back(s);
	
	while(true){
		wtf.clear();
		LOOPB(i,0,n){
			if(al.find(i)==al.end())
				wtf.push_back((node){h[i],i});
		}
		k=max_element(wtf.begin(),wtf.end(),cmp)->id;
		if(h[k]==oo)
			goto NO;
		al.insert(k);
		r.push_back(k);
		if(k!=t){
			bool flag=false;
			LOOPB(i,0,p[k].size()){
				if(al.find(p[k][i])==al.end()){
					flag=true;
					break;
				}
			}
			if(!flag)
				goto NO;
			LOOPB(i,0,n)
				h[i]=oo;
			calh();	
		}else
			break;	
	}
	LOOPB(i,0,n)
		if(al.find(i)==al.end())
			goto NO;
	
	printf("YES\n");
	printf("%d",r[0]);
	LOOPB(i,1,r.size())
		printf(" %d",r[i]);
	
	return 0;
	
NO:
	printf("NO\n"); 
}
