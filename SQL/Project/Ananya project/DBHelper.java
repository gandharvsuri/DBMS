
import java.util.*;
import java.sql.*;
import java.time.*;
import java.util.Date;

public class DBHelper {
    //STEP 2a: Set JDBC driver name and database URL
    static final String JDBC_DRIVER = "com.mysql.cj.jdbc.Driver";  
    static final String DB_URL = "jdbc:mysql://localhost/library";

    //  Database credentials
    static final String USER = "root";
    static final String PASS = "*Rasika0507";

    static Scanner sc = new Scanner(System.in); 

    static Connection conn = null;
    static Statement stmt = null;
    static ResultSet rs;

    static int bookID = 0 ;
   
    public void initialize() {
        
        try{
            //STEP 2b: Register JDBC driver
            Class.forName(JDBC_DRIVER);

            //STEP 3: Open a connection
            System.out.println("Connecting to database...");
            conn = DriverManager.getConnection(DB_URL,USER,PASS);

            //STEP 4: Execute a query
            System.out.println("Creating statement...");
            stmt = conn.createStatement();
            
        }catch(SQLException se){
            //Handle errors for JDBC
            se.printStackTrace();
        }catch(Exception e){
            //Handle errors for Class.forName
            e.printStackTrace();
        }
    }//end main


    public void addBook(){
        
        System.out.println("Enter name:");
        String name = sc.nextLine();

        System.out.println("Enter genre:");
        String genre = sc.nextLine();

        System.out.println("Enter num of copies:");
        int copies = sc.nextInt();

        Book b = new Book(name,genre,copies);
        //STEP 4: Execute a query

        System.out.println("created book!");

        try{
            String sql;
            sql = "insert into Book values (" + String.valueOf("'" + b.getBook_id()) + "'" + "," + "null" + "," + "null" + "," + "'" + b.getGenre() + "'" + "," + "'" +b.getAuthor() + "'" + "," + "'" +b.getPublication() +"'" + "," + "'" +b.getName() +"'" + "," + "'" + String.valueOf(copies) +"'" + ")";
            System.out.println(sql);
            stmt.executeUpdate(sql);
            System.out.println("Table updated!");
        }
        catch(SQLException se){
            //Handle errors for JDBC
            se.printStackTrace();
        }catch(Exception e){
            //Handle errors for Class.forName
            e.printStackTrace();
        }
        //STEP 6: Clean-up environment
    }

    public void displayBook(){
        
        System.out.println("Enter genre (or All to display all books):");
        String genre = sc.nextLine();

        //STEP 4: Execute a query

        try{
            String sql;
            if(!(genre=="All")) sql = "select * from  Book";
            else sql = "select * from Book where genre = " + genre;
            System.out.println(sql);
            ResultSet rs = stmt.executeQuery(sql);
            while(rs.next()){
                //Retrieve by column name
                String name  = rs.getString("name");
                System.out.println(name);
            }
        }
        catch(SQLException se){
            //Handle errors for JDBC
            se.printStackTrace();
        }catch(Exception e){
            //Handle errors for Class.forName
            e.printStackTrace();
        }
        //STEP 6: Clean-up environment
    }

    public void payFees(){

        System.out.println("enter cash to be paid");
        float cash = sc.nextFloat();
        
        System.out.println("enter member id");
        int mem_id = sc.nextInt();

        //STEP 4: Execute a query

        try{
            String sql;
            sql = "select monthly_fee from Subscription,`Member` where Subscription.member_id = " + String.valueOf(mem_id);
            System.out.println(sql);
            ResultSet rs = stmt.executeQuery(sql);
            //Retrieve by column name
            int fee = 0;
            while(rs.next()){
                fee  = rs.getInt("monthly_fee");
            }
            if(cash < fee) {
                System.out.print("Fees to be paid :");
                System.out.println(fee);
            }
            else{
                LocalDate new_date = LocalDate.now().plusMonths(1);
                System.out.println(new_date);
                sql = "UPDATE `Subscription` SET end_date = Date('" + new_date + "') where member_id = " + String.valueOf(mem_id);
                System.out.println(sql);
                stmt.executeUpdate(sql);
                System.out.println("Table updated!");
            }
        }
        catch(SQLException se){
            //Handle errors for JDBC
            se.printStackTrace();
        }catch(Exception e){
            //Handle errors for Class.forName
            e.printStackTrace();
        }
        //STEP 6: Clean-up environment
    }

    public void getNumOfCopies(){
        
        System.out.println("Enter name of book:");
        String name = sc.nextLine();

        //STEP 4: Execute a query

        try{
            String sql;
            sql = "select copies_left from Book where name = '" + name + "'";
            System.out.println(sql);
            ResultSet rs = stmt.executeQuery(sql);
            while(rs.next()){
                //Retrieve by column name
                int copies  = rs.getInt("copies_left");
                System.out.println(copies);
            }
        }
        catch(SQLException se){
            //Handle errors for JDBC
            se.printStackTrace();
        }catch(Exception e){
            //Handle errors for Class.forName
            e.printStackTrace();
        }
        //STEP 6: Clean-up environment
    }

    public void borrowBook(){

        System.out.println("Enter name:");
        String name = sc.nextLine();
        
        System.out.println("Enter id:");
        int mem_id = sc.nextInt();

        //STEP 4: Execute a query

        Book_Issue_Details d = new Book_Issue_Details(name,mem_id);

        System.out.println("created book issue!");

        try{
            String sql;
            sql = "insert into Book_Issue_Details values("+d.getBook_details_id() + "," + "'" + d.getBorrow_date()+"'" + "," + "'" + d.getReturn_date()+"'" + "," + "'" + d.getBook_name()+"'"+ "," + "'" + d.getMember_id()+"'" + "," + "null" + ")";
            System.out.println(sql);
            stmt.executeUpdate(sql);
            System.out.println("Table updated!");
        }
        catch(SQLException se){
            //Handle errors for JDBC
            se.printStackTrace();
        }catch(Exception e){
            //Handle errors for Class.forName
            e.printStackTrace();
        }
        //STEP 6: Clean-up environment
    }

    public void terminate(){
        try{
            if(stmt!=null)
                stmt.close();
        }catch(SQLException se2){
        }// nothing we can do
        try{
            if(conn!=null)
                conn.close();
        }catch(SQLException se){
            se.printStackTrace();
        }//end finally try
    }
}//end FirstExample
