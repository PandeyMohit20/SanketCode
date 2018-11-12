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
<title>Register</title>
</head>
<body>
<div class="container">
        <div class="card card-container">
			<form:form method="post" action="register.html" modelAttribute="register">

				
				First Name: <form:input path="firstName" class="form-control" type="text"/>
				
				
				Last Name: <form:input path="lastName" class="form-control" type="text"/>
				
				
				City: <form:input path="City" class="form-control" type="text"/>
				
				
				Country: <form:input path="Country" class="form-control" type="text"/>
				
				
				Phone: <form:input path="phone" class="form-control" type="text"/>
				
				
				Password: <form:input path="password" class="form-control" type="password"/>
				
				
				Email: <form:input path="email" class="form-control" type="text"/>
				
				<button class="btn btn-lg btn-primary btn-block btn-signin" type="submit">Register</button>
            </form:form>
          
          <c:if test="${not empty error}">
    			<div class = "alert alert-danger">
    				<strong>Error!</strong><c:out value="${error}"></c:out>
    			</div>
    		</c:if>
          </div>
          </div>

</body>
</html>