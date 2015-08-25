import java.io.*;
import java.util.*;
public class Main {
    public static void main(String[] args) throws IOException {
        Reader r = new Reader(System.in);
        double x = r.nextDouble();
        int n = r.nextInt();
        String str = r.next();
    }
}

class Reader {
    final BufferedReader reader;
    StringTokenizer tokenizer;
    public Reader(InputStream input) {
        reader = new BufferedReader(new InputStreamReader(input));
        tokenizer = new StringTokenizer("");
    }

    public String next() throws IOException {
        while (!tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}
