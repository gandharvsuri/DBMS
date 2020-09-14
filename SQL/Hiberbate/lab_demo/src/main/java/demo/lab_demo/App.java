package demo.lab_demo;

//****************************************** Many to Many********************************

import java.util.HashSet;
import java.util.Set;

import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import org.hibernate.cfg.Configuration;

public class App { 

	public static void main(String args[])
	{
		Configuration cfg=new Configuration().configure().addAnnotatedClass(Categories.class).addAnnotatedClass(Item.class);	        
		
			    SessionFactory factory = cfg.buildSessionFactory();
			    Session ses = factory.openSession();	

		Categories c1 = new Categories();
		c1.setCategoryId(1);
		c1.setCategoryName("cat 1");

		Categories c2=new Categories();
		c2.setCategoryId(2);
		c2.setCategoryName("cat 2");

		Item i1=new Item();
		Item i2 = new Item();

		i1.setItemId(101);
		i1.setItemName("item1");

		i2.setItemId(102);
		i2.setItemName("item2");

		Set  s =new HashSet();
		s.add(i1);
		s.add(i2);

		c1.setItems(s);
		c2.setItems(s);

		Transaction tx = ses.beginTransaction();
		ses.save(c1);
		ses.save(c2);
		tx.commit();
		System.out.println("Man to Many using annotations been done...!!!!!");
		ses.close();
	}

}

//import java.util.HashSet;
//import java.util.Set;
//
//import org.hibernate.Session;
//import org.hibernate.SessionFactory;
//import org.hibernate.Transaction;
////import org.hibernate.cfg.AnnotationConfiguration;
//import org.hibernate.cfg.Configuration;
//
//public class App { 
//
//	public static void main(String[] args)
//	{
//
//		Configuration cfg=new Configuration().configure().addAnnotatedClass(Customers.class).addAnnotatedClass(Vendor.class);	        
//		
//			    SessionFactory factory = cfg.buildSessionFactory();
//			    Session session = factory.openSession();		
//
//	      Vendor v=new Vendor();
//	      v.setVendorId(100);
//	      v.setVendorName("java4s");
//
//	      Customers c1=new Customers();
//	      c1.setCustomerId(500);
//	      c1.setCustomerName("customer1");
//
//	      Customers c2=new Customers();
//	      c2.setCustomerId(501);
//	      c2.setCustomerName("customer2");
//
//	      Set s=new HashSet();
//	      s.add(c1);
//	      s.add(c2);
//
//	      v.setChildren(s);
//
//	      Transaction tx=session.beginTransaction();
//	           session.save(v);
//	      tx.commit();
//
//		session.close();
//		System.out.println("One to Many Annotatios Done...!!!!!!");
//		factory.close();
//	}
//
//}

//*********************************** ONE to ONE Mapping***************************

//import org.hibernate.Session;
//import org.hibernate.SessionFactory;
//import org.hibernate.Transaction;
//import org.hibernate.cfg.Configuration;
//
//public class App {
//	public  static  void main(String args[])
//	{
//
//		Configuration cfg=new Configuration().configure().addAnnotatedClass(Student.class).addAnnotatedClass(Address.class);	        
//
//	    SessionFactory factory = cfg.buildSessionFactory();
//	    Session session = factory.openSession();
//
//		Student  s = new Student();
//		s.setStudentId(101);
//		s.setStudentName("James");
//		s.setGrp("mpc");
//
//		Address  ad = new Address();
//		ad.setAddressId(1);
//		ad.setPlace("Carolina");
//
//		ad.setParent(s);
//		Transaction  tx = session.beginTransaction();
//		session.save(ad);
//		tx.commit();
//		session.close();
//		System.out.println("One to One with annotations is done..!!!!");
//		factory.close();
//	}
//}

// SIMPLE ENTRY TO student table

//import org.hibernate.Session;
//import org.hibernate.SessionFactory;
//import org.hibernate.Transaction;
//import org.hibernate.boot.registry.StandardServiceRegistryBuilder;
//import org.hibernate.cfg.Configuration;
//import org.hibernate.service.ServiceRegistry;
//
//
//
//
//public class App 
//{
//    public static void main( String[] args )
//    {
//        //System.out.println( "Hello World!" );
//    	
//    	student std=new student();
//    	std.setId(55);
//    	std.setName("apurva");
//    	
//    	
//    	
//    	
//    	Configuration c = new Configuration().configure().addAnnotatedClass(student.class);
//
//        ServiceRegistry sr = new StandardServiceRegistryBuilder().applySettings(c.getProperties()).build();
//
//
//        SessionFactory sf = c.buildSessionFactory(sr);
//
//        		
//        Session s=sf.openSession();
//        
//        Transaction tx=s.beginTransaction();
//        //s.save(p);
//        s.save(std);
//        tx.commit();
//    	
//    	
//    	//save(std);
//    }
//}
