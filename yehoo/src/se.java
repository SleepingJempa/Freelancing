import java.util.Scanner;

public class se {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        while(n > 0) {
            System.out.println(n % 10);
            n /= 10;
        }
    }
}
