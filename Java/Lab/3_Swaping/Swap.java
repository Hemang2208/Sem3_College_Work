import java.util.*;

class Swap {
    public static void main(String args[]) {
        System.out.print("Enter two numbers : ");
        
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        sc.close();

        System.out.println("Before Swap a : " + a + " and b : " + b);

        a = a + b;
        b = a - b;
        a = a - b;

        System.out.println("After Swap a : " + a + " and b : " + b);
    }
}