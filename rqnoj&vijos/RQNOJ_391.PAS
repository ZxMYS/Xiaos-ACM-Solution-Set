program rqnoj_391;
var
i,b,j,k,m,n:longint;
f:array[1..100,0..500] of qword;
function s(num,peo:longint):qword;
begin
        if peo=1 then exit(num);
        if num=1 then exit(1);
        if f[num,peo]>0 then exit(f[num,peo]);
        for i:=0 to peo do
                inc(f[num,peo],s(num-1,peo-i));
        exit(f[num,peo]);
end;
begin
read(n,m);
if n=0 then begin write(1);halt; end;
if n*2>m then begin write(0);halt; end;
write(s(n,m-2*n));
end.
