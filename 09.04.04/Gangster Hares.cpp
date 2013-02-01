#include <iostream>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
int i,t,j;
unsigned long long int a,o[30004];
cin>>t;
for(i=1;i<=t;i++)
{
cin>>a;
for(j=1;j<=20;j++)
{
if(((a-(a%j))/j)<=(a%j))
{
o[i]=j;
break;
}
}
}
for(i=1;i<=t;i++)
{
cout<<o[i]<<endl;
}
return 0;
}
