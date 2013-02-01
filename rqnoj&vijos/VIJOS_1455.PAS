program vijos_1455;
type:
hugenum=array[1..1000] of integer;
var
f1,f2:array[0..1000,0..999] of longint;
a,b,c,x,y,i,j,n,m:longint;
st,st1,st2:ansistring;
function mu(fa1,fa2:hugenum):hugenum;
var
a,b,c,d,e,f,g,h,i,j,k:longint;
r:ansistring;
ch:string;
begin
for i:=1 to 1000 do
        r[i]:='0';
for i:=1 to length(fa1) do
for j:=1 to length(fa2) do
begin
        val(fa1[i],c,e);
        val(fa2[j],d,e);
        f:=c*d;
        g:=f mod 10;
        h:=f div 10;
        val(r[i+j-1],a,k);
        inc(g,a);
        if g>10 then begin g:=g mod 10;inc(f); end;

        str(g,ch);
        r:=copy(r,1,i+j)+ch+copy(r,i+j+2,length(r)-i-j-2);
        str(f,ch);
        r:=copy(r,1,i+j-1)+ch+copy(r,i+j+1,length(r)-i-j-1);
end;
exit(r);
end;
begin
assign(input,'f:\in.txt');
reset(input);

readln(st);
read(m);
writeln(mu('1111','1111'));
end.
