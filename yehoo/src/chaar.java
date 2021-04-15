import java.util.ArrayList;
import java.util.Scanner;

public class chaar {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        int sum = 0;

        for(int i = 1; i <= n; i++) {
            if (n % i == 0) {
                sum += i;
            }
        }

        System.out.println(sum);
    }
}
