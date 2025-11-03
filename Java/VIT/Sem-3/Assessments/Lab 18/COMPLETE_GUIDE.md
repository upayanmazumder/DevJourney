# Lab 18: Complete Guide to Java Collections Framework

## Table of Contents

1. [Introduction to Collections](#introduction-to-collections)
2. [ArrayList](#arraylist)
3. [HashMap](#hashmap)
4. [TreeMap](#treemap)
5. [Common Operations](#common-operations)
6. [Complete Syntax Guide](#complete-syntax-guide)
7. [Common Patterns & Examples](#common-patterns--examples)
8. [Best Practices](#best-practices)
9. [Common Errors & Solutions](#common-errors--solutions)
10. [Practice Problems Summary](#practice-problems-summary)

---

## Introduction to Collections

The **Java Collections Framework** provides a unified architecture for storing and manipulating groups of objects. It includes interfaces, implementations, and algorithms.

### Collection Hierarchy:

```
Collection (Interface)
├── List (Interface)
│   ├── ArrayList (Class)
│   ├── LinkedList (Class)
│   └── Vector (Class)
├── Set (Interface)
│   ├── HashSet (Class)
│   └── TreeSet (Class)
└── Queue (Interface)

Map (Interface)
├── HashMap (Class)
├── TreeMap (Class)
└── LinkedHashMap (Class)
```

### Why Use Collections?

1. **Dynamic Size**: Automatically grows/shrinks
2. **Type Safety**: Generic support for compile-time checking
3. **Rich APIs**: Built-in methods for common operations
4. **Performance**: Optimized implementations
5. **Reusability**: Standard interfaces across different implementations

---

## ArrayList

### What is ArrayList?

`ArrayList` is a **resizable array** implementation of the `List` interface. It provides dynamic array capabilities with fast random access.

### Key Features:

- ✅ **Dynamic resizing** - Grows automatically
- ✅ **Indexed access** - Fast get/set operations O(1)
- ✅ **Ordered** - Maintains insertion order
- ✅ **Allows duplicates** - Can store same elements multiple times
- ✅ **Allows null** - Can contain null elements
- ❌ **Not synchronized** - Not thread-safe by default

---

### ArrayList Syntax

#### Import:

```java
import java.util.ArrayList;
```

#### Declaration & Initialization:

```java
// Basic declaration
ArrayList<Type> list = new ArrayList<>();

// With initial capacity
ArrayList<String> list = new ArrayList<>(20);

// From another collection
ArrayList<Integer> list = new ArrayList<>(anotherList);

// Examples
ArrayList<String> names = new ArrayList<>();
ArrayList<Integer> numbers = new ArrayList<>();
ArrayList<Double> prices = new ArrayList<>();
```

---

### ArrayList Methods

| Method                | Description                    | Example                 |
| --------------------- | ------------------------------ | ----------------------- |
| `add(element)`        | Adds element at end            | `list.add("Apple")`     |
| `add(index, element)` | Inserts at specific index      | `list.add(0, "First")`  |
| `get(index)`          | Returns element at index       | `list.get(2)`           |
| `set(index, element)` | Replaces element at index      | `list.set(1, "New")`    |
| `remove(index)`       | Removes element at index       | `list.remove(0)`        |
| `remove(object)`      | Removes first occurrence       | `list.remove("Apple")`  |
| `contains(object)`    | Checks if element exists       | `list.contains("Bob")`  |
| `indexOf(object)`     | Returns first index of element | `list.indexOf("Apple")` |
| `size()`              | Returns number of elements     | `list.size()`           |
| `isEmpty()`           | Checks if list is empty        | `list.isEmpty()`        |
| `clear()`             | Removes all elements           | `list.clear()`          |

---

### ArrayList Examples

#### Example 1: Basic Operations

```java
import java.util.ArrayList;

public class ArrayListBasics {
    public static void main(String[] args) {
        ArrayList<String> fruits = new ArrayList<>();

        // Adding elements
        fruits.add("Apple");
        fruits.add("Banana");
        fruits.add("Cherry");

        // Accessing elements
        System.out.println(fruits.get(0));  // Apple
        System.out.println(fruits.get(1));  // Banana

        // Size
        System.out.println(fruits.size());  // 3

        // Checking existence
        System.out.println(fruits.contains("Banana"));  // true

        // Removing
        fruits.remove(1);  // Removes "Banana"
        System.out.println(fruits);  // [Apple, Cherry]

        // Iterating
        for (String fruit : fruits) {
            System.out.println(fruit);
        }
    }
}
```

---

#### Example 2: Student Registration (Index Access)

```java
import java.util.ArrayList;
import java.util.Scanner;

public class StudentRegistration {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine(); // Consume newline

        ArrayList<String> students = new ArrayList<>();

        // Read student names
        for (int i = 0; i < n; i++) {
            students.add(sc.nextLine());
        }

        // Get index to retrieve
        int index = sc.nextInt();

        // Validate and retrieve
        if (index >= 0 && index < students.size()) {
            System.out.println("Element at index " + index + ": " + students.get(index));
        } else {
            System.out.println("Invalid index");
        }

        sc.close();
    }
}
```

---

#### Example 3: Remove Duplicates

```java
import java.util.ArrayList;
import java.util.Scanner;

public class RemoveDuplicates {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        ArrayList<Integer> transactions = new ArrayList<>();
        ArrayList<Integer> unique = new ArrayList<>();

        // Read transactions
        for (int i = 0; i < n; i++) {
            transactions.add(sc.nextInt());
        }

        // Remove duplicates (keep first occurrence)
        for (Integer transaction : transactions) {
            if (!unique.contains(transaction)) {
                unique.add(transaction);
            }
        }

        // Display unique transactions
        for (Integer amount : unique) {
            System.out.println(amount);
        }

        sc.close();
    }
}
```

---

#### Example 4: Vowel Filter

```java
import java.util.ArrayList;
import java.util.Scanner;

public class VowelFilter {

    public static int countVowels(String word) {
        int count = 0;
        String vowels = "aeiouAEIOU";

        for (char c : word.toCharArray()) {
            if (vowels.indexOf(c) != -1) {
                count++;
            }
        }

        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine(); // Consume newline

        ArrayList<String> words = new ArrayList<>();

        // Read words
        for (int i = 0; i < n; i++) {
            words.add(sc.nextLine());
        }

        // Filter words with <= 2 vowels
        ArrayList<String> filtered = new ArrayList<>();
        for (String word : words) {
            if (countVowels(word) <= 2) {
                filtered.add(word);
            }
        }

        // Display filtered words
        for (String word : filtered) {
            System.out.println(word);
        }

        sc.close();
    }
}
```

---

#### Example 5: Warehouse Manager (CRUD Operations)

```java
import java.util.ArrayList;
import java.util.Scanner;

public class WarehouseManager {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<String> products = new ArrayList<>();

        String input = sc.nextLine();
        String[] operations = input.split(" ");

        for (int i = 0; i < operations.length; i++) {
            int choice = Integer.parseInt(operations[i]);

            switch (choice) {
                case 1: // Insert
                    i++;
                    String addProduct = operations[i];
                    products.add(addProduct);
                    System.out.println(addProduct + " has been added to the list.");
                    break;

                case 2: // Delete
                    i++;
                    String removeProduct = operations[i];
                    if (products.remove(removeProduct)) {
                        System.out.println(removeProduct + " has been removed from the list.");
                    }
                    break;

                case 3: // Display
                    if (products.isEmpty()) {
                        System.out.println("The list is empty.");
                    } else {
                        System.out.println("Items in the list:");
                        for (String product : products) {
                            System.out.println(product);
                        }
                    }
                    break;

                case 4: // Search
                    i++;
                    String searchProduct = operations[i];
                    if (products.contains(searchProduct)) {
                        System.out.println(searchProduct + " is found in the list.");
                    } else {
                        System.out.println(searchProduct + " not found in the list.");
                    }
                    break;
            }
        }

        sc.close();
    }
}
```

---

#### Example 6: Geometric Mean Calculation

```java
import java.util.ArrayList;
import java.util.Scanner;

public class GeometricMean {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        ArrayList<Double> marks = new ArrayList<>();

        // Read marks
        for (int i = 0; i < n; i++) {
            marks.add(sc.nextDouble());
        }

        // Calculate product
        double product = 1.0;
        for (Double mark : marks) {
            product *= mark;
        }

        // Calculate geometric mean
        double geometricMean = Math.pow(product, 1.0 / n);

        System.out.printf("Geometric mean of the list: %.2f%n", geometricMean);

        sc.close();
    }
}
```

---

#### Example 7: Strictly Increasing Subsequence

```java
import java.util.ArrayList;
import java.util.Scanner;

public class MonitoringSystem {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        ArrayList<Integer> increasing = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int num = sc.nextInt();

            // Add only if greater than last element
            if (increasing.isEmpty() || num > increasing.get(increasing.size() - 1)) {
                increasing.add(num);
            }
        }

        System.out.println(increasing);

        sc.close();
    }
}
```

---

#### Example 8: Store Manager (Custom Class)

```java
import java.util.ArrayList;
import java.util.Scanner;

class ItemType {
    private String name;
    private double deposit;
    private double costPerDay;

    public ItemType(String name, double deposit, double costPerDay) {
        this.name = name;
        this.deposit = deposit;
        this.costPerDay = costPerDay;
    }

    public String getName() { return name; }
    public double getDeposit() { return deposit; }
    public double getCostPerDay() { return costPerDay; }
}

public class StoreManager {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine(); // Consume newline

        ArrayList<ItemType> items = new ArrayList<>();

        // Read items
        for (int i = 0; i < n; i++) {
            String name = sc.nextLine();
            double deposit = Double.parseDouble(sc.nextLine());
            double costPerDay = Double.parseDouble(sc.nextLine());

            items.add(new ItemType(name, deposit, costPerDay));
        }

        // Display in tabular format
        System.out.printf("%-20s%-20s%-20s%n", "Name", "Deposit", "Cost Per Day");

        for (ItemType item : items) {
            System.out.printf("%-20s%-20.1f%-20.1f%n",
                item.getName(),
                item.getDeposit(),
                item.getCostPerDay());
        }

        sc.close();
    }
}
```

---

## HashMap

### What is HashMap?

`HashMap` stores key-value pairs and provides fast access using keys. It uses **hashing** for storage and retrieval.

### Key Features:

- ✅ **Key-Value pairs** - Store data as (key, value)
- ✅ **Fast access** - O(1) average time for get/put
- ✅ **Unique keys** - No duplicate keys allowed
- ✅ **One null key** - Can have one null key
- ✅ **Multiple null values** - Can have multiple null values
- ❌ **Unordered** - No guaranteed order
- ❌ **Not synchronized** - Not thread-safe

---

### HashMap Syntax

#### Import:

```java
import java.util.HashMap;
import java.util.Map;
```

#### Declaration & Initialization:

```java
// Basic declaration
HashMap<KeyType, ValueType> map = new HashMap<>();

// Examples
HashMap<String, Integer> scores = new HashMap<>();
HashMap<Integer, String> idToName = new HashMap<>();
HashMap<String, Double> prices = new HashMap<>();
```

---

### HashMap Methods

| Method                 | Description                    | Example                   |
| ---------------------- | ------------------------------ | ------------------------- |
| `put(key, value)`      | Adds/updates key-value pair    | `map.put("John", 85)`     |
| `get(key)`             | Returns value for key          | `map.get("John")`         |
| `remove(key)`          | Removes key-value pair         | `map.remove("John")`      |
| `containsKey(key)`     | Checks if key exists           | `map.containsKey("John")` |
| `containsValue(value)` | Checks if value exists         | `map.containsValue(85)`   |
| `keySet()`             | Returns set of all keys        | `map.keySet()`            |
| `values()`             | Returns collection of values   | `map.values()`            |
| `entrySet()`           | Returns set of key-value pairs | `map.entrySet()`          |
| `size()`               | Returns number of pairs        | `map.size()`              |
| `isEmpty()`            | Checks if map is empty         | `map.isEmpty()`           |
| `clear()`              | Removes all pairs              | `map.clear()`             |

---

### HashMap Examples

#### Example 1: Basic Operations

```java
import java.util.HashMap;

public class HashMapBasics {
    public static void main(String[] args) {
        HashMap<String, Integer> scores = new HashMap<>();

        // Adding key-value pairs
        scores.put("Alice", 85);
        scores.put("Bob", 92);
        scores.put("Charlie", 78);

        // Getting values
        System.out.println(scores.get("Alice"));  // 85

        // Checking existence
        System.out.println(scores.containsKey("Bob"));  // true

        // Updating value
        scores.put("Alice", 90);  // Updates Alice's score

        // Removing
        scores.remove("Charlie");

        // Iterating over keys
        for (String name : scores.keySet()) {
            System.out.println(name + ": " + scores.get(name));
        }

        // Iterating over entries
        for (Map.Entry<String, Integer> entry : scores.entrySet()) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }
    }
}
```

---

#### Example 2: Fruit Festival (Sum of Values)

```java
import java.util.HashMap;
import java.util.Scanner;

public class FruitFestival {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        HashMap<String, Double> fruits = new HashMap<>();

        while (true) {
            String input = sc.nextLine();

            if (input.equals("done")) {
                break;
            }

            // Check format
            if (!input.contains(":")) {
                System.out.println("Invalid format");
                sc.close();
                return;
            }

            String[] parts = input.split(":");

            if (parts.length != 2) {
                System.out.println("Invalid format");
                sc.close();
                return;
            }

            String fruitName = parts[0];

            try {
                double quantity = Double.parseDouble(parts[1]);
                fruits.put(fruitName, quantity);
            } catch (NumberFormatException e) {
                System.out.println("Invalid input");
                sc.close();
                return;
            }
        }

        // Calculate sum
        double sum = 0.0;
        for (Double quantity : fruits.values()) {
            sum += quantity;
        }

        System.out.printf("%.2f%n", sum);

        sc.close();
    }
}
```

---

#### Example 3: Course Analyzer (Find Min/Max)

```java
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class CourseAnalyzer {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        HashMap<String, Double> courses = new HashMap<>();

        while (true) {
            String courseName = sc.nextLine();

            if (courseName.equals("done")) {
                break;
            }

            double rating = sc.nextDouble();
            sc.nextLine(); // Consume newline

            courses.put(courseName, rating);
        }

        // Find highest and lowest rated courses
        String highestCourse = null;
        String lowestCourse = null;
        double highestRating = Double.MIN_VALUE;
        double lowestRating = Double.MAX_VALUE;

        for (Map.Entry<String, Double> entry : courses.entrySet()) {
            String course = entry.getKey();
            double rating = entry.getValue();

            if (rating > highestRating) {
                highestRating = rating;
                highestCourse = course;
            }

            if (rating < lowestRating) {
                lowestRating = rating;
                lowestCourse = course;
            }
        }

        System.out.println("Highest Rated Course: " + highestCourse);
        System.out.println("Lowest Rated Course: " + lowestCourse);

        sc.close();
    }
}
```

---

## TreeMap

### What is TreeMap?

`TreeMap` stores key-value pairs in **sorted order** based on keys. It uses a **Red-Black tree** structure.

### Key Features:

- ✅ **Sorted order** - Keys are automatically sorted
- ✅ **Key-Value pairs** - Store data as (key, value)
- ✅ **No null keys** - Cannot have null keys
- ✅ **Natural ordering** - Keys sorted by natural order or comparator
- ❌ **Slower** - O(log n) for get/put operations
- ❌ **Not synchronized** - Not thread-safe

---

### TreeMap Syntax

#### Import:

```java
import java.util.TreeMap;
import java.util.Map;
```

#### Declaration & Initialization:

```java
// Basic declaration (natural ordering)
TreeMap<KeyType, ValueType> map = new TreeMap<>();

// Examples
TreeMap<String, Integer> sortedScores = new TreeMap<>();
TreeMap<Integer, String> sortedIds = new TreeMap<>();
TreeMap<Character, Integer> charFreq = new TreeMap<>();
```

---

### TreeMap Methods

Same as HashMap, plus:

| Method         | Description                  | Example            |
| -------------- | ---------------------------- | ------------------ |
| `firstKey()`   | Returns first (lowest) key   | `map.firstKey()`   |
| `lastKey()`    | Returns last (highest) key   | `map.lastKey()`    |
| `firstEntry()` | Returns first key-value pair | `map.firstEntry()` |
| `lastEntry()`  | Returns last key-value pair  | `map.lastEntry()`  |
| `headMap(key)` | Returns map with keys < key  | `map.headMap("M")` |
| `tailMap(key)` | Returns map with keys >= key | `map.tailMap("M")` |

---

### TreeMap Example

#### Character Frequency Counter

```java
import java.util.TreeMap;
import java.util.Map;
import java.util.Scanner;

public class MessageAnalyzer {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine(); // Consume newline

        TreeMap<Character, Integer> frequency = new TreeMap<>();

        // Read lines
        for (int i = 0; i < n; i++) {
            String line = sc.nextLine();

            // Process each character
            for (char c : line.toCharArray()) {
                // Skip spaces, count only letters
                if (c != ' ' && Character.isLetter(c)) {
                    frequency.put(c, frequency.getOrDefault(c, 0) + 1);
                }
            }
        }

        // Display sorted frequencies
        System.out.println("Character Frequency:");
        for (Map.Entry<Character, Integer> entry : frequency.entrySet()) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }

        sc.close();
    }
}
```

---

## Common Operations

### Iterating Through Collections

#### ArrayList Iteration:

```java
ArrayList<String> list = new ArrayList<>();
list.add("A");
list.add("B");
list.add("C");

// Method 1: Enhanced for loop
for (String item : list) {
    System.out.println(item);
}

// Method 2: Traditional for loop
for (int i = 0; i < list.size(); i++) {
    System.out.println(list.get(i));
}

// Method 3: Iterator
Iterator<String> it = list.iterator();
while (it.hasNext()) {
    System.out.println(it.next());
}

// Method 4: forEach (Java 8+)
list.forEach(item -> System.out.println(item));
```

---

#### HashMap/TreeMap Iteration:

```java
HashMap<String, Integer> map = new HashMap<>();
map.put("A", 1);
map.put("B", 2);

// Method 1: Iterate over keys
for (String key : map.keySet()) {
    System.out.println(key + ": " + map.get(key));
}

// Method 2: Iterate over values
for (Integer value : map.values()) {
    System.out.println(value);
}

// Method 3: Iterate over entries (Best)
for (Map.Entry<String, Integer> entry : map.entrySet()) {
    System.out.println(entry.getKey() + ": " + entry.getValue());
}

// Method 4: forEach (Java 8+)
map.forEach((key, value) -> System.out.println(key + ": " + value));
```

---

### Sorting

#### ArrayList Sorting:

```java
import java.util.ArrayList;
import java.util.Collections;

ArrayList<Integer> numbers = new ArrayList<>();
numbers.add(5);
numbers.add(2);
numbers.add(8);

// Sort ascending
Collections.sort(numbers);
System.out.println(numbers);  // [2, 5, 8]

// Sort descending
Collections.sort(numbers, Collections.reverseOrder());
System.out.println(numbers);  // [8, 5, 2]
```

---

### Searching

#### ArrayList Search:

```java
ArrayList<String> fruits = new ArrayList<>();
fruits.add("Apple");
fruits.add("Banana");
fruits.add("Cherry");

// Check if exists
boolean hasApple = fruits.contains("Apple");  // true

// Find index
int index = fruits.indexOf("Banana");  // 1

// Find last index
int lastIndex = fruits.lastIndexOf("Apple");  // 0
```

---

## Complete Syntax Guide

### ArrayList Quick Reference

```java
// Declaration
ArrayList<Type> list = new ArrayList<>();

// Adding
list.add(element);                    // Add at end
list.add(index, element);             // Add at index
list.addAll(anotherList);             // Add all elements

// Accessing
Type elem = list.get(index);          // Get element
list.set(index, element);             // Replace element

// Removing
list.remove(index);                   // Remove by index
list.remove(object);                  // Remove by value
list.clear();                         // Remove all

// Searching
boolean exists = list.contains(obj);  // Check existence
int idx = list.indexOf(obj);          // Find index

// Size
int size = list.size();               // Get size
boolean empty = list.isEmpty();       // Check if empty

// Conversion
Object[] arr = list.toArray();        // To array
String str = list.toString();         // To string [a, b, c]
```

---

### HashMap Quick Reference

```java
// Declaration
HashMap<KeyType, ValueType> map = new HashMap<>();

// Adding/Updating
map.put(key, value);                  // Add or update
map.putIfAbsent(key, value);          // Add only if absent

// Accessing
ValueType val = map.get(key);         // Get value
ValueType val = map.getOrDefault(key, defaultValue);

// Removing
map.remove(key);                      // Remove by key
map.clear();                          // Remove all

// Checking
boolean hasKey = map.containsKey(key);
boolean hasValue = map.containsValue(value);

// Size
int size = map.size();
boolean empty = map.isEmpty();

// Iteration
Set<KeyType> keys = map.keySet();     // Get all keys
Collection<ValueType> vals = map.values();  // Get all values
Set<Map.Entry<K,V>> entries = map.entrySet();  // Get entries
```

---

### TreeMap Quick Reference

```java
// Declaration
TreeMap<KeyType, ValueType> map = new TreeMap<>();

// Same methods as HashMap, plus:

// Navigation
KeyType first = map.firstKey();       // First (smallest) key
KeyType last = map.lastKey();         // Last (largest) key
Map.Entry<K,V> firstEntry = map.firstEntry();
Map.Entry<K,V> lastEntry = map.lastEntry();

// Sub-maps
SortedMap<K,V> head = map.headMap(key);   // Keys < key
SortedMap<K,V> tail = map.tailMap(key);   // Keys >= key
SortedMap<K,V> sub = map.subMap(from, to); // from <= keys < to
```

---

## Common Patterns & Examples

### Pattern 1: Index-Based Access

**Use Case**: Student registration, element retrieval

```java
import java.util.ArrayList;
import java.util.Scanner;

public class IndexAccess {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();

        ArrayList<String> items = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            items.add(sc.nextLine());
        }

        int index = sc.nextInt();

        if (index >= 0 && index < items.size()) {
            System.out.println("Element at index " + index + ": " + items.get(index));
        } else {
            System.out.println("Invalid index");
        }

        sc.close();
    }
}
```

---

### Pattern 2: Remove Duplicates

**Use Case**: Bank transactions, unique elements

```java
import java.util.ArrayList;

public class RemoveDuplicates {
    public static ArrayList<Integer> removeDuplicates(ArrayList<Integer> list) {
        ArrayList<Integer> unique = new ArrayList<>();

        for (Integer item : list) {
            if (!unique.contains(item)) {
                unique.add(item);
            }
        }

        return unique;
    }
}
```

---

### Pattern 3: Filtering Elements

**Use Case**: Vowel filter, conditional selection

```java
import java.util.ArrayList;

public class FilterPattern {
    public static ArrayList<String> filter(ArrayList<String> list, Condition condition) {
        ArrayList<String> filtered = new ArrayList<>();

        for (String item : list) {
            if (condition.test(item)) {
                filtered.add(item);
            }
        }

        return filtered;
    }
}
```

---

### Pattern 4: CRUD Operations

**Use Case**: Warehouse manager, product management

```java
import java.util.ArrayList;

public class CRUDOperations {
    private ArrayList<String> items = new ArrayList<>();

    // Create
    public void add(String item) {
        items.add(item);
        System.out.println(item + " has been added to the list.");
    }

    // Read
    public void display() {
        if (items.isEmpty()) {
            System.out.println("The list is empty.");
        } else {
            System.out.println("Items in the list:");
            for (String item : items) {
                System.out.println(item);
            }
        }
    }

    // Update (Replace)
    public void update(int index, String newItem) {
        if (index >= 0 && index < items.size()) {
            items.set(index, newItem);
        }
    }

    // Delete
    public void delete(String item) {
        if (items.remove(item)) {
            System.out.println(item + " has been removed from the list.");
        }
    }

    // Search
    public void search(String item) {
        if (items.contains(item)) {
            System.out.println(item + " is found in the list.");
        } else {
            System.out.println(item + " not found in the list.");
        }
    }
}
```

---

### Pattern 5: Sum/Product Calculations

**Use Case**: Geometric mean, total calculations

```java
import java.util.ArrayList;

public class Calculations {
    public static double calculateSum(ArrayList<Double> numbers) {
        double sum = 0.0;
        for (Double num : numbers) {
            sum += num;
        }
        return sum;
    }

    public static double calculateProduct(ArrayList<Double> numbers) {
        double product = 1.0;
        for (Double num : numbers) {
            product *= num;
        }
        return product;
    }

    public static double calculateGeometricMean(ArrayList<Double> numbers) {
        double product = calculateProduct(numbers);
        return Math.pow(product, 1.0 / numbers.size());
    }
}
```

---

### Pattern 6: HashMap Sum of Values

**Use Case**: Fruit festival, total quantity

```java
import java.util.HashMap;

public class SumValues {
    public static double sumMapValues(HashMap<String, Double> map) {
        double sum = 0.0;
        for (Double value : map.values()) {
            sum += value;
        }
        return sum;
    }
}
```

---

### Pattern 7: HashMap Find Min/Max

**Use Case**: Course analyzer, ratings

```java
import java.util.HashMap;
import java.util.Map;

public class FindMinMax {
    public static String findMaxKey(HashMap<String, Double> map) {
        String maxKey = null;
        double maxValue = Double.MIN_VALUE;

        for (Map.Entry<String, Double> entry : map.entrySet()) {
            if (entry.getValue() > maxValue) {
                maxValue = entry.getValue();
                maxKey = entry.getKey();
            }
        }

        return maxKey;
    }

    public static String findMinKey(HashMap<String, Double> map) {
        String minKey = null;
        double minValue = Double.MAX_VALUE;

        for (Map.Entry<String, Double> entry : map.entrySet()) {
            if (entry.getValue() < minValue) {
                minValue = entry.getValue();
                minKey = entry.getKey();
            }
        }

        return minKey;
    }
}
```

---

### Pattern 8: TreeMap Frequency Counter

**Use Case**: Character frequency, word count

```java
import java.util.TreeMap;

public class FrequencyCounter {
    public static TreeMap<Character, Integer> countCharacters(String text) {
        TreeMap<Character, Integer> freq = new TreeMap<>();

        for (char c : text.toCharArray()) {
            if (c != ' ' && Character.isLetter(c)) {
                freq.put(c, freq.getOrDefault(c, 0) + 1);
            }
        }

        return freq;
    }
}
```

---

### Pattern 9: Strictly Increasing Subsequence

**Use Case**: Monitoring system, filtering

```java
import java.util.ArrayList;

public class IncreasingSubsequence {
    public static ArrayList<Integer> extractIncreasing(int[] arr) {
        ArrayList<Integer> result = new ArrayList<>();

        for (int num : arr) {
            if (result.isEmpty() || num > result.get(result.size() - 1)) {
                result.add(num);
            }
        }

        return result;
    }
}
```

---

## Best Practices

### 1. Use Appropriate Collection

```java
// Use ArrayList when:
// - Need indexed access
// - Order matters
// - Duplicates allowed
ArrayList<String> names = new ArrayList<>();

// Use HashMap when:
// - Need key-value mapping
// - Fast lookup by key
// - Order doesn't matter
HashMap<String, Integer> scores = new HashMap<>();

// Use TreeMap when:
// - Need sorted keys
// - Key-value mapping
TreeMap<String, Integer> sortedScores = new TreeMap<>();
```

---

### 2. Specify Initial Capacity (If Known)

```java
// Good for performance if size is known
ArrayList<String> list = new ArrayList<>(100);
HashMap<String, Integer> map = new HashMap<>(50);
```

---

### 3. Use Enhanced For Loop

```java
// Good ✓
for (String item : list) {
    System.out.println(item);
}

// Less readable ✗
for (int i = 0; i < list.size(); i++) {
    System.out.println(list.get(i));
}
```

---

### 4. Use getOrDefault for Maps

```java
// Good ✓
int count = map.getOrDefault("key", 0);

// Verbose ✗
int count;
if (map.containsKey("key")) {
    count = map.get("key");
} else {
    count = 0;
}
```

---

### 5. Validate Before Access

```java
// Good ✓
if (index >= 0 && index < list.size()) {
    System.out.println(list.get(index));
} else {
    System.out.println("Invalid index");
}

// Risky ✗
System.out.println(list.get(index)); // May throw exception
```

---

### 6. Use Diamond Operator

```java
// Good ✓
ArrayList<String> list = new ArrayList<>();

// Verbose ✗
ArrayList<String> list = new ArrayList<String>();
```

---

## Common Errors & Solutions

### Error 1: IndexOutOfBoundsException

**Problem:**

```java
ArrayList<String> list = new ArrayList<>();
list.add("A");
System.out.println(list.get(5)); // Error! Index 5 out of bounds
```

**Solution:**

```java
if (index >= 0 && index < list.size()) {
    System.out.println(list.get(index));
} else {
    System.out.println("Invalid index");
}
```

---

### Error 2: NullPointerException with Maps

**Problem:**

```java
HashMap<String, Integer> map = new HashMap<>();
int value = map.get("nonexistent"); // Returns null, causes NPE
```

**Solution:**

```java
// Use getOrDefault
int value = map.getOrDefault("nonexistent", 0);

// Or check first
if (map.containsKey("key")) {
    int value = map.get("key");
}
```

---

### Error 3: ConcurrentModificationException

**Problem:**

```java
ArrayList<String> list = new ArrayList<>();
list.add("A");
list.add("B");

for (String item : list) {
    if (item.equals("A")) {
        list.remove(item); // Error! Modifying while iterating
    }
}
```

**Solution:**

```java
// Use Iterator
Iterator<String> it = list.iterator();
while (it.hasNext()) {
    String item = it.next();
    if (item.equals("A")) {
        it.remove(); // Safe removal
    }
}

// Or use removeIf (Java 8+)
list.removeIf(item -> item.equals("A"));
```

---

### Error 4: TreeMap with null key

**Problem:**

```java
TreeMap<String, Integer> map = new TreeMap<>();
map.put(null, 1); // NullPointerException! TreeMap doesn't allow null keys
```

**Solution:**

```java
// Use HashMap instead if you need null keys
HashMap<String, Integer> map = new HashMap<>();
map.put(null, 1); // Works fine
```

---

### Error 5: Incorrect Type Casting

**Problem:**

```java
ArrayList list = new ArrayList(); // Raw type
list.add("Hello");
Integer num = (Integer) list.get(0); // ClassCastException!
```

**Solution:**

```java
// Use generics
ArrayList<String> list = new ArrayList<>();
list.add("Hello");
String str = list.get(0); // No casting needed
```

---

## Practice Problems Summary

### 1. **Computer Science Class**

- **Topic**: ArrayList index access
- **Key Concepts**: get(), size(), index validation
- **Pattern**: Index-based retrieval with validation

### 2. **Fruit Festival**

- **Topic**: HashMap value summation
- **Key Concepts**: HashMap, values(), parsing, validation
- **Pattern**: Parse input, sum map values

### 3. **Geometric Mean**

- **Topic**: ArrayList mathematical calculation
- **Key Concepts**: ArrayList, Math.pow(), product calculation
- **Pattern**: Calculate product, apply formula

### 4. **Message Analyzer**

- **Topic**: TreeMap character frequency
- **Key Concepts**: TreeMap, getOrDefault(), sorting
- **Pattern**: Count frequencies in sorted order

### 5. **Remove Duplicates**

- **Topic**: ArrayList duplicate removal
- **Key Concepts**: contains(), maintaining order
- **Pattern**: Filter unique elements

### 6. **Store Manager**

- **Topic**: ArrayList with custom objects
- **Key Concepts**: Custom class, formatted output
- **Pattern**: Store objects, display in table format

### 7. **Vowel Filter**

- **Topic**: ArrayList filtering
- **Key Concepts**: contains(), conditional filtering
- **Pattern**: Count vowels, filter based on count

### 8. **Warehouse Manager**

- **Topic**: ArrayList CRUD operations
- **Key Concepts**: add(), remove(), contains()
- **Pattern**: Create, Read, Update, Delete operations

### 9. **E-Learning Administrator**

- **Topic**: HashMap min/max finding
- **Key Concepts**: HashMap iteration, comparison
- **Pattern**: Find entry with min/max value

### 10. **Monitoring System**

- **Topic**: ArrayList strictly increasing subsequence
- **Key Concepts**: Dynamic filtering, last element check
- **Pattern**: Add only if greater than last

---

## Quick Reference Cheat Sheet

### ArrayList Essentials

```java
// Create
ArrayList<Type> list = new ArrayList<>();

// Add
list.add(element);
list.add(index, element);

// Get
Type item = list.get(index);

// Remove
list.remove(index);
list.remove(object);

// Check
boolean exists = list.contains(object);
int idx = list.indexOf(object);
int size = list.size();
boolean empty = list.isEmpty();

// Iterate
for (Type item : list) { }
```

---

### HashMap Essentials

```java
// Create
HashMap<K, V> map = new HashMap<>();

// Put
map.put(key, value);

// Get
V value = map.get(key);
V value = map.getOrDefault(key, defaultValue);

// Remove
map.remove(key);

// Check
boolean hasKey = map.containsKey(key);
int size = map.size();

// Iterate
for (K key : map.keySet()) { }
for (V value : map.values()) { }
for (Map.Entry<K,V> entry : map.entrySet()) {
    K key = entry.getKey();
    V value = entry.getValue();
}
```

---

### TreeMap Essentials

```java
// Create (sorted by keys)
TreeMap<K, V> map = new TreeMap<>();

// All HashMap methods work
// Plus:
K first = map.firstKey();
K last = map.lastKey();

// Automatic sorting when iterating
for (Map.Entry<K,V> entry : map.entrySet()) {
    // Entries are in sorted order by key
}
```

---

## Study Strategy

### Day 1: ArrayList Basics

- Understand ArrayList concept
- Practice add, get, remove, contains
- Master index validation
- Solve: Computer Science Class, Warehouse Manager

### Day 2: ArrayList Advanced

- Practice remove duplicates
- Learn filtering techniques
- Master custom objects in ArrayList
- Solve: Remove Duplicates, Vowel Filter, Store Manager

### Day 3: ArrayList Calculations

- Practice mathematical operations
- Learn increasing subsequence
- Master iteration patterns
- Solve: Geometric Mean, Monitoring System

### Day 4: HashMap

- Understand key-value concept
- Practice put, get, iteration
- Learn sum and min/max patterns
- Solve: Fruit Festival, E-Learning Administrator

### Day 5: TreeMap & Review

- Learn TreeMap (sorted order)
- Practice frequency counting
- Review all patterns
- Solve: Message Analyzer

### Day 6: Final Practice

- Solve all 10 exercises from scratch
- Debug common errors
- Time yourself on each problem
- Review cheat sheet

---

## Final Tips for Assessment

1. ✅ **Always validate indices** before accessing ArrayList
2. ✅ **Use getOrDefault()** for HashMap to avoid null
3. ✅ **TreeMap auto-sorts** - use for frequency/sorted output
4. ✅ **Check isEmpty()** before displaying collections
5. ✅ **Use enhanced for loop** for cleaner iteration
6. ✅ **Use printf for formatting** - `%-20s` for left-aligned columns
7. ✅ **Parse carefully** - check format before split()
8. ✅ **Handle exceptions** - try-catch for parsing
9. ✅ **Test edge cases** - empty list, invalid index, null values
10. ✅ **Practice all patterns** - Each type has specific use cases

---

## Common Templates

### ArrayList Template:

```java
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine(); // Consume newline

        ArrayList<Type> list = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            list.add(sc.nextLine());
        }

        // Process list

        sc.close();
    }
}
```

---

### HashMap Template:

```java
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        HashMap<String, Type> map = new HashMap<>();

        while (true) {
            String input = sc.nextLine();
            if (input.equals("done")) break;

            // Parse and add to map
            map.put(key, value);
        }

        // Process map
        for (Map.Entry<String, Type> entry : map.entrySet()) {
            // Process entry
        }

        sc.close();
    }
}
```

---

### TreeMap Template:

```java
import java.util.TreeMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        TreeMap<Character, Integer> freq = new TreeMap<>();

        // Count frequencies
        for (char c : text.toCharArray()) {
            freq.put(c, freq.getOrDefault(c, 0) + 1);
        }

        // Display (auto-sorted)
        for (Map.Entry<Character, Integer> entry : freq.entrySet()) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }
    }
}
```

---

## Good Luck! 🚀

**Remember:**

- **ArrayList** = Ordered, indexed, allows duplicates
- **HashMap** = Key-value, fast access, unordered
- **TreeMap** = Key-value, sorted by keys, slower
- **Always validate** before accessing
- **Use generics** for type safety

You've got this! 💪
