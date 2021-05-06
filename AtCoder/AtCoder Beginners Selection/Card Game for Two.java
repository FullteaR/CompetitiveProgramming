import java.util.Scanner;
import java.util.Arrays;
import java.util.Comparator;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] a = new int[N];
        for(int i=0;i<N;i++){
            a[i] = -1*sc.nextInt();
        }
        Arrays.sort(a);
        int delta=0;
        for(int i=0;i<N;i++){
            delta+=-1*a[i]*Math.pow(-1,i);
        }
        System.out.println(delta);
    }
}
