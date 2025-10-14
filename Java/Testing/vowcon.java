import java.util.*;
class vowcon
{
    static String s=new String();
    int countVowels(String st)
    {
        int c=0;
        for(int i=0;i<st.length();i++)
        {
            char ch=st.charAt(i);
            if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
                c++;
        }
        return c;
    }

    void modify()
    {
        s+=" ";
        String w="";
        for(int i=0;i<s.length();i++)
        {
            char ch=s.charAt(i);
            if(ch==' ')
            {
                int v=countVowels(w);
                int c=w.length()-v;
                System.out.print(w+"\t");
                for(int j=0;j<v;j++)
                {
                    System.out.print("V");
                }
                System.out.println();
                for(int k=0;k<c;k++)
                {
                    if(k==0)
                    {
                        System.out.print("\tC");
                    }
                    else
                    {
                        System.out.print("C");
                    }
                }
                System.out.println();
                w="";
            }
            else
            {
                w+=ch;
            }
        }
    }

    public static void main(String[]args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the sentence: ");
        s=sc.nextLine().trim().toUpperCase();

        char l=s.charAt(s.length()-1);
        if(l=='.'|| l=='?'|| l=='!')
        {
            s=s.substring(0,s.length()-1);
            vowcon obj=new vowcon();
            obj.modify();
        }
        else
        {
            System.out.println("INVALID INPUT!!");
            System.exit(0);
        }
    }
}