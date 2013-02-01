program rqnoj_274;
const
f:array[1..4] of longint=(6,2,4,8);
var
f1:longint;
a,m,n:qword;
begin
read(n);
if n=1 then begin write('1');halt; end;
m:=n;
a:=0;
repeat
if m mod 5 = 2 then
a:=a+1+(m div 5)
else
        if m mod 5 = 4 then
        a:=a+2+(m div 5)
        else
        a:=a+(m div 5);
m:=m div 5;
until m=0;
n:=f[a mod 4 + 1];
write(n);
end.