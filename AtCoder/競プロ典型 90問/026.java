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
import java.util.ArrayList;

public class Main {
	public static final int INF = 2000000100;
	public static final long MOD = 1000000007;

	public static void main(String[] args) {
		FastScanner sc = new FastScanner(System.in);
		Integer N = sc.nextInt();
		ArrayList<HashSet<Integer>> neighbors = new ArrayList<HashSet<Integer>>();
		for(Integer i=0;i<N;i++){
			HashSet<Integer> tmp = new HashSet<Integer>();
			tmp.clear();
			neighbors.add(tmp);
		}
		for(Integer i=0;i<N-1;i++){
			Integer A,B;
			A = sc.nextInt()-1;
			B = sc.nextInt()-1;
			neighbors.get(A).add(B);
			neighbors.get(B).add(A);
		}
		ArrayList<Integer> g1 = new ArrayList<Integer>();
		ArrayList<Integer> g2 = new ArrayList<Integer>();
		HashSet<Integer> now = new HashSet<Integer>();
		HashSet<Integer> next = new HashSet<Integer>();
		g1.clear();
		g2.clear();
		now.clear();
		next.clear();
		now.add(0);
		//g2.add(1);
		Integer group_number = 1;
		Boolean[] already = new Boolean[N];
		already[0] = true;
		for(Integer i=0;i<N;i++){
			already[i]=false;
		}
		while(now.size()>0){
			next.clear();
			for(Integer n:now){
				for(Integer _n:neighbors.get(n)){
					if(already[_n]){
						continue;
					}
					else{
						already[_n]=true;
						next.add(_n);
						if(group_number==1){
							g1.add(_n+1);
						}
						else{
							g2.add(_n+1);
						}
					}
				}
			}
			now.clear();
			for(Integer n:next){
				now.add(n);
			}
			group_number = 3-group_number;
		}
		StringBuffer buf = new StringBuffer();
		if(g1.size()>g2.size()){
			for(Integer i=0;i<N/2;i++){
				 buf.append(g1.get(i).toString());
				 if(i<N/2-1){
					 buf.append(" ");
				 }
				 else{
					 buf.append("\n");
				 }
			}
		}
		else{
			for(Integer i=0;i<N/2;i++){
				 buf.append(g2.get(i).toString());
				 if(i<N/2-1){
					 buf.append(" ");
				 }
				 else{
					 buf.append("\n");
				 }
			}
		}
		System.out.print(buf.toString());
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