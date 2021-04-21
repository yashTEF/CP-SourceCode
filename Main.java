				import java.util.*;
				import java.io.*;


				public class Main implements Runnable{

					final long INF = (long) 1e9 + 7;
					boolean vis[][];
					int k;

					static class Pair implements Comparable<Pair> {
						int first;
						long second;

						Pair(int first, long second) {
							this.first = first;
							this.second = second;
						}

						public int compareTo(Pair p) {
							return Long.compare(second, p.second);
						}

					}

					private long pow(long a, long p) {
						long prod = 1;
						while (p > 0) {
							if ((p & 1) == 1) {
								prod = prod * a % INF;
							}
							a = a * a % INF;
							p >>= 1;
						}
						return prod;
					}

					private void solve() throws IOException {
						long n = nextInt();
						long m = nextInt();
						long ans = pow(2, m);
						ans -= 1;
						if (ans < 0) ans += INF;
						ans = pow(ans, n);
						pw.println(ans);
					}



					
					private void dbg(Object... a) {
						System.err.println(Arrays.deepToString(a));
					}

					private void brute() throws IOException {

					}

					private void test() throws IOException {
						Random rnd = new Random();
						for (int i = 0; i < 10; ++i) {
							int n = rnd.nextInt(10) + 1;
							int a[] = new int[n];
							for (int j = 0; j < n; ++j) {
								a[j] = rnd.nextInt(2);
							}
							System.err.println(Arrays.toString(a));
						}
					}

					public static void main(String args[]) {
						new Main().run();
					}

					BufferedReader br;
					PrintWriter pw;
					StringTokenizer st;

					public void run() {
						try {
							br = new BufferedReader(new InputStreamReader(System.in));
							pw = new PrintWriter(System.out);
							st = null;
							solve();
							pw.flush();
							pw.close();
						} catch (IOException e) {
							e.printStackTrace();
							System.exit(1);
						}
					}

					public String next() throws IOException {
						while (st == null || !st.hasMoreTokens()) {
							st = new StringTokenizer(br.readLine());	
						}
						return st.nextToken();
					}

					public int nextInt() throws IOException { 
						return Integer.parseInt(next());
					}

					public long nextLong() throws IOException{
						return Long.parseLong(next());	
					}

					public double nextDouble() throws IOException {
						return Double.parseDouble(next());
					}
				}