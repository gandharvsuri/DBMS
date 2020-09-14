package demo.lab_demo;

import javax.persistence.Entity;
import javax.persistence.Id;
@Entity

public class exam {
	
	@Id
	private int n;
	

	public int getN() {
		return n;
	}

	public void setN(int n) {
		this.n = n;
	}
	

	
		
}
