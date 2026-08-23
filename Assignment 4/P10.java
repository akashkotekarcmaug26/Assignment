import java.util.Scanner;

public class P10 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] a =new int[5];
        int sum =0;
        System.out.println("Enter 5 integers:");

        for (int i = 0; i < 5; i++) {
            a[i] = sc.nextInt();
        }

        for (int num : a) {
            sum+=num;
        }
        System.out.println("Avg of All Elements: "+sum/5);
    }
}