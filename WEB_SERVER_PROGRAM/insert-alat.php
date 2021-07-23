<?php
require_once('config.php'); 

$conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

if(is_array($_POST) && count($_POST) > 0) {
	$namaalat = $_POST['alat'];
    $API_key = generateRandomString();

	$errflag = false;
    $errmsg_arr= "";

	if($namaalat == '') {
		$errmsg_arr[] = 'Tugas Kosong';
		$errflag = true;
	}

	if($errflag) {
		$_SESSION['ERRMSG_ARR'] = $errmsg_arr;
        echo $errmsg_arr;
		session_write_close();
		header("location: daftar-alat.php");
		exit();
	}

		//Create INSERT query

        $sql = "INSERT INTO `data_alat` (nama, api_key) VALUES ( '$namaalat' , '$API_key')";
        $result = $conn->query($sql);

		//Check whether the query was successful or not
		if($result) {
			$_SESSION['MSGS'] = array('<strong>Selamt </strong> Perubahan Berhasil');
			session_write_close();
			header("location: daftar-alat.php");
			exit();
		} else {
			die("Query failed: ".mysqli_error( $conn));
		}
	
}

function generateRandomString($length = 10) {
    $characters = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
    $charactersLength = strlen($characters);
    $randomString = '';
    for ($i = 0; $i < $length; $i++) {
        $randomString .= $characters[rand(0, $charactersLength - 1)];
    }
    return $randomString;
}
?>