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
import java.util.HashSet;
import java.math.BigInteger;
import java.util.List;
import java.util.ArrayList;
import java.lang.Math;
import java.util.Objects;
import java.util.Optional;
import java.util.function.*;
 
//未検査エラーが出る。
 
 
public class Main{
	public static final int INF=2000000100;
	public static final long MOD=1000000007;
    public static void main(String[] args){
		FastScanner sc = new FastScanner(System.in);
		Integer N, M;
		N = sc.nextInt();
		M = sc.nextInt();
		HashMap<Integer, HashSet<Integer>> v = new HashMap<Integer, HashSet<Integer>>();
		HashMap<Pair, Integer> weights = new HashMap<Pair, Integer>();
		for(Integer i=0;i<N;i++){
			v.put(i, new HashSet<Integer>());
			v.get(i).clear();
		}
		for(Integer i=0;i<M;i++){
			Integer A,B,C;
			A = sc.nextInt();
			B = sc.nextInt();
			C = sc.nextInt();
			A--;
			B--;
			v.get(A).add(B);
			v.get(B).add(A);
			Pair<Integer, Integer> p1 = Pair.of(A,B);
			Pair<Integer, Integer> p2 = Pair.of(B,A);
			weights.put(p1,C);
			weights.put(p2,C);
		}
		List<Integer> distance_1 = dijkstra(v, weights, N, 0);
		List<Integer> distance_N = dijkstra(v, weights, N, N-1);
		StringBuffer buf = new StringBuffer();
		for(int k=0;k<N;k++){
			Integer retval = distance_1.get(k) + distance_N.get(k);
			buf.append(String.valueOf(retval));
			buf.append("\n");
		}
		System.out.print(buf.toString());
    }
 
	private static List<Integer> dijkstra(HashMap<Integer, HashSet<Integer>> v, HashMap<Pair, Integer> weights, int N, int s){
        List<Integer> retval = new ArrayList<Integer>();
        retval.clear();
        for(int i=0;i<N;i++){
            retval.add(INF);
        }
        retval.set(s,0);
        HashSet<Integer> next = new HashSet<Integer>();
        HashSet<Integer> _next = new HashSet<Integer>();
        next.clear();
        next.add(s);
		
        while(!next.isEmpty()){
            _next.clear();
            for(Integer next_element: next){
                for(Integer neighbor: v.get(next_element)){
					Pair p = Pair.of(next_element, neighbor);
					Integer weight = weights.get(p);
                    if(retval.get(neighbor)>retval.get(next_element)+weight){
                        retval.set(neighbor, retval.get(next_element)+weight);
                        _next.add(neighbor);
                    }
                }
            }
            next.clear();
            for(int n: _next){
                next.add(n);
            }
        }
        return retval;
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
 
 
 
class Pair<L, R> {
	private L left;
	private R right;
 
	public static <L, R> Pair<L, R> of(L left, R right) {
		return new Pair<>(left, right);
	}
 
	public Pair<R, L> swap() {
		return of(right, left);
	}
 
	public void accept(BiConsumer<L, R> action) {
		action.accept(left, right);
	}
 
	public void accept(Consumer<L> leftAction, Consumer<R> rightAction) {
		leftAction.accept(left);
		rightAction.accept(right);
	}
 
	public <K> K unify(BiFunction<L, R, K> mapper) {
		return mapper.apply(left, right);
	}
 
	public <LL, RR> Pair<LL, RR> map(Function<L, LL> leftMapper, Function<R, RR> rightMapper) {
		return of(leftMapper.apply(left),
				rightMapper.apply(right));
	}
 
	public boolean test(BiPredicate<L, R> predicate) {
		return predicate.test(left, right);
	}
 
	public Pair<Boolean, Boolean> test(Predicate<L> leftPredicate, Predicate<R> rightPredicate) {
		return map(l -> leftPredicate.test(l),
				r -> rightPredicate.test(r));
	}
 
	@Override
	public int hashCode() {
		return Objects.hash(left, right);
	}
 
	@Override
	public boolean equals(Object other) {
		return other instanceof Pair &&
				((Pair)other).test((l, r) -> Objects.equals(l, left) && Objects.equals(r, right));
	}
 
	@Override
	public String toString() {
		return String.format("(%s, %s)", left, right);
	}
 
	private Pair(L left, R right) {
		this.left = Optional.of(left)
				.orElseThrow(() -> new NullPointerException());
		this.right = Optional.of(right)
				.orElseThrow(() -> new NullPointerException());
	}
}