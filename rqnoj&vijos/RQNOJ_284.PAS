program rqnoj_284;
var
k,q,ans:int64;
i,j:longint;
A,B:array[1..50] of int64;
buf:array[1..4096] of byte;
function gcd(x,y:int64):int64;
var
t:int64;
begin
if x<y then begin x:=x xor y;y:=x xor y;x:=x xor y;end;
while y<>0 do
begin
t:=y;
y:=x mod y;
x:=t;
end;
exit(x);
end;
begin
assign(input,'f:\in.txt');
reset(input);
settextbuf(input,buf);
read(k);
for i:=1 to k do
        read(A[i]);
read(q);
for i:=1 to q do
        read(B[i]);
for i:=q-1 downto 1 do
        for j:=1 to i do
        B[j]:=gcd(B[j],B[j+1]);
ans:=B[1];
for i:=k-1 downto 1 do
        for j:=1 to i do
                A[j]:=(A[j]*A[j+1]) div gcd(A[j],A[j+1]);
if ans mod A[1] <>0 then begin
writeln(0);halt; end;
k:=1;
ans:=ans div A[1];
i:=2;
while i<=ans do
begin
q:=1;
while (ans mod i)=0 do
begin
inc(q);
ans:=ans div i;
end;
k:=k*q;
inc(i);
end;
writeln(k);
end.