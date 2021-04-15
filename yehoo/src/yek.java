import java.util.ArrayList;
import java.util.Scanner;

public class yek {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = 10;

        int arr[] = new int[n];

        for(int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        float avg = 0;

        for(int i = 0; i < n; i++) {
            avg += arr[i];
        }

        avg /= n;

        for(int i = 0; i < n; i++) {
            System.out.println(avg);
        }
    }
}
