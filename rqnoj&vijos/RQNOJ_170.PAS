program rqnoj_170;
var
f,d,i,j,m,t,y,u,k,a,x,z:longint;
ch:char;
begin
assign(input,'f:\in.txt');
reset(input);

readln(m,t,u,f,d);
a:=0;
for i:=1 to t do
begin
readln(ch);
case ch of
'u':dec(m,u+d);
'f':dec(m,2*f);
'd':dec(m,u+d);
end;
if m>=0 then inc(a) else break;
end;
write(a);
end.