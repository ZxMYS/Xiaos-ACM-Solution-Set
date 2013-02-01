program VIJOS_1482;
type
str=record
        x,y:longint;
        end;
strs=array[0..10] of str;
var
sts:array[ord('A')*10+ord('A')..ord('z')*10+ord('z')] of strs;
st:string;
i,j,k,a,m,n:longint;
function check(st:strs;x,y:longint):boolean;
var i:longint;
begin
for i:=1 to st[0].x do
begin
        if (st[i].x<x) and (st[i].y<y) and (st[i].y<>x) then exit(true);
end;
exit(false);
end;
function check2(st:strs;x,y:longint):boolean;
var i:longint;
begin
for i:=1 to st[0].x do
begin
        if (st[i].x<x) and (st[i].y<y) then exit(true);
end;
exit(false);
end;
procedure deal(st:string);
var
i,j,k,a,m,n:longint;
begin
fillchar(sts,sizeof(sts),0);
for i:=1 to length(st) do
begin
a:=ord(st[i])*10;
        for j:=i+1 to length(st) do
             begin
               k:=ord(st[j]);
               if check(sts[a+k],i,j) then begin
                        writeln('de1ete'{,' ',st,' ',i,' ',j});exit;end;
               inc(sts[a+k,0].x);
               sts[a+k,sts[a+k,0].x].x:=i;
               sts[a+k,sts[a+k,0].x].y:=j;
             end;
end;
for i:=1 to length(st) do
begin
a:=ord(st[i]);
        for j:=i+1 to length(st) do
             begin
               k:=ord(st[j])*10;
               if check(sts[a+k],j,i) then begin
                        writeln('de1ete'{,'2',st,' ',i,' ',j});exit;end;
             end;
end;
writeln('safe');
end;

begin
assign(input,'f:\in.txt');
reset(input);
assign(output,'f:\out.txt');
rewrite(output);
readln(n);
for i:=1 to n do
begin
readln(st);
deal(st);
end;
close(output);
end.