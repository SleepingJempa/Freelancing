public class Start {

    public static void main(String[] args) {
        System.out.println("Elham is at Rome");

        int x = 3;
        String str = "Elham";
        boolean b = false;
        float f = 3.2f;
        double d = 3.2F;
        int t = (int) 3.9; // Casting => 3

        char c = '\n';

        int s = 3 + 2; // + - / * %

        /**
         * ^: bit-wise xor => 00,11 => 0    10,01=>1
         * |: bit-wise or  => at least one 1 => 1 ow => 0
         * &: bit-wise and => both 1 => 1 ow = > 0
         *
         * Bit applications:
         *  -> Binary exponential a ** b
         */

        int bit = 3 ^ 2;


//        if (/* Condition */) {
//            // Do sth
//        } else {
//            // Do something else
//        }

        int a = 4;
        a += (1 > 3 ? 1 : -1); // short-hand from of if
        // syntax knowledge
        System.out.println("A is " + a);

        // 1. IF
        boolean day = false;
        if (! day) {
            System.out.println("It's day");
        } else {
            System.out.println("It's night");
        }

        if (3 * 2 < 10) {
            System.out.println("haha");
        }

        // 2. LOOP
        int n = 10;
        for(int i = 0, j = 3; i < n; i += 2, j++) {
            System.out.println(i + j);
        }

//        AnScaryObject obj = new AnScaryObject();
//        for ( 1 ; 2 ; 3 )
//        for(AnScary iterator = obj; iterator.good(); iterator.next()) {
//            // DO sthm
//        }

        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 3; j++) {
//                if ((i+j) % 2 == 0) {
//                    System.out.print("B");
//                } else {
//                    System.out.print("W");
//                }
                System.out.print(((i+j) % 2 == 0 ? "B" : "W"));
            }
            System.out.println();
        }

    }


}
