program rqnoj_386;
var
c3:array[0..32768] of longint;
c1:array[0..32768] of boolean;
p:array[0..1000000] of longint;
x,y,a,b,c,i,j,m,n,k:longint;
buf:array[1..4096] of longint;
begin
assign(input,'f:\in.txt');
reset(input);
settextbuf(input,buf);

read(n,m);
fillchar(p,sizeof(p),0);
fillchar(c3,sizeof(c3),0);
fillchar(c1,sizeof(c1),0);
c:=-maxlongint;
x:=c;
for i:=1 to n do
begin
        read(a);
        p[i]:=a;
        c1[a]:=true;
        if c3[a]=0 then
                inc(b);
        inc(c3[a]);
        if i>m then begin dec(c3[p[i-m]]);if c3[p[i-m]]=0 then dec(b); end;
        if b>c then begin c:=b;k:=i end;
end;
fillchar(c3,sizeof(c3),0);
for i:=k downto k-m+1 do
begin
    inc(c3[p[i]]);
    for j:=1 to 32768 do
        if (c1[j])and(c3[j]=0) then break;
    if c1[j]=false then break;
end;
writeln(c,' ',k-i+1);
end.
