#include<stdio.h>
#include<memory.h>
#include<math.h>
__int64 i,j,n,m;
bool s[100010];
int main()
{
	memset(s,1,sizeof(s));
	for (i=2;i<=317;i++)
		if (s[i])
			for (j=i*i;j<=100000;j+=i)
				s[j]=0;
	scanf("%I64d",&n);
	while (n>0)
	{
		if (n==1)
		{
			printf("0\n");
			scanf("%d",&n);
			continue;
		}
		m=n;
		for (i=2;i<=100000;i++)
			if (s[i] && n%i==0)
			{
				while (m%i==0)
					m/=i;
				n=(n/i)*(i-1);
			}
		if (m>1) n=(n/m)*(m-1);  //NOTICE !!不然素数要一直求到1000000000才行！
		printf("%I64d\n",n);
		scanf("%I64d",&n);
	}
	return 0;
}
