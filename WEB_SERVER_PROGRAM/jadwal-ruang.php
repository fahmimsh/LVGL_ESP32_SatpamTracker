<?php
//Start session
session_start();
include 'head.php';
?>

<body class="sb-nav-fixed">
<?php
include 'nav.php';

if(!isset($_SESSION)) session_start();
//Include database connection details
require_once('config.php'); 

$conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}


$sql = "SELECT * FROM data_pinjaman";
$result = $conn->query($sql);

$pinjam;

if ($result->num_rows > 0) {
  // output data of each row
  while($row = mysqli_fetch_object($result)) {
	$pinjam[] = $row;
}}

?>
<div id="layoutSidenav_content">
                <main>
                    <div class="container-fluid">
                        <div class="row">
                        </div>
                        <div class="row">
                        </div>
                        <div class="card mb-4">
                            <div class="card-header">
                                <i class="fas fa-table mr-1"></i>
                                Data Presensi Satpam
                            </div>
                            
                            <div class="card-body">
                                 
 
                                <div class="table-responsive">
                                <table border="0" cellspacing="5" cellpadding="5">
                                <tbody>
                                <tr>
                                    <td>Tanggal:</td>
                                    <td><input type="text" id="max" name="max"></td>
                                </tr>
                                </tbody></table>
                                    <table class="table table-bordered" id="tabel-dataa" width="100%" height="40" cellspacing="0">
                                        <thead>
                                            <tr>
                                                <th>Gedung</th>
                                                <th>Ruangan</th>
                                                <th>Keperluan</th>
                                                <th>Tanggal Dipinjam</th>
                                                <th>Tanggal Digunakan</th>
                                                <th>Waktu Digunakan</th>
                                                <th>Nama Peminjam</th>
                                                <th>NRP</th>
                                                <th>No. HP Peminjam</th>
                                                <th>Status</th>
                                            </tr>
                                        </thead>
                                        <tbody>
                                        <?php
                                        foreach ($pinjam as $pinjams) {
                                        ?>
                                        <?php echo "<tr>
                                        <td>" . getdatafromdb($pinjams->ruang ). "</td>"?>
                                        <?php  echo "<td>". $pinjams->ruang . "</td>" ?>
                                        <?php  echo "<td>" . $pinjams->keperluan . "</td>" ?>
                                        <?php echo "<td>" . $pinjams->tanggal_masuk . "</td>" ?>
                                        <?php echo "<td>" . $pinjams->tanggal_dipinjam . "</td>" ?>
                                        <?php echo "<td>" . date("h:i:sa",strtotime($pinjams->waktu1)) . "=>" . date("h:i:sa",strtotime($pinjams->waktu2)) . "</td>" ?>
                                        <?php echo "<td>" . $pinjams->nama . "</td>" ?>
                                        <?php echo "<td>" . $pinjams->nrp . "</td>" ?>
                                        <?php echo "<td>" . $pinjams->no_hp . "</td>" ?>
                                        <?php echo '<td class="text-center"><a href="delete-pinjam.php?delete=' . $pinjams->id . '"><button type="button" class="btn btn-default" >Hapus</button></a></td></tr>'?>
                                        
                                        <?php
                                            }
                                        ?>
                                        </tbody>
                                    </table>
                                </div>
                            </div>
                        </div>
                    </div>
                </main>

<?php

function getdatafromdb($ruanganq){

    require_once('config.php');

    $conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
    // Check connection
    if ($conn->connect_error) {
      die("Connection failed: " . $conn->connect_error);
    }
    
    
    $sql = "SELECT gedung FROM data_ruang WHERE ruang = '$ruanganq'";
    $result = $conn->query($sql);
    
    if ($result->num_rows > 0) {
      // output data of each row
      while($row = mysqli_fetch_array($result)) {
       return $row['gedung'];
        
    }}

 

}


include 'footer.php';
?>
</body>