<?php
require_once('config.php'); 

$conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

if(is_array($_GET) && count($_GET) > 0 ) {
	$rfid = $_GET['rfid'];
    $nip = $_GET['nip'];

    $sql = "SELECT `ruang`,`satpam` FROM `data_tugas_new` WHERE nip = $nip";
    $result = $conn->query($sql);

	//Check whether the query was successful or not
    if ($result->num_rows > 0) {
        while($row = $result->fetch_array()) {
        $nama_ruang = $row['ruang'];
        $nama_pengecek = $row['satpam'];

        }
    
        $sql = "INSERT INTO `tugas_selesai`(`nama_ruang`, `pengecek`, `status`) VALUES ('$nama_ruang','$nama_pengecek',1)";
        $result = $conn->query($sql);

        if ($result){
            $data['status'] = "data masuk";
        }
        else{
            $data['status'] = 'tidak masuk ->'.mysqli_error( $conn);
        }

    }
    else{
        $data['status'] = "Tugas";
        }




}