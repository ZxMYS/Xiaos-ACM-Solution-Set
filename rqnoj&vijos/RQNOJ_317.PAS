program rqnoj_317;
var
f,d:array[0..10000,0..10000] of integer;
i,j,k,a,r,c,h,m,n:longint;
function max(x,y:longint):longint;
begin
if (x>y) then exit(x) else exit(y);
end;

function fi(x,y:longint):longint;
begin
if (x=0) or (y=0) or (x>r) or (y>c) then exit(0);
if f[x,y]>0 then exit(f[x,y]);
if d[x-1,y]>d[x,y] then
f[x,y]:=max(fi(x-1,y)+1,f[x,y]);
if d[x+1,y]>d[x,y] then
f[x,y]:=max(fi(x+1,y)+1,f[x,y]);
if d[x,y+1]>d[x,y] then
f[x,y]:=max(fi(x,y+1)+1,f[x,y]);
if d[x,y-1]>d[x,y] then
f[x,y]:=max(fi(x,y-1)+1,f[x,y]);
exit(f[x,y]);
end;
begin
assign(input,'f:\in.txt');
reset(input);
{fillchar(f,sizeof(f),0);
fillchar(d,sizeof(d),0);}
read(r,c);
for i:=1 to r do
for j:=1 to c do
read(d[i,j]);

for i:=1 to r do
for j:=1 to c do
        k:=max(k,fi(i,j));

write(k+1);
end.