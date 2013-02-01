program rqnoj_256;
const
g=(sqrt(5)+1)/2;
var
a,b,c:longint;
begin
read(a,b);
if a>b then begin a:=a xor b;b:=a xor b;a:=a xor b; end;
for c:=0 to 20000 do
begin
        if (a=trunc(c*g)) and (b=trunc(c*g)+c) then begin
        writeln('N');halt;
        end;
end;
writeln('Y');
end.
