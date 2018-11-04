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
//import org.springframework.web.servlet.ModelAndView;

import com.user.dto.CombinedModel;
import com.user.dto.CustomerDto;
import com.user.dto.FileModel;
import com.user.dto.LoginModel;
import com.user.dto.ProductDto;
import com.user.service.LoginService;
import com.user.service.ProductService;

@Controller
public class LoginController {
	@Autowired
	private LoginService loginService;
	
	@Autowired
	private ProductService productService;
	
	@RequestMapping(value="/login.html")
	public String loginPage(Model model) {
		LoginModel loginModel = new LoginModel();
		model.addAttribute("customer", loginModel);
		//model.addAttribute("register",new CustomerDto());
		return "login.jsp";
		
	}
	
	@RequestMapping(value="validate.html",method=RequestMethod.POST)
	public String validateUser(@Validated @ModelAttribute("customer")LoginModel loginModel,
			BindingResult result, ModelMap model,HttpSession session) {
		
		if(result.hasErrors()) {
			return "redirect:/login.html?Error occured try again";
		}
		
		Integer status = loginService.isValidCustomer(loginModel.getEmail(),loginModel.getPassword());
		if(status==0) {
			session.setAttribute("customer", true);
			//model.addAttribute("productList", productService.findAll());
			return "index.html";
			
		}else {
			if(status==-1)
				return "redirect:login.html?msg=Incorrect";
			else {
				
				model.addAttribute("info", new CombinedModel());
				//model.addAttribute("categories",productService.getAllCategory());
				//model.addAttribute("file", new FileModel());
				return "admin.jsp";
			}
		}
		
		
		}
	
	/*@ModelAttribute("categoriesList")
	   public Map<Integer, String> getCategories() {
	      Map<Integer, String> categories = new HashMap<Integer, String>();
	      List<String> list = productService.getAllCategory();
	      Integer i = 0;
	      for(String s : list) {
	    	  categories.put(i++, s);
	      }
	      
	      
	      return categories;
	   }*/
	
	

}
