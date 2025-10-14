import java.util.Scanner;
class SOD{
    public static void main(String[]args){
        System.out.print("Enter a number : ");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.close();
        int sum=0 , digit;
        while (n>0){
            digit = n%10;
            sum+=digit;
            n/=10;
        }

        System.out.println("Sum of digits is "+sum);
    }
}