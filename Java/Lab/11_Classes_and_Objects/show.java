class A { // Class
    int a, b, c; // Definition

    int add(int x, int y, int z) {
        return x + y + z;
    }

    int multiply(int x, int y, int z) {
        return x * y * z;
    }

    A(int a, int b, int c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }
}

class show {
    public static void main(String args[]) {
        A obj = new A(10, 12, 20); // Object creation

        System.out.println(obj.add(obj.a, obj.b, obj.c)); // accessing method using object

        System.out.println(obj.multiply(obj.a, obj.b, obj.c)); // accessing method using object
    }
}