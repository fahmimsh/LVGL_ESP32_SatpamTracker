<?php
require_once('config.php'); 

$conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

if(is_array($_GET) && count($_GET) > 0 ) {
	$nip = $_GET['nip'];

    $sql = "SELECT ruang FROM data_tugas_new
            WHERE nip = '$nip' AND status = 0 LIMIT 1";
    
    $result1 = $conn->query($sql);

    $msg = array();

    if ($result1->num_rows > 0) {

        while($row = $result1->fetch_array()) {

            $msg["lokasi"] = $row["ruang"];
            echo(json_encode($msg));

        }
                
            
    }
        
    else{

        echo ('{"selesai misi"}');

    }
    
}
?>