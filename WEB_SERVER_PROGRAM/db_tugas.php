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

    $sql = "SELECT `nip` FROM `data_satpam_new` WHERE nama = '$nama'";
    $result = $conn->query($sql);
    if ($result->num_rows > 0) {
        // output data of each row
        while($row = $result->fetch_assoc()) {
            $nip = $row["nip"];
    } }     

    $sql = "SELECT `rfid`, `lantai` FROM `data_ruang_new` WHERE `ruang` = '$tugas'";
    $result = $conn->query($sql);
    if ($result->num_rows > 0) {
        // output data of each row
        while($row = $result->fetch_assoc()) {
            $rfid = $row["rfid"];
            $lantai = $row["lantai"];
    } }     

		//Create INSERT query

        $sql = "INSERT INTO `data_tugas_new` (`ruang`, `lantai`, `nip`, `satpam`, `rfid`) VALUES ( '$tugas' , '$lantai', ' $nip', ' $nama', ' $rfid')";
        $result = $conn->query($sql);

		//Check whether the query was successful or not
		if($result) {
			$_SESSION['MSGS'] = array('<strong>Selamt </strong> Perubahan Berhasil');
			session_write_close();
			header("location: penugasan_new.php");
			exit();
		} else {
			die("Query failed: ".mysqli_error( $conn));
		}
	
}

if(is_array($_GET) && count($_GET)) {
	$tugasx = $_GET['delete'];
    

    $sql = "DELETE FROM `data_tugas_new`
            WHERE id=$tugasx";
    $result = $conn->query($sql);

	//Check whether the query was successful or not
	if($result) {
		$_SESSION['MSGS'] = array('<strong>Selamt </strong> Perubahan Berhasil');
		session_write_close();
		header("location: penugasan_new.php");
		exit();
	}else {
		$_SESSION['ERRMSG_ARR'] = array('<strong>Oh no!</strong> Changes didn\'t happen, make sure your database is up.');
		session_write_close();
		header("location: penugasan_new.php");
		exit();
	}
}
?>