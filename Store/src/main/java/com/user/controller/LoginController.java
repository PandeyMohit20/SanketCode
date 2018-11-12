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

import com.user.dto.CombinedModel;
import com.user.dto.LoginModel;
import com.user.service.LoginService;


@Controller
public class LoginController {
	@Autowired
	private LoginService loginService;
	
	
	
	@RequestMapping(value="/login.html")
	public String loginPage(Model model) {
		LoginModel loginModel = new LoginModel();
		model.addAttribute("customer", loginModel);
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
	

	@RequestMapping(value="logout.html")
	public ModelAndView logOut(HttpSession session) {
		session.invalidate();
		ModelAndView modelAndView = new ModelAndView("login.jsp");
		modelAndView.addObject("customer", new LoginModel());
		return modelAndView;
	}
	

}
