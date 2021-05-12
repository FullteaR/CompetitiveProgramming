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
		Integer H,W;
		H = sc.nextInt();
		W = sc.nextInt();
		H+=2;
		W+=2;
		Boolean[][] tiles = new Boolean[H][];
		for(Integer h=0;h<H;h++){
			tiles[h] = new Boolean[W];
			for(Integer w=0;w<W;w++){
				tiles[h][w] = false;
			}
		}
		UnionFind uf = new UnionFind(H*W);
		Integer Q;
		Q = sc.nextInt();
		for(int i=0;i<Q;i++){
			Integer q1;
			q1 = sc.nextInt();
			if(q1==1){
				Integer r, c;
				r = sc.nextInt();
				c = sc.nextInt();
				tiles[r][c] = true;
				if(tiles[r-1][c]){
					uf.Union((r-1)*W+c, r*W+c);
				}
				if(tiles[r+1][c]){
					uf.Union((r+1)*W+c, r*W+c);
				}
				if(tiles[r][c-1]){
					uf.Union(r*W+c-1, r*W+c);
				}
				if(tiles[r][c+1]){
					uf.Union(r*W+c+1, r*W+c);
				}
			}
			else{//q1==2
				Integer ra,ca,rb,cb;
				ra = sc.nextInt();
				ca = sc.nextInt();
				rb = sc.nextInt();
				cb = sc.nextInt();
				if(!tiles[ra][ca] || !tiles[rb][cb]){
					System.out.println("No");
				}
				else if(uf.Same(ra*W+ca, rb*W+cb)){
					System.out.println("Yes");
				}
				else{
					System.out.println("No");
				}
			}
		}
    }
}

class UnionFind{
	private Integer[] parents;
	public UnionFind(Integer n){
		parents = new Integer[n];
		for(Integer i=0;i<n;i++){
			parents[i] = i;
		}
	}
	private Integer Root(Integer x){
		if(parents[x] == x){
			return x;
		}
		parents[x] = Root(parents[x]);
		return parents[x];
	}
	public Boolean Same(Integer x, Integer y){
		return Root(x) == Root(y);
	}

	public void Union(Integer x, Integer y){
		x = Root(x);
		y = Root(y);
		if(x==y) return;
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