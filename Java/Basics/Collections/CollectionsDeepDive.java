package Java.Basics.Collections;
import java.util.*;

public class CollectionsDeepDive {

    public static void main(String[] args) {
        // -------------------- 1️⃣ ARRAYLIST --------------------
        System.out.println("=== ArrayList Demo ===");

        // Declaration and Initialization
        ArrayList<String> fruits = new ArrayList<>(Arrays.asList("Apple", "Banana", "Cherry", "Apple"));

        // Basic Operations
        fruits.add("Mango");                      // Add element
        fruits.add(1, "Guava");                   // Insert at index
        fruits.remove("Apple");                   // Remove first occurrence
        fruits.set(2, "Kiwi");                    // Replace element
        System.out.println("List: " + fruits);    // Display list
        System.out.println("Element at 1: " + fruits.get(1));
        System.out.println("Contains Banana? " + fruits.contains("Banana"));
        System.out.println("Index of Kiwi: " + fruits.indexOf("Kiwi"));
        System.out.println("Size: " + fruits.size());

        // Iteration
        System.out.println("Iterating using forEach:");
        fruits.forEach(System.out::println);

        // Sorting
        Collections.sort(fruits);
        System.out.println("Sorted: " + fruits);
        Collections.sort(fruits, Collections.reverseOrder());
        System.out.println("Reverse Sorted: " + fruits);

        // Clear
        fruits.clear();
        System.out.println("After clear: " + fruits + "\n");

        // -------------------- 2️⃣ HASHMAP --------------------
        System.out.println("=== HashMap Demo ===");

        // Declaration
        HashMap<String, Integer> scores = new HashMap<>();

        // Add & Update
        scores.put("Alice", 85);
        scores.put("Bob", 92);
        scores.put("Charlie", 78);
        scores.put("Alice", 90); // Update existing key
        System.out.println("Scores: " + scores);

        // Access
        System.out.println("Bob's score: " + scores.get("Bob"));
        System.out.println("Eve’s score (default): " + scores.getOrDefault("Eve", -1));

        // Existence
        System.out.println("Has key 'Charlie'? " + scores.containsKey("Charlie"));
        System.out.println("Has value 90? " + scores.containsValue(90));

        // Iteration
        System.out.println("\nIterating over keys:");
        for (String key : scores.keySet())
            System.out.println(key + " -> " + scores.get(key));

        System.out.println("\nIterating using entrySet:");
        for (Map.Entry<String, Integer> e : scores.entrySet())
            System.out.println(e.getKey() + " = " + e.getValue());

        // Removal
        scores.remove("Charlie");
        System.out.println("After removing Charlie: " + scores);

        // Map Functions (Java 8+)
        scores.forEach((k, v) -> System.out.println(k + " scored " + v));

        // Summation Example
        int total = 0;
        for (int val : scores.values()) total += val;
        System.out.println("Total Score: " + total);

        // Min/Max by value
        String topStudent = Collections.max(scores.entrySet(), Map.Entry.comparingByValue()).getKey();
        String lowStudent = Collections.min(scores.entrySet(), Map.Entry.comparingByValue()).getKey();
        System.out.println("Topper: " + topStudent);
        System.out.println("Lowest Scorer: " + lowStudent + "\n");

        // -------------------- 3️⃣ TREEMAP --------------------
        System.out.println("=== TreeMap Demo ===");

        TreeMap<String, Double> prices = new TreeMap<>();
        prices.put("Banana", 25.0);
        prices.put("Apple", 30.0);
        prices.put("Mango", 50.0);
        prices.put("Guava", 35.0);

        // Sorted automatically
        System.out.println("Prices (sorted by key): " + prices);

        // Accessing entries
        System.out.println("First key: " + prices.firstKey());
        System.out.println("Last key: " + prices.lastKey());
        System.out.println("HeadMap(< Mango): " + prices.headMap("Mango"));
        System.out.println("TailMap(>= Mango): " + prices.tailMap("Mango"));

        // Iteration
        System.out.println("\nIterating through TreeMap:");
        prices.forEach((k, v) -> System.out.println(k + " => " + v));

        // Character frequency example (TreeMap keeps it sorted)
        System.out.println("\nCharacter Frequency Example:");
        String word = "banana";
        TreeMap<Character, Integer> freq = new TreeMap<>();
        for (char c : word.toCharArray()) {
            freq.put(c, freq.getOrDefault(c, 0) + 1);
        }
        freq.forEach((ch, count) -> System.out.println(ch + ": " + count));

        // -------------------- 4️⃣ COMMON OPERATIONS --------------------
        System.out.println("\n=== Common Operations Summary ===");
        ArrayList<Integer> nums = new ArrayList<>(Arrays.asList(10, 20, 30, 40, 50));

        // Searching
        System.out.println("Contains 30? " + nums.contains(30));
        System.out.println("Index of 20: " + nums.indexOf(20));

        // Iterating
        nums.forEach(n -> System.out.print(n + " "));
        System.out.println();

        // Sorting
        Collections.sort(nums, Collections.reverseOrder());
        System.out.println("Reverse Sorted: " + nums);

        // Conversion
        Object[] arr = nums.toArray();
        System.out.println("Converted to Array: " + Arrays.toString(arr));

        // -------------------- 5️⃣ BEST PRACTICES --------------------
        System.out.println("\n=== Best Practices ===");
        ArrayList<String> names = new ArrayList<>(100); // Initial capacity
        HashMap<String, Integer> fastLookup = new HashMap<>(50);

        System.out.println("Use getOrDefault: " + fastLookup.getOrDefault("Unknown", -999));
        System.out.println("Validate before index access:");
        int idx = 2;
        if (idx < nums.size()) System.out.println("Element: " + nums.get(idx));
        else System.out.println("Invalid index");
    }
}
