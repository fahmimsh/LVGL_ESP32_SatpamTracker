<?php
//Start session
session_start();
include 'head.php';
?>


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


$sql2 = "SELECT COUNT(*) FROM data_presensi WHERE DATE(date) = DATE(NOW())";
$result = $conn->query($sql2);

$absen;

if ($result->num_rows > 0) {
  // output data of each row
  while($row = mysqli_fetch_array($result)) {
	$absen = $row['COUNT(*)'];
}}

$sql2 = "SELECT COUNT(nama) FROM data_satpam";
$result = $conn->query($sql2);

$orang;

if ($result->num_rows > 0) {
  // output data of each row
  while($row = mysqli_fetch_array($result)) {
	$orang = $row['COUNT(nama)'];
}}


$sql2 = "SELECT COUNT(*) FROM status_ruang WHERE tanggal = CURDATE()";
$result = $conn->query($sql2);

$ruang;

if ($result->num_rows > 0) {
  // output data of each row
  while($row = mysqli_fetch_array($result)) {
	$ruang = $row['COUNT(*)'];
}}


$sql2 = "SELECT COUNT(ruang) FROM data_ruang";
$result = $conn->query($sql2);

$ruangan;

if ($result->num_rows > 0) {
  // output data of each row
  while($row = mysqli_fetch_array($result)) {
	$ruangan = $row['COUNT(ruang)'];
}}

$sql3 = "SELECT * FROM tugas_satpam";
$result = $conn->query($sql3);

$tugas_satpam;

if ($result->num_rows > 0) {
  // output data of each row
  while($row = mysqli_fetch_object($result)) {
	$tugas_satpam[] = $row;
}}

$sql = "SELECT * FROM data_pinjaman WHERE tanggal_dipinjam = CURDATE()";
$result = $conn->query($sql);

$pinjam = array();

if ($result->num_rows > 0) {
  // output data of each row
  while($row = mysqli_fetch_object($result)) {
	$pinjam[] = $row;
}}

?>


?>
<body class="sb-nav-fixed">
            <div id="layoutSidenav_content">
                <main>
                    <div class="container-fluid">
                        <h1 class="mt-4">Dashboard</h1>
                        
                        <div class="row">
                            <div class="col-xl-4 col-md-6">
                                <div class="card bg-primary text-white mb-4">
                                <div class="card-footer d-flex align-items-center justify-content-between">
                                        <a class="small text-white stretched-link" href="#">Waktu Sekarang</a>
                                    </div>
                                    <div class="card-body"><H1><?php echo  date("h:i:sa"); ?></H1><br><H2><?php echo date("Y/m/d"); ?></H2> </div>
                                </div>
                            </div>

                            <div class="col-xl-4 col-md-6">
                                <div class="card bg-primary text-white mb-4">
                                <div class="card-footer d-flex align-items-center justify-content-between">
                                        <a class="small text-white stretched-link" href="#">Total Ruangan Dicek Hari Ini</a>
                                    </div>
                                    <div class="card-body"><H1><?php echo  $ruang; ?></H1><br><H2><?php echo "Dari " . $ruangan . " Ruangan"; ?></H2> </div>
                                </div>
                            </div>
                            <div class="col-xl-4 col-md-6">
                                <div class="card bg-primary text-white mb-4">
                                <div class="card-footer d-flex align-items-center justify-content-between">
                                        <a class="small text-white stretched-link" href="#">Total Satpan Yang Sudah Presensi Hari Ini</a>
                                    </div>
                                    <div class="card-body"><H1><?php echo  $absen; ?></H1><br><H2><?php echo "Dari " . $orang . " Orang"; ?></H2> </div>
                                </div>
                            </div>
                        </div>
                            
                        
                        <div class="card mb-4">
                            <div class="card-header">
                                <i class="fas fa-table mr-1"></i>
                                Penugasan
                            </div>

                            <div class="card-body">
                            <div class="table-responsive">
                                    <table class="table table-bordered" id="dataTable" width="100%" cellspacing="0">
                                        <thead>
                                            <tr>
                                                <th>Id</th>
                                                <th>Nama</th>
                                                <th>Tugas</th>
                                                <th>Keterangan</th>
                                                <th>Tanggal</th>
                                                <th>Hapus</th>
                                            </tr>
                                        </thead>

                                        <tbody>
                                        
                                        <?php
                                        foreach ($tugas_satpam as $tugas_satpamx) {
                                        ?>
                                        <?php echo "<tr>
                                        <td>" . $tugas_satpamx->id . "</td>"?>
                                        <?php  echo "<td>". $tugas_satpamx->nama . "</td>" ?>
                                        <?php  echo "<td>" . $tugas_satpamx->tugas . "</td>" ?>
                                        <?php echo "<td>" . $tugas_satpamx->keterangan . "</td>" ?>
                                        <?php echo "<td>" . $tugas_satpamx->tanggal . "</td>" ?>
                                        <?php echo '<td class="text-center"><a href="delete-penugasan.php?delete=' . $tugas_satpamx->id . '"><button type="button" class="btn btn-default" >Hapus</button></a></td></tr>'?>
                                        
                                        <?php
                                            }
                                        ?>
                                        </tbody>


                                    </table>
                                </div>
                            </div>
                        </div>

                        <div class="card mb-4">
                            <div class="card-header">
                                <i class="fas fa-table mr-1"></i>
                                Daftar Ruangan Dipinjam Hari Ini
                            </div>
                            
                            <div class="card-body">
                            <div class="table-responsive">
                                    <table class="table table-bordered" id="dataTablex" width="100%" cellspacing="0">
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
        
    }
  }
}
include 'footerv2.php';
?>
</body>