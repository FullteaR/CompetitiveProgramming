import java.io.Closeable;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
import java.util.Scanner;
import java.lang.StringBuffer;
import java.util.Arrays;
import java.util.HashMap;
import java.math.BigInteger;
import java.lang.Math;


public class Main{
	public static final int INF=2000000100;
	public static final long MOD=1000000007;
    public static void main(String[] args){
        FastScanner sc = new FastScanner(System.in);
		Integer N = sc.nextInt();
		Integer c1[] = new Integer[N];
		Integer c2[] = new Integer[N];
		for(int i=0;i<N;i++){
			Integer C, P;
			C = sc.nextInt();
			P = sc.nextInt();
			if(C==1){
				c1[i]=P;
				c2[i]=0;
			}
			else{
				c1[i]=0;
				c2[i]=P;
			}
		}
		Integer c1_a[] = new Integer[N+1];
		Integer c2_a[] = new Integer[N+1];
		c1_a[0] = 0;
		c2_a[0] = 0;
		for(int i=0;i<N;i++){
			c1_a[i+1] = c1_a[i]+c1[i];
			c2_a[i+1] = c2_a[i]+c2[i];
		}
		Integer Q = sc.nextInt();
		StringBuffer buf = new StringBuffer();
		for(int i=0;i<Q;i++){
			Integer L, R;
			L = sc.nextInt();
			R = sc.nextInt();
			buf.append(String.valueOf(c1_a[R]-c1_a[L-1]));
			buf.append(" ");
			buf.append(String.valueOf(c2_a[R]-c2_a[L-1]));
			buf.append("\n");
		}
		System.out.print(buf.toString());
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
		}else{
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
	private int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1;}
	private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
	public boolean hasNext() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; return hasNextByte();}
	public String next() {
		if (!hasNext()) throw new NoSuchElementException();
		StringBuilder sb = new StringBuilder();
		int b = readByte();
		while(isPrintableChar(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	public long nextLong() {
		if (!hasNext()) throw new NoSuchElementException();
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
		while(true){
			if ('0' <= b && b <= '9') {
				n *= 10;
				n += b - '0';
			}else if(b == -1 || !isPrintableChar(b)){
				return minus ? -n : n;
			}else{
				throw new NumberFormatException();
			}
			b = readByte();
		}
	}
	public int nextInt() {
		long nl = nextLong();
		if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
		return (int) nl;
	}
	public double nextDouble() { return Double.parseDouble(next());}
	public void close() {
		try {
			in.close();
		} catch (IOException e) {
		}
	}
}