program rqnoj_366;
type
points=record
        f,n:qword;
        end;
lines=record
        p1,p2,v:qword;
        end;
var
k,s,a,b,c,d,t,m,n:qword;
i,j:longint;
ans:qword;
p:array[1..20000] of points;
li:array[1..20000] of lines;
buf:array[1..10000] of byte;
procedure qsort(lx,rx:qword);
var
l,r,x:qword;
t:lines;
begin
l:=lx;r:=rx;x:=li[((lx+rx) shr 1)].v;
repeat
        while (li[l].v<x) and (l<rx) do
                inc(l);
        while (li[r].v>x) and (r>lx) do
                dec(r);
        if l<=r then begin
                t:=li[l];
                li[l]:=li[r];
                li[r]:=t;
                inc(l);
                dec(r);
                end;
until l>=r;
if l<rx then qsort(l,rx);
if r>lx then qsort(lx,r);
end;
begin
assign(input,'f:\in.txt');
reset(input);
settextbuf(input,buf);
read(t);
for j:=1 to t do
begin
ans:=0;
read(n);
for i:=1 to n-1 do
begin
        read(li[i].p1,li[i].p2,li[i].v);
        p[i].f:=i;p[i].n:=0;
end;
p[n].f:=n;p[n].n:=0;
qsort(1,n-1);
for i:=1 to n-1 do
begin
       a:=p[li[i].p1].f;
       b:=p[li[i].p2].f;
       c:=1;
       while p[a].n<>0 do
                begin
                        a:=p[a].n;
                        inc(c);
                end;
       p[a].n:=b;
       d:=0;
       while b<>0 do
                begin
                        p[b].f:=p[li[i].p1].f;
                        inc(d);
                        b:=p[b].n;
                end;
       ans:=ans+(c*d)*(li[i].v+1);
end;
writeln(ans-n+1);
end;
end.


