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
$uid = $_POST['uid'];
$seperator = ".................";

require_once('config.php'); 

$conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

$sql = "UPDATE `data_satpam_new` 
        SET `rfid`='$rfid', `nip`='$nip', `nama`='$nama', `email`='$email', `posisi`='$posisi', `alamat`='$alamat', `umur`='$umur', `nomor_hp`='$no_hp' 
        WHERE `u_id` = '$uid'";

        $result = $conn->query($sql);

		//Check whether the query was successful or not
		if($result) {
            //echo $nama. $seperator  . $nip. $seperator  . $email .$seperator  . $alamat . $seperator  . $no_hp . $seperator  . $rfid . $seperator  . $posisi . $seperator  . $umur . $seperator  . $uid;
			session_write_close();
			header("location: presensi.php");
			exit();
		} else {
            echo $nama . $nip . $email . $alamat . $no_hp . $rfid . $posisi . $umur . $uid;
			die("Query failed: ".mysqli_error( $conn)); 
            
		}




}
?>