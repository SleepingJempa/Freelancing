import java.util.ArrayList;
import java.util.Scanner;

public class dow {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        int fc = 1;

        for(int i = 0; i < n; i++) {
            fc *= i+1;
        }

        for(int i = 0; i < n; i++) {
            System.out.println(fc);
        }
    }
}
