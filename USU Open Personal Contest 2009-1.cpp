#include<stdio.h>
#include<string.h>
char us[202][40],a[40],b[40],tmp;
bool got[202],f;
int i,j,k,q,n,t,tt;
int find(char a[]){
int i=0;
while(strcmp(us[i],a)&&i<t)i++;
return i;
}
int main(){
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
scanf("%d%d%d\n",&i,&n,&q);
j=0;
t=0;
for(int i=0;i<n;i++){
    f=false;
    k=0;
    scanf("%c",&tmp);
    while(tmp!='\n'&&tmp!='#'){
        a[k]=(tmp>='a'?tmp-'a'+'A':tmp);
        b[k++]=tmp;
        scanf("%c",&tmp);
    }
    if(tmp=='#'){scanf("%d\n",&tt);f=true;}else {a[k]=' ';b[k++]=' ';}
    b[k]=a[k]='\0';
    j=find(a);
    if(j!=t)continue;
    strcpy(us[t++],a);
    //printf("added %s\n",us[t-1]);
    if(t==q+1)break;
}
if(f)
printf("%s#%d\n",b,tt);
else
printf("%s\n",b);
}
