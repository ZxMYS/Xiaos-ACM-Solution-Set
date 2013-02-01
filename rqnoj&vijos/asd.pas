 program chenbl;
const
n=1000000;
var
i,k,a,b:longint;
begin
randomize;
i:=0;
k:=0;
repeat
 a:=random(2);
 b:=random(2);
 if (a=1) or (b=1) then begin
inc(i);
if a xor b=1 then
inc(k);
end;
until i=n;
writeln(k);
end.