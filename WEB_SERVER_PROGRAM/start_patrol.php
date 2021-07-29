<?php
require_once('config.php'); 

$conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}


    $sql = "UPDATE `data_tugas_new` SET `status`='1' WHERE 1";

    $result2 = $conn->query($sql);

    if ($result2->num_rows > 0) {
        while($row = $result2->fetch_assoc()) {
            // output data of each row
            $data[] = $row;
            echo json_encode($data);
        }

    }

