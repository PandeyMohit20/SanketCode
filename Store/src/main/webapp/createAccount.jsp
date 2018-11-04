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
			<form:form method="POST" action="register.html" modelAttribue="register">
            	<form:label path="firstName">firstName</form:label>
				<form:input path="firstName" id="firstName" class="form-control" type="text"/>
				<form:label path="lastName">lastName</form:label>
				<form:input path="lastName" id="lastName" class="form-control" type="text"/>
				<form:label path="City">City</form:label>
				<form:input path="City" id="City" class="form-control" type="text"/>
				<form:label path="Country">Country</form:label>
				<form:input path="Country" id="Country" class="form-control" type="text"/>
				<form:label path="phone">phone</form:label>
				<form:input path="phone" id="phone" class="form-control" type="text"/>
            	<form:label path="email">Email</form:label>
				<form:input path="email" id="email" class="form-control" type="email"/>
				<form:label path="password">Password</form:label>
				<form:input path="password" id="password" class="form-control" type="password"/>
            </form:form>
            
          </div>
          <c:if test="${not empty param.msg}">
    			<div class = "alert alert-danger">
    				<strong>Error!</strong>Registration failed try again.
    			</div>
    </c:if>
          </div>

</body>
</html>