<?php
require_once('config.php'); 

$conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

if(is_array($_GET) && count($_GET) > 0 ) {
	$date = $_GET['date'];

    $sql = "SELECT `id`,`ruang`, waktu2, `nama`, `nrp`, `status` FROM `data_pinjaman` WHERE DATE(`tanggal_dipinjam`) = DATE('$date')";

    $result2 = $conn->query($sql);

    if ($result2->num_rows > 0) {
        while($row = $result2->fetch_assoc()) {
            // output data of each row
            $data[] = $row;
            echo json_encode($data);
        }

    }

}