### Problem Statement

```plaintext
- A list has the objects of maximum 2 strings, 2 complex numbers and 2 integers.
- If atleast one integer object is prime, all strings should be reversed and the real
part as well as the imaginary part of all the complex numbers should be
interchanged
- If atleast one string object is palindrome, all the complex numbers should
be conjugated and the integer objects should be negated.
- If both of the above conditions are satisfied, print the middle element of the list.
- If none of the above conditions satisfied, convert all the
strings into list object.
```

### Output

#### Test Case 1

```plaintext
[(5+3j),"Madam",6,-1]
[(5-3j), 'Madam', -6, 1]
```

#### Test Case 2

```plaintext
["Hello","Python",3,25,(-1+7j)]
['olleH', 'nohtyP', 3, 25, (7-1j)]
```

#### Test Case 3

```plaintext
["Malayalam",(3+3j),(7-2j),"CSE",7] 
(7-2j)
```

#### Test Case 4

```plaintext
["Hello",12,(3-8j)]
['H', 'e', 'l', 'l', 'o', 12, (3-8j)]
```

#### Test Case 5

```plaintext
[1,1,1] 
Invalid Data!
```
