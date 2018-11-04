package com.user.dao;

import java.util.ArrayList;
import java.util.List;

import org.hibernate.Query;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Repository;

import com.user.entity.Product;

@Repository
public class ProductDao {
	
	@Autowired
	SessionFactory sessionFactory;
	
	@SuppressWarnings("unchecked")
	public List<Product> getAllProducts(){
		
		Session session = null;
		try {
			session = sessionFactory.openSession();
			Query query = session.createQuery("from Product");
			return (List<Product>)query.list();
			
		}catch(Exception e) {
			e.printStackTrace();
			return null;
			
		}finally {
			
			session.close();
			
		}
		
	}
	

	public Product getProduct(Integer id){
		
		Session session = null;
		try {
			session = sessionFactory.openSession();
			Query query = session.createQuery("from Product where id = :id");
			query.setParameter("id", id);
			return (Product) query.uniqueResult();
			
		}catch(Exception e) {
			e.printStackTrace();
			return null;
			
		}finally {
			
			session.close();
			
		}
		
	}
	
	@SuppressWarnings("unchecked")
	public List<Product> getAllProductsByCategory(String category){
		
		Session session = null;
		try {
			session = sessionFactory.openSession();
			Query query = session.createQuery("from Product where category= :category");
			query.setParameter("category", category);
			return (List<Product>)query.list();
			
		}catch(Exception e) {
			e.printStackTrace();
			return null;
			
		}finally {
			
			session.close();
			
		}
		
	}
	public void saveProduct(Product product) {
		Session session = null;
		try {
			session = sessionFactory.openSession();
			session.beginTransaction();
			session.save(product);
			session.getTransaction().commit();
		}catch(Exception e) {
			e.printStackTrace();
		}finally {
			session.close();
		}
	}

	@SuppressWarnings("unchecked")
	public List<String> getAllCategories(){
		
		Session session = null;
		try {
			session = sessionFactory.openSession();
			Query query = session.createQuery("select distinct category from Product");
			List<Product> p = query.list();
			List<String> categories = new ArrayList<String>();
			for(Product x: p) {
				categories.add(x.getCategory());
			}
			return categories;
			
		}catch(Exception e) {
			e.printStackTrace();
			return null;
			
		}finally {
			
			session.close();
			
		}
		
	}
}
