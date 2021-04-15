import java.util.ArrayList;
import java.util.Scanner;

public class shish {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = 10;

        int min = scanner.nextInt();

        for(int i = 1; i < n; i++) {
            int x = scanner.nextInt();
            if (x < min) {
                min = x;
            }
        }

        System.out.println(min);
    }
}
