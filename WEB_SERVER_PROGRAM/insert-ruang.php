<?php
require_once('config.php'); 

$conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

if(is_array($_POST) && count($_POST) > 0) {
    $nama_ruang = $_POST['ruang'];
	$gedung = $_POST['gedung'];
    $lantai = $_POST['lantai'];
    $keterangan = $_POST['keterangan'];

	$errflag = false;

	if($nama_ruang  == '') {
		$errmsg_arr[] = 'nama_ruang Kosong';
		$errflag = true;
	}
    if($lantai  == '') {
		$errmsg_arr[] = 'lantai Kosong';
		$errflag = true;
	}
    if($gedung == '') {
		$errmsg_arr[] = 'gedung Kosong';
		$errflag = true;
	}
    if($keterangan == '') {
		$errmsg_arr[] = 'keterangan Kosong';
		$errflag = true;
	}
    

	if($errflag) {
		$_SESSION['ERRMSG_ARR'] = $errmsg_arr;
        print_r($errmsg_arr);
		session_write_close();
        echo '<script language="javascript">';
        echo 'alert(' . $errmsg_arr . ')';
        echo '</script>';
		//header("location: penugasan.php");
		exit();
	}

    echo $nama_ruang . $gedung . $keterangan;

		//Create INSERT query

        $sql = "INSERT INTO `data_ruang` (ruang, lantai, gedung, keterangan) VALUES ( '$nama_ruang' ,'$lantai', ' $gedung', '$keterangan')";
        $result = $conn->query($sql);

		//Check whether the query was successful or not
		if($result) {
			$_SESSION['MSGS'] = array('<strong>Selamt </strong> Perubahan Berhasil');
			session_write_close();
			header("location: daftar-ruang.php");
			exit();
		} else {
			die("Query failed: ".mysqli_error( $conn));
		}
	
}
?>