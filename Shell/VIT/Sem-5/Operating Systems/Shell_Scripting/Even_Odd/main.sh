echo "Name: Upayan Mazumder, Reg.No: 24BDS0367"
echo "Enter a number:"
read num
if [ $((num % 2)) -eq 0 ]
then
       echo "$num is Even"
else
       echo "$num is Odd"
fi
