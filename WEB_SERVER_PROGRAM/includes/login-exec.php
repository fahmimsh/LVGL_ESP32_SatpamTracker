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
	


	$username = $_POST['username'];
	$password = $_POST['password'];
	
	//Input Validations
	if($username == '') {
		$errmsg_arr[] = 'Please provide a username.';
		$errflag = true;
	}
	if($password == '') {
		$errmsg_arr[] = 'Please enter the password.';
		$errflag = true;
	}
	
	//If there are input validations, redirect back to the login form
	if($errflag) {
		$_SESSION['ERRMSG_ARR'] = $errmsg_arr;
		session_write_close();
		header("location: ../login.php");
		exit();
	}
	
	//Create query
	//$qry="SELECT * FROM tbl_user WHERE user_name='$username' AND password='".md5($_POST['password'])."'";
	$qry="SELECT * FROM tbl_user WHERE user_name='$username' AND password='$password'";
	$result=mysqli_query($link,$qry);

	//Check whether the query was successful or not
	if($result) {
		if(mysqli_num_rows($result) == 1) {
			//Login Successful
			session_regenerate_id();
			$member = mysqli_fetch_assoc($result);
			$_SESSION['SESS_USER_ID'] = $member['user_id'];
			$_SESSION['SESS_USERNAME'] = $member['user_name'];
			$_SESSION['SESS_IS_ADMIN'] = $member['user_is_admin'];
			session_write_close();
			header("location: ../index.php");
			exit();
		}else {
			//Login failed
			$_SESSION['ERRMSG_ARR'] = array('password Salah GAN !!');
			session_write_close();
			header("location: ../login.php");
			exit();
		}
	}else {
		die("Query failed: ".mysqli_error($link));
	}
?>