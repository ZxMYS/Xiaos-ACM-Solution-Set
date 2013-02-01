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
int i,j,k,b,c,m,n,s,t,l,tt,cas;
vector<string> dict;
vector<string>::iterator dictend,a;
char st[10000];
string tmp;
vector<string>::iterator getPos(string& val){
	int left=0,right=dictend-dict.begin(),mid=(left+right)>>1,l;
	while(left<right){
		l=dict[mid].compare(val);
		if(l<0)
			left=mid+1;
		else if(l>0)
			right=mid;
		else
			break;
		mid=(left+right)>>1;
	}
	return dict.begin()+mid;
}

void out(string& val,vector<string>::iterator& a){
	vector<string> o;
	int p=0;
	while(p<8&&a!=dictend){
		if((mismatch(val.begin(),val.end(),a->begin()).first)!=val.end())
			break;
		o.push_back(*a);
		p++;
		a++;
	}
	if(p==0)
		cout<<val;
	else{
		cout<<o[0];
		LOOPB(p,1,o.size())
			cout<<' '<<o[p];
	}
	cout<<endl;
	
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d",&n);
	LOOPB(i,0,n){
		scanf("%s",st);
		dict.push_back(st);
	}
	sort(dict.begin(),dict.end());
	dictend=unique(dict.begin(),dict.end());
	/*for(vector<string>::iterator j=dict.begin();j!=dictend;j++){
		cout<<*j<<' ';
	}
	cout<<endl;*/
	scanf("%d",&m);
	LOOPB(i,0,m){
		scanf("%s",st);
		tmp=string(st);
		a=getPos(tmp);
		//if(a!=dictend)
		//	cout<<*a<<endl;
		out(tmp,a);
	}
	return 0;
}
