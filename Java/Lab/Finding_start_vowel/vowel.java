import java.util.Scanner;
class vowel{
    public static void main (String args[]){
        System.out.print("Enter a sentence : ");
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine().trim().toLowerCase();
        sc.close();

        String w="";
        for (int i=0 ; i<s.length() ; i++){
            if (s.charAt(i)==' '){
                if (w.charAt(0)=='a' ||w.charAt(0)=='e'  ||w.charAt(0)=='i'  ||w.charAt(0)=='o'  ||w.charAt(0)=='u'){
                    System.out.println(w);
                }
                w="";
            }
            else w+=s.charAt(i);
        }
        // Check the last word after the loop ends
        if (w.length()>0 && (w.charAt(0)=='a' ||w.charAt(0)=='e'  ||w.charAt(0)=='i'  ||w.charAt(0)=='o'  ||w.charAt(0)=='u')) System.out.println(w);

        //? issue was the code only printed a word when it has a white space after it , but at the last word , it doesn't have space after it so it was not getting printed , so added a check if w has a legal word and if yes then print it 
    }
}