import java.util.*;

class sum_avg {
    int a[] = new int[5];
    int s = 0;

    void input() {
        System.out.print("Enter array elements (5): ");

        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < a.length; i++) {
            a[i] = sc.nextInt();
        }

        sc.close();
    }

    int sum() {
        for (int i = 0; i < a.length; i++) {
            s += a[i];
        }
        return s;
    }

    double avg() {
        int ssum = sum();
        double average = (double) ssum / a.length;    // hehe , Local Variable ssum & average
        return average;
    }

    public static void main(String[] args) {

        sum_avg obj = new sum_avg();
        obj.input();

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter s for sum of elements \t a for Average of elements \t any other key to quit");
        char c = sc.next().charAt(0);
        sc.close();

        switch (c) {
            case 'a':
                System.out.println("Average of elements is: " + obj.avg());
                break;
            case 's':
                System.out.println("Sum of elements is: " + obj.sum());
                break;
            default:
                System.out.println("Exited");
                break;
        }
    }
}