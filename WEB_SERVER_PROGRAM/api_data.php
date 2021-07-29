<?php
require_once('config.php'); 

$conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}



    $sql = "SELECT `ruang`,`status_ruangan`,`waktu_cek` FROM `data_tugas_new`";
    $result = $conn->query($sql);

    $data = array();
    $stack = array();

	//Check whether the query was successful or not
    if ($result->num_rows > 0) {
        while($row = $result->fetch_array()) {
        $data["Lokasi"] = $row['ruang'];
        $data["Status"] = $row['status_ruangan'];
        $data["Waktu"] = $row['waktu_cek'];
        array_push($stack, $data);
        

        }
        echo (json_encode($stack));
    }
    else{
        $data['status'] = "tidak ada data";
        echo (json_encode($data));
        }

