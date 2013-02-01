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
int i,j,k,a,m,n,s,t,l,tt,cas;
const int oo=1<<29;
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
char tmp,str[500],ch;
float f1,f2;
const char str1[]="ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
const char str2[]="our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out","w",stdout);
	#endif
	for(int i=0;i<strlen(str1);i++){
		if(str[str1[i]])
			assert(str[str1[i]]==str2[i]);
		str[str1[i]]=str2[i];
	}
	str['q']='z';
	str['z']='q';
	str['\n']='\n';
	scanf("%d\n",&tt);
	s=0;
	while(++s,tt--){
		printf("Case #%d: ", s);
		while(scanf("%c",&ch)!=EOF){
			printf("%c",str[ch]);
			if(ch=='\n')
				break;
		}
	}
	
	return 0;
}
