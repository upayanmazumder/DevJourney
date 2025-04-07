Single File Programming Question
Problem Statement



Rahman is in charge of an inventory system at a store that receives products in batches from multiple suppliers. Each batch comes with a list of item IDs that represent the products. Before updating the inventory system, Rahman needs to merge these lists of item IDs and then sort them to keep the records well-organized.



Write a program to help Rahman by using vectors to store the lists, and then performing merging and sorting operations to combine the two lists and arrange them in ascending order.

Input format :
The first line contains an integer n, the number of item IDs in the first batch.

The next line contains n space-separated integers, representing the item IDs for the first batch.

The following line contains an integer m, the number of item IDs in the second batch.

The next line contains m space-separated integers, representing the item IDs for the second batch.

Output format :
The output prints the merged and sorted list of item IDs in a single line, separated by spaces.



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ m, n ≤ 15

1 ≤ vector elements ≤ 200

Sample test cases :
Input 1 :
5
2 4 6 8 10
5
1 3 5 7 9
Output 1 :
1 2 3 4 5 6 7 8 9 10 
Input 2 :
2
4 5
4
1 2 3 6
Output 2 :
1 2 3 4 5 6 
Input 3 :
4
7 9 11 13
3
2 4 6
Output 3 :
2 4 6 7 9 11 13 