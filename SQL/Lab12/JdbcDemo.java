//STEP 1. Import required packages
import java.sql.*;
/*************
// Save this in a separate class class Employee.java
public class Employee{
	String first_name;
	String last_name;
	public Employee(String fname, String lname){first_name=fname;last_name=lname;};
	public void setFname(String fname){first_name=fname;}
	public void setLname(String lname){last_name=lname;}
}
*********************/

public class JdbcDemo {
   //STEP 2a: Set JDBC driver name and database URL
   static final String JDBC_DRIVER = "com.mysql.cj.jdbc.Driver";  
   static final String DB_URL = "jdbc:mysql://localhost/companydb";

   //  Database credentials
   static final String USER = "root";
   static final String PASS = "13042012";
   
   public static void main(String[] args) {
   Connection conn = null;
   Statement stmt = null;
   try{
      //STEP 2b: Register JDBC driver
      Class.forName(JDBC_DRIVER);

      //STEP 3: Open a connection
      System.out.println("Connecting to database...");
      conn = DriverManager.getConnection(DB_URL,USER,PASS);

      //STEP 4: Execute a query
      System.out.println("Creating statement...");
      stmt = conn.createStatement();
      String sql;
      sql = "SELECT fname, lname from employee";
      ResultSet rs = stmt.executeQuery(sql);

      //STEP 5: Extract data from result set
      while(rs.next()){
         //Retrieve by column name
         String fname  = rs.getString("fname");
         String lname = rs.getString("lname");

         //Display values
         System.out.print("fname: " + fname);
         System.out.println(", lname: " + lname);
		 
		 // Create Employee object if you have saved the Employee class in a separate java file
		 // Employee e = new Employee(fname,lname);
		 // Save or pass around e object as needed
      }
      //STEP 6: Clean-up environment
      rs.close();
      stmt.close();
      conn.close();
   }catch(SQLException se){
      //Handle errors for JDBC
      se.printStackTrace();
   }catch(Exception e){
      //Handle errors for Class.forName
      e.printStackTrace();
   }finally{
      //finally block used to close resources
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
   }//end try
   System.out.println("Goodbye!");
}//end main
}//end FirstExample
