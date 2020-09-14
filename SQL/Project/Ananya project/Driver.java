import java.util.* ;

public class Driver{

    public static void printOptions(){
        System.out.println("Welcome to the library! Please enter option");
        System.out.println("1: Display Available Books");
        System.out.println("2: Pay Fees");
        System.out.println("3: Check Book Availability");
        System.out.println("4: Borrow Book");
        System.out.println("5: Add Book");
        System.out.println("6: Exit");
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in); 

        DBHelper db = new DBHelper();

        db.initialize();

        printOptions();

        int option = sc.nextInt();
        while(option != 6){
            switch(option){
                case 1: 
                    db.displayBook();
                    break ;
                case 2:
                    db.payFees();
                    break;
                case 3:
                    db.getNumOfCopies();
                    break;
                case 4:
                    db.borrowBook();
                    break;
                case 5:
                    db.addBook();
                    break;
                case 6:
                    System.exit(0);
                default:
                    System.out.println("Invalid option");
                    break;
            }
            printOptions();
            option = sc.nextInt();
        }
        db.terminate();
    }

}