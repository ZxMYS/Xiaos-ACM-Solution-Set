program rqnoj_196;
var
ga:array[0..100,0..100] of longint;
s:array[0..100] of boolean;
r,num:array[0..100] of longint;
a,b,i,j,x,y,m,n,p:longint;
f1:text;
procedure find(room:longint);
var
k,k2,ko,k3:longint;
begin
s[room]:=true;
if room=p then
begin
write(a);
halt;
end;
for k2:= 1 to num[room] do
begin
ko:=maxint;
for k:= 0 to n do
begin
if (ga[room,k]<ko) and not(s[k]) then
begin
k3:=k;
ko:=ga[room,k];
end;
end;
{writeln('k',k,' room',room,' ga',ga[room,k],' s',s[k]);}
a:=a+ga[room,k3];
{writeln('+',k,' ga',ga[room,k]);}
inc(x);
r[x]:=k3;
find(k3);
end;
{writeln('-',r[x],' ga',ga[r[x-1],room]);}
r[x]:=0;
dec(x);
a:=a+ga[r[x],room];
end;

begin
assign(f1,'f:\in.txt');
reset(f1);
for i:= 0 to 100 do
begin
for j:= 0 to 100 do
ga[i,j]:=maxint;
s[i]:=false;
r[i]:=0;
num[i]:=0;
end;
x:=0;
read(f1,n,p);
if p=0 then
begin
write(0);
halt;
end;
for i:= 1 to n-1 do
begin
read(f1,a,b);
inc(num[a]);
read(f1,ga[a,b]);
end;
a:=0;
s[0]:=true;
find(0);
end.
