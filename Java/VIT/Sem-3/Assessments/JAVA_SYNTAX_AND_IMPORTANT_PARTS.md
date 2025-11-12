# Java — Important Parts & Syntax (quick reference)

This file highlights important Java constructs, idioms and quick examples relevant to the `Assessments` assignments in this folder (basic algorithms, file I/O & serialization, collections, OOP, etc.). Use it as a quick cheat sheet while exploring the exercise `main.java` files.

---

## Table of contents

- Basic project structure and compile/run
- `main` method and entry point
- Primitive types & variables
- Control flow (if/switch/loops)
- Methods (definition, overloading, recursion)
- Classes, constructors and `this`
- Access modifiers & encapsulation
- Inheritance, polymorphism, `super`
- Interfaces & abstract classes
- Common Java Collections (List, Map, Set)
- Arrays vs ArrayList
- File I/O (text & binary)
- Serialization (`Serializable`, `ObjectOutputStream`)
- Exception handling (checked vs unchecked)
- Common algorithms & patterns (sorting, searching)
- Helpful tips & compilation examples

---

## Basic project structure and compile/run

Typical file layout:

- `src/` or root with `main.java` files
- `README.md` per assignment

Compile & run (Windows PowerShell):

```powershell
# compile
javac path\to\Main.java
# run
java -cp path\to Main
```

Notes:

- If classes are in packages, compile from the project root and run with the fully-qualified class name.
- For multiple files: `javac *.java` or `javac -d bin src/**/*.java`.

---

## Entry point — main method

Signature:

```java
public static void main(String[] args) {
    // program starts here
}
```

`args` contains command-line arguments. Typical usage to parse input or flags.

---

## Primitive types & variables

Examples:

```java
int n = 10;
long big = 1_000_000L;
double x = 3.14;
boolean ok = true;
char ch = 'A';
String s = "hello"; // reference type
```

Use wrapper classes when you need nullability or use collections that require objects (e.g., `Integer`).

---

## Control flow

If / else:

```java
if (x > 0) {
    // ...
} else if (x == 0) {
    // ...
} else {
    // ...
}
```

Switch (modern Java with arrow labels):

```java
switch (value) {
    case 1 -> System.out.println("one");
    case 2 -> System.out.println("two");
    default -> System.out.println("other");
}
```

Loops:

```java
for (int i = 0; i < n; i++) { }
for (String item : list) { }
while (condition) { }
do { } while (condition);
```

---

## Methods

Declaration:

```java
public static int sum(int a, int b) {
    return a + b;
}
```

Overloading:

```java
public int area(int r) { return 3 * r * r; }
public double area(double r) { return Math.PI * r * r; }
```

Recursion example (factorial):

```java
public static long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
```

---

## Classes, constructors, `this`

```java
public class Person {
    private String name;
    private int age;

    public Person(String name, int age) {
        this.name = name; // `this` refers to instance field
        this.age = age;
    }

    public String toString() {
        return name + " (" + age + ")";
    }
}
```

Default constructor exists if you don't declare any constructor. If you declare a constructor, provide a no-arg constructor when frameworks or code expect it.

---

## Access modifiers & encapsulation

- `public` — accessible everywhere
- `protected` — accessible in same package and subclasses
- (default) package-private — accessible in same package
- `private` — accessible only within the class

Use getters/setters to expose fields safely.

```java
public class Student {
    private int id;
    public int getId() { return id; }
    public void setId(int id) { this.id = id; }
}
```

---

## Inheritance & polymorphism

```java
public class Animal { public void speak() { System.out.println("..."); } }
public class Dog extends Animal { @Override public void speak() { System.out.println("Woof"); } }

Animal a = new Dog();
a.speak(); // calls Dog.speak() -> polymorphism
```

Use `@Override` to catch mistakes.

Call parent constructor or methods with `super()` / `super.method()`.

---

## Interfaces & abstract classes

Interface (multiple inheritance of type):

```java
public interface Shape {
    double area();
}

public class Circle implements Shape {
    private double r;
    public Circle(double r) { this.r = r; }
    public double area() { return Math.PI * r * r; }
}
```

Abstract class when you provide base functionality:

```java
public abstract class Vehicle {
    abstract void drive();
    public void start() { System.out.println("Starting"); }
}
```

---

## Collections — common usage

List (dynamic array):

```java
List<String> list = new ArrayList<>();
list.add("one");
String first = list.get(0);
```

Map (key-value):

```java
Map<String,Integer> map = new HashMap<>();
map.put("a", 1);
int v = map.getOrDefault("b", 0);
```

Set (unique elements):

```java
Set<Integer> set = new HashSet<>();
```

Prefer the `List`/`Map` interfaces in variable types for flexibility.

---

## Arrays vs ArrayList

Fixed-size array:

```java
int[] arr = new int[10];
arr[0] = 5;
```

ArrayList — resizable, convenient methods:

```java
ArrayList<Integer> a = new ArrayList<>();
a.add(1); a.remove(Integer.valueOf(1));
```

When performance critical, primitive arrays avoid boxing/unboxing.

---

## File I/O — text files

Read with `BufferedReader` and `FileReader` or `Files` (since Java 7+):

```java
// try-with-resources ensures close()
try (BufferedReader br = new BufferedReader(new FileReader("input.txt"))) {
    String line;
    while ((line = br.readLine()) != null) {
        System.out.println(line);
    }
}
```

Write with `PrintWriter` or `BufferedWriter`:

```java
try (PrintWriter out = new PrintWriter(new FileWriter("output.txt"))) {
    out.println("Hello");
}
```

Using `java.nio.file.Files` for small files:

```java
List<String> lines = Files.readAllLines(Paths.get("input.txt"));
Files.write(Paths.get("out.txt"), List.of("line1"), StandardOpenOption.CREATE);
```

---

## File I/O — binary & serialization

Make a class serializable:

```java
public class Student implements Serializable {
    private static final long serialVersionUID = 1L;
    private String name;
    private int id;
}
```

Write object to file:

```java
try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("data.ser"))) {
    oos.writeObject(student);
}

try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream("data.ser"))) {
    Student s = (Student) ois.readObject();
}
```

Use `transient` to skip fields during serialization (e.g., passwords).

---

## Exception handling

Checked vs unchecked:

- Checked exceptions (e.g., `IOException`) must be declared or handled.
- Unchecked exceptions (e.g., `NullPointerException`, `IllegalArgumentException`) are runtime exceptions.

Example:

```java
try {
    // risky code
} catch (IOException e) {
    e.printStackTrace();
} finally {
    // always runs (unless JVM exits)
}
```

Prefer specific catches over a broad `catch (Exception e)` where possible.

---

## Common algorithms & patterns in assessments

- Prime number check: trial division up to sqrt(n).
- Fibonacci: iterative or recursive with memoization.
- Factorial: iterative or recursive (watch for overflow).
- Sorting: use `Arrays.sort()` or `Collections.sort()`; implement algorithms for learning.
- Searching: linear search for unsorted, binary search for sorted arrays.

Edge cases to consider:

- Empty inputs, null references
- Off-by-one in loops & array indices
- Large inputs (overflow, long vs int)
- File not found & permission errors

---

## Useful snippets & idioms

Scanner for console input:

```java
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
String line = sc.nextLine();
```

String utilities:

```java
String s = "hello";
int len = s.length();
String upper = s.toUpperCase();
String[] parts = s.split("\\s+");
```

StringBuilder for efficient concatenation:

```java
StringBuilder sb = new StringBuilder();
sb.append("a");
String result = sb.toString();
```

Use `Collections.reverse(list)` and `Collections.sort(list)` for convenience.

---

## Testing, debugging & style tips

- Add small test `main` runs to verify each assignment quickly.
- Print intermediate values when debugging.
- Keep methods short and single-responsibility.
- Use meaningful variable names.
- Close streams with try-with-resources.

---

## Quick sample: Student records (file IO + serialization sketch)

```java
// Student.java
public class Student implements Serializable {
    private static final long serialVersionUID = 1L;
    private String name;
    private int id;
    // constructors, getters, setters
}

// SaveStudents.java
public class SaveStudents {
    public static void save(List<Student> list, String path) throws IOException {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(path))) {
            oos.writeObject(list);
        }
    }

    public static List<Student> load(String path) throws IOException, ClassNotFoundException {
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(path))) {
            return (List<Student>) ois.readObject();
        }
    }
}
```

This pattern is used by many assignments in the `File IO, Serialization/` subfolder.

---

## Where this cheat-sheet helps in `Assessments`

- `File IO, Serialization/` — follow file read/write and serializable examples.
- Algorithm assignments (primes, perfect squares, number analyzers) — use the algorithm patterns and edge-case list.
- `Library Management`, `Inventory Manager`, `Student Records Storage` — model entities as classes, persist via serialization or text files, and use collections for in-memory storage.

---
