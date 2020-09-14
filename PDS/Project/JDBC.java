//STEP 1. Import required packages
import java.util.*;
import java.sql.*;
import java.time.*;

public class JDBC {
   //STEP 2a: Set JDBC driver name and database URL
   static final String JDBC_DRIVER = "com.mysql.cj.jdbc.Driver";  
   static final String DB_URL = "jdbc:mysql://localhost/Garagedb";

   //  Database credentials
   static final String USER = "root";
   static final String PASS = "G0daVAr1%";
   
   Connection conn = null;
   Statement stmt = null;
   Statement upd = null;
   static Scanner sc = new Scanner(System.in); 

    public void Initialize(){
        try{
            //STEP 2b: Register JDBC driver
            Class.forName(JDBC_DRIVER);            
            //STEP 3: Open a connection
            System.out.println("Connecting to database...");
            conn = DriverManager.getConnection(DB_URL,USER,PASS);            
            //STEP 4: Execute a query
            System.out.println("Creating statement...");
            stmt = conn.createStatement(); 
            upd = conn.createStatement();
            System.out.println("#######DONE####"); 
        }
        catch(SQLException se){
            //Handle errors for JDBC
            se.printStackTrace();
        }
        catch(Exception e){
            //Handle errors for Class.forName
            e.printStackTrace();
        }
    }

    public void uninitialize(){
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
        }
    }

    public void addItem(){
        System.out.println("Item id ");
        int id = sc.nextInt();
        sc.nextLine();

        System.out.println("Item name ");
        String name = sc.nextLine();

        System.out.println("Item Category ");
        String category = sc.nextLine();

        System.out.println("Item MRP ");
        Float mrp = sc.nextFloat();    
        sc.nextLine();

        System.out.println("Part number");
        String partNo = sc.nextLine();

        System.out.println("Item Vehicle Type ");
        String type = sc.nextLine();

        System.out.println("Please enter you owner id to authenticate.");
        int o_id = sc.nextInt();

        try{
            String sql, auth_sql;
            sql = "insert into item values (" +id+ ",\"" + name + "\"" +",\""+ category + "\"," + mrp + ",\"" + partNo + "\"" + ",\""+ type + "\","+null+ ")"+";";
            auth_sql = "select owner_id from owner where owner_id = "+o_id+";";
            System.out.println(auth_sql);
            ResultSet rs = stmt.executeQuery(auth_sql);
            while(rs.next()){
                //Retrieve by column name
                int owner_id  = rs.getInt("owner_id");
                if(owner_id == o_id){
                    System.out.println(auth_sql);
                    stmt.executeUpdate(sql);
                }

                else{
                    System.out.println("Authentication failed");
                }
            }
        }
        catch(SQLException se){
            //Handle errors for JDBC
            se.printStackTrace();
        }catch(Exception e){
            //Handle errors for Class.forName
            e.printStackTrace();
        }
    }

    public void removeItem(){
        System.out.println("Item id ");
        int id = sc.nextInt();

        System.out.println("Please enter your owner id to authenticate.");
        int o_id = sc.nextInt();


        try{
            String sql,auth_sql;
            sql = "delete from item where item_id = "+id+";";
            auth_sql = "select owner_id from owner where owner_id = "+o_id+";";
            System.out.println(auth_sql);
            ResultSet rs = stmt.executeQuery(auth_sql);
            while(rs.next()){
                //Retrieve by column name
                int owner_id  = rs.getInt("owner_id");
                if(owner_id == o_id){
                    System.out.println(sql);
                    upd.executeUpdate(sql);
                }

                else{
                    System.out.println("Authentication failed");
                }
            }
        }
        catch(SQLException se){
            //Handle errors for JDBC
            se.printStackTrace();
        }catch(Exception e){
            //Handle errors for Class.forName
            e.printStackTrace();
        }

    }

    public void computeBill(){

        String sql;
        System.out.println("Enter Bill number: ");
        int bno = sc.nextInt();

        try{
            sql = "select * from item where bill_no = "+bno+";";
            System.out.println(sql);
            ResultSet rs = stmt.executeQuery(sql);
            int bill_sum = 0;
            while(rs.next()){
                String name = rs.getString("item_name");
                int price = rs.getInt("mrp");
                bill_sum += price;
                System.out.println(name + ":"+ price);
            
            }
            System.out.println("Total : "+ bill_sum);
        }
        catch(SQLException se){
            //Handle errors for JDBC
            se.printStackTrace();
        }catch(Exception e){
            //Handle errors for Class.forName
            e.printStackTrace();
        }
    }

    public void sellItem(){
        System.out.println("Item id ");
        int id = sc.nextInt();
        sc.nextLine();

        System.out.println("Item name ");
        String name = sc.nextLine();

        System.out.println("Item Category ");
        String category = sc.nextLine();

        System.out.println("Item MRP ");
        Float mrp = sc.nextFloat();     
        sc.nextLine();

        System.out.println("Part number");
        String partNo = sc.nextLine();

        System.out.println("Item Vehicle Type ");
        String type = sc.nextLine();

        System.out.println("Please enter your customer id to authenticate.");
        int c_id = sc.nextInt();

        try{
            String sql, auth_sql;
            sql = "insert into item values (" +id+ ",\"" + name + "\"" +",\""+ category + "\"," + mrp + ",\"" + partNo + "\"" + ",\""+ type + "\","+null+ ")";
            auth_sql = "select cust_id from customer where cust_id = "+c_id+";";
            System.out.println(auth_sql);
            ResultSet rs = stmt.executeQuery(auth_sql);
            while(rs.next()){
                //Retrieve by column name
                int cust_id  = rs.getInt("cust_id");
                if(cust_id == c_id){
                    System.out.println(sql);
                    upd.executeUpdate(sql);
                }

                else{
                    System.out.println("Authentication failed");
                }
            }
        }
        catch(SQLException se){
            //Handle errors for JDBC
            se.printStackTrace();
        }catch(Exception e){
            //Handle errors for Class.forName
            e.printStackTrace();
        }
    }

    public void buyItem(){

        System.out.println("Item name ");
        String name = sc.nextLine();

        System.out.println("Please enter your customer id.");
        int c_id = sc.nextInt();

        try{
            String sql, auth_sql;
            sql = "update item set bill_no = "+c_id+" where item_name =' "+name +"';";
            auth_sql = "select cust_id from customer where cust_id = "+c_id+";";
            System.out.println(auth_sql);
            ResultSet rs = stmt.executeQuery(sql);
            
            while(rs.next()){
                int cust_id  = rs.getInt("cust_id");
                if(cust_id == c_id){
                    System.out.println(auth_sql);
                    upd.executeUpdate(sql);
                }

                else{
                    System.out.println("Authentication failed");
                }
            }
        }
        catch(SQLException se){
            //Handle errors for JDBC
            se.printStackTrace();
        }catch(Exception e){
            //Handle errors for Class.forName
            e.printStackTrace();
        }
    }
    


    

}//end FirstExample
