<?php
require_once('config.php'); 

$conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

if(is_array($_GET) && count($_GET) > 0 && isset($_GET['delete'])) {
	$tugasx = $_GET['delete'];
    

    $sql = "DELETE FROM `data_alat`
            WHERE e_id='$tugasx'";
    $result = $conn->query($sql);

	//Check whether the query was successful or not
	if($result) {
		$_SESSION['MSGS'] = array('<strong>Selamt </strong> Perubahan Berhasil');
		session_write_close();
		header("location: daftar-alat.php");
		exit();
	}else {
		$_SESSION['ERRMSG_ARR'] = array('<strong>Oh no!</strong> Changes didn\'t happen, make sure your database is up.');
		session_write_close();
		header("location: daftar-alat.php");
		exit();
	}
}
?>