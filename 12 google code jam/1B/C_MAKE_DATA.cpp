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
		printf("%d ",(*x)[i]);
	}
	printf("\n");
}

void rand_it(){
	//RAND_MAX
	int i,j,x;
	LOOPB(i,0,nums.size()){
		j=(int)((nums.size()-i)*(rand()/(double)RAND_MAX))+i;
		x=nums[j];
		nums[j]=nums[i];
		nums[i]=x;
	}
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
	printf("10\n");
	LOOPB(i,0,10){
		printf("500 ");
		LOOPB(j,0,500){
			long long int x;
			x=rand();
			x*=rand();
			x*=rand();
			x/=10;
			printf("%lld ",x);
		}	
		printf("\n");
	}
	
	return 0;
}
