package productdatabase;

import java.sql.*;
import java.util.Scanner;

public class ProductDatabase{

    static Connection con;
    static Statement st;
    static ResultSet rs;
    static Scanner scan = new Scanner(System.in);
    
    static void openDB(){
        try{
            Class.forName("org.apache.derby.jdbc.ClientDriver");
            con = DriverManager.getConnection("jdbc:derby://localhost:1527/products","suraj","suraj");
            st = con.createStatement();
        }catch(ClassNotFoundException | SQLException e){
            System.out.println(e);
        }
    }
    
    static void closeDB(){
        try{
            st.close();
            con.close();
        }catch(SQLException e){
            System.out.println(e);
        }
    }
    
    static void insert(){
        try{
            openDB();
            System.out.println("\nInsert:");
            System.out.print(" Enter Product ID : ");
            int pID = scan.nextInt();
            System.out.print("\n Enter Product Name : ");
            String pName = scan.next();
            System.out.print("\n Enter Unit Price : ");
            double unitPrice = scan.nextDouble();
            System.out.print("\n Enter Supplier Name : ");
            String sName = scan.next();
            
            String s = "insert into products (p_id, p_name, unit_price, supplier_name) values("+pID+",'"+pName+"',"+unitPrice+",'"+sName+"')";
            
            int n = st.executeUpdate(s);
            
            if(n>0){
                System.out.println("\nRecord successfully inserted.");
            }
            else{
                System.out.println("\nRecord insertion failed!");
            }
            
            closeDB();
        }catch(SQLException e){
            System.out.println(e);
        }
    }
    
    static void deleteByID(){
        try{
            openDB();
            System.out.print("\nDelete by Product ID:\n");
            System.out.print("\n Enter the ID of the product you want to delete: ");
            int pId = scan.nextInt();
            String s = "delete from products where p_id="+pId+"";
            
            int n = st.executeUpdate(s);
            
            if(n>0){
                System.out.println("\nRecord successfully deleted.");
            }
            else{
                System.out.println("\nRecord deletion failed!");
            }
            
            closeDB();
        }catch(SQLException e){
            System.out.println(e);
        }
    }
    
    static void searchBySupplierName(){
        try{
            openDB();
            System.out.print("\nSearch by Supplier's Name:\n");
            System.out.print("\n Enter Suppler's Name: ");
            String sName = scan.next();
            
            String s = "select * from products where supplier_name = '"+sName+"'";
            
            rs = st.executeQuery(s);
            int count = 0;
            
            while(rs.next()){
                count++;
                System.out.println("\n "+rs.getInt(1)+" "+rs.getString(2)+" "+rs.getDouble(3)+" "+rs.getString(4)+"\n");
            }
            
            if(count==0){
                System.out.println("\nNo records found!\n");
            }
            
            closeDB();
        }catch(SQLException e){
            System.out.println(e);
        }
    }
    
    static void searchByUnitPrice(){
        try{
            openDB();
            System.out.print("\nSearch by Unit Price:\n");
            
            String s = "select * from products where (unit_price >= 1000.0 AND unit_price <= 4000.0)";
            
            rs = st.executeQuery(s);
            
            int count = 0;
            
            while(rs.next()){
                count++;
                System.out.println("\n "+rs.getInt(1)+" "+rs.getString(2)+" "+rs.getDouble(3)+" "+rs.getString(4)+"\n");
            }
            
            if(count==0){
                System.out.println("\nNo records found!\n");
            }
            
            closeDB();
        }catch(SQLException e){
            System.out.println(e);
        }
    }
    
    public static void main(String[] args) {
        int choice;
        
        do{
            System.out.print("Database Products:\n");
            System.out.print(" 1. Insert a product.\n 2. Delete a specified product.\n 3. Search and Display the product details based on supplier name.\n 4. Search and Display the product which has unit price range between Rs. 1000 to Rs. 4000\n 5. Exit.");
            System.out.print("\n Enter your choice: ");
            choice = scan.nextInt();
            
            switch(choice){
                case 1: insert();
                        break;
                
                case 2: deleteByID();
                        break;
                        
                case 3: searchBySupplierName();
                        break;
                        
                case 4: searchByUnitPrice();
                        break;
                        
                case 5: break;
                
                default: System.out.println("Invalid choice!");
            }
        }while(choice != 5);
    }
    
}
