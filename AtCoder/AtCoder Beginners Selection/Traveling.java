import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int t1,x1,y1;
        int t2,x2,y2;
        t1 = 0;
        x1 = 0;
        y1 = 0;
        for(int i=0;i<N;i++){
            t2 = sc.nextInt();
            x2 = sc.nextInt();
            y2 = sc.nextInt();
            int d = distance(x1,y1,x2,y2);
            if(d%2!=(t2-t1)%2 || d>t2-t1){
                System.out.println("No");
                return ;
            }
            t1=t2;
            x1=x2;
            y1=y2;
        }
        System.out.println("Yes");
    }

    private static int distance(int x1, int y1, int x2, int y2){
        return Math.abs(x1-x2)+Math.abs(y1-y2);
    }
}
