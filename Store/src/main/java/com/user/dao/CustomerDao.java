package com.user.dao;

import org.hibernate.Query;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Repository;

import com.user.entity.Customer;

@Repository
public class CustomerDao {
	@Autowired
	SessionFactory sessionFactory;
	
	public Customer getCustomer(String email,String pwd) {
		
		Session session = null;
		try {
			session = sessionFactory.openSession();
			Query query = session.createQuery("from Customer where email = :p1 and password = :p2");
			query.setParameter("p1", email);
			query.setParameter("p2",pwd);
			Customer customer = (Customer)query.uniqueResult();
			return customer;
		}catch(Exception e) {
			e.printStackTrace();
			return null;
		}finally {
			session.close();
		}
		
	}
	
	public boolean isEmailRegistered(String email) {
		
		Session session = null;
		try {
			session = sessionFactory.openSession();
			Query query = session.createQuery("from Customer where email = :p1");
			query.setParameter("p1", email);
			Customer customer = (Customer)query.uniqueResult();
			if(customer!=null) {
				return true;
			}else {
				return false;
			}
		
		}catch(Exception e) {
			e.printStackTrace();
			return false;
			
		}finally {
			session.close();
		}
		
	}
	
	public void saveCustomer(Customer customer) {
		Session session = null;
		try {
			session = sessionFactory.openSession();
			session.beginTransaction();
			session.save(customer);
			session.getTransaction().commit();
		}catch(Exception e) {
			e.printStackTrace();
		}finally {
			session.close();
		}
	}

}
