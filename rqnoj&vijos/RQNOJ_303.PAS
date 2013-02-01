program rqnoj_303;
var
s,s2:array[1..100000] of longint;
n,i,j,m,a,b:longint;
procedure qsort(lx,rx:longint);
var
i,j,x,t:longint;
begin
i:=lx;j:=rx;t:=s[(lx+rx) div 2];
repeat
        while (s[i]<t)and(i<rx) do
                inc(i);
        while (s[j]>t)and(j>lx) do
                dec(j);

        if i<=j then
        begin
        x:=s[i];
        s[i]:=s[j];
        s[j]:=x;
        inc(i);
        dec(j);
        end;
until i>=j;
if j>lx then qsort(lx,j);
if i<rx then qsort(i,rx);
end;

procedure qsort2(lx,rx:longint);
var
i,j,x,t:longint;
begin
i:=lx;j:=rx;t:=s2[(lx+rx) div 2];
repeat
        while (s2[i]<t)and(i<rx) do
                inc(i);
        while (s2[j]>t)and(j>lx) do
                dec(j);

        if i<=j then
        begin
        x:=s2[i];
        s2[i]:=s2[j];
        s2[j]:=x;
        inc(i);
        dec(j);
        end;
until i>=j;
if j>lx then qsort2(lx,j);
if i<rx then qsort2(i,rx);
end;


begin
assign(INPUT,'f:\in.txt');
reset(input);
repeat
	a:=0;
	read(n);
	if n=0 then halt;
	for i:= 1 to n do
	read(s[i]);
	for i:= 1 to n do
	read(s2[i]);
	qsort(1,n);
	qsort2(1,n);

	{for i:= 1 to n do
	write(s[i],' ');
	writeln;
	for i:= 1 to n do
	write(s2[i],' ');
        writeln; }

	repeat
        //writeln('****************');
        //writeln(s2[n],' ',s[n],' ',s2[1],' ',s[1]);
        if s2[n]<s[n] then
        begin
        inc(a,200);
        dec(n);
        end
        else
        if s2[1]<s[1] then
	begin
		inc(a,200);
		dec(n);
		for m:= 1 to n do
		begin
			s[m]:=s[m+1];
			s2[m]:=s2[m+1];
		end;
		end
	else
                if (s[n]<=s2[n])and(s[1]<=s2[1])and(n<>1) then
                begin
		dec(n);
                if s[1]<s2[n] then dec(a,200);
                for m:= 1 to n do
		s[m]:=s[m+1];
                end
                else
                if s2[1]>=s[1] then
		begin
		if s2[1]>s[1] then dec(a,200);
		dec(n);
                for m:= 1 to n do
		begin
			s[m]:=s[m+1];
			s2[m]:=s2[m+1];
		end;

		end;
        //writeln('****************')
	until n=0;
	writeln(a);
until false;
end.
