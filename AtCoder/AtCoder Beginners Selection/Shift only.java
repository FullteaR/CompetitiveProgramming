import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] A = new int[N];
        for(int i=0;i<N;i++){
            A[i] = sc.nextInt();
        }
        System.out.println(count(A));
    }

    private static int count(int[] A){
        int retval=0;
        while(true){
            for(int i=0;i<A.length;i++){
                if(A[i]%2==1){
                    return retval;
                }
                else{
                    A[i]=A[i]/2;
                }
            }
            retval++;
        }
    }
}
