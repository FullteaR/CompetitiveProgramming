import java.util.Scanner;
import java.util.TreeSet;
import java.util.Set;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        for(String parenthes:output(N)){
            System.out.println(parenthes);
        }
    }

    private static Set<String> output(int n){
        Set<String> retval = new TreeSet<String>();
        if(n==2){
            retval.add("()");
            return retval;
        }
        if(n%2==1 || n<=0){
            return retval;
        }
        for(int i=1;i<n;i++){
            for(String parenthes1:output(i)){
                for(String parenthes2:output(n-i)){
                    retval.add(parenthes1+parenthes2);
                }
            }
        }
        for(String parenthes:output(n-2)){
            retval.add("("+parenthes+")");
        }
        return retval;
    }
}