Single File Programming Question
Problem Statement



Alice is concerned about the security of her confidential messages and wants to implement a simple encryption and decryption program. 



Implement a simple encryption algorithm that increments the ASCII value of each character in the message. Implement a corresponding decryption algorithm that decrements the ASCII value of each character.



Create a program that takes user input for a confidential message, encrypts the message using a basic encryption algorithm, writes the encrypted message to a file named encrypted_data.txt, and then reads the encrypted data from the file to decrypt it. The decrypted message is then displayed to ensure the correctness of the encryption and decryption process.



Assist Alice in this task.

Input format :
The input consists of a string, representing a confidential message entered by the user.

Output format :
The first line of output displays "Encrypted Message: " followed by a string representing the encrypted message after applying the encryption algorithm.

The second line of output displays "Decrypted Message: " followed by a string representing the decrypted message after reading the encrypted data from the file and applying the decryption algorithm.



Refer to the sample output for formatting specifications.

Code constraints :
The given testcases fall under the following constraints:

The string contains lowercase, uppercase and numbers with at most 50 characters.

Sample test cases :
Input 1 :
Hello
Output 1 :
Encrypted Message: Ifmmp
Decrypted Message: Hello
Input 2 :
12345
Output 2 :
Encrypted Message: 23456
Decrypted Message: 12345