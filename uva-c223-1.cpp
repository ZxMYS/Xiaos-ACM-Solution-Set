#include<stdio.h>
#include<string.h>
int a[200],n,m,i;
char tmp;
int main(){
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
scanf("%d\n",&n);
while(n){
n--;
memset(a,0,sizeof(a));
m=0;
scanf("%c",&tmp);
while(tmp!='\n'){
                 if(tmp>='a'&&tmp<='z'){
                 a[tmp]++;
                 if(a[tmp]>m)m=a[tmp];
                 }
                 if(tmp>='A'&&tmp<='Z'){
                 a[tmp-'A'+'a']++;
                 if(a[tmp-'A'+'a']>m)m=a[tmp-'A'+'a'];
                 }
                 scanf("%c",&tmp);
                 }
for(i=(int)'a';i<=(int)'z';i++)
        if(a[i]==m)printf("%c",(char)i);
printf("\n");
}
}
