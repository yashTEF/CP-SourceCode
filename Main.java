import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;

public class Main implements Runnable {

    long INF = (long) 1e9 + 7;

    private void solve() throws IOException {
        int n = nextInt();
        int k = nextInt();
        String s = next();
        char c[] = s.toCharArray();
        long ans = 0;
        long t = n / 2 + (n % 2 != 0 ? 1 : 0);
        for (int i = 0; i < t; ++i) {
            int cur = c[i] - 'a';
            int rem = t - 1 - i;
            ans = (ans + cur * pow(k, rem) % INF) % INF;
        }
        boolean ok = false;
        for (int i = 0; i < t; ++i) {
            if (c[i] < c[N - 1 - i]) {
                ok  = true;
                break;
            }
        }
        if (ok) {
            ans++;
            ans %= INF; 
        }

    }

    public static void main(String[] args) {
        new Main().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            writer = new PrintWriter(System.out);
            int t = nextInt();
            for (int i = 0)
            solve();
            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}
