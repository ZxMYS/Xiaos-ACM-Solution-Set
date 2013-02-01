program rqnoj_291;
var
st:string;
a,b:array['a'..'z'] of longint;
c:char;
i,j,n,m,x,y:longint;
f:boolean;
begin
readln(n);
readln(st);
m:=length(st);
for i:= 1 to m do
inc(a[st[i]]);

for i:= 1 to n do
begin
fillchar(b,sizeof(b),0);
readln(st);
j:=length(st);
if j=m then
begin
        for x:=1 to j do
                inc(b[st[x]]);
        f:=true;
        c:='a';
        for x:=1 to 26 do
        begin
                if a[c]<>b[c] then
                        begin
                        f:=false;
                        break;
                        end;
                inc(c);
        end;
        if f then inc(y);
end;
end;
write(y);
end.