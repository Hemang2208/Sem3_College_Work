import java.util.Scanner;
class pal {
    public static void main(String args[]){
        System.out.print("Enter a String : ");
        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        int i=0 ,j=s.length()-1;
        boolean flag = true;
        while(i<j){
            if (s.charAt(i) != s.charAt(j)){
                flag = false;
                break;
            }
            i++;
            j--;
        }

        if (flag == true) System.out.println(s + " is a palindrome");
        else System.out.println(s + " is not a palindrome");
    }
}
