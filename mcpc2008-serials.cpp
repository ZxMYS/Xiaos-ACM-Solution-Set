#include<stdio.h>
#include<list>
#include<string.h>
#include<assert.h>
using namespace std;
int a,b,s,t,k,q,qq,qqq,pointer;
char tmp[81],tmp2;
struct node{long int st,en,sn,tn,next;} p[30000],tp;

void getname(char name[]){
    int i=0;
    scanf("%c",&tmp2);
    while(tmp2!='\n'){
        name[i++]=tmp2;
        scanf("%c",&tmp2);
    }
    name[i]='\0';
}

int newn(){
    pointer++;
    p[pointer].next=-1;
    return pointer;
}

void put_list()
{
int k=0;
while(k!=-1){
    printf("%d %d %c %d\n",p[k].st,p[k].en,p[k].sn,p[k].tn);
    k=p[k].next;
    }
}

int main(){
    freopen("serials.in","r",stdin);
    freopen("out","w",stdout);
    getname(tmp);
    while(strcmp(tmp,"END")){
    pointer=-1;
    p[0].st=p[0].en=p[0].sn=p[0].tn=p[0].next=-1;
    printf("%s\n",tmp);
    scanf("%d\n",&a);
    while(a>0){
        scanf("%d %c %d",&b,&s,&t);
        k=newn();
        p[k].st=a;p[k].en=b;p[k].sn=s;p[k].tn=t;p[k].next=-1;
        qq=q=0;
        while(q!=-1&&p[q].st<=p[k].st){
            qq=q;
            q=p[q].next;
        }
        if(q==-1){q=newn();p[qq].next=q;}
        
        tp=p[qq];
        if(p[k].st==p[qq].st){
            p[qq]=p[k];
            if(p[qq].en<tp.en){
                p[k]=tp;
                p[k].st=p[qq].en+1;
                p[qq].next=k;
            }
        }else if(p[k].st<=p[qq].en){
            p[qq].en=p[k].st-1;
            p[k].next=p[qq].next;
            p[qq].next=k;
            if(p[k].en<tp.en){
                qqq=newn();
                p[qqq]=tp;
                p[qqq].next=p[k].next;
                p[qqq].st=p[k].en+1;
                p[k].next=qqq;
                k=qqq;
            }
        }else{
            p[k].next=p[qq].next;
            p[qq].next=k;
        }
        q=k;
        /*while(p[q].next!=-1&&b>=p[p[q].next].st){
            if(b >= p[p[q].next].en){
                 p[q].next = p[p[q].next].next;
            }
            else {
                 p[p[q].next].st = b + 1;
            }
        }*/

        q=0;
        while(p[q].next!=-1){
            if(p[q].en+1==p[p[q].next].st&&p[q].tn==p[p[q].next].tn&&p[q].sn==p[p[q].next].sn){
                p[q].en=p[p[q].next].en;
                p[q].next=p[p[q].next].next;
            }else
            q=p[q].next;
        }



        
        scanf("%d\n",&a);
    }
    put_list();
    getname(tmp);
    }
}
