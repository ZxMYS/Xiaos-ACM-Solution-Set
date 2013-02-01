program rqnoj_135;
type
hugenum=array[0..11] of int64;
var
f:array[-10..90,-10..90,0..1] of  hugenum;
a:array[0..81,0..81] of longint;
q,s,kk:hugenum;
i,j,k,n,m,t:longint;

function max1(x,y:longint):longint;
begin
if x>y then exit(x) else exit(y);
end;

operator > (fa1,fa2:hugenum)r:boolean;
var
i,k:longint;
begin
if fa1[0]>fa2[0] then exit(true) else if fa1[0]<fa2[0] then exit(false);
k:=fa1[0];
//write(k);
for i:=k downto 1 do
        if fa1[k]>fa2[k] then exit(true) else if fa1[k]<fa2[k] then exit(false);
        //write('aaa');
        exit(false);
end;

operator + (fa1,fa2:hugenum)r:hugenum;
var
i,k:longint;
begin
fillchar(r,sizeof(r),0);
k:=max1(fa1[0],fa2[0]);
for i:=1 to k do
begin
        r[i]:=r[i]+fa1[i]+fa2[i];
        if r[i]>=100000000 then begin inc(r[i+1]);dec(r[i],100000000); end;
end;
if r[k+1]>0 then r[0]:=k+1 else r[0]:=k;
end;

operator * (fa1:longint;fa2:hugenum)r:hugenum ;
var
i,k:longint;
begin
fillchar(r,sizeof(r),0);
k:=fa2[0];
for i:=1 to k do
begin
        r[i]:=fa1*fa2[i];
end;
i:=1;
repeat
        if r[i]>=100000000 then begin inc(r[i+1],r[i] div 100000000);r[i]:=r[i] mod 100000000; end;
        inc(i);
until i=10;
while (r[i]=0)and(i>1) do
dec(i);
r[0]:=i;
end;

function max(x,y:hugenum):hugenum;
begin
if x>y then exit(x) else exit(y);
end;




begin
assign(input,'f:\in.txt');
reset(input);

read(n,m);
fillchar(f,sizeof(f),0);
{for i:=0 to 81 do
        for j:=0 to 81 do
                a[i,j]:=-maxlongint;   }
for i:=1 to n do
        for j:=1 to m do
                read(a[i,j]);
q[0]:=1;
q[1]:=0;
for i:=1 to n do
begin
kk[0]:=1;
kk[1]:=1;
fillchar(f,sizeof(f),0);
t:=0;
for k:=1 to m do
begin

                        for j:=1 to k do
                        begin
                                {if m-k+j+1>80 then f[j,m-k+j,(t+1) mod 2]:=f[j-1,m-k+j,t]+(a[i,j-1] * kk)
                                else if j-1<1 then f[j,m-k+j,(t+1) mod 2]:=f[j,m-k+j+1,t]+(a[i,m-k+j+1] * kk)
                                else }
                                f[j,m-k+j,(t+1) mod 2]:=max(f[j-1,m-k+j,t]+(a[i,j-1] * kk),f[j,m-k+j+1,t]+(a[i,m-k+j+1] * kk));
                        end;
t:=(t+1) mod 2;
kk:=kk+kk;
end;
s[0]:=1;
s[1]:=0;
for j:=1 to m do
begin
s:=max(s,f[j,j,t]+(a[i,j]*kk));
end;
q:=q+s;
end;



{q[0]:=3;
q[1]:=90000000;
q[2]:=q[1];
q[3]:=q[1];
//q:=q+q;
q:=3*q;}

write(q[q[0]]);

for i:=q[0]-1 downto 1 do
begin
        for j:=7 downto 1 do
                if q[i] div trunc(exp(ln(10)*j))=0 then write(0);
        write(q[i]);
end;
writeln;
end.

