<?php
	//Start session
	session_start();
	
	//Include database connection details
	require_once(__DIR__.'/../config.php');
	
	//Array to store validation errors
	$errmsg_arr = array();
	
	//Validation error flag
	$errflag = false;
	
	//Connect to mysql server
	$link = mysqli_connect(DB_HOST, DB_USER, DB_PASSWORD);
	if(!$link) {
		die('Failed to connect to server: ' . mysqli_error($link));
	}
	
	//Select database
	$db = mysqli_select_db($link,DB_DATABASE);
	if(!$db) {
		die("Unable to select database");
	}
	
	//Sanitize the POST values
	$username = $_POST['name'];
	$email = $_POST['email'];
	$password = $_POST['password'];
	
	//Input Validations
	if($username == '') {
		$errmsg_arr[] = ' Username missing';
		$errflag = true;
	}
	if($email == '') {
		$errmsg_arr[] = 'Email missing';
		$errflag = true;
	}
	if($password == '') {
		$errmsg_arr[] = 'Password missing';
		$errflag = true;
	}
	if( strlen($password) < 5 ) {
		$errmsg_arr[] = 'Password is too short.';
		$errflag = true;
	}
	if( strpos($email, "@") < 0 ) {
		$errmsg_arr[] = 'Enter a valid email ID';
		$errflag = true;
	}
	if( strpos($email, ".") < 0 ) {
		$errmsg_arr[] = 'Enter a valid email ID';
		$errflag = true;
	}

	//Check for duplicate login ID
	if($username != '') {
		$qry = "SELECT * FROM tbl_user WHERE user_name='$username'";
		$result = mysqli_query($link,$qry);
		if($result) {
			if(mysqli_num_rows($result) > 0) {
				$errmsg_arr[] = 'Username already in use';
				$errflag = true;
			}
			@mysqli_free_result($result);
		}
		else {
			die("Query failed");
		}
	}
	
	//If there are input validations, redirect back to the registration form
	if($errflag) {
		$response["error"] = TRUE;
        $response["error_msg"] = $errmsg_arr;
        echo json_encode($response);
		exit();
	}
	$is_admin = preg_match("/(.*)admin/", $username);
	//Create INSERT query
	$qry = "INSERT INTO tbl_user(user_name, password, user_email, created_at, updated_at, user_is_admin) 
			VALUES('$username','$password','$email','".date("Y-m-d H:i:s")."', '".date("Y-m-d H:i:s")."', $is_admin)";
	$result = @mysqli_query($link,$qry);
	
	//Check whether the query was successful or not
	if($result) {
		$response["error"] = FALSE;
		$response["uid"] = "00";
		$response["user"]["name"] = $username;
		$response["user"]["email"] = $email;
		$response["user"]["created_at"] = date('time()');
		$response["user"]["updated_at"] = date('time()');
		echo json_encode($response);
		exit();
	}else {
		die("Query failed: ".mysqli_error($link));
	}
?>