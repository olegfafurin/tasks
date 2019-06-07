program tr;
{$APPTYPE CONSOLE}
uses
  SysUtils,
  math;

var c,i,j,n,m,v,z: integer;
        mi,s: extended;
    d: array [1..5000] of extended;
    mark: array [1..5000] of boolean;
    x,y: array [1..5000] of integer;

begin

   read(n);
   for i:=1 to n do
   begin
      read(x[i]);
      read(y[i]);
   end;
   for i:=1 to n do mark[i]:=false;
   for i:=2 to n do d[i]:=sqrt((x[i]-x[1])*(x[i]-x[1])+(y[i]-y[1])*(y[i]-y[1]));
   d[1]:=0;
   s:=0;
   mark[1]:=true;
   for i:=1 to n-1 do
   begin
       mi:=40000;
       v:=0;
       for j:=1 to n do
       begin
           if (mark[j]=false) and (d[j]<mi) then
           begin
               mi:=d[j];
               v:=j;
           end;
       end;
       mark[v]:=true;

       s:=s+d[v];
       for j:=1 to n do
       begin
                if mark[j]=false then d[j]:=min(d[j],sqrt((x[j]-x[v])*(x[j]-x[v])+(y[j]-y[v])*(y[j]-y[v])));
       end;
   end;
   writeln(s:0:6);
end.