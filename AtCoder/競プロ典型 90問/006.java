import java.io.Closeable;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
import java.util.Scanner;
import java.util.TreeSet;
import java.util.HashSet;
import java.util.Set;
import java.util.HashMap;
import java.util.Map;
import java.util.List;
import java.util.ArrayList;
import java.lang.StringBuffer;


public class Main{
    public static void main(String[] args){
        FastScanner sc = new FastScanner(System.in);
		int N,K;
		N = sc.nextInt();
		K = sc.nextInt();
		String S;
		S = sc.next();
		StringBuffer ans = new StringBuffer();
		while(K>0){
			String cand = S.substring(0,S.length()-K+1);
			int ind = minArg(cand);
			ans.append(String.valueOf(cand.charAt(ind)));
			S = S.substring(ind+1);
			K--;
		}
		System.out.println(ans.toString());
    }

	private static int minArg(String S){
		int ind = 0;
		char c = S.charAt(0);
		for(int i=0;i<S.length();i++){
			if(c>S.charAt(i)){
				ind = i;
				c = S.charAt(i);
			}
		}
		return ind;
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