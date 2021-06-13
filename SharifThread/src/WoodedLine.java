import java.util.Scanner;

public class WoodedLine {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int a = scanner.nextInt();
        int b = scanner.nextInt();

        int x = Math.min(n, m);
        int y = Math.max(a, b);

        int r = (x + y - 1) / y;

        System.out.println(r);
    }
}
