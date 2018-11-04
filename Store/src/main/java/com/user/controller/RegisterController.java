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

import com.user.dto.CustomerDto;
import com.user.dto.LoginModel;
import com.user.service.RegisterService;

@Controller
public class RegisterController {
	@Autowired
	RegisterService registerService;
	
	@RequestMapping(value="createAccount.html")
	public String createAccount(Model model) {
		model.addAttribute("register", new CustomerDto());
		return "createAccount.jsp";
		
	}
	@RequestMapping(value="register.html",method=RequestMethod.POST)
	public String register(@Validated @ModelAttribute("register")CustomerDto customer,
			BindingResult result, ModelMap model,HttpSession session) {
		
		boolean status = registerService.registerCustomer(customer);
		if(status) {
			session.setAttribute("customer", true);
			return "index.html";
		}
		else {
			model.addAttribute("customer",new LoginModel());
			return "redirect:createAccount.html?msg=fail";
		}
		
	}
	

}
