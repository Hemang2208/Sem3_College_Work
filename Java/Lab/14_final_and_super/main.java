class Vehicle{
    final int maxGears = 6;
    String brand;
    int currentGear;

    Vehicle(String brand) {
        this.brand = brand;
        this.currentGear = 1;
    }
    
    void displayInfo() {
        System.out.println("Brand: " + brand);
        System.out.println("Current Gear: " + currentGear);
    }
    
    void shiftGear(int gear) {
        if (gear <= maxGears && gear > 0) {
            this.currentGear = gear;
            System.out.println("Shifted to gear " + gear);
        } else {
            System.out.println("Invalid gear!");
        }
    }
}

class Car extends Vehicle{
    int horsepower;
    Car (String Brand , int horsepower){
        super(Brand);  // using super to call parent's class's constructor
        this.horsepower = horsepower;
    }

    void displayInfo(){
        System.out.println("Brand: " + brand);
        System.out.println("Current Gear: " + currentGear);
        System.out.println("Horsepower: " + horsepower);
    }
}

class main{
    public static void main(String args[]){
        Car w11 = new Car("tMercedes" , 650);
        w11.displayInfo();
        w11.shiftGear(2);
        w11.displayInfo();
    }
}