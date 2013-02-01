program rqnoj_353;
var
n,m,a,b,c,d,x,y,i,j,z:longint;
q1,q2:array[0..30000] of longint;
buf:array[1..10000] of byte;
function bs1(l,r,n:longint):longint;
var
k:longint;
begin
if l>=r then exit(r);
k:=(l+r) shr 1;
if q1[k]<n then exit(bs1(l,k,n)) else exit(bs1(k+1,r,n));
end;
function bs2(l,r,n:longint):longint;
var
k:longint;
begin
if l>=r then exit(l);
k:=(l+r) shr 1;
if q2[k]>n then exit(bs2(l,k,n)) else exit(bs2(k+1,r,n));
end;
begin
assign(input,'f:\in.txt');
reset(input);
settextbuf(input,buf);

read(n);
for i:=1 to n do begin
        q1[i]:=maxint;
        q2[i]:=maxint;
end;
read(a);
q1[1]:=a;
q2[1]:=a;
q1[0]:=1;q2[0]:=1;
for z:=2 to n do
begin
    read(a);
    if q1[q1[0]]>=a then begin inc(q1[0]);q1[q1[0]]:=a; end
    else begin q1[bs1(1,q1[0],a)]:=a; end;
    if q2[q2[0]]<=a then begin inc(q2[0]);q2[q2[0]]:=a; end
    else begin q2[bs2(1,q2[0],a)]:=a; end;
end;
if q1[0]>q2[0] then writeln(n-q1[0]) else writeln(n-q2[0]);
end.
