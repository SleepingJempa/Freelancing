import java.util.ArrayList;
import java.util.Scanner;

public class haft {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = 5;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                System.out.print(i*j);
                System.out.print("\t");
            }
            System.out.println("");
        }
    }
}
