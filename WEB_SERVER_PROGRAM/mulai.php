<?php

if(is_array($_GET) && count($_GET) > 0 ) {

$status = $_GET['mulai'];
$tempat = $_GET['tempat'];
require_once('config.php'); 

$conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

$sql = "UPDATE `data_tugas_new` SET `status`= $status WHERE 1";
$result = $conn->query($sql);


if ($result) {
    mysqli_close($conn);
    if($tempat == 1){
        require_once('penugasan_new.php');
    }
    else{
        require_once('index.php');
    }
    
}
else{
    echo "fail";
}



}
else{
    echo "fail";
}
?>