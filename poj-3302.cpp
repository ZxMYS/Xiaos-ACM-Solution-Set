#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<map>
#include<queue>
#include<list>
#include<sstream>
using namespace std;
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define RLOOP(x,y,z) for((x)=(y);(x)>=(z);(x)--)
#define RLOOPB(x,y,z) for((x)=(y);(x)>(z);(x)--)
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define PI 3.1415926535898
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
string str1,str2;
int len1,len2,i,j,tt;
bool f1;
int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&tt);
while(tt--){
cin>>str2>>str1;
j=0;
len1 = str1.length();
len2 = str2.length();
    for(i = 0 ; i < len2 ; i ++)
	{
		if( str1[j] == str2[i])
		{
				j++;
		}
	}
	if(j == len1){
        cout<<"YES\n";
        continue;
        }
    reverse(str1.begin(),str1.end());
    j=0;
    for(i = 0 ; i < len2 ; i ++)
	{
		if( str1[j] == str2[i])
		{
				j++;
		}
	}
	if(j == len1){
        cout<<"YES\n";
        continue;
    }
    cout<<"NO\n";
    }
}
