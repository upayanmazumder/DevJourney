import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String line = br.readLine();
    if (line == null) line = "";

    int hyphens = 0;
    StringBuilder rest = new StringBuilder();
    for (int i = 0; i < line.length(); i++) {
      char c = line.charAt(i);
      if (c == '-') hyphens++;
      else rest.append(c);
    }

    StringBuilder out = new StringBuilder(line.length());
    for (int i = 0; i < hyphens; i++) out.append('-');
    out.append(rest);
    System.out.println(out);
  }
}
