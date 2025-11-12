# Assessment quick reference — Q1 & Q2

This file contains concise notes, examples and exam-style hints tailored to your assessment topics.

- Q1: Classes & Objects, Inheritance, Abstract Classes, Interfaces
- Q2: Exception Handling, File Handling, Collection Framework

Use these as quick revision notes when solving `main.java` files in this folder.

---

## Q1 — Classes & Objects, Inheritance, Abstract Classes, Interfaces

Purpose: implement data models, reuse code via inheritance, express contracts with interfaces and reuse base behavior with abstract classes.

Key concepts

- Class: blueprint with fields and methods.
- Object: an instance of a class (created with `new`).
- Constructor: initializes an instance. If none provided, a default no-arg constructor exists.
- `this`: refers to the current instance.
- `static`: member belongs to the class, not instance.

Minimal example — class and object:

```java
public class Book {
    private String title;
    private String author;

    public Book(String title, String author) {
        this.title = title;
        this.author = author;
    }

    public String toString() { return title + " by " + author; }
}

// usage
Book b = new Book("Java Basics", "A. Author");
System.out.println(b);
```

Inheritance

- `extends` adds a parent class.
- Use `super(...)` to call parent constructors and `super.method()` to call parent implementations.
- Prefer composition if "has-a" fits better than "is-a".

Example — inheritance and overriding:

```java
public class Animal { public void speak() { System.out.println("..."); } }
public class Cat extends Animal { @Override public void speak() { System.out.println("Meow"); } }

Animal a = new Cat();
a.speak(); // prints "Meow"
```

Abstract classes

- Use `abstract class` when you want partial implementation and common fields/methods.
- Can have abstract methods (no body) which subclasses must implement.

```java
public abstract class Shape {
    double x, y;
    public Shape(double x, double y) { this.x = x; this.y = y; }
    public abstract double area();
}
```

Interfaces

- Declare a contract: methods that implementing classes must provide.
- Since Java 8, interfaces can have `default` and `static` methods.
- A class can implement multiple interfaces.

```java
public interface Printable { void print(); }
public class Report implements Printable { public void print() { System.out.println("report"); } }
```

Common exam pitfalls (Q1)

- Forgetting to use `@Override` for overridden methods — `@Override` helps catch signature mistakes.
- Not providing `serialVersionUID` when serializing classes (if required by question context).
- Confusing `static` with instance members.
- Using package-private unintentionally when classes are in different packages (visibility errors).

Short checklist for Q1 problems

- Identify entities (classes) and their relationships (extends/implements).
- Decide which methods should be abstract or default.
- Implement constructors and `toString()` for easy printing in `main`.
- Keep methods small: single responsibility.

---

## Q2 — Exception handling, File handling, Collection Framework

Exception handling

- Checked exceptions (e.g., `IOException`) must be declared (`throws`) or handled (`try/catch`).
- Unchecked exceptions extend `RuntimeException` and are not required to be declared/handled.
- Use try-with-resources for AutoCloseable resources (streams, readers, writers).

Example — try-with-resources:

```java
try (BufferedReader br = new BufferedReader(new FileReader("in.txt"))) {
    String line;
    while ((line = br.readLine()) != null) {
        System.out.println(line);
    }
} catch (IOException e) {
    System.err.println("IO error: " + e.getMessage());
}
```

Best practices — exceptions

- Catch specific exceptions, not `Exception`, unless the problem needs a catch-all.
- Use `finally` only if needed (resources should be closed in try-with-resources).
- For library code, prefer throwing meaningful exceptions (wrap low-level exceptions with contextual messages).

File handling

- Text files: `BufferedReader` / `BufferedWriter` or `Files` (NIO) for small files.
- Binary files / object storage: `ObjectOutputStream` / `ObjectInputStream` and implement `Serializable`.
- Use `Paths` / `Files` for concise operations in modern code.

Examples

Read all lines (NIO):

```java
List<String> lines = Files.readAllLines(Paths.get("data.txt"));
```

Serialize objects:

```java
public class Item implements Serializable { private static final long serialVersionUID = 1L; String name; }

try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("items.ser"))) {
    oos.writeObject(itemsList);
}
```

Collection framework — quick cheats

- List (ordered, may contain duplicates): `ArrayList`, `LinkedList`.
- Set (unique elements): `HashSet`, `LinkedHashSet`, `TreeSet` (sorted).
- Map (key -> value): `HashMap`, `LinkedHashMap`, `TreeMap`.

Typical operations

```java
List<String> l = new ArrayList<>();
l.add("a");
Collections.sort(l); // sort

Map<String,Integer> freq = new HashMap<>();
freq.put(key, freq.getOrDefault(key, 0) + 1);

Set<Integer> s = new HashSet<>();
s.add(5);
```

Exam tips — collections

- Use `HashMap` for frequency counters.
- If ordering matters, choose `LinkedHashMap` or `TreeMap` accordingly.
- For deduplication while preserving order: use `LinkedHashSet` or stream operations.
- Remember `List.get(index)` is O(1) for `ArrayList`, but O(n) for `LinkedList`.

Common Q2 pitfalls

- Not closing streams (use try-with-resources).
- Confusing `IOException` and `FileNotFoundException` handling — `FileNotFoundException` is a subclass of `IOException`.
- Using equality `==` for strings — use `equals()` or `equalsIgnoreCase()`.
- When deserializing, class definition changes can cause `InvalidClassException` (serialVersionUID mismatch).

---

## Quick exam practice problems & approach

1. Q1-style: "Design a `Vehicle` hierarchy with `Car` and `Bike`; make `Vehicle` abstract with an abstract `fuelEfficiency()` method. Provide constructors and `toString()` methods."

Approach:

- Create `abstract class Vehicle` with fields common to all.
- Implement `Car` and `Bike` with overrides for `fuelEfficiency()`.
- Instantiate in `main` and print.

2. Q2-style: "Read names from `students.txt` and print counts per letter using a Map; handle missing file gracefully."

Approach:

- Use `Files.readAllLines` or `BufferedReader` inside try-with-resources.
- Use a `Map<Character,Integer>` frequency map.
- Catch `IOException` and print a user-friendly message.

---

## Compile & run reminders (PowerShell)

```powershell
javac path\to\Main.java
java -cp path\to Main
```

When packages are used, run with the fully-qualified class name from project root.

---

If you want, I can:

- generate skeleton `.java` files for the two sample problems above (complete and ready-to-run), or
- annotate a specific `main.java` in your `Assessments` folder for feedback.

File created: `ASSESSMENT_Q1_Q2.md` — next step: tell me if you want skeleton code or annotated files for particular assignments.
