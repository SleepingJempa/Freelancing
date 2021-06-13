import java.util.Scanner;

public class Teaming {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int a = 0;

        for(int i = 0; i < 3; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            a += Math.min(x, y);
        }

        System.out.println(a);
    }
}
