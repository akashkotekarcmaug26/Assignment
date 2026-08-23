import java.util.Scanner;

public class P11 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] a =new int[5];
        int pos =0;
        int neg =0;
        System.out.println("Enter 5 integers:");

        for (int i = 0; i < 5; i++) {
            a[i] = sc.nextInt();
        }

        for (int num : a) {
            if(num>0)
                pos++;
            if(num<0)
                neg++;
        }
        System.out.println("Number of Positive Numbers: "+ pos + "\n Number of negative numbers: "+neg);
    }
}