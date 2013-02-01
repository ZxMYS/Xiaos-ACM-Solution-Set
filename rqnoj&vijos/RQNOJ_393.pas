program rqnoj_392;
type
zb=record
        x,y:longint;
        end;
var
ga:array[1..100,1..100] of longint;
e,e1,e2,e3:array[0..101,0..101] of boolean;
buf:array[1..4096] of byte;
q:array[1..10000] of zb;
ch:char;
i,j,k,a,m,n,p,x,y:longint;
procedure predeal(x1,y1:longint);
var
i,j,t,x,a,b:longint;
begin
        a:=1;
        t:=1;
        b:=1;
        q[1].x:=x1;
        q[1].y:=y1;
        e[x1,y1]:=true;
        repeat
        x1:=q[a].x;
        y1:=q[a].y;
        inc(a);
        dec(t);
        for i:=-1 to 1 do
                for j:=-1 to 1 do
                        if (x1+i>0) and(x1+i<=n)and(y1+j>0)and(y1+j<=n) then
                        if (not(e[x1+i,y1+j]))and(ga[x1+i,y1+j]<>-1) then begin
                            e[x1+i,y1+j]:=true;
                            if ga[x1,y1]=0 then begin
                            inc(b);
                            inc(t);
                            q[b].x:=x1+i;
                            q[b].y:=y1+j;
                            end;
                        end;
        until t=0;


end;

function check1(x1,y1:longint):longint;
var
a:longint;
i,j:longint;
begin
a:=0;
for i:=-1 to 1 do
                for j:=-1 to 1 do
                        if (x1+i>0) and(x1+i<=n)and(y1+j>0)and(y1+j<=n) then
                        if not(e[x1+i,y1+j]) then inc(a);
exit(a);

end;

procedure tag(x1,y1:longint);
var
a:longint;
i,j:longint;
begin
a:=0;
for i:=-1 to 1 do
                for j:=-1 to 1 do
                        if (x1+i>0) and(x1+i<=n)and(y1+j>0)and(y1+j<=n) then
                                e[x1+i,y1+j]:=true;
end;
function check2(x1,y1:longint):longint;
var
a:longint;
i,j:longint;
begin
a:=0;
for i:=-1 to 1 do
                for j:=-1 to 1 do
                        if (x1+i>0) and(x1+i<=n)and(y1+j>0)and(y1+j<=n) then
                        if (ga[x1+i,y1+j]=-1)and(e[x1+i,y1+j]) then inc(a);
exit(2);

end;
function deal:boolean;
var
x,y,i,a:longint;
begin
a:=0;
for i:=1 to 10 do
for x:=1 to n do
for y:=1 to n do
        begin
                if (ga[x,y]=-1)or(ga[x,y]=0) then continue;
                if check1(x,y)=ga[x,y] then tag(x,y);
        end;
for i:=1 to 10 do
for x:=1 to n do
for y:=1 to n do
        begin
                if (ga[x,y]=-1)or(ga[x,y]=0) then continue;
                if check2(x,y)+check1(x,y)=ga[x,y] then tag(x,y);
        end;
for x:=1 to n do
for y:=1 to n do
        begin
                if (ga[x,y]=-1)and(e[x,y]) then inc(a);
        end;
{for i:=1 to n do
        begin
                for j:=1 to n do
                        write(e[i,j],' ');
        writeln;
        end; }
if a=m then exit(true) else exit(false);
end;
begin
assign(input,'f:\in.txt');
reset(input);
assign(output,'f:\out.txt');
rewrite(output);
settextbuf(input,buf);
fillchar(e,sizeof(e),0);
readln(n,m,p);
for i:=1 to n do
begin
        for j :=1 to n do
        begin
                read(ch);
                if ch='*' then ga[i,j]:=-1 else ga[i,j]:=ord(ch)-ord('0');
        end;
readln;
end;
for a:= 1 to p do
begin
        read(x,y);
        x:=3;
        y:=3;
        fillchar(e,sizeof(e),0);
        if e3[x,y] and e2[x,y] then begin Writeln('Yes');Continue; end;
        if e3[x,y] and not(e2[x,y]) then begin Writeln('No');Continue; end;
        predeal(x,y);
        e1:=e;
        {for i:=1 to n do
        begin
                for j:=1 to n do
                        write(e[i,j],' ');
        writeln;
        end;   }
        if deal then begin
        writeln('Yes');
        for i:=1 to n do
                for j:=1 to n do
                        if e1[i,j] then e2[i,j]:=true;e3[i,j]:=true;
        end else begin
        writeln('No');
        for i:=1 to n do
                for j:=1 to n do
                        if e1[i,j] then e2[i,j]:=false;e3[i,j]:=true;
        end;
end;
end.