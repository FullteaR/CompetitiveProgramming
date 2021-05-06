import java.util.Scanner;
public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a = Integer.parseInt(sc.next());
        int b = Integer.parseInt(sc.next());
        int c = Integer.parseInt(sc.next());
        String s = sc.next();
        System.out.printf("%d %s\n",a+b+c,s);
    }
}
