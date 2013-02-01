#include<string.h>
#include<stdio.h>
char tmp[27],tmp2[27];
void deal(char a[],char b[]){
    if(!a[0])return;
    if(!a[1]){printf("%c",a[0]);return;}
    char tmp[27],tmp2[27];
    char root=a[0];
    int p=0,len=0;
    while(b[len]!=root){
    tmp2[len]=b[len];
    len++;
    }
    tmp2[len]='\0';
    strncpy(tmp,a+1,(len));
    tmp[len]='\0';
    deal(tmp,tmp2);
    strncpy(tmp,a+len+1,(strlen(a)-len));
    strncpy(tmp2,b+len+1,(strlen(b)-len));
    deal(tmp,tmp2);
    printf("%c",root);
}

int main(){
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
while(scanf("%s%s",&tmp,&tmp2)!=EOF){
deal(tmp,tmp2);
printf("\n");
}
}
