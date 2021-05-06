import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N,A,B;
        N = sc.nextInt();
        A = sc.nextInt();
        B = sc.nextInt();
        int retval=0;
        for(int i=1;i<=N;i++){
            int s = calcSum(i);
            if(A<=s && s<=B){
                retval+=i;
            }
        }
        System.out.println(retval);
    }

    private static int calcSum(int X){
        int retval=0;
        while(X>0){
            retval+=X%10;
            X=X/10;
        }
        return retval;
    }
}
