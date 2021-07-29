<?php
require_once('config.php'); 

$conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

if(is_array($_GET) && count($_GET) > 0 ) {
	$rfid = $_GET['rfid'];
    $status = $_GET['status'];

    $sql = "SELECT `ruang`,`satpam` FROM `data_tugas_new` WHERE rfid = '$rfid' AND status = 0";
    $result = $conn->query($sql);

	//Check whether the query was successful or not
    if ($result->num_rows > 0) {
        while($row = $result->fetch_array()) {
        $nama_ruang = $row['ruang'];
        $nama_pengecek = $row['satpam'];
        }

        $data = array();
    
        $sql = "INSERT INTO `data_masuk`(`ruang`, `status`, `nama_ruang`, `nama_pengecek`) VALUES ('$rfid','$status','$nama_ruang','$nama_pengecek')";
        $sql2 = "UPDATE `data_tugas_new` SET `status_ruangan`='$status',`status`=1 WHERE ruang = '$nama_ruang'";
        $result = $conn->query($sql);
        $result2 = $conn->query($sql2);

        if ($result2){
            $data['status'] = "data masuk";
            echo (json_encode($data));
        }
        else{
            $data['status'] = 'tidak masuk ->'.mysqli_error( $conn);
            echo (json_encode($data));
        }

    }
    else{
        $data['status'] = "sudah dicek";
        echo (json_encode($data));
        }




}
else {
    echo('{"input error"}');
}