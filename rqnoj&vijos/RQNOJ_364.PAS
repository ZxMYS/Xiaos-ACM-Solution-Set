program rqnoj_364;
type
homework=array[0..1] of longint;
var
a,b,c,d,e,n,i,j,qs,k,g:longint;
f,q:array[1..10000] of longint;
hw:array [1..10000] of homework;
buf:array[1..10000] of byte;
procedure qsort(lx,rx:longint);
var
l,r,k:longint;
a:homework;
begin
l:=lx;r:=rx;k:=hw[(lx+rx) shr 1][0];
repeat
        while (hw[l][0]<k)and(l<rx) do
                inc(l);
        while (hw[r][0]>k)and(r>lx) do
                dec(r);
        if l<=r then begin
                a:=hw[l];
                hw[l]:=hw[r];
                hw[r]:=a;
                inc(l);
                dec(r);
        end;
until l>=r;
if l<rx then qsort(l,rx);
if r>lx then qsort(lx,r);
end;

function min(x,y:longint):longint;
begin
if x<y then exit(x) else exit(y);
end;

function dfs(b:longint):longint;
var
i,j,q,a,g,e:longint;
begin
if f[b]>=0 then exit(f[b]);
q:=maxint;
a:=b+1;
while (hw[b][1]>hw[a][0]-1)and(a<=k) do
        inc(a);
if a<=k then begin
        g:=a+1;
        while (hw[g][0]=hw[a][0])and(g<=k) do
                inc(g);
        dec(g);
        for e:=a to g do
                q:=min(q,dfs(e)+(hw[e][1]-hw[e][0]+1));
        a:=g+1;
        end;
if q=maxint then q:=0;
f[b]:=q;
writeln(b,' ',q);
exit(q);

end;

begin
assign(input,'f:\in.txt');
reset(input);
settextbuf(input,buf);
read(n,k);
for i:=1 to k do
begin
        read(hw[i][0],hw[i][1]);
        inc(hw[i][1],hw[i][0]-1);
        f[i]:=-1;
        qs[i]:=maxint;
end;
qsort(1,k);
for i:=1 to k do
        writeln(hw[i][0],' ',hw[i][1]);
a:=1;
g:=2;
q:=maxint;
while hw[g][0]=hw[a][0] do
    inc(g);
dec(g);
for e:=a to g do
     q:=min(q,dfs(e)+(hw[e,1]-hw[e,0]+1));

writeln(n-q);
end.
