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
int i,j,k,m,n,s,t,l,tt,cas,a;
const int oo=1<<29;
vector<int> p[1001];
int h[1001]; 
multimap<int,int> cp;
map<int,int>::iterator iter;
set<int> al;
set<int> inmap;
vector<int> r;
vector<map<int,int>::iterator> tmp; 
set<int> stmp;
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
            if(*gaiter!=s&&h[*gaiter]>h[tt]+1){
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
	//if(h[s]==oo)
	//	goto NO;
	LOOPB(i,0,p[s].size()){
		cp.insert(make_pair(h[p[s][i]],p[s][i]));
	}
	al.insert(s);
	r.push_back(s);
	inmap.insert(s);
	
	while(true){
		tmp.clear();
		if(!cp.size())
			goto NO;
		iter=cp.end();
		iter--;
		a=iter->first;
		tmp.push_back(iter);
		iter--;
		while(iter->first==a){
			tmp.push_back(iter);
			if(iter==cp.begin())
				break; 
			iter--;
		} 
		
		l=oo;
		m=-1;
		LOOPB(i,0,tmp.size()){
			stmp.clear();
			LOOPB(j,0,p[tmp[i]->second].size()){
				stmp.insert(p[tmp[i]->second][j]); 
			}
			
			if(l>stmp.size()){
				l=stmp.size();
				k=tmp[i]->second; 
				m=i;
			}
		}
		
		cp.erase(tmp[m]);
		if(al.find(k)!=al.end())
			continue;
			
			
		al.insert(k);
		r.push_back(k);
		if(k!=t){
			bool flag=false;
			LOOPB(i,0,p[k].size()){
				if(al.find(p[k][i])==al.end()){
					flag=true;
				}
				if(inmap.find(p[k][i])==inmap.end()){
					cp.insert(make_pair(h[p[k][i]],p[k][i]));
					inmap.insert(p[k][i]);
				}
			}
			if(!flag)
				goto NO;	
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
