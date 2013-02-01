program rqnoj_167;
var
b,c,i,j,k,n:longint;
a:array[0..100000] of longint;
function bs(lx,rx,num:longint):longint;
var
mid:longint;
begin
if (lx>rx) then exit(lx);
mid:=(lx+rx) shr 1;
if num=a[mid] then exit(mid);
if num<a[mid] then exit(bs(mid+1,rx,num)) else exit(bs(lx,mid-1,num));
end;

begin
assign(input,'f:\in.txt');
reset(input);

read(n);
a[0]:=maxlongint;
k:=0;
for i:=1 to n do
begin
read(c);
if c=0 then continue;
b:=bs(1,k,c);
if (b>k) then
        begin
        inc(k);
        a[k]:=c;
        end
        else
        a[b]:=c;

end;
write(k);
end.