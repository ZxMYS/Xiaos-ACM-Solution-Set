#include<cstdio>
#include<cmath>

double a,b,c,d,e,m,g,x,y,r;
int i,j,bi,bj;

double f3(double p,double q)
{
	double a,b,c;
	if(p<0)return -f3(-p,q);
	if(q<0)return -f3(p,-q);
	if(p*p+q*q<r*r)return p*q/2;
	a=acos(q/sqrt(p*p+q*q));
	b=0;c=0;
	if(q<r)
	{
		b=acos(q/r);
		c=sqrt(r*r-q*q);
	}
	return((a-b)*r*r+q*c)/2;
}

double f2(double xa,double ya,double xb,double yb)
{
	double co,si,xc,yc,dd;
	xc=xb-xa;yc=yb-ya;
	dd=sqrt(xc*xc+yc*yc);
	co=xc/dd;si=yc/dd;
	return f3(xa*co+ya*si,ya*co-xa*si)-f3(xb*co+yb*si,yb*co-xb*si);
}

double f(double p,double q)
{
	return fabs(f2(-p,-q,c-p,-q)+f2(c-p,-q,x-p,y-q)+f2(x-p,y-q,-p,-q));
}

int main()
{
	while(scanf("%lf%lf%lf%lf",&a,&b,&c,&r))
	{
		if(r<1e-9)break;
		x=(a*a+c*c-b*b)/c/2;
		y=sqrt(a*a-x*x);
		a=c/2;b=y/2;d=c/9;e=y/9;
		while(e>1e-9)
		{
			m=0;
			for(i=-5;i<6;i++)
				for(j=-5;j<6;j++)
				{
					g=f(a+d*i,b+e*j);
					if(g>m)
					{
						m=g;bi=i;bj=j;
					}
				}
			a+=d*bi;b+=e*bj;
			d/=2.2;e/=2.2;
		}
		printf("%.2lf\n",m);
	}
	return 0;
}

