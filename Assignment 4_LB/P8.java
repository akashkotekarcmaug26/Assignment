import java.util.Scanner;

public class P8 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] a = new String[5];

        System.out.println("Enter 5 Names:");

        for (int i = 0; i < 5; i++) {
            a[i] = sc.next();
        }

        for (String num : a) {
            System.out.print(num + " ");
        }
    }
}