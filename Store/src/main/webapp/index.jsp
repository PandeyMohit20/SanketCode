<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix = "fmt" uri = "http://java.sun.com/jsp/jstl/fmt" %>

<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<!-- Latest compiled and minified CSS -->

<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">


<!-- jQuery library -->
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>

<!-- Latest compiled JavaScript -->
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
<meta name="viewport" content="width=device-width, initial-scale=1">

<link rel="stylesheet" href="resources/products.css">

<title>Online Shopping</title>
</head>
<body>
	<header>
		<nav class="navbar navbar-inverse">
			<div class="container-fluid">
				<div class = "navbar-header">
					<a class="navbar-brand" href="#"><span class="glyphicon glyphicon-align-justify"></span></a>
					<a class="navbar-brand" href="#">OnlineStore</a>
				</div>
				<ul class = "nav navbar-nav navbar-right">
					<li><a href="logout.html" >Logout</a></li>
					<li>
					  <a href="#">
						<span class="glyphicon glyphicon-shopping-cart" style="color:rgb(157,157,157)"></span>
					   </a>	
					</li>
					
				</ul>
			</div>
		</nav>
	</header>
	<section>


		<div class="container">
		<div class="grid">
		<div class="content">
			<div class="flex-container">
			  
			  <c:forEach items="${productList}" var="product">
				<div class="product">
					<img src="img.html?id=${product.id}" alt="${product.productName}" style="width:100%"/>
					<div class = "info">
						<p class="Product-Name"><c:out value="${product.productName}"/></p>
						<p><fmt:formatNumber type="currency" value="${product.unitPrice}"></fmt:formatNumber></p>
					</div>
				</div>
				</c:forEach>
			</div>
			</div>
			</div>
		</div>
		
	</section>
</body>
</html>