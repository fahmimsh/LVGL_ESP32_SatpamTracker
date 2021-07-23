<?php
require_once('config.php'); 
date_default_timezone_set('UTC');

$conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

if(is_array($_POST) && count($_POST) > 0) {
    $uidd = $_POST['nip'];


	$errflag = false;

	if($uidd == '') {
		$errmsg_arr[] = 'nip kosong';
		$errflag = true;
	}

$nama;
$posisi;

$dateme = date("Y/m/d");


    $sql = ("SELECT * FROM data_satpam WHERE nip = '$uidd'");
    $result = $conn->query($sql);  
        if(mysqli_num_rows($result) == 0) {
             $errmsg_arr[] = 'Pengirim Tidak Dikenal';
             $errflag = true;
         } 
         else{
        while($row = mysqli_fetch_array($result)) {
                 $nama = $row['nama'];
                 $posisi = $row['posisi'];

         }
        }
    $sql = ("SELECT * FROM data_presensi WHERE date = '$dateme'");
    $result = $conn->query($sql);  
        if(mysqli_num_rows($result) != 0) {
             $errmsg_arr[] = 'Sudah Absen';
             $errflag = true;
         } 


	if($errflag) {
		$_SESSION['ERRMSG_ARR'] = $errmsg_arr;
        echo "error";
        print_r($errmsg_arr);
		session_write_close();
		//header("location: penugasan.php");
		exit();
	}




		//Create INSERT query

        $sql = "INSERT INTO `data_presensi` (`u_id`, `nama`, `posisi`) 
        VALUES ( '$uidd ' , '$nama', '$posisi')";
        $result = $conn->query($sql);

		//Check whether the query was successful or not
		if($result) {
			$_SESSION['MSGS'] = array('<strong>Selamt </strong> Perubahan Berhasil');
			session_write_close();
            echo json_encode($_SESSION['MSGS']);
			exit();
		} else {
            echo "kalah";
			die("Query failed: ".mysqli_error( $conn));
		}
	
}

?>