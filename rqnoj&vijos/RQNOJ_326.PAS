program rqnoj_326;
type
gra= record
        ch:char;
        b:boolean;
        sx:longint;
        sy:longint;
        a:boolean;
        l:longint;
end;
var
word:array[1..10,0..1000000] of string;
wu :array[1..10,0..1000000] of boolean;
i,j,l,k1,k2,a,b,x,y,m,n,wordnum,maxx,maxy:longint;
t,c:char;
ga:array[1..100] of gra;
g2:array[0..100,0..100] of char;

//hash:array[1..100000] of boolean;
st,st2:string;



function max(x,y:longint):longint;
begin
if x>y then max:=x else max:=y;
end;

procedure okey;
var
i,j,k:longint;
begin
for i:=1 to n do
begin
 if ga[i].a then
        for j:=ga[i].sx to ga[i].sx+ga[i].l-1 do
                begin
                write(g2[j,ga[i].sy]);
                end
 else
         for j:=ga[i].sy to ga[i].sy+ga[i].l-1 do
                begin
                write(g2[ga[i].sx,j]);
                end;
 writeln;

end;
halt;
end;

procedure dfs(id:longint);
var
i,j,k,ii,m,cc:longint;
f:boolean;
x:char;
g3:array[0..10,0..10] of boolean;
begin

if id=n+1 then okey;
val(word[ga[id].l,0],ii,cc);
        for i:=1 to ii do
        begin
                fillchar(g3,sizeof(g3),0);
                f:=true;
                if wu[ga[id].l,i] then continue;
                wu[ga[id].l,i]:=true;
                if ga[id].a then
                        begin
                                k:=0;
                           for j:=ga[id].sx to ga[id].sx+ga[id].l-1 do
                                begin
                                inc(k);
                                if (g2[j,ga[id].sy]='_') or (g2[j,ga[id].sy]=word[ga[id].l,i][k]) then
                                begin
                                g2[j,ga[id].sy]:=word[ga[id].l,i][k];
                                if (g2[j,ga[id].sy]='_') then g3[j,ga[id].sy]:=true;
                                end
                                else
                                begin
                                   for m:=ga[id].sx to j-1 do
                                     if g3[j,ga[id].sy] then g2[j,ga[id].sy]:='_';
                                      f:=false;
                                end;
                           end;
                        end
                        else
                        begin
                                k:=0;
                           for j:=ga[id].sy to ga[id].sy+ga[id].l-1 do
                                begin
                                inc(k);
                                if (g2[ga[id].sx,j]='_') or (g2[ga[id].sx,j]=word[ga[id].l,i][k]) then
                                begin
                                g2[ga[id].sx,j]:=word[ga[id].l,i][k];
                                if g2[ga[id].sx,j]='_' then g3[ga[id].sx,j]:=true;
                                end
                                else
                                begin
                                   for m:=ga[id].sx to j-1 do
                                     if g3[ga[id].sx,j] then g2[ga[id].sx,j]:='_';
                                      f:=false;
                                end;
                           end;
                        end;



                 if f then dfs(id+1);
                  if ga[id].a then
                        begin
                           for j:=ga[id].sx to ga[id].sx+ga[id].l do
                                      g2[j,ga[id].sy]:='_';
                        end
                        else
                        begin
                           for j:=ga[id].sy to ga[id].sy+ga[id].l do
                                      g2[ga[id].sx,j]:='_';
                        end;
                 wu[ga[id].l,i]:=false;
        end;
end;
begin
assign(input,'f:\in.txt');
reset(input);

readln(n);


for i:=1 to n do
                begin
                  read(x,y);
                  read(t,c);
                  readln(l);
                  maxx:=max(maxx,x+l);
                  maxy:=max(maxy,y+l);
                  if c='A' then
                  begin
                        ga[i].b:=true;
                        ga[i].sx:=x;
                        ga[i].sy:=y;
                        ga[i].a:=true;
                        ga[i].l:=l;
                  end
                  else
                        begin
                        ga[i].b:=true;
                        ga[i].sx:=x;
                        ga[i].sy:=y;
                        ga[i].a:=false;
                        ga[i].l:=l;
                        end;
                end;
for i:=0 to maxx do
for j:=0 to maxy do
g2[i,j]:='_';

fillchar(word,sizeof(word),0);
repeat
                repeat
                read(c);
                case c of
                'a'..'z':c:=chr(ord('A')+ord(c)-ord('a'))
                end;
                st:=st+c
                until eoln;
                readln;
                if length(st)<=10 then
                begin
                val(word[length(st),0],k1,k2);
                word[length(st),k1+1]:=st;
                str(k1+1,st2);
                word[length(st),0]:=st2;
                inc(m);
                end;
                st:='';
until eof(input);
dfs(1);

end.
