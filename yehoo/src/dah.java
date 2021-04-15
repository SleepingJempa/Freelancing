import java.util.Scanner;

public class dah {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= 2*n-2*i; j++) {
                System.out.print(" ");
            }
            for(int j = 1; j <= i; j++) {
                System.out.print(j);
                System.out.print(" ");
            }
            for(int j = i-1; j >= 1; j--) {
                System.out.print(j);
                System.out.print(" ");
            }
            System.out.println("");
        }
    }
}
