#include<stdio.h>
#include<string.h>

char names[20][100],tmp[100],tmp2[100];
int account[20];
int i,j,k,a,n,t,o=0;
int fz(){
    int i=0;
    while(account[i]<=0&&i<n)i++;
    return i<n?i:-1;
}
int ff(){
    int i=0;
    while(account[i]>=0&&i<n)i++;
    return i<n?i:-1;
}
int find(char name[]){
    int i=0;
    while(strcmp(names[i],name))i++;
    return i;
}
int main(){
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
while(1){
    scanf("%d%d",&n,&t);
    if(n==0)break;
    printf("Case #%d\n",++o);
    for(i=0;i<n;i++){
        account[i]=0;
        scanf("%s",&names[i]);
    }
    for(i=0;i<t;i++){
        scanf("%s%s%d",&tmp,&tmp2,&a);
        j=find(tmp);
        account[j]-=a;
        j=find(tmp2);
        account[j]+=a;
    }
    while(j=fz(),k=ff(),j!=-1&&k!=-1){
    a=account[j];
    account[k]+=account[j];
    account[j]=0;
    if(account[k]>0){account[j]+=account[k];account[k]=0;}
    printf("%s %s %d\n",names[j],names[k],a-account[j]);
    }
    printf("\n");
}
}
