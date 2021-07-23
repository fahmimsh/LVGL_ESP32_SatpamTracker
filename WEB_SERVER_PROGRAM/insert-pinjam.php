<?php
require_once('config.php'); 

$conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

if(is_array($_POST) && count($_POST) > 0) {
    $nama = $_POST['nama'];
	$nrp = $_POST['nrp'];
    $hp = $_POST['hp'];
	$ruang = $_POST['ruang'];
    $date = $_POST['date'];
	$waktu1 = $_POST['waktu1'];
    $waktu2 = $_POST['waktu2'];
	$keperluan = $_POST['keperluan'];

	$errflag = false;

	if($nama == '') {
		$errmsg_arr[] = 'Tugas Kosong';
		$errflag = true;
	}
    if($nrp == '') {
		$errmsg_arr[] = 'nrp Kosong';
		$errflag = true;
	}
    if($hp == '') {
		$errmsg_arr[] = 'No Hp Kosong';
		$errflag = true;
	}
    if($ruang == '') {
		$errmsg_arr[] = 'Nama Ruang Kosong';
		$errflag = true;
	}
    if($date == '') {
		$errmsg_arr[] = 'Tanggal Kosong';
		$errflag = true;
	}
    if($waktu1 == '') {
		$errmsg_arr[] = 'Waktu Mulai Kosong';
		$errflag = true;
	}
    if($waktu2 == '') {
		$errmsg_arr[] = 'Waktu Berakhir Kosong';
		$errflag = true;
	}
    if($keperluan == '') {
		$errmsg_arr[] = 'Keperluan Kosong';
		$errflag = true;
	}

    $sql = ("SELECT ruang FROM data_pinjaman WHERE tanggal_dipinjam = '$date'");
    $result = $conn->query($sql);  
        if(mysqli_num_rows($result) != 0) {
            $errmsg_arr[] = 'Ruang Telah Digunakan Pada Tanggal Tersebut';
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

    echo $nama . $nrp . $hp . $ruang . $date . $waktu1 . $waktu2 . $keperluan;

		//Create INSERT query

        $sql = "INSERT INTO `data_pinjaman` (`ruang`, `keperluan`, `waktu1`, `waktu2`, `nama`, `nrp`, `no_hp`, `tanggal_dipinjam`) 
        VALUES ( '$ruang' , '$keperluan', '$waktu1', '$waktu2 ', '$nama', '$nrp', '$hp', '$date')";
        $result = $conn->query($sql);

		//Check whether the query was successful or not
		if($result) {
			$_SESSION['MSGS'] = array('<strong>Selamt </strong> Perubahan Berhasil');
			session_write_close();
			header("location: jadwal-ruang.php");
			exit();
		} else {
			die("Query failed: ".mysqli_error( $conn));
		}
	
}
?>