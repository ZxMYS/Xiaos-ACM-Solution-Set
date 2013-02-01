program rqnoj_387;
type
line=array[0..1500] of longint;
linkage=array[-1..1500] of longint;
var
buf:array[1..4096] of byte;
i,j,k,a,b,m,n:longint;
li:line;
lin:array[0..1500] of linkage;
function findmax:longint;
var
i,t,a:longint;
begin
t:=-maxlongint;
for i:=0 to n-1 do
begin
        if li[i]>t then begin t:=li[i];a:=i; end;
end;
exit(a);
end;

{procedure qsort(lx,rx:longint);
var
t,l,r:longint;
tt:linkage;
begin
l:=lx;r:=rx;t:=li[(l+r)shr 1];
repeat
        while (li[r]>t)and(r>lx) do
                dec(r);
        while (li[l]<t)and(l<rx) do
                inc(l);
        if l<=r then begin
                li[l]:=li[l] xor li[r];
                li[r]:=li[l] xor li[r];
                li[l]:=li[l] xor li[r];
                tt:=lin[l];
                lin[l]:=lin[r];
                lin[r]:=tt;
                inc(l);
                dec(r);
                end;
until l>=r;
if l<rx then qsort(l,rx);
if r>lx then qsort(r,lx);
end;}

begin
assign(input,'f:\in.txt');
reset(input);
settextbuf(input,buf);
read(n);
for i:=0 to n-1 do
begin
        lin[i,0]:=0;
        li[i]:=0;
        lin[i,-1]:=i;
end;

for i:=1 to n do
        begin
                read(a,k);
                for j:=1 to k do
                        begin
                                read(b);
                                //writeln(',,',a,' ',b);
                                inc(li[a]);
                                inc(lin[a,0]);
                                lin[a,lin[a,0]]:=b;
                                inc(li[b]);
                                inc(lin[b,0]);
                                lin[b,lin[b,0]]:=a;
                        end;
        end;
a:=0;
b:=findmax;
while li[b]>0 do
begin
        //writeln(li[b],' ',lin[b,-1]);
        li[b]:=0;
        inc(a);
        for i:=1 to lin[b,0] do
        begin
                dec(li[lin[b,i]]);
                //writeln('***',lin[b,i],' ',li[lin[b,i]]);
        end;
        b:=findmax;
end;
writeln(a);
end.
