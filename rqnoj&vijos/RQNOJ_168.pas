program rqnoj_168;
type
hugenum=array[0..700] of longint;
var
ww:array[1..1000] of hugenum;
sum:hugenum;
na:array[1..1000] of string;
st,st2:ansistring;
x,y,z,a,b,i,j,c,m,n:longint;
buf:array[1..4096] of byte;

operator = (fa1,fa2:hugenum)re:boolean;
var
i,k:longint;
begin
if fa1[0]<>fa2[0] then exit(false);
k:=fa1[0];
for i:=k downto 1 do
        if fa1[i]<>fa2[i] then exit(false);
exit(true);
end;

operator > (fa1,fa2:hugenum)re:boolean;
var
i:longint;
begin
if fa1[0]>fa2[0] then exit(true);
if fa1[0]<fa2[0] then exit(false);
//if fa1=fa2 then exit(false);
for i:=fa1[0] downto 1 do
begin
        if fa1[i]>fa2[i] then exit(true) else if fa1[i]<fa2[i] then exit(false);
end;
exit(false);
end;

function max(x,y:longint):longint;
begin
if x>y then exit(x) else exit(y);
end;

operator + (fa1,fa2:hugenum)re:hugenum;
var
i,k:longint;
begin
fillchar(re,sizeof(re),0);
k:=max(fa1[0],fa2[0]);
if k>=698 then k:=698;
for i:=1 to k+1 do
begin
re[i]:=fa1[i]+fa2[i]+re[i];
if re[i] >= 10000 then begin re[i+1]:=re[i+1]+1; re[i]:=re[i] - 10000; end;
end;
re[0]:=k+1;
end;

procedure qsort(lx,rx:longint);
var
l,r:longint;
x,t:hugenum;
st3:string;
begin
l:=lx;r:=rx;x:=ww[(lx+rx) shr 1];
repeat
        while (ww[l]>x)and(l<rx) do
                inc(l);
        while (x>ww[r])and(r>lx) do
                dec(r);
        if l<=r then begin
                st3:=na[l];
                na[l]:=na[r];
                na[r]:=st3;
                t:=ww[l];
                ww[l]:=ww[r];
                ww[r]:=t;
                inc(l);
                dec(r);
        end;
until l>=r;
if l<rx then qsort(l,rx);
if r>lx then qsort(lx,r);
end;

procedure qsort2(lx,rx:longint);
var
l,r:longint;
x,t:string;
begin
l:=lx;r:=rx;x:=na[(lx+rx) shr 1];
repeat
        while (na[l]<x)and(l<rx) do
                inc(l);
        while (x<na[r])and(r>lx) do
                dec(r);
        if l<=r then begin
                t:=na[l];
                na[l]:=na[r];
                na[r]:=t;
                inc(l);
                dec(r);
        end;
until l>=r;
if l<rx then qsort2(l,rx);
if r>lx then qsort2(lx,r);
end;

begin
assign(input,'f:\in.txt');
reset(input);
settextbuf(input,buf);

assign(output,'f:\out.txt');
rewrite(output);

readln(n);
fillchar(sum,sizeof(sum),0);
fillchar(ww,sizeof(ww),0);
for i:=1 to n do
        begin
                readln(na[i]);
                readln(st);
                x:=length(st) div 4;
                a:=length(st) - (x * 4);
                st2:=copy(st,1,a);

                val(st2,ww[i,x+1],c);
                st:=copy(st,a+1,length(st)-a+1);
                a:=x;
                x:=length(st) div 4;
                for j:=x downto 1 do
                        begin
                                st2:=copy(st,(x-j) * 4 + 1,4);
                                val(st2,ww[i,j],c);
                        end;
                if ww[i,a+1]>0 then ww[i,0]:=a+1 else ww[i,0]:=a;
                sum:=sum+ww[i];
        end;
qsort(1,n);

a:=1;
repeat
        b:=a;
        while (ww[b]=ww[a])and(b<=n) do
                inc(b);
        dec(b);
        if b>a then qsort2(a,b);
        a:=b+1;
until a>=n;

for i:=1 to n do
        writeln(na[i]);



str(sum[123] mod 100,st);
while length(st) < 2 do
        st:='0'+st;
write(st);
for i:=122 downto 1 do
        begin
        str(sum[i],st);
        while length(st) < 4 do
        st:='0'+st;
        write(st);
        end;
writeln;
close(output);
end.