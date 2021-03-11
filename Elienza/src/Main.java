public class Main {

    public static void main(String[] args) {

        Human elham = new Human("elham");
//        elham.name = "alireza";

//        String s = "abc";
//        changeString(s);
//        System.out.println(s);
//
//        int n = 3;
//        addOne(n);
//        System.out.println(n);
//
//        changeName(elham);
//        System.out.println(elham.getName());

    }

    public static void changeString(String s) {
        s = "cba";
    }

    public static void addOne(int x) {
        x++;
        // Pass by value - low cost
    }

    public static void changeName(Human human) {
        human.setName("alireza");
        // Pass by reference - dynamic high cost
    }

}
