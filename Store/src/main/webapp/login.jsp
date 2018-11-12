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
<link rel="stylesheet" href="resources/login.css">
<title>SignIn</title>
</head>
<body>
<div class="container">
        <div class="card card-container">
            <p id="profile-name" class="profile-name-card"></p>
            <form:form method = "POST" action="validate.html" modelAttribute="customer">
            	<form:label path="email">Email</form:label>
				<form:input path="email" id="email" class="form-control" type="email"/>
				<form:label path="password">Password</form:label>
				<form:input path="password" id="password" class="form-control" type="password"/>
          
                <button class="btn btn-lg btn-primary btn-block btn-signin" type="submit">Sign in</button>
            </form:form>
            <div>
            	<a href="createAccount.html">Create account</a>
          	</div>
            
        
    <c:if test="${not empty param.msg}">
    	<div class = "alert alert-danger">
    		<strong>Error!</strong>Incorrect username or password
    	</div>
    </c:if>
    </div>
    </div>
</body>
</html>