package com.user.controller;

import javax.servlet.http.HttpSession;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.ui.ModelMap;
import org.springframework.validation.BindingResult;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.servlet.ModelAndView;

import com.user.dto.CustomerDto;
import com.user.service.RegisterService;

@Controller
public class RegisterController {
	@Autowired
	RegisterService registerService;
	
	@RequestMapping(value="createAccount.html")
	public ModelAndView createAccount() {
		System.out.println("in register");
		ModelAndView modelView = new ModelAndView("createAccount.jsp");
		modelView.addObject("register", new CustomerDto());
		System.out.println("in register");
		return modelView;
		
	}
	@RequestMapping(value="register.html",method=RequestMethod.POST)
	public String register(HttpSession session,@ModelAttribute("register")CustomerDto customer) {
		System.out.println("in register2");
		boolean status = registerService.registerCustomer(customer);
		if(status) {
			return "index.html";
		}
		else {
			
			return "loginfail.html";
		}
		
	}
	
	@RequestMapping(value="loginfail.html")
	public ModelAndView registrationFail() {
		
		ModelAndView modelView = new ModelAndView("createAccount.jsp");
		modelView.addObject("register", new CustomerDto());
		modelView.addObject("error", "There was an error registering account, please try again");
		return modelView;
		
	}
	

}
