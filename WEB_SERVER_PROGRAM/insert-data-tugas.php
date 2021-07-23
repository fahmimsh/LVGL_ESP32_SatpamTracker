<?php
require_once('config.php'); 

$conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

if(is_array($_POST) && count($_POST) > 0) {
	$tugas = $_POST['tugas'];
    $tugdesc = htmlspecialchars($_POST['tugdesc']);

	$errflag = false;

	if($tugas == '') {
		$errmsg_arr[] = 'Tugas Kosong';
		$errflag = true;
	}

	if($errflag) {
		$_SESSION['ERRMSG_ARR'] = $errmsg_arr;
        echo $errmsg_arr;
		session_write_close();
		header("location: data_tugas.php");
		exit();
	}

		//Create INSERT query

        $sql = "INSERT INTO `data_tugas` (tugas, tgs_description) VALUES ( '$tugas' , '$tugdesc')";
        $result = $conn->query($sql);

		//Check whether the query was successful or not
		if($result) {
			$_SESSION['MSGS'] = array('<strong>Selamt </strong> Perubahan Berhasil');
			session_write_close();
			header("location: data-tugas.php");
			exit();
		} else {
			die("Query failed: ".mysqli_error( $conn));
		}
	
}
?>