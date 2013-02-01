program rqnoj_385;
type
hugenum=array[0..1000] of qword;
var
i,j,k,a,m,n:longint;
f:array[1..100,1..100] of qword;
pp:hugenum;

procedure mu(a:qword;var b:hugenum);
var
j,i,k:longint;
c:hugenum;
begin
        fillchar(c,sizeof(c),0);
        k:=trunc(ln(a)/ln(10))+1;
        for i:=1 to b[0]+k-1 do
                c[i]:=c[i]+b[i]*a;
        for i:=1 to b[0]+k do
        begin
                inc(c[i+1],c[i] div 10);
                c[i]:=c[i] mod 10;
        end;
        while c[i]=0 do dec(i);
        c[0]:=i;
        b:=c;
end;
procedure p(n:qword;var b:hugenum);
var i:longint;
begin
        for i:=2 to n do
             mu(i,b);

end;

function s(n,r:longint):qword;
begin
if f[n,r]>0 then exit(f[n,r]);
if n=r then exit(1);
if r=1 then exit(1);
if (n<r) then exit(0);
f[n,r]:=r*s(n-1,r) + s(n-1,r-1);
exit(f[n,r]);
end;
begin
        fillchar(pp,sizeof(pp),0);
        fillchar(f,sizeof(f),0);
        read(n,m);
        //n:=100;m:=100;
        pp[0]:=1;
        pp[1]:=1;
        p(n-1,pp);
        mu(s(m,n-1),pp);
        for i:= pp[0] downto 1  do
               write(pp[i]);
        writeln;
end.
