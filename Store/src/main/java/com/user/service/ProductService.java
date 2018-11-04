package com.user.service;


import java.awt.image.BufferedImage;
import java.io.ByteArrayInputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.List;

import javax.imageio.ImageIO;

import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;

import com.user.dao.ProductDao;
import com.user.dto.CombinedModel;
import com.user.dto.ProductDto;
import com.user.entity.Product;

@Service
public class ProductService {
	
	@Autowired
	ProductDao pDao;
	public List<Product> findAll(){
		List<Product> products = pDao.getAllProducts();
		return products;
	}
	
	public boolean saveProduct(ProductDto productDto) {
		try {
			Product product = new Product();
			BeanUtils.copyProperties(productDto, product);
			//System.out.println(productDto.getImg());
			pDao.saveProduct(product);
//			BufferedImage img = ImageIO.read(new ByteArrayInputStream(productDto.getImg()));
//			File o = new File("C:\\Users\\Sanket\\eclipse-workspace\\save.png");
//			ImageIO.write(img, "png", o);
			return true;
		}catch(Exception e) {
			return false;
		}
	}
	public List<String> getAllCategory(){
		List<String> products = pDao.getAllCategories();
		return products;
	}
	
	public ProductDto getProduct(Integer id) {
		Product prod = pDao.getProduct(id);
		//System.out.println(prod);
		ProductDto product = new ProductDto();
		BeanUtils.copyProperties(prod, product);
		//System.out.println(product+" "+product.getImg());
		
		try {
			byte[] b = product.getImg();
			FileOutputStream f = new FileOutputStream("C:\\Users\\Sanket\\eclipse-workspace\\save.png");
			f.write(b);
			f.close();
			
		}catch(Exception e) {
			e.printStackTrace();
		}
		
		
		
		
		return product;
	}

	public void saveProductAndImg(CombinedModel mod) throws IOException {
		MultipartFile file = mod.getFile().getFile();
		ProductDto source = mod.getProduct();
		Product product = new Product();
		BeanUtils.copyProperties(source, product);
		product.setImg(file.getBytes());
		pDao.saveProduct(product);
		
	}
}
