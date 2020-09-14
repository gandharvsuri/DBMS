import java.lang.*;

public class Student{
	int rollno;
	String name;
	public Student (String s, int r){ rollno = r; name = s; }
	public String getName() { return name; }
	public void setName(String s){ name = s; }
	public int getRollNo() { return rollno; }
	public void setRollNo(int s){ rollno = s; }
};

