<?php

if(is_array($_POST) && count($_POST) > 0 ) {

$nama = $_POST['nama'];
$email = $_POST['email'];
$pass = $_POST['password'];

require_once('config.php'); 

$conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

if( isset( $nama ) && isset( $email ) && isset( $pass ) ) {
    $sql = "INSERT INTO `tbl_user`(`user_name`, `password`, `user_email`, `user_is_admin`) VALUES ('$nama','$pass','$email','1')";
        $result = $conn->query($sql);

		//Check whether the query was successful or not
		if($result) {
			session_write_close();
			header("location: admin.php");
            echo '<script language="javascript">';
            echo 'alert("Data Tersimpan")';
            echo '</script>';
			exit();
		} else {
			die("Query failed: ".mysqli_error( $conn));
		}

}
else{
    echo '<script language="javascript">';
    echo 'alert("Data KOSOSNG")';
    echo '</script>';
}






}
?>