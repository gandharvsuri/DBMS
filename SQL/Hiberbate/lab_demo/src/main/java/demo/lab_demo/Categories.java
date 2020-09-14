package demo.lab_demo;

import java.util.Set;

import javax.persistence.CascadeType;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.JoinTable;
import javax.persistence.ManyToMany;
import javax.persistence.Table;

@Entity
@Table(name="Categories")
public class Categories
{
	@Id
	@Column(name="catid")
	 private int categoryId;
	@Column(name="catname",length=10)
	private String categoryName;
	@ManyToMany(targetEntity=Item.class,cascade=CascadeType.ALL)
	@JoinTable(name="categories_item",joinColumns=@JoinColumn(name="cat_id_fk",referencedColumnName="catid"),inverseJoinColumns=@JoinColumn(name="item_id_fk",referencedColumnName="itemid"))
	private Set items;

	public int getCategoryId() {
		return categoryId;
	}
	public void setCategoryId(int categoryId) {
		this.categoryId = categoryId;
	}
	public Set getItems() {
		return items;
	}
	public void setItems(Set items) {
		this.items = items;
	}
	public String getCategoryName() {
		return categoryName;
	}
	public void setCategoryName(String categoryname) {
		this.categoryName = categoryname;
	}

}
