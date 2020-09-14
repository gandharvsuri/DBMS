import java.util.* ;

public class GarageSystem{

    public static void instructions(){
        System.out.println("Please select one of the following oprions:");
        System.out.println("1, to add an item to the store.");
        System.out.println("2, to remove an item from the store.");
        System.out.println("3, to sell an item.");
        System.out.println("4, to add an item to the cart.");
        System.out.println("5, to compute your bill.");
        System.out.println("6, exit the store.");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); 

        JDBC db = new JDBC();

        db.Initialize();

        instructions();

        int option = sc.nextInt();
        while(option != 6){
            switch(option){
                case 1: 
                    db.addItem();
                    break ;
                case 2:
                    db.removeItem();
                    break;
                case 3:
                    db.sellItem();
                    break;
                case 4:
                    db.buyItem();
                    break;
                case 5:
                    db.computeBill();
                    break;
                case 6:
                    System.exit(0);
                default:
                    System.out.println("Invalid option");
                    break;
            }
            instructions();
            option = sc.nextInt();
        }
        db.uninitialize();

    }
}