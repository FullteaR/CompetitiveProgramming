import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        while(!S.equals("")){
            if(S.substring(S.length()-5,S.length()).equals("dream")){
                S = S.substring(0,S.length()-5);
                continue;
            }
            else if(S.substring(S.length()-5,S.length()).equals("erase")){
                S = S.substring(0,S.length()-5);
                continue;
            }
            else if(S.substring(S.length()-6,S.length()).equals("eraser")){
                S = S.substring(0,S.length()-6);
                continue;
            }
            else if(S.substring(S.length()-7,S.length()).equals("dreamer")){
                S = S.substring(0,S.length()-7);
                continue;
            }
            else{
                System.out.println("NO");
                return ;
            }
        }
        System.out.println("YES");
    }
}
