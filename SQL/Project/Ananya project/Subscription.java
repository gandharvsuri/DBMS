import java.util.*;

public class Subscription {
	private int subscription_id ;
	
	private Date start_date;
	
	private Date end_date;
	
	private float monthly_fee;
	
	private float reg_fee;
	
	private String type;
	
	public int getSubscription_id() {
		return subscription_id;
	}
	public void setSubscription_id(int subscription_id) {
		this.subscription_id = subscription_id;
	}
	public Date getStart_date() {
		return start_date;
	}
	public void setStart_date(Date start_date) {
		this.start_date = start_date;
	}
	public Date getEnd_date() {
		return end_date;
	}
	public void setEnd_date(Date end_date) {
		this.end_date = end_date;
	}
	public float getMonthly_fee() {
		return monthly_fee;
	}
	public void setMonthly_fee(float monthly_fee) {
		this.monthly_fee = monthly_fee;
	}
	public float getReg_fee() {
		return reg_fee;
	}
	public void setReg_fee(float reg_fee) {
		this.reg_fee = reg_fee;
	}
	public String getType() {
		return type;
	}
	public void setType(String type) {
		this.type = type;
	}
	public void setParent(Member parent) {
		this.parent = parent;
	}
}