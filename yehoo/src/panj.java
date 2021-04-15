import java.util.ArrayList;
import java.util.Scanner;

public class panj {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        if (n == 2) {
            System.out.println("YES");
            return;
        }

        boolean prime = true;

        for(int i = 2; i < n-1; i++) {
            if (n % i == 0) {
                prime = false;
                break;
            }
        }

        if (prime) {
            System.out.println("It's prime");
        } else {
            System.out.println("It's not prime");
        }
    }
}
