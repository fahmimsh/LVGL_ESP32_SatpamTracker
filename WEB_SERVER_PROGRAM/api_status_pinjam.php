<?php
require_once('config.php'); 

$conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

if(is_array($_GET) && count($_GET) > 0 ) {
	$id= $_GET['id'];

    $sql = "UPDATE `data_pinjaman` SET `status`='1' WHERE `id` = $id ";

    $result2 = $conn->query($sql);

    if ($result2) {
        
        $data['status'] = "data Masuk";

    }

    else{
        $data['status'] = "data Tidak masuk ".mysqli_error( $conn);
    }

    echo json_encode($data);

}