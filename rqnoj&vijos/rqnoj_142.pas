program rqnoj_142;
var
f1:text;
ga:array[1..100,1..100] of longint;
l:array[1..100] of longint;
s:array[1..100] of boolean;
a,x,y,k,i,n:longint;
begin
assign(f1,'f:\in.txt');
reset(f1);
a:=0;
for x:= 1 to 100 do
begin
for y:= 1 to 100 do
        ga[x,y]:=maxint;
s[x]:=false;
end;
read(f1,n);
for x:=1 to n do
begin
for y:=1 to n do
        read(f1,ga[x,y]);
l[x]:=ga[1,x];
end;
s[1]:=true;
for x:=2 to n do
begin
i:=maxint;
for y:=2 to n do
if (l[y]<i) and not(s[y]) then
begin k:=y;i:=l[y]; end;
inc(a,i);
s[k]:=true;
for y:= 2 to n do
if l[y]>ga[k,y] then l[y]:=ga[k,y];
end;
write(a);
end.