int RabinMillerKnl(unsigned long n)
{
unsigned long b, m, j, v, i, k=10;
//�ȼ����m��j��ʹ��n-1=m*2^j������m����������j�ǷǸ�����
while(k--){
m=n - 1;
j=0;
while(!(m & 1))
{
++j;
m>>=1;
}
//���ȡһ��b��2<=b<n-1
b=random(2,m);
//����v=b^m mod n
v=PowMod(b, m, n);
//���v==1��ͨ������
if(v == 1)
{
return 1;
}

i=1;
//���v=n-1��ͨ������
while(v != n - 1)
{
//���i==l��������������
if(i == j)
{
return 0;
}
//v=v^2 mod n��i=i+1
v=PowMod(v, 2, n);
i++;
}
}
return 1;
}
