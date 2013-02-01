program rqnoj_232;
var
a,b,c,sa:array[1..maxint] of integer;
n,s,sb,sc:longint;
i:integer;

function max(x,y:longint):longint;
begin
if x>y then max:=x else max:=y;
end;

function find(u,w:longint):longint;
begin

 if w=1 then
  sa[u]:=1
 else
  sa[u]:=0;

 if u<>n then
 find:=max(find(u+1,1),find(u+1,0));

 if u=n then
 begin
 sb:=0;
 sc:=0;
  for i:= 1 to n do
    if sa[i]=1 then
        begin
          sb:=sb+a[i];
          sc:=sc+b[i];
        end;
 find:=sqr(sb)+sqr(sc);
 end;
end;

begin
read(n);
for i:=1 to n do
begin
read(a[i],b[i]);
end;
write(max(find(1,1),find(1,0)));
end.