<?php

if(is_array($_POST) && count($_POST) > 0 ) {
    require_once('config.php'); 
    $conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}


if($_REQUEST['taglist']) {

  $name = $_REQUEST['namanya'];
  $nip = getnip($name);
  

  foreach ($_REQUEST['taglist'] as $value)
  {

    $rfid = getrfid($value);

      $sql = "INSERT INTO `data_tugas_new`(`ruang`, `nip`, `satpam`, `rfid`,  `status`, `status_ruangan`) VALUES ('$value','$nip','$name','$rfid',1,'Belum_dicek')";
                           $result = $conn->query($sql);
                           
                           if ($result) {
                            header("location: penugasan_new.php");
                              
                           }
                           else{
                              return "Not Done";
                           }
  }
  }
  




}


      function getnip($nama){
      
        require_once('config.php');
    
        $conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
        // Check connection
        if ($conn->connect_error) {
          die("Connection failed: " . $conn->connect_error);
        }

           $sql = "SELECT nip FROM `data_satpam_new` WHERE nama = '$nama'";
           $result = $conn->query($sql);
           
           if ($result->num_rows > 0) {

            while($row = mysqli_fetch_array($result)) {
                              return $row['nip'];
                              
                           }
               
           }else{
              return "kosong";
            }

     }
     function getrfid($ruang){
      
        require_once('config.php');
    
        $conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
        // Check connection
        if ($conn->connect_error) {
          die("Connection failed: " . $conn->connect_error);
        }

           $sql = "SELECT rfid_ruang FROM ruang WHERE ruang = '$ruang'";
           $result = $conn->query($sql);
           
           if ($result->num_rows > 0) {
            while($row = mysqli_fetch_array($result)) {
                return $row['rfid_ruang'];
                
             } 
               
           }else{
              return "kosong";
            }

     }
?>