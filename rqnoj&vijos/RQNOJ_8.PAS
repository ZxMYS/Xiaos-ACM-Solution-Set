program rqnoj_8;
const
digit=100000;
type
hugenum=array[0..50] of longint;
var
f:array[0..1,1..1050] of hugenum;
i,j,k,w,a,lim,lim2:longint;
function max(x,y:longint):longint;
begin
if x>y then exit(x) else exit(y);
end;

operator + (fa1,fa2:hugenum)r:hugenum;
var
i,k:longint;
begin
k:=max(fa1[0],fa2[0]);
for i:=1 to k do
begin
inc(fa1[i],fa2[i]);
if fa1[i] >= digit then begin inc(fa1[i+1],fa1[i] div digit);fa1[i]:=fa1[i] mod digit; end;
end;
if fa1[k+1] >0 then fa1[0]:=k+1 else fa1[0]:=k;
exit(fa1);
end;

begin
fillchar(f,sizeof(f),0);
read(k,w);
lim:=(1 shl k) - 1;
       for j:=1 to lim do
       begin
        f[0,j,0]:=1;
        f[0,j,1]:=1;
       end;
a:=0;
for i:=1 to
end.