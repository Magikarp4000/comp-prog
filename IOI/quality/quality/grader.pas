program qualitymain;
   uses quality;
   var R,C,H,W,ans,i,j: longint;
   var Q: Qtype;
begin
   read(R);
   read(C);
   read(H);
   read(W);
   for i:=0 to R-1 do for j:=0 to C-1 do read(Q[i][j]);
   ans := rectangle(R,C,H,W,Q);
   writeln(ans);
end.
