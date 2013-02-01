program rqnoj_262;
var
p,s,n,a,i:longint;
f1:text;
begin
assign(f1,'f:\in.txt');
reset(f1);
readln(f1,p,s,n);
repeat
read(f1,a);
inc(i);
until (a<=n)or(i>s)or(i>=p);
while (a=n)and(not(eof(input)) do begin inc(i);read(f1,a); end;
if (i>p)or((i=p)and(a>=n)) then write(-1) else write(i);
end.
