#include<cstdio>
#include<cmath>

int la,lb,lc,ma,mb,mc,hh,mm,ss,t1,t2,i;
double xa,ya,xb,yb,s,p;

void gc(int t)
{
	double a,b,c,m;
	a=p/10800*t;b=p/900*t;c=p/15*t;m=ma+mb+mc;
	xa=(cos(a)*la*ma+cos(b)*lb*mb+cos(c)*lc*mc)/m;
	ya=(sin(a)*la*ma+sin(b)*lb*mb+sin(c)*lc*mc)/m;
}

int main()
{
	p=acos(0);
	while(scanf("%d%d%d%d%d%d",&la,&lb,&lc,&ma,&mb,&mc)>5&&la>=0)
	{
		scanf("%d:%d:%d",&hh,&mm,&ss);
		t1=hh*3600+mm*60+ss;
		scanf("%d:%d:%d",&hh,&mm,&ss);
		t2=hh*3600+mm*60+ss;
		gc(t1);s=0;
		for(i=t1+1;i<=t2;i++)
		{
			xb=xa;yb=ya;gc(i);
			s+=sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
		}
		printf("%.2lf\n",s/2);
	}
	return 0;
}

