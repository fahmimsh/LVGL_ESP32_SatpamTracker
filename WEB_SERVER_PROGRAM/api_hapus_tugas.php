<?php
if(is_array($_GET) && count($_GET) > 0 ) {
    require_once('config.php'); 
    $conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

$rfid = $_GET['user'];

      $sql = "DELETE FROM `data_tugas_new` WHERE `ruang` = '$rfid'";
                           $result = $conn->query($sql);
                           
                           if ($result) {
                              require_once('penugasan_new.php'); 
                              
                           }
                           else{
                              return "Not Done";
                           }




}



    ?>