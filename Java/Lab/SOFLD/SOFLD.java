import java.util.Scanner;
class SOFLD {
    public static void main(String args[]){
        System.out.print("Enter a number : ");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.close();
        int sum=n%10 , digit=0;
        while (n>0){
            digit = n%10;
            n/=10;
        }
        sum+=digit;

        System.out.println("Sum of first and last digit is "+sum);
    }
}
