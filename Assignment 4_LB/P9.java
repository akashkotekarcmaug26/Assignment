import java.util.Arrays;
import java.util.Scanner;

public class P9 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] a = new int[5];

        System.out.println("Enter 5 integers:");

        for (int i = 0; i < 5; i++) {
            a[i] = sc.nextInt();
        }
        Arrays.sort(a);
        
            System.out.println("Largest Numnber in the Array: "+a[4]);
        
    }
}