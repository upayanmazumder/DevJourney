# Java File I/O - Complete Guide for Lab 15

## Table of Contents

1. [Introduction to File I/O](#introduction-to-file-io)
2. [File Handling Classes](#file-handling-classes)
3. [Reading from Files](#reading-from-files)
4. [Writing to Files](#writing-to-files)
5. [Exception Handling](#exception-handling)
6. [String Manipulation](#string-manipulation)
7. [Complete Examples](#complete-examples)
8. [Common Patterns & Best Practices](#common-patterns--best-practices)

---

## Introduction to File I/O

File I/O (Input/Output) allows Java programs to read from and write to files on the disk. All file operations in Java use classes from the `java.io` package.

### Why File I/O?

- **Persistence**: Store data permanently
- **Data Exchange**: Share data between programs
- **Logging**: Keep records of program execution
- **Configuration**: Store settings and preferences

---

## File Handling Classes

### 1. FileWriter

**Purpose**: Write character data to files

**Syntax**:

```java
FileWriter fw = new FileWriter("filename.txt");
```

**Key Methods**:

```java
write(String str)      // Write a string
write(int c)          // Write a single character
close()               // Close the stream
```

**Example**:

```java
FileWriter fw = new FileWriter("output.txt");
fw.write("Hello World");
fw.write('\n');
fw.close();
```

**Important Notes**:

- Creates a new file if it doesn't exist
- **Overwrites** existing content by default
- Must close the stream to ensure data is written
- Throws `IOException`

---

### 2. FileReader

**Purpose**: Read character data from files

**Syntax**:

```java
FileReader fr = new FileReader("filename.txt");
```

**Key Methods**:

```java
read()                // Read a single character (returns int, -1 if end)
read(char[] cbuf)     // Read into character array
close()               // Close the stream
```

**Example**:

```java
FileReader fr = new FileReader("input.txt");
int ch;
while ((ch = fr.read()) != -1) {
    System.out.print((char) ch);
}
fr.close();
```

**Important Notes**:

- Reads one character at a time
- Returns -1 when end of file is reached
- Cast int to char for display
- Throws `IOException`

---

### 3. BufferedWriter

**Purpose**: Write text efficiently with buffering

**Syntax**:

```java
BufferedWriter bw = new BufferedWriter(new FileWriter("file.txt"));
```

**Key Methods**:

```java
write(String str)     // Write a string
newLine()            // Write platform-specific line separator
close()              // Close the stream
```

**Example**:

```java
BufferedWriter bw = new BufferedWriter(new FileWriter("data.txt"));
bw.write("First Line");
bw.newLine();
bw.write("Second Line");
bw.close();
```

**Advantages**:

- More efficient for large amounts of text
- Has `newLine()` method for platform-independent line breaks
- Buffers data to reduce disk I/O operations

---

### 4. BufferedReader

**Purpose**: Read text efficiently with buffering

**Syntax**:

```java
BufferedReader br = new BufferedReader(new FileReader("file.txt"));
```

**Key Methods**:

```java
readLine()           // Read a line of text (returns String, null if end)
read()              // Read a single character
close()             // Close the stream
```

**Example**:

```java
BufferedReader br = new BufferedReader(new FileReader("data.txt"));
String line;
while ((line = br.readLine()) != null) {
    System.out.println(line);
}
br.close();
```

**Advantages**:

- Read entire lines at once
- Much faster than FileReader for text files
- Returns null at end of file

---

### 5. FileOutputStream

**Purpose**: Write raw byte data to files

**Syntax**:

```java
FileOutputStream fos = new FileOutputStream("file.bin");
```

**Key Methods**:

```java
write(int b)          // Write a single byte
write(byte[] b)       // Write byte array
close()              // Close the stream
```

**Example**:

```java
FileOutputStream fos = new FileOutputStream("binary.dat");
fos.write(65);  // Writes 'A'
fos.close();
```

---

### 6. FileInputStream

**Purpose**: Read raw byte data from files

**Syntax**:

```java
FileInputStream fis = new FileInputStream("file.bin");
```

**Key Methods**:

```java
read()               // Read a single byte (returns int, -1 if end)
available()          // Returns bytes available to read
close()              // Close the stream
```

**Example**:

```java
FileInputStream fis = new FileInputStream("binary.dat");
int data;
while ((data = fis.read()) != -1) {
    System.out.print((char) data);
}
fis.close();
```

---

### 7. DataOutputStream

**Purpose**: Write primitive data types to files

**Syntax**:

```java
DataOutputStream dos = new DataOutputStream(new FileOutputStream("data.bin"));
```

**Key Methods**:

```java
writeInt(int v)      // Write an integer
writeDouble(double v) // Write a double
writeBytes(String s) // Write string as bytes
writeUTF(String s)   // Write string in UTF format
close()              // Close the stream
```

**Example**:

```java
DataOutputStream dos = new DataOutputStream(new FileOutputStream("data.bin"));
dos.writeInt(100);
dos.writeDouble(3.14);
dos.writeBytes("Hello");
dos.close();
```

---

### 8. DataInputStream

**Purpose**: Read primitive data types from files

**Syntax**:

```java
DataInputStream dis = new DataInputStream(new FileInputStream("data.bin"));
```

**Key Methods**:

```java
readInt()            // Read an integer
readDouble()         // Read a double
readUTF()            // Read a UTF string
available()          // Check available bytes
close()              // Close the stream
```

**Example**:

```java
DataInputStream dis = new DataInputStream(new FileInputStream("data.bin"));
int num = dis.readInt();
double value = dis.readDouble();
dis.close();
```

---

## Reading from Files

### Pattern 1: Reading Character by Character (FileReader)

```java
FileReader fr = new FileReader("input.txt");
int ch;
while ((ch = fr.read()) != -1) {
    System.out.print((char) ch);
}
fr.close();
```

**When to Use**: Small files, character-level processing

---

### Pattern 2: Reading Line by Line (BufferedReader)

```java
BufferedReader br = new BufferedReader(new FileReader("input.txt"));
String line;
while ((line = br.readLine()) != null) {
    System.out.println(line);
}
br.close();
```

**When to Use**: Text files, line-based processing (most common)

---

### Pattern 3: Reading Bytes (DataInputStream)

```java
DataInputStream dis = new DataInputStream(new FileInputStream("data.txt"));
StringBuilder sb = new StringBuilder();
while (dis.available() > 0) {
    sb.append((char) dis.read());
}
dis.close();
String content = sb.toString();
```

**When to Use**: Binary data, byte-level control

---

### Pattern 4: Reading with StringBuilder

```java
BufferedReader br = new BufferedReader(new FileReader("data.txt"));
StringBuilder content = new StringBuilder();
String line;
while ((line = br.readLine()) != null) {
    content.append(line).append("\n");
}
br.close();
String fullContent = content.toString();
```

**When to Use**: Need entire file content as a single string

---

## Writing to Files

### Pattern 1: Simple Text Writing (FileWriter)

```java
FileWriter fw = new FileWriter("output.txt");
fw.write("Line 1\n");
fw.write("Line 2\n");
fw.close();
```

**When to Use**: Simple, small text output

---

### Pattern 2: Efficient Text Writing (BufferedWriter)

```java
BufferedWriter bw = new BufferedWriter(new FileWriter("output.txt"));
bw.write("First Line");
bw.newLine();
bw.write("Second Line");
bw.close();
```

**When to Use**: Multiple writes, better performance

---

### Pattern 3: Formatted Output

```java
FileWriter fw = new FileWriter("prices.txt");
double price = 99.99;
fw.write(String.format("%.2f", price));  // Writes "99.99"
fw.close();
```

**When to Use**: Decimal formatting, precise output format

---

### Pattern 4: Binary Data Writing (DataOutputStream)

```java
DataOutputStream dos = new DataOutputStream(new FileOutputStream("data.bin"));
dos.writeBytes("Hello World");
dos.close();
```

**When to Use**: Binary files, primitive type storage

---

## Exception Handling

### Why Exception Handling?

File operations can fail for many reasons:

- File doesn't exist
- No permission to read/write
- Disk is full
- File is locked by another program

### Method 1: Throws Declaration

```java
public void readFile(String filename) throws IOException {
    BufferedReader br = new BufferedReader(new FileReader(filename));
    String line = br.readLine();
    br.close();
}
```

**When to Use**: When the calling method should handle the exception

---

### Method 2: Try-Catch Block

```java
public void readFile(String filename) {
    try {
        BufferedReader br = new BufferedReader(new FileReader(filename));
        String line = br.readLine();
        br.close();
    } catch (IOException e) {
        System.out.println("Error: " + e.getMessage());
        e.printStackTrace();
    }
}
```

**When to Use**: When you want to handle the error in this method

---

### Method 3: Try-with-Resources (Best Practice - Java 7+)

```java
public void readFile(String filename) {
    try (BufferedReader br = new BufferedReader(new FileReader(filename))) {
        String line = br.readLine();
        // No need to close - automatically closed
    } catch (IOException e) {
        System.out.println("Error: " + e.getMessage());
    }
}
```

**Advantages**:

- Automatically closes resources
- Cleaner code
- Prevents resource leaks

---

## String Manipulation

### 1. String Formatting

#### Format Decimals

```java
double value = 3.14159;
String formatted = String.format("%.2f", value);  // "3.14"
```

**Format Specifiers**:

- `%d` - Integer
- `%f` - Float/Double
- `%.2f` - Float with 2 decimal places
- `%s` - String
- `%c` - Character

---

### 2. String Splitting

```java
String text = "Hello World Java";
String[] words = text.split("\\s+");  // Split by whitespace
// Result: ["Hello", "World", "Java"]
```

**Common Delimiters**:

- `"\\s+"` - One or more whitespace characters
- `","` - Comma
- `"\\."` - Period (dot)
- `"\\|"` - Pipe

---

### 3. String Methods

```java
String str = "  Hello World  ";

// Case conversion
str.toLowerCase()        // "  hello world  "
str.toUpperCase()        // "  HELLO WORLD  "

// Trimming
str.trim()              // "Hello World"

// Checking content
str.contains("World")    // true
str.startsWith("Hello")  // false (has spaces)
str.endsWith("World")    // false (has spaces)

// Finding
str.indexOf("World")     // 8
str.indexOf("xyz")       // -1 (not found)

// Checking empty
str.isEmpty()           // false
str.trim().isEmpty()    // false
"".isEmpty()            // true
```

---

### 4. Character Array Conversion

```java
String text = "Hello";

// String to char array
char[] chars = text.toCharArray();

// Iterate through characters
for (char ch : chars) {
    System.out.println(ch);
}
```

---

### 5. StringBuilder

```java
StringBuilder sb = new StringBuilder();

sb.append("Hello");
sb.append(" ");
sb.append("World");
String result = sb.toString();  // "Hello World"
```

**When to Use**:

- Building strings in loops
- Concatenating many strings
- Better performance than string concatenation

---

### 6. Character Checking

```java
char ch = 'A';

// Check if vowel
if ("AEIOUaeiou".indexOf(ch) != -1) {
    System.out.println("Vowel");
}

// Check if digit
if (Character.isDigit(ch)) {
    System.out.println("Digit");
}

// Check if letter
if (Character.isLetter(ch)) {
    System.out.println("Letter");
}

// Check if uppercase
if (Character.isUpperCase(ch)) {
    System.out.println("Uppercase");
}
```

---

## Complete Examples

### Example 1: Copy File Content

```java
import java.io.*;

class FileCopy {
    public void copyFile(String source, String destination) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(source));
        BufferedWriter bw = new BufferedWriter(new FileWriter(destination));

        String line;
        while ((line = br.readLine()) != null) {
            bw.write(line + "\n");
        }

        br.close();
        bw.close();
    }

    public static void main(String[] args) {
        FileCopy fc = new FileCopy();
        try {
            fc.copyFile("input.txt", "output.txt");
            System.out.println("File copied successfully");
        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
```

---

### Example 2: Count Words in File

```java
import java.io.*;

class WordCounter {
    public int countWords(String filename) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(filename));
        int count = 0;
        String line;

        while ((line = br.readLine()) != null) {
            String[] words = line.trim().split("\\s+");
            for (String word : words) {
                if (!word.isEmpty()) {
                    count++;
                }
            }
        }

        br.close();
        return count;
    }

    public static void main(String[] args) {
        WordCounter wc = new WordCounter();
        try {
            int words = wc.countWords("text.txt");
            System.out.println("Total words: " + words);
        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
```

---

### Example 3: Write and Read Formatted Data

```java
import java.io.*;

class StudentRecord {
    private String name;
    private int marks;

    public void writeRecord(String filename, String name, int marks) throws IOException {
        BufferedWriter bw = new BufferedWriter(new FileWriter(filename));
        bw.write("Name: " + name + "\n");
        bw.write("Marks: " + marks + "\n");
        bw.close();
    }

    public void readRecord(String filename) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(filename));
        String line;

        while ((line = br.readLine()) != null) {
            System.out.println(line);
        }

        br.close();
    }

    public static void main(String[] args) {
        StudentRecord sr = new StudentRecord();
        try {
            sr.writeRecord("student.txt", "John Doe", 95);
            sr.readRecord("student.txt");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
```

---

### Example 4: Sentiment Analysis

```java
import java.io.*;

class SentimentAnalyzer {
    public void writeText(String text, String filename) throws IOException {
        DataOutputStream dos = new DataOutputStream(new FileOutputStream(filename));
        dos.writeBytes(text);
        dos.close();
    }

    public String analyzeSentiment(String filename) throws IOException {
        DataInputStream dis = new DataInputStream(new FileInputStream(filename));
        StringBuilder content = new StringBuilder();

        while (dis.available() > 0) {
            content.append((char) dis.read());
        }
        dis.close();

        String text = content.toString().toLowerCase();

        if (text.contains("happy") || text.contains("good") ||
            text.contains("excellent") || text.contains("positive")) {
            return "Positive";
        } else if (text.contains("sad") || text.contains("bad") ||
                   text.contains("terrible") || text.contains("negative")) {
            return "Negative";
        } else {
            return "Neutral";
        }
    }

    public static void main(String[] args) {
        SentimentAnalyzer sa = new SentimentAnalyzer();
        try {
            sa.writeText("I am happy today", "input.txt");
            String sentiment = sa.analyzeSentiment("input.txt");
            System.out.println("Sentiment: " + sentiment);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
```

---

### Example 5: Character Encryption/Decryption

```java
import java.io.*;

class Encryption {
    public String encrypt(String message) {
        StringBuilder encrypted = new StringBuilder();
        for (char ch : message.toCharArray()) {
            encrypted.append((char)(ch + 1));  // Shift by 1
        }
        return encrypted.toString();
    }

    public String decrypt(String message) {
        StringBuilder decrypted = new StringBuilder();
        for (char ch : message.toCharArray()) {
            decrypted.append((char)(ch - 1));  // Shift back by 1
        }
        return decrypted.toString();
    }

    public void saveToFile(String data, String filename) throws IOException {
        FileWriter fw = new FileWriter(filename);
        fw.write(data);
        fw.close();
    }

    public String readFromFile(String filename) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(filename));
        StringBuilder content = new StringBuilder();
        String line;

        while ((line = br.readLine()) != null) {
            content.append(line);
        }

        br.close();
        return content.toString();
    }

    public static void main(String[] args) {
        Encryption enc = new Encryption();
        String message = "Hello";

        try {
            String encrypted = enc.encrypt(message);
            System.out.println("Encrypted: " + encrypted);

            enc.saveToFile(encrypted, "encrypted.txt");
            String read = enc.readFromFile("encrypted.txt");

            String decrypted = enc.decrypt(read);
            System.out.println("Decrypted: " + decrypted);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
```

---

### Example 6: Replace Vowels

```java
import java.io.*;

class VowelReplacer {
    public String replaceVowels(String text, char consonant) {
        StringBuilder result = new StringBuilder();

        for (char ch : text.toCharArray()) {
            if ("AEIOUaeiou".indexOf(ch) != -1) {
                result.append(consonant);
            } else {
                result.append(ch);
            }
        }

        return result.toString();
    }

    public void processFile(String input, String output, char consonant) throws IOException {
        // Read from input file
        BufferedReader br = new BufferedReader(new FileReader(input));
        StringBuilder content = new StringBuilder();
        String line;

        while ((line = br.readLine()) != null) {
            content.append(line);
        }
        br.close();

        // Replace vowels
        String modified = replaceVowels(content.toString(), consonant);

        // Write to output file
        FileWriter fw = new FileWriter(output);
        fw.write(modified);
        fw.close();
    }

    public static void main(String[] args) {
        VowelReplacer vr = new VowelReplacer();
        try {
            vr.processFile("input.txt", "output.txt", 'x');
            System.out.println("Vowels replaced successfully");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
```

---

## Common Patterns & Best Practices

### 1. Always Close Streams

```java
// BAD - Stream might not close if exception occurs
FileWriter fw = new FileWriter("file.txt");
fw.write("data");
fw.close();

// GOOD - Using try-with-resources
try (FileWriter fw = new FileWriter("file.txt")) {
    fw.write("data");
} catch (IOException e) {
    e.printStackTrace();
}
```

---

### 2. Handle Exceptions Properly

```java
// Method signature declares exception
public void method() throws IOException {
    // Calling code must handle
}

// Or handle locally
public void method() {
    try {
        // File operations
    } catch (IOException e) {
        e.printStackTrace();  // or log error
    }
}
```

---

### 3. Use BufferedReader/Writer for Text

```java
// Inefficient
FileReader fr = new FileReader("file.txt");

// Efficient
BufferedReader br = new BufferedReader(new FileReader("file.txt"));
```

---

### 4. Check for Empty Strings

```java
String[] words = line.trim().split("\\s+");
for (String word : words) {
    if (!word.isEmpty()) {  // Important check
        count++;
    }
}
```

---

### 5. Use StringBuilder for String Building

```java
// BAD - Creates many string objects
String result = "";
for (int i = 0; i < 1000; i++) {
    result += "word ";
}

// GOOD - Efficient
StringBuilder sb = new StringBuilder();
for (int i = 0; i < 1000; i++) {
    sb.append("word ");
}
String result = sb.toString();
```

---

### 6. Proper File Paths

```java
// Windows
String path = "C:\\Users\\Documents\\file.txt";

// Or use forward slash (works on all platforms)
String path = "C:/Users/Documents/file.txt";

// Relative path
String path = "data/file.txt";
```

---

### 7. Reading Until End of File

```java
// For BufferedReader - check for null
while ((line = br.readLine()) != null) {
    // Process line
}

// For FileReader/InputStream - check for -1
while ((ch = fr.read()) != -1) {
    // Process character
}

// For DataInputStream - check available()
while (dis.available() > 0) {
    // Read data
}
```

---

## Quick Reference Card

### Common File Operations

| Operation         | Code                                                                                                                     |
| ----------------- | ------------------------------------------------------------------------------------------------------------------------ |
| Write text        | `FileWriter fw = new FileWriter("file.txt");`<br>`fw.write("text");`<br>`fw.close();`                                    |
| Read text         | `BufferedReader br = new BufferedReader(new FileReader("file.txt"));`<br>`String line = br.readLine();`<br>`br.close();` |
| Copy file         | Read from source, write to destination                                                                                   |
| Append to file    | `FileWriter fw = new FileWriter("file.txt", true);`                                                                      |
| Check file exists | `File f = new File("file.txt");`<br>`boolean exists = f.exists();`                                                       |

---

### Common String Operations

| Operation      | Code                                     |
| -------------- | ---------------------------------------- |
| Split string   | `String[] parts = str.split("\\s+");`    |
| Format decimal | `String.format("%.2f", value)`           |
| Check vowel    | `"AEIOUaeiou".indexOf(ch) != -1`         |
| Convert case   | `str.toLowerCase()`, `str.toUpperCase()` |
| Trim spaces    | `str.trim()`                             |
| Check contains | `str.contains("substring")`              |

---

## Tips for Assessment

1. **Always import java.io.\***

   ```java
   import java.io.*;
   ```

2. **Remember to close streams** or use try-with-resources

3. **Handle IOException** with throws or try-catch

4. **Use correct read loop patterns**:
   - `readLine() != null` for BufferedReader
   - `read() != -1` for FileReader/InputStream
   - `available() > 0` for DataInputStream

5. **Format output correctly**:
   - Use `String.format()` for decimal places
   - Use `\n` or `newLine()` for new lines

6. **String manipulation**:
   - `split()` for word separation
   - `trim()` to remove spaces
   - `toLowerCase()/toUpperCase()` for case conversion

7. **Common mistakes to avoid**:
   - Forgetting to close streams
   - Not handling exceptions
   - Not checking for empty strings after split
   - Forgetting to cast `read()` result to char

---

## Summary

### Key Concepts Covered:

✅ File reading (FileReader, BufferedReader, DataInputStream)  
✅ File writing (FileWriter, BufferedWriter, DataOutputStream)  
✅ Exception handling (try-catch, throws)  
✅ String manipulation (split, format, trim, contains)  
✅ Character operations (vowel checking, encryption)  
✅ File copying and processing  
✅ Data analysis (word counting, sentiment analysis)

### Most Important Classes:

1. **BufferedReader** - Read text files line by line
2. **BufferedWriter** - Write text files efficiently
3. **FileReader** - Read characters
4. **FileWriter** - Write characters
5. **DataInputStream/DataOutputStream** - Read/write bytes

### Master These Patterns:

1. Read file line by line
2. Write formatted data to file
3. Copy file content
4. Process and transform text
5. Exception handling with file operations

---

**Good luck with your assessment! 🚀**

_Remember: Practice these patterns, understand the syntax, and always handle exceptions properly!_
