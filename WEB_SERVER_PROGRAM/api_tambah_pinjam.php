<?php

if(is_array($_POST) && count($_POST) > 0 ) {

$nama = $_POST['nama'];
$nrp = $_POST['nrp'];
$no_hp = $_POST['no_hp'];
$ruangan = $_POST['ruangan'];
$keperluan = $_POST['keperluan'];
$tgl = $_POST['tgl'];
$waktu1 = $_POST['waktu1'];
$waktu2 = $_POST['waktu2'];

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

$sql = "INSERT INTO `data_pinjaman`(`ruang`, `keperluan`, `waktu1`, `waktu2`, `nama`, `nrp`, `no_hp`, `tanggal_dipinjam`, `status`) VALUES ('$ruangan','$keperluan','$waktu1','$waktu2','$nama','$nrp','$no_hp','$tgl','0')";
        $result = $conn->query($sql);

		//Check whether the query was successful or not
		if($result) {
			session_write_close();
			header("location: peminjaman.php");
			exit();
		} else {
			die("Query failed: ".mysqli_error( $conn));
		}




}
?>