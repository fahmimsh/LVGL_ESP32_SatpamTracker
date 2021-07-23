<?php
require_once('config.php'); 

$conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

if(is_array($_POST) && count($_POST) > 0) {
    $nama = $_POST['nama'];
	$tugas = $_POST['tugas'];
    $keterangan = htmlspecialchars($_POST['keterangan']);

	$errflag = false;

	if($tugas == '') {
		$errmsg_arr[] = 'Tugas Kosong';
		$errflag = true;
	}

	if($errflag) {
		$_SESSION['ERRMSG_ARR'] = $errmsg_arr;
        echo $errmsg_arr;
		session_write_close();
		header("location: penugasan.php");
		exit();
	}

		//Create INSERT query

        $sql = "INSERT INTO `tugas_satpam` (nama, tugas, keterangan) VALUES ( '$nama' , '$tugas', '$keterangan')";
        $result = $conn->query($sql);

		//Check whether the query was successful or not
		if($result) {
			$_SESSION['MSGS'] = array('<strong>Selamt </strong> Perubahan Berhasil');
			session_write_close();
			header("location: penugasan.php");
			exit();
		} else {
			die("Query failed: ".mysqli_error( $conn));
		}
	
}
?>