program rqnoj_242;
var
c:array[0..100000] of longint;
a,b,d:array[1..100000] of longint;
n,i,j,k,max:longint;
function bs(x,y:longint):longint;
var
mid:longint;
begin
if x=y then exit(x);
mid:=(x+y) shr 1;
if k>b[mid] then exit(bs(mid+1,y)) else exit(bs(x,mid));

end;



begin
assign(input,'f:\in.txt');
reset(input);
read(n);
for i:=1 to n do
begin
        read(a[i]);
        c[a[i]]:=i;
end;
for i:=1 to n do
begin
        read(b[i]);
        d[c[b[i]]]:=i;
end;
fillchar(b,sizeof(b),0);
b[1]:=d[1];
max:=1;
for i:=2 to n do
begin
        k:=d[i];
        if k<b[1] then
                b[1]:=k
        else if k>b[max] then
                begin
                 inc(max);
                 b[max]:=k;
                end
        else
                b[bs(1,max)]:=k;

end;

write(n-max);
end.
