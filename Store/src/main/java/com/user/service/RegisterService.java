package com.user.service;

import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.user.dao.CustomerDao;
import com.user.dto.CustomerDto;
import com.user.entity.Customer;

@Service
public class RegisterService {
	
	@Autowired
	CustomerDao customerDao;
	
	public boolean registerCustomer(CustomerDto user) {
		
		boolean isRegistered = customerDao.isEmailRegistered(user.getEmail());//check if there is user with this email already
		if(!isRegistered) {
			Customer customer = new Customer();
			BeanUtils.copyProperties(user, customer);
			customerDao.saveCustomer(customer);
			return true;
		}else {
			return false;
		}
		
	}

}
