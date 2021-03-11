import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();

        for(int i = 0; i <= (n)/2; i++) {
            if (i == 0 || i == n-1) {
                for(int j = 0; j < n; j++) {
                    System.out.print('*');
                }
            } else {
                for(int j = 0; j < (n - 2 * i + 1)/2; j++) {
                    System.out.print('*');
                }
                for(int j = 0; j < 2 * i - 1; j++) {
                    System.out.print(' ');
                }
                for(int j = 0; j < (n - 2 * i + 1)/2; j++) {
                    System.out.print('*');
                }
            }
            System.out.println();
        }

        for(int i = (n)/2-1; i >= 0; i--) {
            if (i == 0 || i == n-1) {
                for(int j = 0; j < n; j++) {
                    System.out.print('*');
                }
            } else {
                for(int j = 0; j < (n - 2 * i + 1)/2; j++) {
                    System.out.print('*');
                }
                for(int j = 0; j < 2 * i - 1; j++) {
                    System.out.print(' ');
                }
                for(int j = 0; j < (n - 2 * i + 1)/2; j++) {
                    System.out.print('*');
                }
            }
            System.out.println();
        }
    }
}
