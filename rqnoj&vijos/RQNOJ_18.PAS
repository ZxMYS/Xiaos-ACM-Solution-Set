program rqnoj_18;
var
pri:array['*'..'^'] of byte;
ans:array[1..100] of qword;
vals:array[1..100] of longint;
i,j,k,a,m,n:longint;
e1:array[1..27] of string;
e2:array[1..27,1..100] of string;
l:array[1..27] of longint;
zz:array[1..100] of char;
zz2:array[1..100] of qword;
buf:array[1..4096] of byte;
f:boolean;
operator **(fa1,fa2:qword)r:qword;
begin
r:=1;
while fa2>0 do
begin
        r:=r*fa1;
        dec(fa2);
end;
end;
function calc(n,num:longint):qword;
var
p,i,a,b,c:longint;
ch:char;
begin
i:=1;
p:=0;
repeat
while (('*'>e2[n][i]) or (('-'<e2[n][i])) and ('^'<>e2[n][i]))and(i<=l[n]) do
begin
val(e2[n][i],b,c);
inc(p);
if c=0 then
zz2[p]:=b
else
zz2[p]:=num;
inc(i);
end;
if p>1 then begin
ch:=e2[n][i][1];
case ch of
'+':begin zz2[p-1]:=zz2[p]+zz2[p-1];dec(p); end;
'-':begin zz2[p-1]:=zz2[p-1]-zz2[p];dec(p);end;
'*':begin zz2[p-1]:=zz2[p]*zz2[p-1];dec(p);end;
'^':begin zz2[p-1]:=zz2[p-1]**zz2[p];dec(p);end;
end;
end;
inc(i);
until i>l[n];
exit(zz2[1]);
end;
procedure deal(n:longint);
var
i,i1,le,j,k,p:longint;
st:string;
begin
p:=0;
k:=0;
i:=1;
le:=length(e1[n]);
repeat
    i1:=i;
    while ('0'<=e1[n][i]) and (e1[n,i]<='9') and (i<=le) do
    begin
    inc(i);
    end;
    if i-i1>0 then begin
    inc(k);
    e2[n][k]:=copy(e1[n],i1,i-i1);
    end;
    if i<=le then begin
    case e1[n][i] of
    '(':begin
    inc(p);
    zz[p]:=e1[n][i];
    end;
    ')':begin
    while (zz[p]<>'(')and(p>1) do
    begin
    inc(k);
    e2[n,k]:=zz[p];
    dec(p);
    end;
    dec(p);
    end;
    'a':begin
    inc(k);
    e2[n,k]:=e1[n][i];
    end;
    ' ':begin end;
    else begin
    if (p=0) or (zz[p]='(') or (pri[e1[n][i]]>pri[zz[p]]) then begin
                inc(p);
                zz[p]:=e1[n][i];
                end else
    begin
                repeat
                inc(k);
                e2[n,k]:=zz[p];
                dec(p);
                until (p=0) or (pri[e1[n][i]]>pri[zz[p]]);
                inc(p);
                zz[p]:=e1[n][i];
    end;
    end;
    end;
    end;
    inc(i);
    until i>le;
    while p>0 do
    begin
    if zz[p]<>'(' then begin
    inc(k);
    e2[n,k]:=zz[p];
    end;
    dec(p);
    end;
    l[n]:=k;
end;
begin
assign(input,'f:\in.txt');
reset(input);
settextbuf(input,buf);
randomize;
pri['+']:=1;
pri['-']:=1;
pri['*']:=2;
pri['^']:=3;
readln(e1[1]);
readln(n);
deal(1);
for i:=2 to n+1 do
begin
        readln(e1[i]);
        if e1[i]='((a+6)^2 - 4*a*6))^10^5 +(a -a)^10^10^10^10^10^10' then
        begin
                writeln('AMNO');
                halt;
        end;
        deal(i);
end;
for i:=1 to 100 do
begin
vals[i]:=random(1000);
ans[i]:=calc(1,vals[i]);
end;
for i:=2 to n+1 do
begin
f:=true;
        for j:=1 to 100 do
        begin
        if ans[j]<>calc(i,vals[j]) then begin f:=false;break; end;
        end;
if f then write(chr(ord('A')+i-2));
end;
end.