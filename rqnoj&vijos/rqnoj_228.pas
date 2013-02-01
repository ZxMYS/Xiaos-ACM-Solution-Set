program rqnoj_228;
var
n,i:longint;
procedure d(x:longint);
begin
if x=1 then
write(1,' ')
else begin
   d(x div 2);
   write(x - (x div 2),' ');
end;
end;
begin
read(n);
writeln(trunc(ln(n)/ln(2)+1));
d(n);
end.