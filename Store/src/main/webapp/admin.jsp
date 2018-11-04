<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
 <%@ taglib prefix="form" uri="http://www.springframework.org/tags/form" %>
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
<title>Admin</title>
</head>
<body>

<div class="container">
        <div class="card card-container">
            <p id="profile-name" class="profile-name-card"></p>
           
            <form:form method = "POST" action="upload.html" modelAttribute="info" enctype="multipart/form-data">
            	<form:label path="product.productName">Product Name</form:label>
				<form:input path="product.productName" id="productName" class="form-control" type="text"/>
				<form:label path="product.unitPrice">Price</form:label>
				<form:input path="product.unitPrice" id="unitPrice" class="form-control" type="number" step="0.01" min="0"/>
				<form:label path="product.category">Category</form:label>
				<form:input path="product.category" id="category" class="form-control" type="text"/>
				
				
			   
				<form:label path="file.file">File Name</form:label>
				<form:input path="file.file" type="file" class="form-control"/>
				<button class="btn btn-lg btn-primary btn-block btn-signin" type="submit">Add Item</button>
            </form:form>
            
            
            
        
    <c:if test="${not empty param.msg}">
    	<div class = "alert alert-danger">
    		<strong>Error!</strong>Incorrect username or password
    	</div>
    </c:if>
    </div>
    </div>
</body>
</html>