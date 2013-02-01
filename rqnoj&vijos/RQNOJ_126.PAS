program rqnoj_126;
type
st=array[0..2] of longint;
var
score:array[1..1000,1..3] of longint;
student:array[1..1000] of st;
i,j,k,temp,n,m,s,t,u,v,w,x,y,z,a,b,c:longint;
procedure qsort(lx,rx,by:longint);
var
l,r,t:longint;
x:st;
begin
l:=lx;r:=rx;
t:=student[(lx+rx) shr 1][by];

repeat
        while (student[l][by]>t)and(l<rx) do
                inc(l);
        while (student[r][by]<t)and(r>lx) do
                dec(r);
        if l<=r then begin
                x:=student[l];
                student[l]:=student[r];
                student[r]:=x;
                inc(l);
                dec(r);
                end;
until l>=r;
if l<rx then qsort(l,rx,by);
if r>lx then qsort(lx,r,by);
end;
procedure qsort2(lx,rx,by:longint);
var
l,r,t:longint;
x:st;
begin
l:=lx;r:=rx;
t:=student[(lx+rx) shr 1][by];

repeat
        while (student[l][by]<t)and(l<rx) do
                inc(l);
        while (student[r][by]>t)and(r>lx) do
                dec(r);
        if l<=r then begin
                x:=student[l];
                student[l]:=student[r];
                student[r]:=x;
                inc(l);
                dec(r);
                end;
until l>=r;
if l<rx then qsort2(l,rx,by);
if r>lx then qsort2(lx,r,by);
end;
begin
assign(input,'f:\in.txt');
reset(input);

read(n);
m:=5;
k:=3;
for i:=1 to n do
        begin
        temp:=0;
        for j:=1 to k do
        begin
                read(score[i,j]);
                temp:=temp + score[i,j];
        end;
        student[i][1]:=temp;
        student[i][0]:=i;
        student[i][2]:=score[i,1];
        end;

qsort(1,n,1);

{for y:=1 to n do
        writeln('...',student[y][1],' ',student[y][0]);}

i:=0;
v:=0;
repeat
        v:=i+1;
        u:=student[v][1];
        x:=student[v][1];
        i:=v;
        while (u=x)and(i<=n) do
                begin inc(i); x:=student[i][1]; end;
        dec(i);
        if i>v then qsort(v,i,2);
        //writeln('***',v,' ',i);
until v>m;
{for y:=1 to n do
        writeln('..',student[y][0]);}
i:=0;
v:=0;
repeat
        v:=i+1;
        u:=student[v][2];
        w:=student[v][1];
        x:=student[v][2];
        y:=student[v][1];
        i:=v;
        while (u=x)and(i<=n)and(w=y) do
                begin inc(i); x:=student[i][2];y:=student[i][1]; end;
        dec(i);
        //writeln('***',v,i);
        if i>v then qsort2(v,i,0)
until v>m;

 for i:=1 to m-1 do
        writeln(student[i][0],' ',student[i][1]);
 write(student[m][0],' ',student[m][1]);
end.
