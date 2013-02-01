program rqnoj_208;
var
i,j,k,n,q:longint;
f:boolean;
max,submin,submax,maxn,minn:int64;
orz:array[1..10000] of byte;
begin
assign(input,'f:\in.txt');
reset(input);
settextbuf(input,orz);
f:=false;
q:=-maxlongint;
read(n);
for i :=1 to n do
begin
read(j);
if j>=0 then f:=true;
if not(f) and (j>=q) then q:=j;
inc(max,j);
if submax<0 then submax:=j else inc(submax,j);
if submin>0 then submin:=j else inc(submin,j);
if submax>maxn then maxn:=submax;
if submin<minn then minn:=submin;
end;
if f then
if (max-minn>maxn)and(max<>minn) then
write(max-minn)
else
write(maxn)
else
write(q);
end.
