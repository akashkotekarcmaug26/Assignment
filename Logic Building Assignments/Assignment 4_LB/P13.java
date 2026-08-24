import java.util.Arrays;
import java.util.Scanner;

public class P13 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Integer[] a =new Integer[5];

        System.out.println("Enter 5 integers:");

        for (int i = 0; i < 5; i++) {
            a[i] = sc.nextInt();
        }

        System.out.println("Enter Number to be Found");
        int f= sc.nextInt();

        if(Arrays.asList(a).contains(f))
            System.out.println("Found");
        else
            System.out.println("Not Found");
    }
}