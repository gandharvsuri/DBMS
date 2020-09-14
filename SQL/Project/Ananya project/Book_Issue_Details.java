import java.util.*;
import java.time.*;

public class Book_Issue_Details {

	private int book_details_id;
	
	private String borrow_date;
	
	private String return_date;

	private  int member_id;

	private String book_name;

	static int count = 0;

	public Book_Issue_Details(String name, int id){
		book_details_id  = count;
		count++;
		borrow_date = String.valueOf(LocalDate.now());
		return_date = String.valueOf(LocalDate.now().plusDays(14));
		book_name = name;
		member_id = id;
		book_name = name;
    }

	public int getBook_details_id() {
		return book_details_id;
	}

	public void setBook_details_id(int book_details_id) {
		this.book_details_id = book_details_id;
	}

	public String getBorrow_date() {
		return borrow_date;
	}

	public void setBorrow_date(String borrow_date) {
		this.borrow_date = borrow_date;
	}

	public String getReturn_date() {
		return return_date;
	}

	public void setReturn_date(String return_date) {
		this.return_date = return_date;
	}

	public String getBook_name() {
		return book_name;
	}

	public void setBook_name(String book_name) {
		this.book_name = book_name;
	}

	public int getMember_id() {
		return member_id;
	}

	public void setMember_id(int member_id) {
		this.member_id = member_id;
	}

}

