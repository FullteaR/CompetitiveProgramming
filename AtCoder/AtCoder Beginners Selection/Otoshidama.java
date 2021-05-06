import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int Y = sc.nextInt();
        for(int i=0;i<=N;i++){
            for(int j=0;j<=N;j++){
                if(N-i-j<0){
                    continue;
                }
                if(10000*i+5000*j+1000*(N-i-j)==Y){
                    System.out.printf("%d %d %d\n",i,j,N-i-j);
                    return ;
                }
            }
        }
        System.out.printf("%d %d %d\n",-1,-1,-1);
    }
}
