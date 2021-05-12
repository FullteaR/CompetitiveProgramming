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
        int H = sc.nextInt();
        int W = sc.nextInt();
        int[][] A = new int[H][];
        int[] tate = new int[W];
        int[] yoko = new int[H];
        for(int w=0;w<W;w++){
            tate[w]=0;
        }
        for(int h=0;h<H;h++){
            yoko[h]=0;
        }
        for(int h=0;h<H;h++){
            A[h] = new int[W];
            for(int w=0;w<W;w++){
                A[h][w] = sc.nextInt();
            }
        }
        for(int h=0;h<H;h++){
            for(int w=0;w<W;w++){
                tate[w]+=A[h][w];
                yoko[h]+=A[h][w];
            }
        }
		
        for(int h=0;h<H;h++){
			StringBuffer buf = new StringBuffer();
            for(int w=0;w<W;w++){
                int b = tate[w] + yoko[h] - A[h][w];
				buf.append(String.valueOf(b));
				if(w<W-1){
					buf.append(" ");
				}
            }
			System.out.println(buf.toString());
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