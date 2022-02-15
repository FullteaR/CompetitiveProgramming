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
	public static final long MOD = 1000000007;

	public static void main(String[] args) {
		FastScanner sc = new FastScanner(System.in);
		Integer N = sc.nextInt();
        Integer Q = sc.nextInt();
        StringBuffer buf = new StringBuffer();
        Pair[] points = new Pair[N];
        BigInteger y_bottom = new BigInteger("2000000100");
        BigInteger y_top = new BigInteger("-2000000100");
        BigInteger x_right = new BigInteger("-2000000100");
        BigInteger x_left = new BigInteger("2000000100");
        for(Integer i=0;i<N;i++){
            BigInteger x = new BigInteger(sc.next());
            BigInteger y = new BigInteger(sc.next());
            Pair p = new Pair(x.subtract(y), x.add(y));
            if(p.first().compareTo(x_left)<0){
                x_left = p.first();
            }
            if(x_right.compareTo(p.first())<0){
                x_right = p.first();
            }
            if(y_top.compareTo(p.second())<0){
                y_top = p.second();
            }
            if(p.second().compareTo(y_bottom)<0){
                y_bottom = p.second();
            }
            points[i] = p;
        }

        for(Integer i=0;i<Q;i++){
            Integer q = sc.nextInt();
            Pair p = points[q-1];
            BigInteger maxDistance = p.first().subtract(x_left).abs();
            maxDistance = p.first().subtract(x_right).abs().max(maxDistance);
            maxDistance = p.second().subtract(y_top).abs().max(maxDistance);
            maxDistance = p.second().subtract(y_bottom).abs().max(maxDistance);
            System.out.println(maxDistance);
        }
	}

}

class Pair{
	private final BigInteger a;
	private final BigInteger b;

	public Pair(BigInteger a_, BigInteger b_){
		a = a_;
		b = b_;
	}

	public BigInteger first(){
		return a;
	}
	public BigInteger second(){
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