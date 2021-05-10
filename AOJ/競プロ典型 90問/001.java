import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N,L;
        int K;
        N = sc.nextInt();
        L = sc.nextInt();
        K = sc.nextInt();
        int[] A = new int[N+2];
        A[0]=0;
        A[N+1]=L;
        for(int i=1;i<=N;i++){
            A[i] = sc.nextInt();
        }
        int[] pieces = new int[N+1];
        for(int i=0;i<N+1;i++){
            pieces[i] = A[i+1]-A[i];
        }

        int min = 0;
        int max = L+1;
        while(max-min>1){
            int mid = (max+min)/2;
            if(isAble(pieces,K,mid)){
                min=mid;
            }
            else{
                max=mid;
            }
        }
        for(int i=min;i<=max;i++){
            if(!isAble(pieces,K,i)){
                System.out.println(i-1);
                return ;
            }
        }

    }

    private static boolean isAble(int[] pieces, int K, int minimum){
        int length = 0;
        int blocks = 0;
        for(int i=0;i<pieces.length;i++){
            length+=pieces[i];
            if(length>=minimum){
                blocks++;
                length = 0;
            }
        }
        return blocks>=K+1;
    }
}