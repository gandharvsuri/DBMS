import java.util.*;

public class Book {

	private int book_id;
	
	private int lib_id;

	private String genre;

	private String author;

	private String publication;

	private String name;
	
	private int copies;

	static int count = 0;
	
    
    public Book(String name,String genre,int copies) {
        this.name = name;
        this.genre = genre;
        this.author = name + "_author";
        this.publication = name + "_publication";
		this.book_id = count;
		this.copies = copies;
        count += 1;
    }
	
	public int getBook_id() {
		return book_id;
	}
	public void setBook_id(int book_id) {
		this.book_id = book_id;
	}
	public int getLib_id() {
		return lib_id;
	}
	public void setLib_id(int lib_id) {
		this.lib_id = lib_id;
	}
	public String getGenre() {
		return genre;
	}
	public void setGenre(String genre) {
		this.genre = genre;
	}
	public String getAuthor() {
		return author;
	}
	public void setAuthor(String author) {
		this.author = author;
	}
	public String getPublication() {
		return publication;
	}
	public void setPublication(String publication) {
		this.publication = publication;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}

}