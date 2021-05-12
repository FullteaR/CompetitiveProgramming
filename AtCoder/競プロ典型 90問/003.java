import java.util.Scanner;
import java.util.TreeSet;
import java.util.HashSet;
import java.util.Set;
import java.util.HashMap;
import java.util.Map;
import java.util.List;
import java.util.ArrayList;


public class Main{
    public static final int INF=1000000010;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        HashMap<Integer , HashSet<Integer>> neibors = new HashMap<Integer , HashSet<Integer>>();
        for(int i=0;i<N;i++){
            neibors.put(i, new HashSet<Integer>());
            neibors.get(i).clear();
        }
        for(int i=0;i<N-1;i++){
            int A, B;
            A = sc.nextInt();
            B = sc.nextInt();
            A-=1;
            B-=1;
            neibors.get(A).add(B);
            neibors.get(B).add(A);
        }

        List<Integer> l1 = dijkstra(neibors, N, 0);
        int city1 = argMax(l1);
        List<Integer> l2 = dijkstra(neibors, N,city1);
        int city2 = argMax(l2);
        int distance = l2.get(city2);
        System.out.println(distance+1);
    }
    
    private static List<Integer> dijkstra(HashMap<Integer, HashSet<Integer>> v, int N, int s){
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
            for(int next_element: next){
                for(int neighbor: v.get(next_element)){
                    if(retval.get(neighbor)>retval.get(next_element)+1){
                        retval.set(neighbor, retval.get(next_element)+1);
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
    
    private static int argMax(List<Integer> l){
        int ind = 0;
        int val = l.get(0);
        for(int i=0;i<l.size();i++){
            if(l.get(i)>val){
                ind = i;
                val=l.get(i);
            }
        }
        return ind;
    }
}
