# Lab 16: Complete Guide to Java Serialization & Deserialization

## Table of Contents

1. [Introduction to Serialization](#introduction-to-serialization)
2. [Why Serialization?](#why-serialization)
3. [Serializable Interface](#serializable-interface)
4. [ObjectOutputStream & ObjectInputStream](#objectoutputstream--objectinputstream)
5. [Complete Syntax Guide](#complete-syntax-guide)
6. [Step-by-Step Implementation](#step-by-step-implementation)
7. [Common Patterns & Examples](#common-patterns--examples)
8. [Best Practices](#best-practices)
9. [Common Errors & Solutions](#common-errors--solutions)
10. [Practice Problems Summary](#practice-problems-summary)

---

## Introduction to Serialization

**Serialization** is the process of converting an object's state into a byte stream so it can be:

- Saved to a file
- Sent over a network
- Stored in a database

**Deserialization** is the reverse process: converting the byte stream back into an object.

```
Object → Byte Stream → File/Network
File/Network → Byte Stream → Object
```

---

## Why Serialization?

### Use Cases:

1. **Persistence**: Save object state to disk and reload later
2. **Deep Copying**: Create exact copies of objects
3. **Communication**: Send objects between JVMs over network
4. **Caching**: Store objects in memory/disk cache
5. **Session Management**: Store user session data

### Real-World Examples:

- Bank account data storage
- Game save files
- Shopping cart persistence
- Employee records management
- Configuration settings

---

## Serializable Interface

### What is it?

`Serializable` is a **marker interface** (no methods to implement) that tells Java "this class can be serialized".

### Syntax:

```java
import java.io.Serializable;

public class ClassName implements Serializable {
    // Class members
}
```

### Important Points:

1. **No methods to implement** - just add `implements Serializable`
2. **All fields must be serializable** or marked as `transient`
3. **Static fields are NOT serialized** (they belong to class, not object)
4. **Transient fields are NOT serialized** (marked with `transient` keyword)

### Example:

```java
import java.io.Serializable;

public class Student implements Serializable {
    private int id;              // Will be serialized
    private String name;         // Will be serialized
    private transient String password;  // NOT serialized
    private static int count;    // NOT serialized (static)

    // Constructor, getters, setters...
}
```

---

## ObjectOutputStream & ObjectInputStream

### ObjectOutputStream (For Serialization)

#### Purpose:

Writes objects to an output stream (file).

#### Syntax:

```java
import java.io.FileOutputStream;
import java.io.ObjectOutputStream;
import java.io.IOException;

// Create output stream
FileOutputStream fos = new FileOutputStream("filename.ser");
ObjectOutputStream oos = new ObjectOutputStream(fos);

// Write object
oos.writeObject(objectToSerialize);

// Close streams
oos.close();
fos.close();
```

#### Key Methods:

| Method                    | Description                       |
| ------------------------- | --------------------------------- |
| `writeObject(Object obj)` | Writes specified object to stream |
| `writeInt(int val)`       | Writes an integer                 |
| `writeDouble(double val)` | Writes a double                   |
| `flush()`                 | Flushes the stream                |
| `close()`                 | Closes the stream                 |

---

### ObjectInputStream (For Deserialization)

#### Purpose:

Reads objects from an input stream (file).

#### Syntax:

```java
import java.io.FileInputStream;
import java.io.ObjectInputStream;
import java.io.IOException;

// Create input stream
FileInputStream fis = new FileInputStream("filename.ser");
ObjectInputStream ois = new ObjectInputStream(fis);

// Read object
ClassName obj = (ClassName) ois.readObject();

// Close streams
ois.close();
fis.close();
```

#### Key Methods:

| Method         | Description                                                 |
| -------------- | ----------------------------------------------------------- |
| `readObject()` | Reads an object from stream (returns Object, needs casting) |
| `readInt()`    | Reads an integer                                            |
| `readDouble()` | Reads a double                                              |
| `close()`      | Closes the stream                                           |

---

## Complete Syntax Guide

### 1. Basic Class with Serializable

```java
import java.io.Serializable;

public class Book implements Serializable {
    private int id;
    private String title;
    private String author;

    // Constructor
    public Book(int id, String title, String author) {
        this.id = id;
        this.title = title;
        this.author = author;
    }

    // Getters
    public int getId() { return id; }
    public String getTitle() { return title; }
    public String getAuthor() { return author; }

    // Setters
    public void setId(int id) { this.id = id; }
    public void setTitle(String title) { this.title = title; }
    public void setAuthor(String author) { this.author = author; }

    @Override
    public String toString() {
        return "Book[id=" + id + ", title=" + title + ", author=" + author + "]";
    }
}
```

---

### 2. Serialization (Write to File)

```java
import java.io.*;

public class SerializeExample {
    public static void main(String[] args) {
        // Create object
        Book book = new Book(1, "Harry Potter", "J.K. Rowling");

        try {
            // Create output streams
            FileOutputStream fos = new FileOutputStream("book.ser");
            ObjectOutputStream oos = new ObjectOutputStream(fos);

            // Serialize object
            oos.writeObject(book);

            // Close streams
            oos.close();
            fos.close();

            System.out.println("Object serialized successfully!");

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
```

---

### 3. Deserialization (Read from File)

```java
import java.io.*;

public class DeserializeExample {
    public static void main(String[] args) {
        try {
            // Create input streams
            FileInputStream fis = new FileInputStream("book.ser");
            ObjectInputStream ois = new ObjectInputStream(fis);

            // Deserialize object
            Book book = (Book) ois.readObject();

            // Close streams
            ois.close();
            fis.close();

            // Use the object
            System.out.println("Object deserialized: " + book);

        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}
```

---

### 4. Serializing Multiple Objects (Array)

```java
import java.io.*;

public class SerializeArray {
    public static void main(String[] args) {
        Book[] books = new Book[3];
        books[0] = new Book(1, "Book1", "Author1");
        books[1] = new Book(2, "Book2", "Author2");
        books[2] = new Book(3, "Book3", "Author3");

        try {
            FileOutputStream fos = new FileOutputStream("books.dat");
            ObjectOutputStream oos = new ObjectOutputStream(fos);

            // Write the entire array
            oos.writeObject(books);

            oos.close();
            fos.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
```

---

### 5. Deserializing Multiple Objects (Array)

```java
import java.io.*;

public class DeserializeArray {
    public static void main(String[] args) {
        try {
            FileInputStream fis = new FileInputStream("books.dat");
            ObjectInputStream ois = new ObjectInputStream(fis);

            // Read the entire array
            Book[] books = (Book[]) ois.readObject();

            ois.close();
            fis.close();

            // Display all books
            for (int i = 0; i < books.length; i++) {
                System.out.println((i + 1) + ". " + books[i]);
            }

        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}
```

---

### 6. Using ArrayList (Dynamic Collection)

```java
import java.io.*;
import java.util.ArrayList;

// Serialization
ArrayList<Book> bookList = new ArrayList<>();
bookList.add(new Book(1, "Title1", "Author1"));
bookList.add(new Book(2, "Title2", "Author2"));

FileOutputStream fos = new FileOutputStream("books.dat");
ObjectOutputStream oos = new ObjectOutputStream(fos);
oos.writeObject(bookList);
oos.close();
fos.close();

// Deserialization
FileInputStream fis = new FileInputStream("books.dat");
ObjectInputStream ois = new ObjectInputStream(fis);
ArrayList<Book> retrievedList = (ArrayList<Book>) ois.readObject();
ois.close();
fis.close();
```

---

## Step-by-Step Implementation

### Complete Example: Bank Account System

```java
import java.io.*;

// Step 1: Create Serializable Class
class BankAccount implements Serializable {
    private double balance;

    public BankAccount(double balance) {
        this.balance = balance;
    }

    public void deposit(double amount) {
        balance += amount;
    }

    public void withdraw(double amount) {
        balance -= amount;
    }

    public double getBalance() {
        return balance;
    }
}

// Step 2: Main Program
public class BankSystem {
    public static void main(String[] args) {
        // Read input
        Scanner sc = new Scanner(System.in);
        double initialBalance = sc.nextDouble();
        double depositAmount = sc.nextDouble();
        double withdrawAmount = sc.nextDouble();

        // Create object
        BankAccount account = new BankAccount(initialBalance);
        account.deposit(depositAmount);
        account.withdraw(withdrawAmount);

        // Serialize
        try {
            FileOutputStream fos = new FileOutputStream("bankAccount.ser");
            ObjectOutputStream oos = new ObjectOutputStream(fos);
            oos.writeObject(account);
            oos.close();
            fos.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Deserialize
        try {
            FileInputStream fis = new FileInputStream("bankAccount.ser");
            ObjectInputStream ois = new ObjectInputStream(fis);
            BankAccount retrievedAccount = (BankAccount) ois.readObject();
            ois.close();
            fis.close();

            // Display result
            System.out.printf("%.2f%n", retrievedAccount.getBalance());

        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }

        sc.close();
    }
}
```

---

## Common Patterns & Examples

### Pattern 1: Simple Object Serialization

**Use Case**: Storing single object (Grade, Movie, Pet Activity)

```java
// 1. Create class implementing Serializable
class Grade implements Serializable {
    private String subject;
    private int score;

    public Grade(String subject, int score) {
        this.subject = subject;
        this.score = score;
    }

    public String getPerformance() {
        if (score >= 90) return "Excellent";
        else if (score > 70) return "Good";
        else return "Needs Improvement";
    }
}

// 2. Main program
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] input = sc.nextLine().split(" ");
        String subject = input[0];
        int score = Integer.parseInt(input[1]);

        Grade grade = new Grade(subject, score);

        // Serialize
        try (ObjectOutputStream oos = new ObjectOutputStream(
                new FileOutputStream("grades.ser"))) {
            oos.writeObject(grade);
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Deserialize
        try (ObjectInputStream ois = new ObjectInputStream(
                new FileInputStream("grades.ser"))) {
            Grade retrievedGrade = (Grade) ois.readObject();
            System.out.println(retrievedGrade.getPerformance());
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }

        sc.close();
    }
}
```

---

### Pattern 2: Array Serialization with Filtering

**Use Case**: Storing multiple objects and filtering (Employee, Book, Ticket)

```java
import java.io.*;
import java.util.*;

class Employee implements Serializable {
    private int id;
    private String name;
    private String department;
    private double salary;

    public Employee(int id, String name, String dept, double salary) {
        this.id = id;
        this.name = name;
        this.department = dept;
        this.salary = salary;
    }

    public double getSalary() { return salary; }

    @Override
    public String toString() {
        return id + " " + name + " " + department + " " + salary;
    }
}

public class HRSystem {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        Employee[] employees = new Employee[n];
        for (int i = 0; i < n; i++) {
            int id = sc.nextInt();
            String name = sc.next();
            String dept = sc.next();
            double salary = sc.nextDouble();
            employees[i] = new Employee(id, name, dept, salary);
        }

        double threshold = sc.nextDouble();

        // Serialize
        try (ObjectOutputStream oos = new ObjectOutputStream(
                new FileOutputStream("employees.ser"))) {
            oos.writeObject(employees);
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Deserialize and filter
        try (ObjectInputStream ois = new ObjectInputStream(
                new FileInputStream("employees.ser"))) {
            Employee[] retrieved = (Employee[]) ois.readObject();

            boolean found = false;
            for (Employee emp : retrieved) {
                if (emp.getSalary() > threshold) {
                    System.out.println(emp);
                    found = true;
                }
            }

            if (!found) {
                System.out.println("No employees found above threshold");
            }

        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }

        sc.close();
    }
}
```

---

### Pattern 3: ArrayList Serialization with Calculation

**Use Case**: Dynamic collection with aggregation (Product cost, Ticket count)

```java
import java.io.*;
import java.util.*;

class Product implements Serializable {
    private int id;
    private String name;
    private double cost;

    public Product(int id, String name, double cost) {
        this.id = id;
        this.name = name;
        this.cost = cost;
    }

    public double getCost() { return cost; }
}

public class StoreSystem {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        ArrayList<Product> products = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int id = sc.nextInt();
            sc.nextLine(); // consume newline
            String name = sc.nextLine();
            double cost = sc.nextDouble();
            products.add(new Product(id, name, cost));
        }

        // Serialize
        try (ObjectOutputStream oos = new ObjectOutputStream(
                new FileOutputStream("products.dat"))) {
            oos.writeObject(products);
            System.out.println("Successfully serialized " + n +
                             " products to products.dat");
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Deserialize and calculate
        try (ObjectInputStream ois = new ObjectInputStream(
                new FileInputStream("products.dat"))) {
            ArrayList<Product> retrieved =
                (ArrayList<Product>) ois.readObject();

            double total = 0;
            for (Product p : retrieved) {
                total += p.getCost();
            }

            System.out.println("Total cost of all products: " + total);

        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }

        sc.close();
    }
}
```

---

### Pattern 4: Modifying Before Serialization

**Use Case**: Transform data before saving (Movie year, Pet activity duration)

```java
import java.io.*;
import java.util.*;

class Movie implements Serializable {
    private String title;
    private int year;

    public Movie(String title, int year) {
        this.title = title;
        this.year = year - 3; // Modify: 3 years earlier
    }

    public int getYear() { return year; }
}

public class MovieSystem {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] input = sc.nextLine().split(" ");
        String title = input[0];
        int year = Integer.parseInt(input[1]);

        Movie movie = new Movie(title, year);

        // Serialize
        try (ObjectOutputStream oos = new ObjectOutputStream(
                new FileOutputStream("movie_info.ser"))) {
            oos.writeObject(movie);
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Deserialize
        try (ObjectInputStream ois = new ObjectInputStream(
                new FileInputStream("movie_info.ser"))) {
            Movie retrieved = (Movie) ois.readObject();
            System.out.println(retrieved.getYear());
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }

        sc.close();
    }
}
```

---

### Pattern 5: Conditional Logic After Deserialization

**Use Case**: Categorization based on data (Season, Performance, Status)

```java
import java.io.*;
import java.util.*;

class Birthday implements Serializable {
    private int month;
    private int day;

    public Birthday(int month, int day) {
        this.month = month;
        this.day = day;
    }

    public String getSeason() {
        if (month < 1 || month > 12) {
            return "Invalid month";
        } else if (month == 12 || month == 1 || month == 2) {
            return "Winter";
        } else if (month >= 3 && month <= 5) {
            return "Spring";
        } else if (month >= 6 && month <= 8) {
            return "Summer";
        } else {
            return "Fall";
        }
    }
}

public class SeasonTracker {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int month = sc.nextInt();
        int day = sc.nextInt();

        Birthday birthday = new Birthday(month, day);

        // Serialize
        try (ObjectOutputStream oos = new ObjectOutputStream(
                new FileOutputStream("birthdays.ser"))) {
            oos.writeObject(birthday);
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Deserialize
        try (ObjectInputStream ois = new ObjectInputStream(
                new FileInputStream("birthdays.ser"))) {
            Birthday retrieved = (Birthday) ois.readObject();
            System.out.println(retrieved.getSeason());
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }

        sc.close();
    }
}
```

---

## Best Practices

### 1. **Use Try-With-Resources** (Automatic Resource Management)

```java
// Good Practice ✓
try (FileOutputStream fos = new FileOutputStream("file.ser");
     ObjectOutputStream oos = new ObjectOutputStream(fos)) {
    oos.writeObject(obj);
} catch (IOException e) {
    e.printStackTrace();
}

// Old Way (Manual Closing)
FileOutputStream fos = null;
ObjectOutputStream oos = null;
try {
    fos = new FileOutputStream("file.ser");
    oos = new ObjectOutputStream(fos);
    oos.writeObject(obj);
} catch (IOException e) {
    e.printStackTrace();
} finally {
    if (oos != null) oos.close();
    if (fos != null) fos.close();
}
```

---

### 2. **Add serialVersionUID**

```java
public class Student implements Serializable {
    private static final long serialVersionUID = 1L;
    // Rest of class...
}
```

**Why?** Ensures version compatibility when class definition changes.

---

### 3. **Handle Exceptions Properly**

```java
try {
    // Serialization code
} catch (IOException e) {
    System.err.println("Error during serialization: " + e.getMessage());
    e.printStackTrace();
}

try {
    // Deserialization code
} catch (IOException e) {
    System.err.println("Error reading file: " + e.getMessage());
} catch (ClassNotFoundException e) {
    System.err.println("Class not found: " + e.getMessage());
}
```

---

### 4. **Use Transient for Sensitive Data**

```java
public class User implements Serializable {
    private String username;
    private transient String password; // Won't be serialized
    private String email;
}
```

---

### 5. **Validate After Deserialization**

```java
try (ObjectInputStream ois = new ObjectInputStream(
        new FileInputStream("data.ser"))) {
    Object obj = ois.readObject();

    // Validate
    if (obj instanceof Student) {
        Student student = (Student) obj;
        // Use student object
    } else {
        System.err.println("Invalid object type!");
    }
}
```

---

## Common Errors & Solutions

### Error 1: NotSerializableException

**Cause**: Class doesn't implement `Serializable`

```java
// Problem
class Book {  // Missing Serializable
    private String title;
}

// Solution
class Book implements Serializable {
    private String title;
}
```

---

### Error 2: ClassNotFoundException

**Cause**: Class not found during deserialization

```java
// Solution: Ensure class is in classpath and properly imported
try {
    ObjectInputStream ois = new ObjectInputStream(
        new FileInputStream("file.ser"));
    MyClass obj = (MyClass) ois.readObject();
    ois.close();
} catch (ClassNotFoundException e) {
    System.err.println("Class not found: " + e.getMessage());
}
```

---

### Error 3: InvalidClassException

**Cause**: Class version mismatch

```java
// Solution: Add serialVersionUID
public class Student implements Serializable {
    private static final long serialVersionUID = 1L;
    // class members
}
```

---

### Error 4: FileNotFoundException

**Cause**: File doesn't exist when deserializing

```java
// Solution: Check file existence
File file = new File("data.ser");
if (!file.exists()) {
    System.err.println("File not found!");
    return;
}

try (ObjectInputStream ois = new ObjectInputStream(
        new FileInputStream(file))) {
    // Deserialization code
}
```

---

### Error 5: Null Pointer After Deserialization

**Cause**: Transient or static fields not restored

```java
public class Config implements Serializable {
    private String name;
    private transient String tempValue; // Will be null after deserialization

    // Use readObject method to restore transient fields
    private void readObject(ObjectInputStream ois)
            throws IOException, ClassNotFoundException {
        ois.defaultReadObject();
        tempValue = "default"; // Restore transient field
    }
}
```

---

## Practice Problems Summary

### 1. **Academic Performance Tracker**

- **Topic**: Simple serialization with conditional logic
- **Key Concepts**: Single object, performance categorization
- **Pattern**: Create → Serialize → Deserialize → Display category

### 2. **Bank Account**

- **Topic**: Object modification before serialization
- **Key Concepts**: Transaction processing, decimal formatting
- **Pattern**: Create → Modify → Serialize → Deserialize → Display

### 3. **Library Books**

- **Topic**: Array serialization with summary
- **Key Concepts**: Multiple objects, array handling, formatted output
- **Pattern**: Create array → Serialize → Deserialize → Display all

### 4. **Library System**

- **Topic**: Array serialization with filtering
- **Key Concepts**: Threshold filtering, conditional display
- **Pattern**: Create array → Serialize → Deserialize → Filter → Display

### 5. **Movie Year**

- **Topic**: Data transformation during serialization
- **Key Concepts**: Modifying values before storing
- **Pattern**: Create with modification → Serialize → Deserialize → Display

### 6. **Pet Activity Monitor**

- **Topic**: Duration calculation and modification
- **Key Concepts**: Adding values, unit conversion
- **Pattern**: Create → Add duration → Serialize → Deserialize → Display

### 7. **Small Online Store**

- **Topic**: ArrayList serialization with aggregation
- **Key Concepts**: Collection handling, sum calculation
- **Pattern**: Create list → Serialize → Deserialize → Calculate total

### 8. **Track Seasons**

- **Topic**: Conditional categorization
- **Key Concepts**: Month-based logic, validation
- **Pattern**: Create → Serialize → Deserialize → Determine season

### 9. **HR Management System**

- **Topic**: Multiple object filtering
- **Key Concepts**: Salary threshold, employee records
- **Pattern**: Create array → Serialize → Deserialize → Filter → Display

### 10. **Movie Ticket Booking**

- **Topic**: Collection search and count
- **Key Concepts**: Searching, counting matches
- **Pattern**: Create list → Serialize → Deserialize → Search → Count

---

## Quick Reference Cheat Sheet

### Essential Imports

```java
import java.io.Serializable;
import java.io.FileOutputStream;
import java.io.ObjectOutputStream;
import java.io.FileInputStream;
import java.io.ObjectInputStream;
import java.io.IOException;
```

### Serialization Template

```java
try (ObjectOutputStream oos = new ObjectOutputStream(
        new FileOutputStream("filename.ser"))) {
    oos.writeObject(object);
} catch (IOException e) {
    e.printStackTrace();
}
```

### Deserialization Template

```java
try (ObjectInputStream ois = new ObjectInputStream(
        new FileInputStream("filename.ser"))) {
    ClassName obj = (ClassName) ois.readObject();
    // Use obj
} catch (IOException | ClassNotFoundException e) {
    e.printStackTrace();
}
```

### Class Template

```java
import java.io.Serializable;

public class ClassName implements Serializable {
    private static final long serialVersionUID = 1L;

    // Fields
    private int field1;
    private String field2;

    // Constructor
    public ClassName(int field1, String field2) {
        this.field1 = field1;
        this.field2 = field2;
    }

    // Getters and Setters
    public int getField1() { return field1; }
    public void setField1(int field1) { this.field1 = field1; }

    // Other methods
}
```

---

## Final Tips for Assessment

1. ✅ **Always implement Serializable** - Don't forget this!
2. ✅ **Use try-with-resources** - Cleaner and safer code
3. ✅ **Cast properly during deserialization** - `(ClassName) ois.readObject()`
4. ✅ **Close streams** - Use try-with-resources or finally block
5. ✅ **Handle both IOException and ClassNotFoundException**
6. ✅ **Test your code** - Serialize and deserialize to verify
7. ✅ **Format output correctly** - Use `printf` for decimals: `%.2f`
8. ✅ **Read problem carefully** - Note file names (`.ser`, `.dat`)
9. ✅ **Understand the pattern** - Single object vs Array vs ArrayList
10. ✅ **Practice all patterns** - Each exercise type has specific structure

---

## Study Strategy

### Day 1: Basics

- Understand serialization concept
- Practice simple object serialization (Grade, Movie)
- Master try-with-resources syntax

### Day 2: Collections

- Practice array serialization (Books, Employees)
- Learn ArrayList serialization (Products, Tickets)
- Understand casting during deserialization

### Day 3: Advanced

- Practice filtering patterns (Library, HR)
- Master modification patterns (Pet Activity, Movie Year)
- Understand conditional logic (Seasons, Performance)

### Day 4: Review

- Solve all 10 exercises from scratch
- Debug common errors
- Time yourself on each problem

---

## Good Luck! 🚀

Remember:

- **Serialization = Object → File**
- **Deserialization = File → Object**
- **Always implement Serializable**
- **Always handle exceptions**
- **Always close streams**

You've got this! 💪
