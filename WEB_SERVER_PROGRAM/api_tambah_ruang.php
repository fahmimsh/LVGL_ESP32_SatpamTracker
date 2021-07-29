<?php

if(is_array($_POST) && count($_POST) > 0 ) {

$nama = $_POST['nama'];
$ket = $_POST['ket'];
$rfid = $_POST['rfid'];


require_once('config.php'); 

$conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}


// echo "Nama " . $nama ."<br>";
// echo "NRP " . $nrp ."<br>";
// echo "No HP " . $no_hp ."<br>";
// echo "Ruangan " . $ruangan ."<br>";
// echo "Keperluan " . $keperluan ."<br>";
// echo "TGL " . $tgl ."<br>";
// echo "Waktu " . $waktu1 ."-" . $waktu2 . "<br>";

$sql = "INSERT INTO `ruang`(`ruang`, `keterangan`, `rfid_ruang`) VALUES ('$nama','$ket','$rfid')";
        $result = $conn->query($sql);

		//Check whether the query was successful or not
		if($result) {
			session_write_close();
			header("location: daftar-ruang.php");
			exit();
		} else {
			die("Query failed: ".mysqli_error( $conn));
		}




}
?>