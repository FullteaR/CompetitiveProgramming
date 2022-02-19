import java.io.Closeable;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
import java.util.Scanner;
import java.util.HashSet;
import java.lang.StringBuffer;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.HashMap;
import java.lang.Math;
import java.util.Objects;
import java.util.Map;
import java.util.Set;

public class Main {
	public static final int INF = 2000000100;
	public static final long MOD = 1000000007;
	public static Map<Integer, Integer> table;
	

	public static void main(String[] args) {
		FastScanner sc = new FastScanner(System.in);
		Integer N = sc.nextInt();

		Pair[] branches = new Pair[N-1];
		Set<Integer>[] neighbors = new HashSet[N];
		for(int i=0;i<N;i++){
			neighbors[i] = new HashSet<Integer>();
			neighbors[i].clear();
		}
		table = new HashMap<Integer, Integer>();
		table.clear();

		for(Integer i=0;i<N-1;i++){
			Integer a = sc.nextInt();
			Integer b = sc.nextInt();
			a--;
			b--;
			branches[i] = new Pair(Math.min(a,b), Math.max(a,b));
			neighbors[a].add(b);
			neighbors[b].add(a);
		}
		Integer[] depth = new Integer[N];
		for(int i=0;i<N;i++){
			depth[i] = INF;
		}
		depth[0] = 0;
		getDepth(0, depth, neighbors);

		Long retval = (long)0;
		for(int i=0;i<N-1;i++){
			Integer a = branches[i].first();
			Integer b = branches[i].second();
			if(depth[a]>depth[b]){
				Integer tmp = dfs(a, depth, neighbors);
				retval+=(long)tmp*(long)(N-tmp);
			}
			else{
				Integer tmp = dfs(b, depth, neighbors);
				retval+=(long)tmp*(long)(N-tmp);
			}
		}
		System.out.println(retval);
	}

	public static Integer dfs(Integer a, Integer[] depth, final Set[] neighbors){
		Integer retval = 1;
		if(table.containsKey(a)){
			return table.get(a);
		}

		Set<Integer> _neighbors = neighbors[a];
		for(Integer neighbor : _neighbors){
			if(depth[neighbor]<=depth[a]){continue;}
			retval += dfs(neighbor, depth, neighbors);
		}
		table.put(a, retval);
		return retval;
	}
	public static void getDepth(Integer i, final Integer[] depth, final Set[] neighbors){
		Set<Integer> _neighbors = neighbors[i];
		for(Integer neighbor : _neighbors){
			if(depth[neighbor]>depth[i]+1){
				depth[neighbor] = depth[i]+1;
				getDepth(neighbor, depth, neighbors);
			}
		}
	}
}

class Pair{
	private final Integer a;
	private final Integer b;

	public Pair(Integer a_, Integer b_){
		a = a_;
		b = b_;
	}

	public Integer first(){
		return a;
	}
	public Integer second(){
		return b;
	}

	@Override
	public boolean equals(Object obj){
		if (obj instanceof Pair){
			Pair p = (Pair) obj;
			return p.a == this.a && p.b == this.b;
		}
		else{
			return false;
		}
	}
	public int hashCode() {
		return (Objects.hash(a, b));
	}

}

class FastScanner implements Closeable {
	private final InputStream in;
	private final byte[] buffer = new byte[1024];
	private int ptr = 0;
	private int buflen = 0;

	public FastScanner(InputStream in) {
		this.in = in;
	}

	private boolean hasNextByte() {
		if (ptr < buflen) {
			return true;
		} else {
			ptr = 0;
			try {
				buflen = in.read(buffer);
			} catch (IOException e) {
				e.printStackTrace();
			}
			if (buflen <= 0) {
				return false;
			}
		}
		return true;
	}

	private int readByte() {
		if (hasNextByte())
			return buffer[ptr++];
		else
			return -1;
	}

	private static boolean isPrintableChar(int c) {
		return 33 <= c && c <= 126;
	}

	public boolean hasNext() {
		while (hasNextByte() && !isPrintableChar(buffer[ptr]))
			ptr++;
		return hasNextByte();
	}

	public String next() {
		if (!hasNext())
			throw new NoSuchElementException();
		StringBuilder sb = new StringBuilder();
		int b = readByte();
		while (isPrintableChar(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	public long nextLong() {
		if (!hasNext())
			throw new NoSuchElementException();
		long n = 0;
		boolean minus = false;
		int b = readByte();
		if (b == '-') {
			minus = true;
			b = readByte();
		}
		if (b < '0' || '9' < b) {
			throw new NumberFormatException();
		}
		while (true) {
			if ('0' <= b && b <= '9') {
				n *= 10;
				n += b - '0';
			} else if (b == -1 || !isPrintableChar(b)) {
				return minus ? -n : n;
			} else {
				throw new NumberFormatException();
			}
			b = readByte();
		}
	}

	public int nextInt() {
		long nl = nextLong();
		if (nl < Long.MIN_VALUE || nl > Long.MAX_VALUE)
			throw new NumberFormatException();
		return (int) nl;
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}

	public void close() {
		try {
			in.close();
		} catch (IOException e) {
		}
	}
}