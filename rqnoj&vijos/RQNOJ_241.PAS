program rqnoj_241;
var
ga:array[1..10,1..10] of longint;
a:array[1..10] of longint;
n,i,j,x,y:longint;
flag:boolean;

procedure find;
var
c,d:longint;
begin
flag:=false;
for j := 1 to n do
        if a[j]= 0 then
        if j<>1 then
        begin
                write(j,' ');
                a[j]:=maxint;
                flag:=true;
                break;
        end
        else
        begin
                write(1);
                halt;
        end;
if flag then
        begin
            for c:= 1 to 10 do
                if ga[c,j]=1 then
                begin
                ga[c,j]:=0 ;
                a[c]:=a[c]-1;
                end;
        end
else
begin
        write('What a poor boy!');
        halt;
end;

end;

begin
read(n);
for i:= 1 to n do
        a[i]:=maxint;
fillchar(ga,sizeof(ga),0);
for i:= 1 to n do
begin
     read(a[i]);
     for x:= 1 to a[i] do
        begin
                read(y);
                ga[i,y]:=1;
        end;
end;
for x:= 1 to 10 do
find;

end.