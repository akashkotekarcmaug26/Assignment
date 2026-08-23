import java.util.Scanner;

public class Wish {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Time:");
        String time = sc.nextLine();

        String[] words = time.split(" ");


        int hour = Integer.parseInt(words[0]);
        String M = words[1].toUpperCase();

        System.out.println("Time is: " + hour + " " + M);

        if (hour < 1 || hour > 12 || !(M.equals("AM") || M.equals("PM"))) {
            System.out.println("Invalid Time");
        }
        else if (M.equals("AM")) {
            if (hour >= 5 && hour < 12) 
                System.out.println("Good Morning");
             else 
                System.out.println("Good Night");
            
            }
        else {
            if (hour == 12 || hour < 5) 
                System.out.println("Good Afternoon");
             else if (hour >= 5 && hour <= 9) 
                System.out.println("Good Evening");
             else 
                System.out.println("Good Night");
             
        
        }

        
    }
}