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
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.HashMap;
import java.math.BigInteger;
import java.lang.Math;
import java.util.Objects;
import java.util.Map;
import java.util.Deque;
import java.util.Comparator;


public class Main {
	public static final long INF = 2000000100;
	public static final long MOD = 1000000007;

	public static void main(String[] args) {
		FastScanner sc = new FastScanner(System.in);
		Integer N = sc.nextInt();
        Pair[] points = new Pair[N];
        for(int i=0;i<N;i++){
            Long x = sc.nextLong();
            Long y = sc.nextLong();
            Pair p = new Pair(x, y);
            points[i] = p;
        }
        Arrays.sort(points);


        Deque<Pair> stack_up = new ArrayDeque<Pair>();
        for(Pair point : points){
            if(stack_up.size()<2){
                stack_up.addFirst(point);
                continue;
            }
            
            while(true){
                Pair p1 = stack_up.removeFirst();
                Pair p2 = stack_up.peekFirst();
                Pair v1 = new Pair(p1.first()-p2.first(), p1.second()-p2.second());
                Pair v2 = new Pair(point.first()-p1.first(), point.second()-p1.second());
                if(cross(v1,v2)<=0){
                    stack_up.addFirst(p1);
                    stack_up.addFirst(point);
                    break;
                }
                else if(stack_up.size()==1){
                    stack_up.addFirst(point);
                    break;
                }
            }
        }

        Arrays.sort(points, Comparator.reverseOrder());

        Deque<Pair> stack_down = new ArrayDeque<Pair>();
        for(Pair point : points){
            if(stack_down.size()<2){
                stack_down.addFirst(point);
                continue;
            }
            
            while(true){
                Pair p1 = stack_down.removeFirst();
                Pair p2 = stack_down.peekFirst();
                Pair v1 = new Pair(p1.first()-p2.first(), p1.second()-p2.second());
                Pair v2 = new Pair(point.first()-p1.first(), point.second()-p1.second());
                if(cross(v1,v2)<=0){
                    stack_down.addFirst(p1);
                    stack_down.addFirst(point);
                    break;
                }
                else if(stack_down.size()==1){
                    stack_down.addFirst(point);
                    break;
                }
            }
        }
        stack_up.removeLast();
        stack_down.removeLast();
        Integer ind = 0;
        Pair[] convex = new Pair[stack_down.size()+stack_up.size()];
        for(Pair p : stack_down){
            convex[ind] = p;
            ind++;
        }
        for(Pair p : stack_up){
            convex[ind] = p;
            ind++;
        }
        Long b = (long)(convex.length);
        Long S2 = (long)0;
        for(int i=0;i<convex.length;i++){
            b += countLattice(convex[i], convex[(i+1)%convex.length]);
            S2 += Area(convex[0], convex[i], convex[(i+1)%convex.length]);
        }
        Long i2 = S2-b+2;

        System.out.println(i2/2+b-N);



	}

    public static Long gcd(Long a, Long b){
        if(Math.min(a,b)==0){
            return Math.max(a,b);
        }
        return gcd(Math.min(a,b), Math.max(a,b)%Math.min(a,b));
    }

    public static Long cross(Pair v1, Pair v2){
        return v1.first() * v2.second() - v1.second() * v2.first();
    }

    public static Long countLattice(Pair p1, Pair p2){
        Long g = gcd(Math.abs(p1.first()-p2.first()), Math.abs(p1.second()-p2.second()));
        return g-(long)1;
    }

    public static Long Area(Pair p1, Pair p2, Pair p3){
        long a = p3.first() - p1.first();
        long b = p3.second() - p1.second();
        long c = p2.first() - p1.first();
        long d = p2.second() - p1.second();
        return Math.abs(a*d-b*c);
    }

}

class Pair implements Comparable<Pair>{
	private final Long a;
	private final Long b;

	public Pair(Long a_, Long b_){
		a = a_;
		b = b_;
	}

	public Long first(){
		return a;
	}
	public Long second(){
		return b;
	}

	@Override
	public boolean equals(Object obj){
		if (obj instanceof Pair){
			Pair p = (Pair) obj;
			return p.a.longValue() == this.a.longValue() && p.b.longValue() == this.b.longValue();
		}
		else{
			return false;
		}
	}
    @Override
    public int compareTo(Pair p){
        if(this.a.longValue()==p.a.longValue()){
            if(this.b.longValue() < p.b.longValue()){
                return -1;
            }
            else if(this.b.longValue() == p.b.longValue()){
                return 0;
            }
            else{
                return 1;
            }
        }
        else{
            if(this.a.longValue() < p.a.longValue()){
                return -1;
            }
            else{
                return 1;
            }
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