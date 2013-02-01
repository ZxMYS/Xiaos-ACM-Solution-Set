program rqnoj_268;
var
a,b,x:qword;
c,i,j:longint;
d:double;
f:boolean;
begin
read(c);
repeat
f:=false;
j:=0;
read(a,b);
if a*b=0 then begin writeln(0);f:=true; end else begin
for i:=1 to 50 do
begin
if a<b then begin x:=a;a:=b;b:=x; end;
d:=ln(a / b + 1)/ln(2);
if d=trunc(d) then begin writeln(j + trunc(d)); f:=true; break; end
else
begin
d:=trunc(d);
a:=a-(b*(trunc(exp(ln(2)*d)) - 1));
b:=b+(b*(trunc(exp(ln(2)*d)) - 1));
j:=j+trunc(d);
end;
end;
end;
dec(c);
if not f then writeln(-1);
until c=0;
end.