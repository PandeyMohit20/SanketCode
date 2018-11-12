package com.user.controller;




import java.io.IOException;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.BindException;
import org.springframework.validation.BindingResult;
import org.springframework.validation.annotation.Validated;

//import org.springframework.web.bind.WebDataBinder;
//import org.springframework.web.bind.annotation.InitBinder;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.multipart.MultipartFile;
import org.springframework.web.servlet.ModelAndView;

import com.user.dto.CombinedModel;
import com.user.dto.FileModel;
import com.user.dto.ProductDto;

import com.user.service.ProductService;

@Controller
public class AdminController {
	
	@Autowired
	ProductService productService;
	
	@RequestMapping(value="insert.html",method=RequestMethod.POST)
	public String insert(@ModelAttribute("ProductDto")ProductDto product){
	 //public String insert(@Validated @ModelAttribute("ProductDto")ProductDto product,HttpSession session, BindingResult result) {
		
		productService.saveProduct(product);
		return "redirect:/success.html";
		
	}
	
	@RequestMapping(value="upload.html",method=RequestMethod.POST)
	public String test(@ModelAttribute("info")CombinedModel mod) {
		System.out.println(mod.getFile()+" "+mod.getProduct());
		try {
			productService.saveProductAndImg(mod);
			System.out.println("success");
		} catch (IOException e) {
			e.printStackTrace();
		}
		return "redirect:/productSaved.html";
	}
	
	protected ModelAndView onSubmit(HttpServletRequest request,HttpServletResponse response,
			@RequestParam(value="UploadFile") MultipartFile image, BindException errors,HttpSession session) {
		
		try {
			
		}catch(Exception e) {
			e.printStackTrace();
		}
		return new ModelAndView("message");
	}
	
	@RequestMapping(value = "productSaved.html",  method = RequestMethod.GET)
	public String success(Model model){
		
		model.addAttribute("info", new CombinedModel());
	    return "admin.jsp";
	}
	
	@RequestMapping(value = "success.html",  method = RequestMethod.GET)
	public String category(Model model){
		
		model.addAttribute("ProductDto", new ProductDto());
		model.addAttribute("file", new FileModel());
	    return "admin.jsp";
	}
	
	
	
}
