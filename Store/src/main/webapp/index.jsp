<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

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
					<li><a href="login.html" >Login</a></li>
					<li>
					  <a href="#">
						<span class="glyphicon glyphicon-shopping-cart" style="colo:rgb(157,157,157)"></span>
					   </a>	
					</li>
					
				</ul>
			</div>
		</nav>
	</header>
	<section>
		<div class = "container">
			<div class = "row">
				<c:forEach items="${productList}" var="product"> 
					<div class="col-sm-4">
						<div class="card" style="width: 18rem;">
						  <img class="card-img-top" src="img.html?id=${product.id}" alt="${product.productName}">
						  <div class="card-body">
						    <h5 class="card-title"><c:out value="${product.productName}"/></h5>
						    <p class="card-text"><c:out value="${product.unitPrice}"/></p>
						  </div>
						</div>
					</div>
				</c:forEach>


			</div>	
		</div>
	</section>
</body>
</html>