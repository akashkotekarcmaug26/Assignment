import java.util.Arrays;
import java.util.Scanner;

public class P12 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] a = new int[5];

        System.out.println("Enter 5 integers:");

        for (int i = 0; i < 5; i++) {
            a[i] = sc.nextInt();
        }
        Arrays.sort(a);
        
        for(int num: a){
            System.out.print(num+" ");
        }
        
    }
}