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

	vector<long long int> nums;
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}


void out_res(vector<int>* x){
	int i;
	LOOPB(i,0,x->size()){
		long long int m=nums[(*x)[i]];
		printf("%I64d ",m);
	}
	printf("\n");
}

vector<int>* rand_it(){
	vector<int>*res=new vector<int>();
	int i;
	LOOPB(i,0,40){
		res->push_back(rand()%nums.size());
	}
	res->erase(unique(res->begin(),res->end()), res->end());
	return res;
}

int main(){
	srand( time(NULL) );
	int i,j,k,a,n,s,t,l,tt,cas;
	long long int m;
	const int oo=1<<29;
	char tmp,str[500],ch;
	float f1,f2;
	map<long long int, vector<int>* >* ma;
	ma=new map<long long int, vector<int>* >;
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out","w",stdout);
	#endif
	
	scanf("%d\n",&tt);
	cas=0;
	
	while(++cas,tt--){
		map<long long int, vector<int>* >::iterator iter1,iter2;
		nums.clear();
		printf("Case #%d: \n", cas);
		scanf("%d",&n);
		LOOPB(i,0,n){
			scanf("%I64d",&m);
			nums.push_back(m);
		}
		wtf:
		vector<int>* xx;
		for(iter1=ma->begin();iter1!=ma->end();iter1++){
			delete iter1->second;
		}
		ma->clear();
		
		vector<int> *x;
			fprintf(stderr,"now at:%d\n",cas);
		while(1){
			xx=rand_it();
			
			long long int now=0,pre;
			LOOPB(i,0,xx->size()){
				now+=nums[(*xx)[i]];
			}
			iter2=ma->find(now);
			if(iter2==ma->end()){
				ma->insert(make_pair(now,xx));
			}else{
				out_res(xx);
				out_res(iter2->second);
				goto next;
			}
			delete xx;
		}
			next:;
	}
	
	return 0;
}
