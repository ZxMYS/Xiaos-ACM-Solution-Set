program rqnoj_278;
var
a1,a2,b1,b2,c1,c2:longint;
x,y:longint;
z:double;
f1:text;
begin
assign(f1,'in.txt');
reset(f1);
read(f1,a1,b1,c1,a2,b2,c2);
if a1/a2=b1/b2 then
begin
write('NO INTEGER ROOT');
halt;
end;
z:=(c1*a2-c2)/(b1*a2 - b2);
if z:= trunc(z) then
y:=z
else
write('NO INTEGER ROOT');
end;
z:=(c1-b1*y)/a1;
if z:= trunc(z) then
x:=z;
writeln(x);
writeln(y)
else
write('NO INTEGER ROOT');
end
end.