<?php
require_once('config.php'); 

$conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

if(is_array($_GET) && count($_GET) > 0 ) {
	$rfid = $_GET['id'];


    

    $sql = "SELECT `nip`, `nama`, `posisi` FROM `data_satpam_new` WHERE rfid = $rfid";
    $result = $conn->query($sql);
    $data['rfid'] = $rfid;

	//Check whether the query was successful or not
    if ($result->num_rows > 0) {
        while($row = $result->fetch_array()) {
        // output data of each row
        $data['absen'] = '1';
        $data['nip'] = $row['nip'];
        $data['nama'] = $row['nama'];
        $nip = $row['nip'];
        $nama = $row['nama'];
        $posisi = $row['posisi'];

        
    }
    $sql = "SELECT * FROM `data_presensi` WHERE DATE(date) = CURRENT_DATE() AND u_id = $nip";
    $result = $conn->query($sql);
    
    if ($result->num_rows > 0) {
        $data['status'] = 'X';
    }
    else{
        
        $sql1 = "INSERT INTO `data_presensi`(`u_id`, `nama`, `posisi`) VALUES ('$nip','$nama','$posisi')";
        $result1 = $conn->query($sql1);
        if ($result1) {
            $data['absen'] = '1';
            $data['status'] = 'Y';
        }else{
            $data['absen'] = '0';
            $data['status'] = 'tidak masuk ->'.mysqli_error( $conn);
        }
    }

    }
    else {
        $data['status'] = "tidak ditemukan";
    }

    echo json_encode($data);
}
?>