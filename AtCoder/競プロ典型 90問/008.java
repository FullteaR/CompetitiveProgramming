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
		int N = sc.nextInt();
		String S = sc.next();
		HashMap<String, BigInteger> mp = new HashMap<String, BigInteger>();
		mp.put("a",BigInteger.ZERO);
		mp.put("at",BigInteger.ZERO);
		mp.put("atc",BigInteger.ZERO);
		mp.put("atco",BigInteger.ZERO);
		mp.put("atcod",BigInteger.ZERO);
		mp.put("atcode",BigInteger.ZERO);
		mp.put("atcoder",BigInteger.ZERO);
		BigInteger retval = BigInteger.ZERO;
		for(int i=0;i<S.length();i++){
			char c = S.charAt(i);
			if("atcoder".indexOf(c)==-1){
				continue;
			}
			if(c=='a'){
				mp.put("a", mp.get("a").add(BigInteger.ONE));
			}
			if(c=='t'){
				mp.put("at", mp.get("at").add(mp.get("a")));
			}
			if(c=='c'){
				mp.put("atc", mp.get("atc").add(mp.get("at")));
			}
			if(c=='o'){
				mp.put("atco", mp.get("atco").add(mp.get("atc")));
			}
			if(c=='d'){
				mp.put("atcod", mp.get("atcod").add(mp.get("atco")));
			}
			if(c=='e'){
				mp.put("atcode", mp.get("atcode").add(mp.get("atcod")));
			}
			if(c=='r'){
				mp.put("atcoder", mp.get("atcoder").add(mp.get("atcode")));
			}
		}
		System.out.println(mp.get("atcoder").mod(BigInteger.valueOf(MOD)));
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