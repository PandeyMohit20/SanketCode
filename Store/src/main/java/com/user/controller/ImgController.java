package com.user.controller;


import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;

import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;


import com.user.dto.ProductDto;
import com.user.service.ProductService;

@Controller
public class ImgController {
	
	@Autowired
	ProductService productService;
	@RequestMapping(value = "img.html", method = RequestMethod.GET)
	  public void showImage(@RequestParam("id") Integer itemId, HttpServletResponse response,HttpServletRequest request) 
	          throws ServletException, IOException{

        System.out.println(itemId);
	    ProductDto product = productService.getProduct(itemId);        
	    response.setContentType("image/jpeg, image/jpg, image/png");
	    response.getOutputStream().write(product.getImg());


	    response.getOutputStream().close();
	}

}
