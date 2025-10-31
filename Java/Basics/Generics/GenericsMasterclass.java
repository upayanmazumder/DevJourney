import java.util.*;

// Generic Methods
class GenericMethods {
    public static <T> void printValue(T value) {
        System.out.println("Value: " + value);
    }

    public static <T extends Comparable<T>> T findMax(T a, T b) {
        return (a.compareTo(b) > 0) ? a : b;
    }

    public static <T> void printArray(T[] array) {
        for (T element : array)
            System.out.print(element + " ");
        System.out.println();
    }

    public static <T> void showType(T obj) {
        System.out.println(obj + " → " + obj.getClass().getName());
    }
}

// Generic Classes
class Box<T> {
    private T content;

    public Box(T content) {
        this.content = content;
    }

    public T get() {
        return content;
    }

    public void set(T content) {
        this.content = content;
    }

    @Override
    public String toString() {
        return "Box{" + content + "}";
    }
}

class Pair<K, V> {
    private K key;
    private V value;

    public Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    public K getKey() {
        return key;
    }

    public V getValue() {
        return value;
    }

    @Override
    public String toString() {
        return "(" + key + ", " + value + ")";
    }
}

// Generic Interface
interface Calculator<T extends Number> {
    T add(T a, T b);
    T subtract(T a, T b);
}

class IntegerCalculator implements Calculator<Integer> {
    public Integer add(Integer a, Integer b) {
        return a + b;
    }

    public Integer subtract(Integer a, Integer b) {
        return a - b;
    }
}

class DoubleCalculator implements Calculator<Double> {
    public Double add(Double a, Double b) {
        return a + b;
    }

    public Double subtract(Double a, Double b) {
        return a - b;
    }
}

// Bounded Types
class Area<T extends Number> {
    private T length, width;

    public Area(T length, T width) {
        this.length = length;
        this.width = width;
    }

    public double area() {
        return length.doubleValue() * width.doubleValue();
    }

    public double sum() {
        return length.doubleValue() + width.doubleValue();
    }
}

// Generic Class Using Comparable
class Sorter<T extends Comparable<T>> {
    private T[] array;

    public Sorter(T[] array) {
        this.array = array;
    }

    public void sort() {
        Arrays.sort(array);
    }

    public void print() {
        System.out.println(Arrays.toString(array));
    }
}

// Generic Interface Implementation
interface MinFinder<T extends Comparable<T>> {
    T findMin(T[] arr);
}

class GenericMinFinder<T extends Comparable<T>> implements MinFinder<T> {
    public T findMin(T[] arr) {
        return Arrays.stream(arr).min(Comparator.naturalOrder()).orElse(null);
    }
}

// Wildcards
class WildcardDemo {
    public static void printList(List<?> list) {
        for (Object o : list)
            System.out.print(o + " ");
        System.out.println();
    }

    public static void printNumbers(List<? extends Number> list) {
        double sum = 0;
        for (Number num : list)
            sum += num.doubleValue();
        System.out.println("Sum = " + sum);
    }
}

// Comparable & Comparator
class Student implements Comparable<Student> {
    String name;
    int age;

    public Student(String name, int age) {
        this.name = name;
        this.age = age;
    }

    @Override
    public int compareTo(Student other) {
        return this.name.compareTo(other.name);
    }

    @Override
    public String toString() {
        return name + "(" + age + ")";
    }
}

class AgeComparator implements Comparator<Student> {
    public int compare(Student s1, Student s2) {
        return Integer.compare(s1.age, s2.age);
    }
}

// Main Class
public class GenericsMasterclass {
    public static void main(String[] args) {
        System.out.println("===== GENERIC METHODS =====");
        GenericMethods.printValue("Hello Generics");
        GenericMethods.showType(42);
        System.out.println("Max: " + GenericMethods.findMax(42, 27));

        String[] names = {"Zoe", "Alex", "Mia"};
        GenericMethods.printArray(names);

        System.out.println("\n===== GENERIC CLASSES =====");
        Box<Integer> intBox = new Box<>(123);
        Box<String> strBox = new Box<>("Test");
        System.out.println(intBox + " | " + strBox);

        Pair<String, Double> pair = new Pair<>("Pi", 3.14);
        System.out.println("Pair: " + pair);

        System.out.println("\n===== GENERIC INTERFACES =====");
        Calculator<Integer> ic = new IntegerCalculator();
        Calculator<Double> dc = new DoubleCalculator();
        System.out.println("Int Add: " + ic.add(10, 5));
        System.out.println("Double Sub: " + dc.subtract(9.5, 4.2));

        System.out.println("\n===== BOUNDED TYPES =====");
        Area<Integer> rect1 = new Area<>(5, 3);
        Area<Double> rect2 = new Area<>(5.5, 3.2);
        System.out.println("Area1 = " + rect1.area() + ", Sum = " + rect1.sum());
        System.out.println("Area2 = " + rect2.area() + ", Sum = " + rect2.sum());

        System.out.println("\n===== GENERIC SORTER =====");
        Integer[] nums = {5, 1, 9, 3, 7};
        Sorter<Integer> sorter = new Sorter<>(nums);
        sorter.sort();
        sorter.print();

        System.out.println("\n===== GENERIC MIN FINDER =====");
        GenericMinFinder<Integer> minFinder = new GenericMinFinder<>();
        System.out.println("Min: " + minFinder.findMin(nums));

        System.out.println("\n===== WILDCARD DEMO =====");
        List<String> strings = Arrays.asList("A", "B", "C");
        List<Integer> integers = Arrays.asList(10, 20, 30);
        WildcardDemo.printList(strings);
        WildcardDemo.printNumbers(integers);

        System.out.println("\n===== COMPARABLE & COMPARATOR =====");
        List<Student> students = new ArrayList<>();
        students.add(new Student("Chitrita", 21));
        students.add(new Student("Upayan", 20));
        students.add(new Student("Anish", 22));

        System.out.println("Before Sort: " + students);
        Collections.sort(students);
        System.out.println("Sorted by Name: " + students);
        students.sort(new AgeComparator());
        System.out.println("Sorted by Age: " + students);
    }
}
