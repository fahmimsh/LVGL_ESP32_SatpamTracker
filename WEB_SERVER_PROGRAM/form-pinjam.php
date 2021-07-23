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


$sql = "SELECT * FROM data_ruang";
$result = $conn->query($sql);

$ruang;

if ($result->num_rows > 0) {
  // output data of each row
  while($row = mysqli_fetch_object($result)) {
	$ruang[] = $row;
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
                                <i class="fas fa-edit mr-1"></i>
                                Form Peminjaman Ruang
                            </div>
                            
                            <div class="card-body"> <canvas id="myAreaChart" width="100%" height="40"></canvas>
                            <div class="col-md-5">
                                            <form class="form-horizontal" action="insert-pinjam.php" method="POST" enctype="multipart/form-data">
                                            <div class="form-group">
                                                    <label for="nama" class="control-label col-md-4">Nama Peminjam</label>
                                                        <div class="col-md-8">
                                                            <input type="text" class="form-control" name="nama" id="nama">
                                                        </div>
                                                    </div>
                                                    <div class="form-group">
                                                    <label for="nrp" class="control-label col-md-4">NRP</label>
                                                        <div class="col-md-8">
                                                            <input type="text" class="form-control" name="nrp" id="nrp">
                                                        </div>
                                                    </div>
                                                    <div class="form-group">
                                                    <label for="hp" class="control-label col-md-4">No. HP</label>
                                                        <div class="col-md-8">
                                                            <input type="text" class="form-control" name="hp" id="hp">
                                                        </div>
                                                    </div>
                                                    <div class="form-group">
                                                        <label for="ruang" class="control-label col-md-4">Ruangan</label>
                                                        <div class="col-md-8">
                                                            <select class="form-control" name="ruang" id="ruang">
                                                                <option value="">----</option>
                                                                <?php
                                                                foreach ($ruang as $ruangs) {
                                                                echo '<option value="'.$ruangs->ruang .'">'. $ruangs->gedung . ' - ' . $ruangs->ruang.'</option>';
                                                                }
                                                                ?>
                                                            </select>
                                                        </div>
                                                    </div>
                                                <div class="form-group">
                                                    <label for="date" class="control-label col-md-4">Tanggal Digunakan</label>
                                                    <div class="col-md-8">
                                                        <input type="date" name="date" id="datepickerxxx " value="" />
                                                    </div>

                                                    <div class="form-group">
                                                    <label for="waktu" class="control-label col-md-4">Jam Digunakan</label>
                                                    <div class="col-md-8">
                                                        <input type="time" name="waktu1" id="timepicker " value="" />
                                                        -
                                                        <input type="time" name="waktu2" id="timepicker " value="" />
                                                    </div>
                                                </div>
                                                <div class="form-group">
                                                    <label for="keperluan" class="control-label col-md-4">Keperluan</label>
                                                    <div class="col-md-8">
                                                        <textarea type="text" class="form-control" name="keperluan" id="keperluan"></textarea>
                                                    </div>
                                                </div>
                                                <div class="modal-footer">
                                        <button type="submit" class="btn btn-primary">Submit</button>
                                    </div>

                                </form>
                </div><!-- /col-md-2 -->

                <br>
                            </div>
                        </div>
                    </div>
                </main>

<?php
include 'footer.php';
?>
</body>