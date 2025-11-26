import java.util.Scanner;

class Add {
    int x, y, z, w;

    int add2(int a, int b) {
        return a + b;
    }

    int add3(int a, int b, int c) {
        return a + b + c;
    }

    int add4(int a, int b, int c, int d) {
        return a + b + c + d;
    }

    Add(int x, int y, int z, int w) { // constructor
        this.x = x;
        this.y = y;
        this.z = z;
        this.w = w;
    }
}

class sum {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter 4 numbers : ");
        int p = sc.nextInt();
        int q = sc.nextInt();
        int r = sc.nextInt();
        int s = sc.nextInt();

        Add obj = new Add(p, q, r, s);
        sc.close();

        System.out.println(obj.add2(obj.x, obj.y));

        System.out.println(obj.add3(obj.x, obj.y, obj.z));

        System.out.println(obj.add4(obj.x, obj.y, obj.z, obj.w));
    }
}