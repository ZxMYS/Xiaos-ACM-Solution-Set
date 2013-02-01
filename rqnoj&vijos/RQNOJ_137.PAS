program rqnoj_137;
var
x,y,n,t,i,l:longint;
str:string;
f1:text;
begin
assign(f1,'f:\in.txt');
reset(f1);
t:=0;
read(f1,n);
for i:=1 to n do
begin
readln(f1,str);
if pos(str,'t')=0 then
begin
val(str,l);
case t of
0:inc(y,l);
1:dec(x,l);
2:dec(y,l);
3:inc(x,l);
end;
write('(',x,',',y,')');
end
else
if pos(str,'l')=0 then
t:=(t+3) mod 4
 else
t:=(t+1) mod 4;

end;
end.
























