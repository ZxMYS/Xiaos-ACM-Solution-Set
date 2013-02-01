program rqnoj_264;
var
f:array[1..5000] of longint;
i,j,c,x,t,n:longint;
begin
assign(input,'f:\in.txt');
reset(input);

read(n);
c:=1;
t:=0;
for i:=1 to n do
begin
read(x);
if x>=c then
begin
{repeat}
inc(t);
f[t]:=c;
{inc(c);}
c:=x;
{until c=x;
dec(c);}
end
else
if f[t]=x then dec(t) else begin write('Wrong'); halt end;
end;
write('Right');
end.