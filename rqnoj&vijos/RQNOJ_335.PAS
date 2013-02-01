program rqnoj_335;
const
len=900000;
type
gra=record
        t:longint;
        f,q:boolean;
end;
qu=record
        x,y:longint;
        a:longint;
end;
var
ga:array[-1..301,-1..301] of gra;
i,j,k,m,a,b,c,s,x,y,top,bot,l:longint;
q:array [0..len] of qu;
buf:array[1..4096] of byte;
function min(x,y:longint):longint;
begin
if x>y then exit(y) else exit(x);
end;

begin
assign(input,'f:\in.txt');
reset(input);

settextbuf(input,buf);
read(m);
fillchar(ga,sizeof(ga),0);
for i:=-1 to 301 do
        for j:=-1 to 301 do
                ga[i,j].t:=maxint;
for i:=1 to m do
begin
        read(a,b,c);
        ga[a,b].f:=true;
        ga[a+1,b].f:=true;
        ga[a+1,b].t:=min(ga[a+1,b].t,c);
        ga[a-1,b].f:=true;
        ga[a-1,b].t:=min(ga[a-1,b].t,c);
        ga[a,b+1].f:=true;
        ga[a,b+1].t:=min(ga[a,b+1].t,c);
        ga[a,b-1].f:=true;
        ga[a,b-1].t:=min(ga[a,b-1].t,c);
        ga[a,b].t:=min(ga[a,b].t,c);
end;
a:=0;
l:=1;
top:=1;
bot:=1;
q[1].x:=0;
q[1].y:=0;
q[1].a:=0;
repeat
        x:=q[top].x;
        y:=q[top].y;
        a:=q[top].a;
        a:=a+1;
        dec(l);
        top:=(top + 1) mod len;
        if not(ga[x,y].f) then begin writeln(a-1); halt; end;
        if not(ga[x+1,y].q) and (ga[x+1,y].t>a) and (x+1<=301) then
        begin
                inc(l);
                bot:=(bot+1) mod len;
                q[bot].x:=x+1;q[bot].y:=y;q[bot].a:=a;
                ga[x+1,y].q:=true;
        end;
        if not(ga[x-1,y].q) and (ga[x-1,y].t>a) and (x-1>=0) then
        begin
                inc(l);
                bot:=(bot+1) mod len;
                q[bot].x:=x-1;q[bot].y:=y;q[bot].a:=a;
                ga[x-1,y].q:=true;
        end;
        if not(ga[x,y+1].q) and (ga[x,y+1].t>a) and (y+1<=301) then
        begin
                inc(l);
                bot:=(bot+1) mod len;
                q[bot].x:=x;q[bot].y:=y+1;q[bot].a:=a;
                ga[x,y+1].q:=true;
        end;
        if not(ga[x,y-1].q) and (ga[x,y-1].t>a) and (y-1>=0) then
        begin
                inc(l);
                bot:=(bot+1) mod len;
                q[bot].x:=x;q[bot].y:=y-1;q[bot].a:=a;
                ga[x,y-1].q:=true;
        end;
until l=0;
writeln(-1);
end.