#include<stdio.h>
#include<string.h>
#include<math.h>
#define PI 3.141592653589793
#define R 6378
struct city{double x,y,z;char name[32];}c[101];
char tmp1[32],tmp2[32];
double a,b;
const double PI2=PI/180.0;
int i,j,k,count;
int main(){
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
scanf("%s",&c[0].name);
i=0;
while(strcmp(c[i].name,"#")){
scanf("%lf%lf",&a,&b);
a*=PI2;b*=PI2;
c[i].x=cos(b)*cos(a);
c[i].y=sin(b)*cos(a);
c[i].z=sin(a);
scanf("%s",&c[++i].name);
}
count=i;
scanf("%s%s",&tmp1,&tmp2);
while(strcmp(tmp1,"#")){
i=j=0;
printf("%s - %s\n",tmp1,tmp2);
while(strcmp(tmp1,c[i].name)&&i<count)i++;
while(strcmp(tmp2,c[j].name)&&j<count)j++;

if(j==count||i==count){printf("Unknown\n\n");scanf("%s%s",&tmp1,&tmp2);continue;}
if(j==i){printf("0 km\n\n");scanf("%s%s",&tmp1,&tmp2);continue;}
printf("%.0f km\n\n",(R*acos(c[i].x*c[j].x+c[i].y*c[j].y+c[i].z*c[j].z)));
scanf("%s%s",&tmp1,&tmp2);
}

}
