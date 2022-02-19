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

public class Main {
	public static final int INF = 2000000100;
	public static final long MOD = 1000000007;

	public static void main(String[] args) {
		FastScanner sc = new FastScanner(System.in);
		BigInteger A = new BigInteger(sc.next());
		BigInteger B = new BigInteger(sc.next());
		BigInteger lcm = A.multiply(B).divide(A.gcd(B));
		BigInteger limit = new BigInteger("10").pow(18);
		if(lcm.compareTo(limit)>0){
			System.out.println("Large");
		}
		else{
			System.out.println(lcm.toString());
		}

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