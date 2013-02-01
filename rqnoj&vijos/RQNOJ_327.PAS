program rqnoj_327;
const
f:array[1..4] of longint=(6,2,4,8);
var
f1:longint;
n,a,m:qword;

begin
assign(input,'f:\in.txt');
reset(input);
read(n);
if n=1 then begin write('drxh');halt; end;
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
case n of
1:write('drxh');
2:write('dyf');
3:write('hades');
4:write('xiaokeke');
5:write('xiaokaka');
6:write('atttx123');
7:write('h');
8:write('LIFE');
9:write('dadi')
end;
end.