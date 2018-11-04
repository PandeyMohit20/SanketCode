package com.user.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;

import com.user.service.ProductService;

@Controller
public class HomeController {
	
	@Autowired
	ProductService productService;
	@RequestMapping("index.html")
	public String userHomePage(Model model) {
		model.addAttribute("productList", productService.findAll());
		return "index.jsp";
	}

}
