<?php
require_once('config.php'); 

$conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

if(is_array($_POST) && count($_POST) > 0) {
    $api_key = $_POST['API'];
    $gedung = $_POST['gedung'];
	$ruang = $_POST['ruang'];
    $status = $_POST['status'];
	$ket = $_POST['ket'];
    $eid= $_POST['e_id'];
	$uid = $_POST['u_id'];


	$errflag = false;

	if($api_key == '') {
		$errmsg_arr[] = 'Tugas Kosong';
		$errflag = true;
	}
    if($gedung == '') {
		$errmsg_arr[] = 'nrp Kosong';
		$errflag = true;
	}
    if($ruang == '') {
		$errmsg_arr[] = 'No Hp Kosong';
		$errflag = true;
	}
    if($status == '') {
		$errmsg_arr[] = 'Nama Ruang Kosong';
		$errflag = true;
	}
    if($ket == '') {
		$errmsg_arr[] = 'Tanggal Kosong';
		$errflag = true;
	}
    if($eid == '') {
		$errmsg_arr[] = 'Waktu Mulai Kosong';
		$errflag = true;
	}
    if($uid == '') {
		$errmsg_arr[] = 'Waktu Berakhir Kosong';
		$errflag = true;
	}


    $sql = ("SELECT * FROM data_alat WHERE api_key = '$api_key'");
    $result = $conn->query($sql);  
        if(mysqli_num_rows($result) == 0) {
            $errmsg_arr[] = 'API KEY SALAH';
            $errflag = true;
        } 

    $sql = ("SELECT * FROM data_satpam WHERE nip = '$uid'");
    $result = $conn->query($sql);  
        if(mysqli_num_rows($result) == 0) {
             $errmsg_arr[] = 'Pengirim Tidak Dikenal';
             $errflag = true;
         } 

    $sql = ("SELECT * FROM data_ruang WHERE ruang = '$ruang'");
    $result = $conn->query($sql);  
        if(mysqli_num_rows($result) == 0) {
          $errmsg_arr[] = 'Ruang Tidak Ditemukan';
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

    $laitaiq = get_lantai($ruang);
    $orangan = get_pengecek($uid);
    echo $laitaiq;
    echo $$orangan;



		//Create INSERT query

        $sql = "INSERT INTO `status_ruang` (`lantai`, `gedung`, `ruangan`, `status`, `keterangan`, `pengecek`) 
        VALUES ( '$laitaiq ' , '$gedung', '$ruang', '$status ', '$ket', '$orangan')";
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

function get_lantai($ruanganq){
    require_once('config.php');

    $conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
    // Check connection
    if ($conn->connect_error) {
      die("Connection failed: " . $conn->connect_error);
    }
    
    
    $sql = "SELECT lantai FROM data_ruang WHERE ruang = '$ruanganq'";
    $result = $conn->query($sql);
    
    if ($result->num_rows > 0) {
      // output data of each row
      while($row = mysqli_fetch_array($result)) {
       return $row['lantai'];
    }
  }

}
function get_pengecek($uuid){
    require_once('config.php');

    $conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
    // Check connection
    if ($conn->connect_error) {
      die("Connection failed: " . $conn->connect_error);
    }
    
    
    $sql = "SELECT nama FROM data_satpam WHERE nip = '$uuid'";
    $result = $conn->query($sql);
    
    if ($result->num_rows > 0) {
      // output data of each row
      while($row = mysqli_fetch_array($result)) {
       return $row['nama'];
        
    }}
    
}
?>