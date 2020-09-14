package demo.lab_demo;


import java.util.Set;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.ManyToMany;
import javax.persistence.Table;

@Entity
@Table(name="items")
public class Item
{
	@Id
	@Column(name="itemid")
	private int itemId;
	@Column(name="itemname",length=10)
	private String itemName;
	@ManyToMany(targetEntity=Categories.class,mappedBy="items")
	private Set  categories;

	public Set getCategories() {
		return categories;
	}
	public void setCategories(Set  categories) {
		this.categories = categories;
	}
	public int getItemId() {
		return itemId;
	}
	public void setItemId(int itemId) {
		this.itemId = itemId;
	}
	public String getItemName() {
		return itemName;
	}
	public void setItemName(String itemName) {
		this.itemName = itemName;
	}
}
