type TWord = record
       Ind, Len: Integer;
     end;

var f: Text;
    Words: array[1..6000] of TWord;
    Data: array[1..10000] of Char;
    Count, i, j, w, mw, ma, a, h: Integer;
    c: Char;
    S: String;

function Area(Width: Integer): Integer;
var i, w, h, Maxw: Integer;
begin
  Maxw := 0;
  h := 1;
  w := 0;
  for i := 1 to Count do
    begin
      if Words[i].Len > Width then
        begin
          Area := 0;
          Exit;
        end;
      if (w + Words[i].Len) > Width then
        begin
          if w > Maxw then Maxw := w;
          w := 0;
          Inc(h);
        end
      else
        Inc(w, Words[i].Len);
      if i < Count then
        if w + 1 > Width then
          begin
            if w > Maxw then Maxw := w;
            w := 0;
            Inc(h);
          end
        else
          Inc(w);
    end;
  if Maxw = 0 then
    Area := 0
  else
    Area := (Maxw + 2) * (h + 2);
end;

begin
  Assign(f, 'Input.txt');
  Reset(f);
  Count := 0;
  i := 1;
  while not Eof(f) do
    begin
      repeat
        Read(f, c);
      until (c <> ' ') and (c <> #13) and (c <> #10);
      while not Eof(f) and (c <> ' ') and (c <> #13) and (c <> #10) do
        begin
          S := S + c;
          Read(f, c);
        end;
      if Eof(f) then S := S + c;
      case S[1] of
      '.', ',', '?', '!':
        begin
          Data[i] := S[1];
          Inc(i);
          Inc(Words[Count].Len);
        end
      else
        begin
          Inc(Count);
          Words[Count].Ind := i;
          Words[Count].Len := Length(S);
          for j := 1 to Length(S) do
            begin
              Data[i] := S[j];
              Inc(i);
            end;
        end;
    end;
    S := '';
  end;
  Close(f);

  ma := MaxInt;
  for i := 1 to 10000 do
    begin
{      w := 0;
      h := 1;
      mw := 0;
      for j := 1 to Count do
        begin
          if (w + Words[j].Len > i) then
            begin
              w := 0;
              Inc(h);
            end
          else
            begin
              Inc(w, Words[j].Len);
              if w > mw then mw := w;
            end;
        end;
      if (h * mw <> 0) and ((h + 2) * (mw + 2) < ma) then
        ma := (h + 2) * (mw + 2);}
      a := Area(i);
      if (a <> 0) and (a < ma) then ma := a;
    end;
  Writeln(ma);
  Assign(f, 'Output.txt');
  Rewrite(f);
  Close(f);
end.