<?php
if(is_array($_GET) && count($_GET) > 0 ) {
    require_once('config.php'); 
    $conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

$uid = $_GET['uid'];

      $sql = "DELETE FROM `data_satpam_new` WHERE `u_id` = '$uid'";
                           $result = $conn->query($sql);
                           
                           if ($result) {
                            session_write_close();
                            header("location: presensi.php");
                            exit();
                              
                           }
                           else{
                              return "Not Done";
                           }




}



    ?>