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
import java.util.Arrays;
import java.util.HashMap;
import java.math.BigInteger;
import java.lang.Math;
import java.util.Objects;
import java.util.Map;

public class Main {
	public static final int INF = 2000000100;
	public static final long MOD = 1000000007;

	public static void main(String[] args) {
		FastScanner sc = new FastScanner(System.in);
		Integer H = sc.nextInt();
        Integer W = sc.nextInt();
        if(H==1 || W==1){
            System.out.println(H*W);
        }
        else if(H%2==0 && W%2==0){
            System.out.println(H*W/4);
        }
        else if(H%2==0 && W%2==1){
            System.out.println(H*(W-1)/4 + H/2);
        }
        else if(H%2==1 && W%2==0){
            System.out.println((H-1)*W/4 + W/2);
        }
        else{
            System.out.println((H-1)*(W-1)/4 + W/2 + H/2 + 1);
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
		return Objects.hash(a, b);
	}

}


class UnionFind {
	private Integer[] parents;

	public UnionFind(Integer n) {
		parents = new Integer[n];
		for (Integer i = 0; i < n; i++) {
			parents[i] = i;
		}
	}

	private Integer Root(Integer x) {
		if (parents[x] == x) {
			return x;
		}
		parents[x] = Root(parents[x]);
		return parents[x];
	}

	public Boolean Same(Integer x, Integer y) {
		return Root(x) == Root(y);
	}

	public void Union(Integer x, Integer y) {
		x = Root(x);
		y = Root(y);
		if (x == y)
			return;
		parents[x] = y;
		return;
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
		if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE)
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