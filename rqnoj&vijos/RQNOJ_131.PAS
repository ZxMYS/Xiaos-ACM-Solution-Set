program rqnoj_131;
var
i,j,k,q,n:longint;
pr:array[1..100] of boolean;
pr2:array[1..100] of longint;
begin
read(n);

for i:=2 to n do
        pr[i]:=true;
for i:=2 to n do
        if pr[i] then
        begin
                k:=2;
                q:=i*k;
                repeat
                        pr[q]:=false;
                        inc(k);
                        q:=i*k;
                until q>n;
        end;
k:=1;
for i:=1 to n do
        if pr[i] then begin pr2[k]:=i;inc(k); end;
dec(k);
i:=4;
while i<=n do
begin
        j:=0;
        repeat
        inc(j);
        q:=0;
        repeat
                inc(q);
        until (pr2[j]+pr2[q]=i)or(q>k);
        until (pr2[j]+pr2[q]=i)or(j>k);
        writeln(i,'=',pr2[j],'+',pr2[q]);
inc(i,2);
end;
end.