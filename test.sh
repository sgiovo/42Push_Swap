n="$1"
gcc randomize.c -o r
rrr=$(./r $n)
echo $rrr
./push_swap $rrr
rm r
unset rrr