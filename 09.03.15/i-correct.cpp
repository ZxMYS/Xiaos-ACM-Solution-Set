/*
 * Problem: NOI1997 wildcard
 * Author: Guo Jiabao
 * Time: 2009.2.15 20:17
 * State: Solved
 
 ����NOI1997�����ѵ�һ���⣬����������ϻ�����һ��ʱ���ͨ���ˡ�������ܾ���������������ƥ�䴮���������ļ������չ���ƥ�䣬�ж��Ƿ���У����ƥ�����Ŀ����������ֵ��

�����������������������ˣ�������Ҫ��������������Ż��ͼ�֦���ҵ�����˳���Ǵ�ƥ�䴮�ĵ�һλ�����һλ(�����ļ����������ֵ)�����Ƕ������ļ�Ϊ��ǡ�+'���ļ������ļ�Ϊ��ǡ�-'���ļ���

�Ż�1.��¼�������ù����ַ���˳��������Ա��Ա�����ʱʹ�á�

�Ż�2.ȥ�������״̬��������*��һ�����˷ѵģ�*?��?*��һ����(���Ǻ�*��һ��)���ڲ���״̬ʱӦ������֡�

�Ż�3.�����ж��ļ����Ƿ�ƥ�䣬��������һλʱ������Ҫ�����������ļ���ƥ�䣬���ǰ�涼��ƥ��ģ�ֻ���ж����һλ�Ƿ������������Ҫ��¼ÿ���ļ����Ѿ�ǰ׺ƥ�䵽����һλ����������*�Ĵ��ڣ�ʹ����жϸ����Դ�����ӡ����統ǰ��ƥ�䴮A*A��A1A2Aǰ׺ƥ�䣬A*A����ƥ�䵽��3λ(A1A)��Ҳ����ƥ�䵽��5λ(A1A2A)���������ں�����չ����״̬δ֪������Ҳ�޷�֪������ƥ�䵽��һλ�Ǻ��ʵģ����Ա��붼��¼�¡�����ÿ���ļ�������һ������ռ䣬�洢���ļ�������ƥ�䵽������λ�á���״̬����չ�У�Ҳ��Ҫ�����еĿ��ֱܷ���չ���������ж�ʱ��һ���ļ���ֻҪ��һ�ֿ���ʹ����ȫƥ�䣬������ƥ��ɹ���

�Ż�4.��������ƥ�䴮��ÿһλ��������ȫƥ�����Ŀʱ����Ҫ�ж��Ƿ��б�Ҫ������һλ�������������������

   1. ������е����ļ�ȫ�������ϸ�ƥ�䣬����������һλ�Ѿ�û�����壬��֦��
   2. ���ǰ׺ƥ������ļ��ĸ���С�����д𰸣���������һλ��һ���������ӣ���֦��
   3. ���ƥ�䴮ĩ�ַ���*����ǰ��С�����Ŵ𰸣���������һ���ǲ���ʹ�����ӣ���֦��

�Ż�5.������ǰ�ȶ����е��ļ�����ʹ���ļ�������ǰ�棬�����ڼ�֦����ǰ������

����5���Ż��������Ż�3�Ǻ��ģ�Ҳ���㷨����Ҫ���ݣ�������̵Ĺ��������Ż�3�����Ż�4�ǹؼ����Ż�4������ǿ����֦����ȥ��������õ�״̬������������ʱ�䡣

�������Ȼд��һ��Ÿ㶨���ջ�ȴ�Ƿ�ͬһ��ô��Ҹ�����Ϊ������ܺã����ܿ��鹹��˼ά�����ͱ��������������־��������Щ�겻���� NOI����NOIP��ȴ�������伣�ˡ���Ԥ���������NOI�������⣬��Ȼ�Ǹ����⣬���õ��߷ֵ��˲����ġ�����+�Ż���Զ��һ�������㷨����ʹ��Ϊ�˾���������������Ҳ�Ǻ����ѣ�ȷ�Ǻ���Ҫ�ġ�
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
const int MAXN=251,MAXS=62;
const char CharSet[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
struct File{int name[10],len,matchpre[10],precnt;bool permission;};
int N,N_p,pattern[10],Apt[10],Max_Length,Ans,Nowlen,Al,ccnt;
File F[MAXN];
bool used[200];
int chas[62];
void dfs(int len);
inline int CharToID(char c)
{
	if (c>='0' && c<='9')return c-'0';
	return (c>='A' && c<='Z')?c-'A'+10:c-'a'+36;
}
inline int cmp(const void *a,const void *b)
{return ((File *)a)->permission==false?-1:1;}
void init()
{
	int i,k;
	char c,Name[10];
	freopen("wildcard.in","r",stdin);
	freopen("wildcard.out","w",stdout);
	c=getchar();
	while (c!=EOF)
	{
		ungetc(c,stdin);
		scanf("%s",Name);
		N++;
		for (i=0;Name[i];i++)
		{
			F[N].name[i+1]=k=CharToID(Name[i]);
			used[k]=true;
		}
		F[N].len=i;
		if (i>Max_Length)
			Max_Length=i;
		c=getchar();c=getchar();
		if (c=='+')
		{
			N_p++;
			F[N].permission=true;
		}
		else
			F[N].permission=false;
		F[N].precnt=1;
		c=getchar();c=getchar();
	}
	qsort(F+1,N,sizeof(F[0]),cmp);
	for (i=0;i<MAXS;i++)
		if (used[i])
			chas[++ccnt]=i;
}
bool update(int k)
{
	int i,j,Newans=0,Pans=0;
	bool np=false,tb;
	for (i=1;i<=N;i++)
	{
		tb=false;
		for (j=1;j<=F[i].precnt;j++)
			tb|=F[i].matchpre[j]==F[i].len || ( F[i].matchpre[j]>=0 && pattern[k]==-1 );
		if (tb)
		{
			if (F[i].permission )
				Newans++;
			else
				np=true; //ƥ���˸���
		}
		if (F[i].permission && F[i].precnt==0)
			Pans++; //��¼������ƥ��ĸ���
	}
	if (Pans==N_p || (N_p-Pans<Ans)) //������ȫ����ƥ�� ���� ǰ׺ƥ�䴮�ĸ���С�����д� ��֦
		return false;
	if (pattern[k]==-1 && Newans<Ans) //���ƥ�䴮ĩ�ַ���*����ǰ��С�����ţ��������һ���Ƕ����  ��֦
		return false;
	if (!np)
	{
		if (Newans>Ans)
		{
			Ans=Newans;
			for(i=1;i<=k;i++)
				Apt[i]=pattern[i];
			Al=k;
		}
		else if (Newans==Ans && k<Al)
		{
			for(i=1;i<=k;i++)
				Apt[i]=pattern[i];
			Al=k;
		}
	}
	return true;
}
void match(File &F,int len)
{
	bool newpre[10]={false};
	int k,i;
	if (pattern[len-1]!=-1)
	{
		for (k=1;k<=F.precnt;k++)
			if (F.matchpre[k]+1<=F.len && (pattern[len]==-2 || F.name[F.matchpre[k]+1]==pattern[len]))
				newpre[F.matchpre[k]+1]=true;
	}
	else
	{
		for (k=1;k<=F.precnt;k++)
			for (i=F.matchpre[k]+1;i<=F.len;i++)
				if (F.name[i]==pattern[len] || pattern[len]==-2)
					newpre[i]=true;
	}
	F.precnt=0;
	for (k=1;k<9;k++)
		if (newpre[k])
			F.matchpre[ ++F.precnt ]=k;
}
void goon(int len,int p)
{
	if (p==N+1)
	{
		if (update(len))
			dfs(len+1);
		return;
	}
	int i,tprecnt,tmatch[10];
	if (F[p].precnt==0)
		goon(len,p+1);
	else
	{
		/*backup*/
		for (i=1;i<=F[p].precnt;i++)
			tmatch[i]=F[p].matchpre[i];
		tprecnt=F[p].precnt;
		/*backup*/
		if (pattern[len-1]==-1)
		{
			match(F[p],len);
			goon(len,p+1);
		}
		else
		{
			if (pattern[len]!=-1)
				match(F[p],len);
			goon(len,p+1);
		}
		/*restore*/
		F[p].precnt=tprecnt;
		for (i=1;i<=F[p].precnt;i++)
			F[p].matchpre[i]=tmatch[i];
		/*restore*/
	}
}
void dfs(int len) //-1:* -2:?
{
	if (len>Max_Length)
		return;
	int i;
	if (pattern[len-1]!=-1)//**������ ������?*
	{
		pattern[len]=-1;
		goon(len,1);
	}
	if (pattern[len-1]!=-1)//������*?
	{
		pattern[len]=-2;
		goon(len,1);
	}
	for (i=1;i<=ccnt;i++)
	{
		pattern[len]=chas[i];
		goon(len,1);
	}
}
void print()
{
	printf("%d\n",Ans);
	for (int i=1;i<=Al;i++)
		if (Apt[i]>=0)
			putchar(CharSet[Apt[i]]);
		else if (Apt[i]==-1)
			putchar('*');
		else
			putchar('?');
	putchar('\n');
}
int main()
{
	init();
	dfs(1);
	print();
	return 0;
}


