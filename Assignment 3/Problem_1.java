import java.util.Scanner;

 class Problem_1 {

    int add(int a,int b){
        return a+b;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter First Number");
        int num_1=sc.nextInt();

        System.out.println("Enter Second Number");
        int num_2=sc.nextInt();

        Problem_1 obj = new Problem_1();

        System.out.println("Sum of Two Numbers: "+ obj.add(num_1,num_2));
    }
    
}
