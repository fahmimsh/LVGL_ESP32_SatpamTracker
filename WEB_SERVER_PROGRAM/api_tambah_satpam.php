<?php

if(is_array($_POST) && count($_POST) > 0 ) {

$nama = $_POST['nama'];
$nip = $_POST['nip'];
$email = $_POST['email'];
$alamat = $_POST['alamat'];
$no_hp = $_POST['no_hp'];
$rfid = $_POST['rfid'];
$posisi = $_POST['posisi'];
$umur = $_POST['umur'];

require_once('config.php'); 

$conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

$sql = "INSERT INTO `data_satpam_new`(`rfid`, `nip`, `nama`, `email`, `pass`, `posisi`, `alamat`, `umur`, `nomor_hp`) VALUES ('$rfid','$nip','$nama','$email','123456','$posisi','$alamat','$umur','$no_hp')";
        $result = $conn->query($sql);

		//Check whether the query was successful or not
		if($result) {
			session_write_close();
			header("location: presensi.php");
			exit();
		} else {
			die("Query failed: ".mysqli_error( $conn));
		}




}
?>