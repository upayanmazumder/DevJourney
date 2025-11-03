# Lab 17: Complete Guide to Java Generics

## Table of Contents

1. [Introduction to Generics](#introduction-to-generics)
2. [Why Use Generics?](#why-use-generics)
3. [Generic Methods](#generic-methods)
4. [Generic Classes](#generic-classes)
5. [Generic Interfaces](#generic-interfaces)
6. [Bounded Type Parameters](#bounded-type-parameters)
7. [Complete Syntax Guide](#complete-syntax-guide)
8. [Common Patterns & Examples](#common-patterns--examples)
9. [Comparable & Comparator](#comparable--comparator)
10. [Best Practices](#best-practices)
11. [Common Errors & Solutions](#common-errors--solutions)
12. [Practice Problems Summary](#practice-problems-summary)

---

## Introduction to Generics

**Generics** enable types (classes and interfaces) to be parameters when defining classes, interfaces, and methods. This allows you to write code that works with different data types while providing compile-time type safety.

### Before Generics (Old Way):

```java
ArrayList list = new ArrayList();
list.add("Hello");
list.add(10);
String s = (String) list.get(0); // Manual casting required
String s2 = (String) list.get(1); // Runtime error! Integer cannot be cast to String
```

### With Generics (Better Way):

```java
ArrayList<String> list = new ArrayList<String>();
list.add("Hello");
list.add(10); // Compile-time error! Type safety
String s = list.get(0); // No casting needed
```

---

## Why Use Generics?

### Benefits:

1. **Type Safety**: Errors detected at compile time, not runtime
2. **Code Reusability**: Write once, use with any type
3. **Elimination of Casts**: No need for manual type casting
4. **Stronger Type Checks**: Catch bugs earlier
5. **Generic Algorithms**: Implement algorithms that work on different types

### Real-World Examples:

- Collections (ArrayList, HashMap, LinkedList)
- Data structures (Stack, Queue, Tree)
- Algorithms (sorting, searching)
- Utility methods (swap, print, find min/max)

---

## Generic Methods

### What is a Generic Method?

A method that can accept parameters of different types and provides type safety.

### Syntax:

```java
access_modifier <TypeParameter> ReturnType methodName(parameters) {
    // method body
}
```

### Components:

- `<TypeParameter>`: Type parameter declaration (e.g., `<T>`, `<E>`, `<K, V>`)
- Must come **before** the return type
- Can have multiple type parameters: `<T, U, V>`

### Example 1: Simple Generic Method

```java
public class GenericMethodExample {
    // Generic method to print any type
    public static <T> void printValue(T value) {
        System.out.println(value);
    }

    public static void main(String[] args) {
        printValue(10);           // Integer
        printValue("Hello");      // String
        printValue(3.14);         // Double
        printValue(true);         // Boolean
    }
}
```

**Output:**

```
10
Hello
3.14
true
```

---

### Example 2: Generic Method with Return Value

```java
public class GenericMethodExample {
    // Generic method to find maximum
    public static <T extends Comparable<T>> T findMax(T a, T b) {
        return (a.compareTo(b) > 0) ? a : b;
    }

    public static void main(String[] args) {
        System.out.println(findMax(10, 20));        // 20
        System.out.println(findMax("Apple", "Banana")); // Banana
        System.out.println(findMax(3.14, 2.71));    // 3.14
    }
}
```

---

### Example 3: Generic Method with Arrays

```java
public class GenericArrayExample {
    // Generic method to print array
    public static <T> void printArray(T[] array) {
        for (T element : array) {
            System.out.print(element + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Integer[] intArray = {1, 2, 3, 4, 5};
        String[] strArray = {"A", "B", "C"};
        Double[] doubleArray = {1.1, 2.2, 3.3};

        printArray(intArray);    // 1 2 3 4 5
        printArray(strArray);    // A B C
        printArray(doubleArray); // 1.1 2.2 3.3
    }
}
```

---

### Example 4: Display Type and Value

```java
public class TypeDisplayer {
    // Generic method to display type and value
    public static <T> void genericDisplay(T element) {
        System.out.println(element.getClass().getName() + " = " + element);
    }

    public static void main(String[] args) {
        genericDisplay(1);      // java.lang.Integer = 1
        genericDisplay(20.25);  // java.lang.Double = 20.25
        genericDisplay("Hello"); // java.lang.String = Hello
    }
}
```

---

## Generic Classes

### What is a Generic Class?

A class that can work with any data type. The type is specified when the object is created.

### Syntax:

```java
class ClassName<TypeParameter> {
    private TypeParameter variable;

    public ClassName(TypeParameter variable) {
        this.variable = variable;
    }

    public TypeParameter getValue() {
        return variable;
    }
}

// Usage
ClassName<String> obj1 = new ClassName<>("Hello");
ClassName<Integer> obj2 = new ClassName<>(100);
```

---

### Example 1: Simple Generic Class

```java
public class Box<T> {
    private T content;

    public Box(T content) {
        this.content = content;
    }

    public T getContent() {
        return content;
    }

    public void setContent(T content) {
        this.content = content;
    }
}

// Usage
Box<Integer> intBox = new Box<>(123);
Box<String> strBox = new Box<>("Hello");
System.out.println(intBox.getContent());  // 123
System.out.println(strBox.getContent());  // Hello
```

---

### Example 2: Generic Class for Pair

```java
public class Pair<K, V> {
    private K key;
    private V value;

    public Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    public K getKey() { return key; }
    public V getValue() { return value; }
}

// Usage
Pair<String, Integer> p1 = new Pair<>("Age", 25);
Pair<Integer, String> p2 = new Pair<>(101, "John");
```

---

### Example 3: Generic Array Wrapper

```java
public class ArrayWrapper<T> {
    private T[] array;

    public ArrayWrapper(T[] array) {
        this.array = array;
    }

    // Reverse array
    public void reverse() {
        int left = 0;
        int right = array.length - 1;
        while (left < right) {
            T temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            left++;
            right--;
        }
    }

    // Print array
    public void printArray() {
        System.out.print("[");
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i]);
            if (i < array.length - 1) System.out.print(", ");
        }
        System.out.println("]");
    }

    // Swap elements
    public void swap(int index1, int index2) {
        if (index1 >= 0 && index1 < array.length &&
            index2 >= 0 && index2 < array.length) {
            T temp = array[index1];
            array[index1] = array[index2];
            array[index2] = temp;
        } else {
            System.out.println("Invalid indices. Swap operation aborted.");
        }
    }

    public T[] getArray() {
        return array;
    }
}
```

---

### Example 4: Generic Sorting Class

```java
import java.util.Arrays;

public class Sorter<T extends Comparable<T>> {
    private T[] array;

    public Sorter(T[] array) {
        this.array = array;
    }

    public void sort() {
        Arrays.sort(array);
    }

    public T[] getSortedArray() {
        return array;
    }

    public String toString() {
        return Arrays.toString(array);
    }
}

// Usage
Double[] doubles = {3.5, 1.2, 4.8, 2.1};
Sorter<Double> sorter = new Sorter<>(doubles);
sorter.sort();
System.out.println(sorter); // [1.2, 2.1, 3.5, 4.8]
```

---

## Generic Interfaces

### What is a Generic Interface?

An interface that can work with any data type.

### Syntax:

```java
interface InterfaceName<TypeParameter> {
    ReturnType methodName(TypeParameter param);
}

// Implementation
class ClassName<TypeParameter> implements InterfaceName<TypeParameter> {
    @Override
    public ReturnType methodName(TypeParameter param) {
        // implementation
    }
}
```

---

### Example 1: Simple Generic Interface

```java
interface NumberProvider<T extends Number> {
    T getValue();
}

class IntegerProvider implements NumberProvider<Integer> {
    private Integer value;

    public IntegerProvider(Integer value) {
        this.value = value;
    }

    @Override
    public Integer getValue() {
        return value;
    }
}

class DoubleProvider implements NumberProvider<Double> {
    private Double value;

    public DoubleProvider(Double value) {
        this.value = value;
    }

    @Override
    public Double getValue() {
        return value;
    }
}
```

---

### Example 2: Generic Interface for Minimum Finder

```java
import java.util.Arrays;

interface Min<T extends Comparable<T>> {
    T findMin(T[] array);
}

class MinFinder<T extends Comparable<T>> implements Min<T> {
    @Override
    public T findMin(T[] array) {
        if (array == null || array.length == 0) {
            return null;
        }
        Arrays.sort(array);
        return array[0];
    }
}

// Usage
Integer[] numbers = {5, 2, 8, 1, 9};
MinFinder<Integer> finder = new MinFinder<>();
System.out.println(finder.findMin(numbers)); // 1
```

---

### Example 3: Generic Interface for Calculator

```java
interface Calculator<T extends Number> {
    T add(T a, T b);
    T subtract(T a, T b);
}

class IntegerCalculator implements Calculator<Integer> {
    @Override
    public Integer add(Integer a, Integer b) {
        return a + b;
    }

    @Override
    public Integer subtract(Integer a, Integer b) {
        return a - b;
    }
}

class DoubleCalculator implements Calculator<Double> {
    @Override
    public Double add(Double a, Double b) {
        return a + b;
    }

    @Override
    public Double subtract(Double a, Double b) {
        return a - b;
    }
}
```

---

## Bounded Type Parameters

### What are Bounded Type Parameters?

Restrict the types that can be used as type arguments.

### Types of Bounds:

#### 1. Upper Bounded (extends)

Restricts to a specific type and its subtypes.

```java
// T must be Number or its subclass
public static <T extends Number> double sum(T a, T b) {
    return a.doubleValue() + b.doubleValue();
}

// Usage
sum(10, 20);        // Works (Integer extends Number)
sum(3.14, 2.71);    // Works (Double extends Number)
sum("10", "20");    // Error! String doesn't extend Number
```

#### 2. Multiple Bounds

Can extend one class and multiple interfaces.

```java
// T must extend Number AND implement Comparable
public static <T extends Number & Comparable<T>> T max(T a, T b) {
    return (a.compareTo(b) > 0) ? a : b;
}
```

#### 3. Wildcard Bounds

Use `?` for unknown type.

```java
// Accept any list
public void printList(List<?> list) {
    for (Object obj : list) {
        System.out.println(obj);
    }
}

// Accept list of Number or its subclasses
public void printNumbers(List<? extends Number> list) {
    for (Number num : list) {
        System.out.println(num);
    }
}
```

---

### Example: Bounded Type with Number

```java
class Area<T extends Number> {
    private T length;
    private T width;

    public Area(T length, T width) {
        this.length = length;
        this.width = width;
    }

    public int sum() {
        return length.intValue() + width.intValue();
    }

    public double area() {
        return length.doubleValue() * width.doubleValue();
    }
}

// Usage
Area<Integer> rect1 = new Area<>(5, 3);
System.out.println(rect1.sum());    // 8
System.out.println(rect1.area());   // 15.0

Area<Double> rect2 = new Area<>(5.5, 3.2);
System.out.println(rect2.sum());    // 8
System.out.println(rect2.area());   // 17.6
```

---

## Complete Syntax Guide

### Type Parameter Naming Conventions

| Convention | Meaning             | Example                 |
| ---------- | ------------------- | ----------------------- |
| `T`        | Type                | `class Box<T>`          |
| `E`        | Element             | `class List<E>`         |
| `K`        | Key                 | `class Map<K, V>`       |
| `V`        | Value               | `class Map<K, V>`       |
| `N`        | Number              | `class Calculator<N>`   |
| `S, U, V`  | 2nd, 3rd, 4th types | `class Triple<S, U, V>` |

---

### Generic Method Syntax Summary

```java
// Basic generic method
public <T> void method(T param) { }

// Generic method with return type
public <T> T method(T param) { return param; }

// Generic method with bounded type
public <T extends Number> void method(T param) { }

// Generic method with multiple type parameters
public <T, U> void method(T param1, U param2) { }

// Generic method with array
public <T> void method(T[] array) { }

// Static generic method
public static <T> T method(T param) { return param; }
```

---

### Generic Class Syntax Summary

```java
// Basic generic class
class ClassName<T> { }

// Generic class with bounded type
class ClassName<T extends SuperClass> { }

// Generic class with multiple type parameters
class ClassName<T, U, V> { }

// Generic class implementing interface
class ClassName<T> implements Interface<T> { }

// Generic class extending class
class ClassName<T> extends SuperClass<T> { }
```

---

### Generic Interface Syntax Summary

```java
// Basic generic interface
interface InterfaceName<T> { }

// Generic interface with bounded type
interface InterfaceName<T extends Number> { }

// Generic interface with multiple type parameters
interface InterfaceName<K, V> { }

// Implementing generic interface
class ClassName<T> implements InterfaceName<T> { }

// Implementing with specific type
class ClassName implements InterfaceName<String> { }
```

---

## Common Patterns & Examples

### Pattern 1: Binary Search with Generics

**Use Case**: Searching in sorted array (Bookshelf Organizer)

```java
import java.util.Scanner;

public class BinarySearchGeneric {
    // Generic binary search method
    public static <T extends Comparable<T>> int binarySearch(T[] array, T key) {
        int left = 0;
        int right = array.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int comparison = array[mid].compareTo(key);

            if (comparison == 0) {
                return mid; // Found
            } else if (comparison < 0) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1; // Not found
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Integer[] books = new Integer[n];

        for (int i = 0; i < n; i++) {
            books[i] = sc.nextInt();
        }

        int searchId = sc.nextInt();

        int index = binarySearch(books, searchId);

        if (index != -1) {
            System.out.println("Element found at index: " + index);
        } else {
            System.out.println("Element not found in the array.");
        }

        sc.close();
    }
}
```

---

### Pattern 2: Sum Calculation with Generic Interface

**Use Case**: Calculating totals (Daily Workout Tracker)

```java
import java.util.Scanner;

interface NumberProvider<T extends Number> {
    T getValue();
}

class IntegerProvider implements NumberProvider<Integer> {
    private Integer value;

    public IntegerProvider(Integer value) {
        this.value = value;
    }

    @Override
    public Integer getValue() {
        return value;
    }
}

public class WorkoutTracker {
    public static <T extends Number> int calculateSum(NumberProvider<T>[] providers) {
        int sum = 0;
        for (NumberProvider<T> provider : providers) {
            sum += provider.getValue().intValue();
        }
        return sum;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        NumberProvider<Integer>[] providers = new NumberProvider[n];
        for (int i = 0; i < n; i++) {
            providers[i] = new IntegerProvider(sc.nextInt());
        }

        System.out.println(calculateSum(providers));
        sc.close();
    }
}
```

---

### Pattern 3: Type Display

**Use Case**: Showing type and value (Generic Display)

```java
import java.util.Scanner;

public class TypeDisplay {
    public static <T> void genericDisplay(T element) {
        System.out.println(element.getClass().getName() + " = " + element);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int intValue = sc.nextInt();
        double doubleValue = sc.nextDouble();

        genericDisplay(intValue);
        genericDisplay(doubleValue);

        sc.close();
    }
}
```

---

### Pattern 4: Array Sorting

**Use Case**: Sorting different types (Generic Sorter)

```java
import java.util.Arrays;
import java.util.Scanner;

class Sorter<T extends Comparable<T>> {
    private T[] array;

    public Sorter(T[] array) {
        this.array = array;
    }

    public void sort() {
        Arrays.sort(array);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder("[");
        for (int i = 0; i < array.length; i++) {
            sb.append(array[i]);
            if (i < array.length - 1) {
                sb.append(", ");
            }
        }
        sb.append("]");
        return sb.toString();
    }
}

public class SorterMain {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Double[] doubles = new Double[n];

        for (int i = 0; i < n; i++) {
            doubles[i] = sc.nextDouble();
        }

        Sorter<Double> sorter = new Sorter<>(doubles);
        sorter.sort();
        System.out.println(sorter);

        sc.close();
    }
}
```

---

### Pattern 5: Array Swapping

**Use Case**: Swapping elements (Gift Rearrangement)

```java
import java.util.Arrays;
import java.util.Scanner;

class ArraySwapper<T> {
    private T[] array;

    public ArraySwapper(T[] array) {
        this.array = array;
    }

    public void swap(int index1, int index2) {
        if (index1 >= 0 && index1 < array.length &&
            index2 >= 0 && index2 < array.length) {
            T temp = array[index1];
            array[index1] = array[index2];
            array[index2] = temp;
        } else {
            throw new IllegalArgumentException("Invalid indices");
        }
    }

    public String arrayToString() {
        StringBuilder sb = new StringBuilder("[");
        for (int i = 0; i < array.length; i++) {
            sb.append(array[i]);
            if (i < array.length - 1) {
                sb.append(", ");
            }
        }
        sb.append("]");
        return sb.toString();
    }
}

public class GiftSwapper {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Integer[] array = new Integer[n];

        for (int i = 0; i < n; i++) {
            array[i] = sc.nextInt();
        }

        int a = sc.nextInt();
        int b = sc.nextInt();

        ArraySwapper<Integer> swapper = new ArraySwapper<>(array);
        System.out.println("Original Array: " + swapper.arrayToString());

        try {
            swapper.swap(a, b);
            System.out.println("Array after swapping elements at indices " +
                             a + " and " + b + ": " + swapper.arrayToString());
        } catch (IllegalArgumentException e) {
            System.out.println("Invalid indices. Swap operation aborted.");
        }

        sc.close();
    }
}
```

---

### Pattern 6: Array Reversal

**Use Case**: Reversing array elements

```java
import java.util.Scanner;

class ArrayReverser<T> {
    private T[] array;

    public ArrayReverser(T[] array) {
        this.array = array;
    }

    public void reverse() {
        int left = 0;
        int right = array.length - 1;

        while (left < right) {
            T temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            left++;
            right--;
        }
    }

    public String arrayToString() {
        StringBuilder sb = new StringBuilder("[");
        for (int i = 0; i < array.length; i++) {
            sb.append(array[i]);
            if (i < array.length - 1) {
                sb.append(", ");
            }
        }
        sb.append("]");
        return sb.toString();
    }
}

public class ReverseArray {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Integer[] array = new Integer[n];

        for (int i = 0; i < n; i++) {
            array[i] = sc.nextInt();
        }

        ArrayReverser<Integer> reverser = new ArrayReverser<>(array);
        System.out.println(reverser.arrayToString());

        reverser.reverse();
        System.out.println(reverser.arrayToString());

        sc.close();
    }
}
```

---

### Pattern 7: FizzBuzz with Generics

**Use Case**: Conditional replacement

```java
import java.util.Scanner;

class FizzBuzz<T extends Number> {
    private T limit;

    public FizzBuzz(T limit) {
        this.limit = limit;
    }

    public void printFizzBuzz() {
        int n = limit.intValue();

        for (int i = 1; i <= n; i++) {
            if (i % 15 == 0) {
                System.out.println("FizzBuzz");
            } else if (i % 3 == 0) {
                System.out.println("Fizz");
            } else if (i % 5 == 0) {
                System.out.println("Buzz");
            } else {
                System.out.println(i);
            }
        }
    }
}

public class FizzBuzzMain {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        FizzBuzz<Integer> fb = new FizzBuzz<>(n);
        fb.printFizzBuzz();

        sc.close();
    }
}
```

---

### Pattern 8: Rectangle Dimensions

**Use Case**: Bounded type with Number

```java
import java.util.Scanner;

class Area<T extends Number> {
    private T length;
    private T width;

    public Area(T length, T width) {
        this.length = length;
        this.width = width;
    }

    public int sum() {
        return length.intValue() + width.intValue();
    }
}

public class RectangleSum {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int length = sc.nextInt();
        int width = sc.nextInt();

        Area<Integer> rect = new Area<>(length, width);
        System.out.println(rect.sum());

        sc.close();
    }
}
```

---

### Pattern 9: Finding Minimum Element

**Use Case**: Generic interface implementation

```java
import java.util.Arrays;
import java.util.Scanner;

interface Min<T extends Comparable<T>> {
    T findMin(T[] array);
}

class MinFinder<T extends Comparable<T>> implements Min<T> {
    @Override
    public T findMin(T[] array) {
        if (array == null || array.length == 0) {
            return null;
        }
        Arrays.sort(array);
        return array[0];
    }
}

public class MinimumFinder {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Integer[] array = new Integer[n];

        for (int i = 0; i < n; i++) {
            array[i] = sc.nextInt();
        }

        MinFinder<Integer> finder = new MinFinder<>();
        System.out.println(finder.findMin(array));

        sc.close();
    }
}
```

---

## Comparable & Comparator

### Comparable Interface

Used to define natural ordering of objects.

#### Syntax:

```java
class ClassName implements Comparable<ClassName> {
    @Override
    public int compareTo(ClassName other) {
        // Return negative if this < other
        // Return 0 if this == other
        // Return positive if this > other
    }
}
```

#### Example: Hall Booking System

```java
import java.util.*;

class Hall implements Comparable<Hall> {
    private String name;
    private String contactNumber;
    private double costPerDay;
    private String ownerName;

    public Hall(String name, String contactNumber,
                double costPerDay, String ownerName) {
        this.name = name;
        this.contactNumber = contactNumber;
        this.costPerDay = costPerDay;
        this.ownerName = ownerName;
    }

    // Getters
    public String getName() { return name; }
    public String getContactNumber() { return contactNumber; }
    public double getCostPerDay() { return costPerDay; }
    public String getOwnerName() { return ownerName; }

    // Setters
    public void setName(String name) { this.name = name; }
    public void setContactNumber(String contactNumber) {
        this.contactNumber = contactNumber;
    }
    public void setCostPerDay(double costPerDay) {
        this.costPerDay = costPerDay;
    }
    public void setOwnerName(String ownerName) {
        this.ownerName = ownerName;
    }

    @Override
    public int compareTo(Hall other) {
        return Double.compare(this.costPerDay, other.costPerDay);
    }

    @Override
    public String toString() {
        return name + " " + contactNumber + " " + costPerDay + " " + ownerName;
    }
}

public class HallBooking {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine(); // Consume newline

        List<Hall> halls = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            String name = sc.nextLine();
            String contact = sc.nextLine();
            double cost = Double.parseDouble(sc.nextLine());
            String owner = sc.nextLine();

            halls.add(new Hall(name, contact, cost, owner));
        }

        Collections.sort(halls);

        for (Hall hall : halls) {
            System.out.println(hall);
        }

        sc.close();
    }
}
```

---

### Comparator Interface

Used to define custom ordering separate from the class.

#### Syntax:

```java
class CustomComparator implements Comparator<ClassName> {
    @Override
    public int compare(ClassName obj1, ClassName obj2) {
        // Comparison logic
    }
}
```

#### Example:

```java
import java.util.*;

class Student {
    String name;
    int age;

    public Student(String name, int age) {
        this.name = name;
        this.age = age;
    }
}

// Sort by name
class NameComparator implements Comparator<Student> {
    @Override
    public int compare(Student s1, Student s2) {
        return s1.name.compareTo(s2.name);
    }
}

// Sort by age
class AgeComparator implements Comparator<Student> {
    @Override
    public int compare(Student s1, Student s2) {
        return Integer.compare(s1.age, s2.age);
    }
}

// Usage
List<Student> students = new ArrayList<>();
Collections.sort(students, new NameComparator());
Collections.sort(students, new AgeComparator());
```

---

## Best Practices

### 1. Use Descriptive Type Parameter Names

```java
// Good ✓
class Box<T> { }
class Map<K, V> { }
class NumberList<N extends Number> { }

// Avoid ✗
class Box<X> { }
class Map<A, B> { }
```

---

### 2. Use Bounded Types When Necessary

```java
// Good ✓ - Restricts to numbers only
public <T extends Number> double sum(T a, T b) {
    return a.doubleValue() + b.doubleValue();
}

// Too Generic ✗
public <T> double sum(T a, T b) {
    // Can't call doubleValue() on any type T
}
```

---

### 3. Avoid Raw Types

```java
// Good ✓
List<String> list = new ArrayList<String>();
List<String> list = new ArrayList<>(); // Diamond operator (Java 7+)

// Bad ✗
List list = new ArrayList(); // Raw type, no type safety
```

---

### 4. Use Wildcards for Flexibility

```java
// Accept any list
public void printList(List<?> list) {
    for (Object obj : list) {
        System.out.println(obj);
    }
}

// Accept only Number subtypes
public double sumList(List<? extends Number> list) {
    double sum = 0;
    for (Number num : list) {
        sum += num.doubleValue();
    }
    return sum;
}
```

---

### 5. Don't Use Generics with Primitives

```java
// Good ✓
List<Integer> list = new ArrayList<>();
Box<Double> box = new Box<>();

// Error ✗
List<int> list = new ArrayList<>(); // Primitives not allowed
Box<double> box = new Box<>();
```

---

## Common Errors & Solutions

### Error 1: Raw Type Usage

**Problem:**

```java
ArrayList list = new ArrayList(); // Warning: Raw type
```

**Solution:**

```java
ArrayList<String> list = new ArrayList<>(); // Type-safe
```

---

### Error 2: Type Mismatch

**Problem:**

```java
Box<Integer> box = new Box<String>(); // Error!
```

**Solution:**

```java
Box<Integer> box = new Box<Integer>(); // Correct
Box<Integer> box = new Box<>(); // Also correct (diamond operator)
```

---

### Error 3: Cannot Create Generic Array

**Problem:**

```java
T[] array = new T[10]; // Error! Cannot create generic array
```

**Solution:**

```java
// Use array of Object and cast
T[] array = (T[]) new Object[10];

// Or accept array in constructor
public GenericClass(T[] array) {
    this.array = array;
}
```

---

### Error 4: Static Context Cannot Use Type Parameters

**Problem:**

```java
class Box<T> {
    private static T value; // Error! Static field cannot use T
}
```

**Solution:**

```java
class Box<T> {
    private T value; // Instance field is fine

    // Static method needs its own type parameter
    public static <U> void staticMethod(U param) {
        // ...
    }
}
```

---

### Error 5: Cannot Use instanceof with Parameterized Type

**Problem:**

```java
if (obj instanceof Box<Integer>) { } // Error!
```

**Solution:**

```java
if (obj instanceof Box<?>) { } // Use wildcard
if (obj instanceof Box) { } // Or raw type
```

---

## Practice Problems Summary

### 1. **Bookshelf Organizer**

- **Topic**: Generic binary search
- **Key Concepts**: Generic method, Comparable, searching
- **Pattern**: Binary search implementation with generics

### 2. **Daily Workout Tracker**

- **Topic**: Generic interface and sum calculation
- **Key Concepts**: Generic interface, NumberProvider, bounded types
- **Pattern**: Interface implementation with calculation

### 3. **Generic Display**

- **Topic**: Type parameter display
- **Key Concepts**: getClass().getName(), generic method
- **Pattern**: Display type and value dynamically

### 4. **Generic Sorter**

- **Topic**: Array sorting with generics
- **Key Concepts**: Generic class, Arrays.sort(), Comparable
- **Pattern**: Generic sorting implementation

### 5. **Gift Rearrangement**

- **Topic**: Array element swapping
- **Key Concepts**: Generic class, array manipulation, validation
- **Pattern**: Swap with index validation

### 6. **FizzBuzz**

- **Topic**: Conditional logic with generics
- **Key Concepts**: Generic class, bounded type (Number), logic
- **Pattern**: Generic class with conditional output

### 7. **Array Reversal**

- **Topic**: Generic array reversal
- **Key Concepts**: Generic class, array manipulation
- **Pattern**: Two-pointer reversal technique

### 8. **Rectangle Dimensions**

- **Topic**: Bounded type with Number
- **Key Concepts**: Generic class, bounded type, Number methods
- **Pattern**: Arithmetic with bounded types

### 9. **Event Hall Booking**

- **Topic**: Comparable interface
- **Key Concepts**: Comparable, Collections.sort(), compareTo()
- **Pattern**: Natural ordering implementation

### 10. **Minimum Element Finder**

- **Topic**: Generic interface implementation
- **Key Concepts**: Generic interface, Arrays.sort(), finding minimum
- **Pattern**: Interface-based algorithm implementation

---

## Quick Reference Cheat Sheet

### Essential Syntax

#### Generic Method:

```java
public static <T> void method(T param) { }
public static <T extends Comparable<T>> T max(T a, T b) { }
```

#### Generic Class:

```java
class ClassName<T> {
    private T field;
    public T getField() { return field; }
}
```

#### Generic Interface:

```java
interface InterfaceName<T> {
    T method();
}
```

#### Bounded Type:

```java
<T extends Number>           // Upper bound
<T extends Class & Interface> // Multiple bounds
```

#### Wildcard:

```java
List<?>                      // Unknown type
List<? extends Number>       // Upper bounded wildcard
List<? super Integer>        // Lower bounded wildcard
```

---

### Common Methods

#### Arrays:

```java
Arrays.sort(array)           // Sort array
Arrays.toString(array)       // Convert to string
Arrays.asList(array)         // Convert to list
```

#### Collections:

```java
Collections.sort(list)       // Sort list
Collections.reverse(list)    // Reverse list
Collections.min(list)        // Find minimum
Collections.max(list)        // Find maximum
```

#### Number Class Methods:

```java
num.intValue()               // Convert to int
num.doubleValue()            // Convert to double
num.longValue()              // Convert to long
num.floatValue()             // Convert to float
```

---

## Study Strategy

### Day 1: Basics

- Understand generic concept and benefits
- Practice generic methods (display, print)
- Master type parameter syntax

### Day 2: Generic Classes

- Practice creating generic classes
- Learn array manipulation (reverse, swap, sort)
- Understand bounded types

### Day 3: Generic Interfaces

- Practice interface implementation
- Learn Comparable interface
- Master sorting and comparison

### Day 4: Advanced

- Practice binary search with generics
- Solve complex problems (Hall booking, MinFinder)
- Review all patterns

### Day 5: Review

- Solve all 10 exercises from scratch
- Debug common errors
- Time yourself on each problem

---

## Final Tips for Assessment

1. ✅ **Remember `<T>` before return type** in generic methods
2. ✅ **Use bounded types** when you need specific methods (Number, Comparable)
3. ✅ **Implement Comparable** for natural ordering
4. ✅ **Use Arrays.toString()** for array to string conversion with `[a, b, c]` format
5. ✅ **Validate indices** before array operations
6. ✅ **Use diamond operator** `<>` for cleaner code (Java 7+)
7. ✅ **Don't forget type casting** when reading from Object arrays
8. ✅ **Test with different types** (Integer, Double, String)
9. ✅ **Handle edge cases** (empty arrays, invalid indices)
10. ✅ **Practice all patterns** - Each exercise has specific structure

---

## Common Templates

### Generic Method Template:

```java
public static <T> void methodName(T param) {
    // Implementation
}
```

### Generic Class Template:

```java
class ClassName<T> {
    private T field;

    public ClassName(T field) {
        this.field = field;
    }

    public T getField() {
        return field;
    }
}
```

### Generic Interface Template:

```java
interface InterfaceName<T> {
    T methodName();
}

class Implementation<T> implements InterfaceName<T> {
    @Override
    public T methodName() {
        // Implementation
    }
}
```

### Comparable Template:

```java
class ClassName implements Comparable<ClassName> {
    private int value;

    @Override
    public int compareTo(ClassName other) {
        return Integer.compare(this.value, other.value);
    }
}
```

---

## Good Luck! 🚀

**Remember:**

- **Generics = Type Safety + Reusability**
- **`<T>` before return type in methods**
- **Bounded types for specific operations**
- **Comparable for natural ordering**
- **Test with multiple types**

You've got this! 💪
