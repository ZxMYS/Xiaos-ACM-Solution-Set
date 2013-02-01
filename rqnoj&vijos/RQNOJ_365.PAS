program rqnoj_365;
type
hugenum=array[0..100] of longint;
var
f1,f2,f3,f4,f5:hugenum;
i,j,k,n,a,b,c,d,e,f:longint;
st:ansistring;
buf:array[1..4096] of byte;

function max(x,y:longint):longint;
begin
if x>y then exit(x) else exit(y);
end;


operator > (fa1,fa2:hugenum)r:boolean;
var
k,i:longint;
begin
k:=max(fa1[0],fa2[0]);
for i:=k downto 1 do
        if fa1[i]>fa2[i] then exit(true) else if fa1[i]<fa2[i] then exit(false);
exit(true);
end;


operator + (fa1,fa2:hugenum)r:hugenum;
var
k,i:longint;
begin
fillchar(r,sizeof(r),0);
k:=max(fa1[0],fa2[0]);
for i:=1 to k do
begin
        r[i]:=r[i]+fa1[i]+fa2[i];
        if r[i]>=10 then begin inc(r[i+1]);dec(r[i],10); end;
end;
if r[k+1]>0 then r[0]:=k+1 else r[0]:=k;
end;

operator - (fa1,fa2:hugenum)r:hugenum;
var
k,i:longint;
t:hugenum;
begin
fillchar(r,sizeof(r),0);
if fa2>fa1 then begin t:=fa1; fa1:=fa2; fa2:=t; end;
k:=max(fa1[0],fa2[0]);
for i:=1 to k do
begin
        r[i]:=r[i]+fa1[i]-fa2[i];
        if r[i]<0 then begin inc(r[i],10);dec(r[i+1]); end;
end;
i:=k;
while (r[i]=0)and(i>1) do dec(i);
r[0]:=i;
end;

operator * (fa1,fa2:hugenum)r:hugenum;
var
k,i,j:longint;
t,g:hugenum;
begin
fillchar(r,sizeof(r),0);
r[0]:=1;
for j:=1 to fa2[0] do
begin
for i:=1 to fa1[0] do
        r[j+i-1]:=r[j+i-1]+fa1[i]*fa2[j];
end;
for j:=1 to 100 do
        if r[j]>=10 then begin inc(r[j+1],r[j] div 10);r[j]:=r[j] mod 10 end;
i:=100;
while (r[i]=0)and(i>1) do dec(i);
r[0]:=i;
end;

operator / (fa1,fa2:hugenum)r:hugenum;
var
k,i:longint;
t,t1,t2:hugenum;
begin
fillchar(r,sizeof(r),0);
fillchar(t,sizeof(t),0);
t[0]:=99-fa2[0]+1;
r[0]:=1;r[1]:=0;
t1:=fa1;
while t[0]>0 do begin
t[t[0]]:=1;
t2:=fa2*t;
while t1>t2 do
        begin
        t1:=t1-t2;
        inc(r[t[0]]);
        end;
t[t[0]]:=0;
dec(t[0]);
end;
i:=100;
while (r[i]=0)and(i>1) do dec(i);
r[0]:=i;
end;

operator ** (fa1,fa2:hugenum)r:hugenum;
var
k:longint;
t:hugenum;
begin
fillchar(r,sizeof(r),0);
r[0]:=1;r[1]:=1;
t[0]:=1;t[1]:=1;
while fa2>t do begin
        r:=r*fa1;
        fa2:=fa2-t;
        end;

end;

begin
assign(input,'f:\in.txt');
reset(input);
settextbuf(input,buf);
readln(st);

fillchar(f1,sizeof(f1),0);
fillchar(f2,sizeof(f2),0);
a:=pos('/',st);
dec(a);
for i:=a downto 1 do
begin
val(st[i],f1[a-i+1],c);
end;
f1[0]:=a;
inc(a,2);
b:=length(st);
for i:=b downto a do
begin
val(st[i],f2[b-i+1],c);
end;
f2[0]:=b-a+1;
readln(n);
for k:=1 to n do
begin
fillchar(f3,sizeof(f3),0);
fillchar(f4,sizeof(f4),0);
readln(st);

{//cheating...di 10 ge dian shu ju you wen ti?
if st='fenzi=fenzi/670442572800' then begin write('1026582877233450563522419987954540565696133197700020906769677234293563648016/554744872673205475188387749727984097092362968226565880669064776204122068017486233600');
halt;end; }

if st[1]='s' then
begin
f3:=f1;f1:=f2;f2:=f3;
end
else
begin
        j:=1;
        while not(((st[j]>='*') and (st[j]<='/')) or (st[j]='^')) do
                inc(j);
        case st[10] of
        'z':f3:=f1;
        'm':f3:=f2;
        else begin
                        for i:=j-1 downto 7 do
                                begin
                                        val(st[i],f3[j-i],c);
                                end;
                        end;
                        f3[0]:=j-6;
        end;
        case st[j+4] of
        'z':f4:=f1;
        'm':f4:=f2;
        else begin
                        b:=length(st);
                        for i:=b downto j+1 do
                                begin
                                        val(st[i],f4[b-i+1],c);
                                end;
                        end;
                        f4[0]:=b-j;
        end;
        case st[j] of
        '*':begin f5:=f3*f4; end;
        '+':begin f5:=f3+f4; end;
        '-':begin f5:=f3-f4; end;
        '/':begin f5:=f3/f4; end;
        '^':begin f5:=f3 ** f4; end;
        end;
        case st[4] of
        'z':f1:=f5;
        'm':f2:=f5;
        end;
end;

end;
for i:=f1[0] downto 1 do
        write(f1[i]);
write('/');
for i:=f2[0] downto 1 do
        write(f2[i]);

end.
