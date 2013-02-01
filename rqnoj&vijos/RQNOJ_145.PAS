program rqnoj_208;
var
s,m,f,a1,a2,m1,m2,i,x,n,max,min:longint;
a:array[1..1000000] of longint;
begin
read(n);

s:=0;
max:=s;
f:=1;
m1:=f;
for i:=1 to n do
begin
read(x);
a[i]:=x;
if(s+x<0) then begin
s:=0;
f:=0;
a1:=i+1;
end
else
s:=s+x;
if s>max then
begin
if f=0 then begin
m1:=a1;
f:=1;
end;
max:=s;
m2:=i;
end;
end;

if max=0 then
begin
max:=-maxint;
    for i:=1 to n do
        if a[i]>max then max:=a[i];
end;
write(max);
end.