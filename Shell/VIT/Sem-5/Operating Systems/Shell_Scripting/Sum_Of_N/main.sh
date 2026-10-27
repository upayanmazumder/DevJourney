echo "Name: Upayan Mazumder, Reg.No: 24BDS0367"
echo "Enter the value of n:"
read n
sum=0
i=1
while [ "$i" -le "$n" ]
do
       echo "Enter number $i:"
       read num
       sum=$((sum+num))
       i=$((i+1))
done
echo "Sum = $sum"
