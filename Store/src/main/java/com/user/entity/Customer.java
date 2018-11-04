package com.user.entity;

import java.util.List;

import javax.persistence.CascadeType;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.OneToMany;
import javax.persistence.Table;


@Entity
@Table(name="customer")
public class Customer {
	
	@Id
	@GeneratedValue(strategy=GenerationType.IDENTITY)
	private Integer id;
	@Column(name="firstName")
	private String firstName;
	@Column(name="lastName")
	private String lastName;
	@Column(name="City")
	private String City;
	@Column(name="Country")
	private String Country;
	@Column(name="Phone")
	private String phone;
	@Column(name="password")
	private String password;
	
	@Column(name="user_type")
	private Integer type;
	
	@Column(name="email")
	private String email;
	
	
//	@OneToMany(mappedBy="customerID",cascade= CascadeType.ALL,orphanRemoval = true)
//	private List<Order> orders;
	
	
	public Integer getId() {
		return id;
	}
	public void setId(Integer id) {
		this.id = id;
	}
	public String getFirstName() {
		return firstName;
	}
	public void setFirstName(String firstName) {
		this.firstName = firstName;
	}
	public String getLastName() {
		return lastName;
	}
	public void setLastName(String lastName) {
		this.lastName = lastName;
	}
	public String getCity() {
		return City;
	}
	public void setCity(String city) {
		City = city;
	}
	public String getCountry() {
		return Country;
	}
	public void setCountry(String country) {
		Country = country;
	}
	public String getPhone() {
		return phone;
	}
	public void setPhone(String phone) {
		this.phone = phone;
	}
	public String getPassword() {
		return password;
	}
	public void setPassword(String password) {
		this.password = password;
	}
	public String getEmail() {
		return email;
	}
	public void setEmail(String email) {
		this.email = email;
	}
//	public List<Order> getOrders() {
//		return orders;
//	}
//	public void setOrders(List<Order> orders) {
//		this.orders = orders;
//	}
//	
//	public void addOrder(Order order) {
//		orders.add(order);
//		order.setCustomerID(this);
//	}
//	
//	public void removeOrder(Order order) {
//		orders.remove(order);
//		order.setCustomerID(null);
//	}
	public Integer getType() {
		return type;
	}
	public void setType(Integer type) {
		this.type = type;
	}
	
	
	

}
