program rqnoj_251;
var
t,g,r,b,n,k,d:int64;
i,j:longint;
f:array[0..1024,0..1024] of int64;
//f[g,b]
x,a,c:int64;
begin
assign(input,'f:\in.txt');
reset(input);

fillchar(f,sizeof(f),0);
read(n,r,g,b,t);
f[0,0]:=n*r*t;
for i:=1 to n do
begin
f[i,0]:=f[i-1,0]-t*r+t*(n-i)*g;
f[0,i]:=f[0,i-1]-(t+(i-1)*b)*r+(n-i)*r*b;
end;

for i:=1 to n do
for j:=1 to n-i do
begin
a:=f[i,j-1]-(t+(j-1)*b)*r+(n-i-j)*b*(i*g+r);
c:=f[i-1,j]-(t+j*b)*r+(n-i-j)*(t+j*b)*g;
if a>c then f[i,j]:=a else f[i,j]:=c;
end;
x:=-maxint;
for i:=0 to n do
        for j:=0 to n do
             if f[i,j]>x then x:=f[i,j];

writeln(x);
end.
