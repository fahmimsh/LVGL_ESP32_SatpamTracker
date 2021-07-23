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


$sql = "SELECT * FROM data_satpam";
$result = $conn->query($sql);

$satpam;

if ($result->num_rows > 0) {
  // output data of each row
  while($row = mysqli_fetch_object($result)) {
	$satpam[] = $row;
}}

$sql2 = "SELECT * FROM data_tugas";
$result = $conn->query($sql2);

$tugas;

if ($result->num_rows > 0) {
  // output data of each row
  while($row = mysqli_fetch_object($result)) {
	$tugas[] = $row;
}}

$sql3 = "SELECT * FROM tugas_satpam";
$result = $conn->query($sql3);

$tugas_satpam;

if ($result->num_rows > 0) {
  // output data of each row
  while($row = mysqli_fetch_object($result)) {
	$tugas_satpam[] = $row;
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
                                Daftar Penugasan
                            </div>
                            
                            <div class="card-body"> <canvas id="myAreaChart" width="100%" height="40"></canvas>
                            <div class="col-md-2">
                                <button type="button" class="btn btn-primary btn-block" data-toggle="modal" data-target="#add-product"><span class="glyphicon glyphicon-plus-sign"></span> Tambah Penugasan</button>

                                <div class="modal fade" id="add-product" tabindex="-1" role="dialog" aria-hidden="true">
                                    <div class="modal-dialog">
                                        <div class="modal-content">
                                            <form class="form-horizontal" action="insert-penugasan.php" method="POST" enctype="multipart/form-data">
                                                <div class="modal-header">
                                                    <h4 class="modal-title">Tambahkan Penugasan</h4>
                                                </div>
                                                <div class="modal-body">
                                                    <div class="form-group">
                                                        <label for="nama" class="control-label col-md-4">Nama Satpam</label>
                                                        <div class="col-md-8">
                                                            <select class="form-control" name="nama" id="nama">
                                                                <option value="">----</option>
                                                                <?php
                                                                foreach ($satpam as $satpams) {
                                                                echo '<option value="'.$satpams->nama.'">'.$satpams->nama.'</option>';
                                                                }
                                                                ?>
                                                            </select>
                                                        </div>
                                                    </div>
                                                    <div class="form-group">
                                                    <label for="tugas" class="control-label col-md-4">Tugas</label>
                                                        <div class="col-md-8">
                                                            <select class="form-control" name="tugas" id="tugas">
                                                                <option value="">----</option>
                                                                <?php
                                                                foreach ($tugas as $tugass) {
                                                                echo '<option value="'.$tugass->tugas.'">'.$tugass->tugas.'</option>';
                                                                }
                                                                ?>
                                                            </select>
                                                        </div>
                                                    </div>
                                                <div class="form-group">
                                                    <label for="keterangan" class="control-label col-md-4">Keterangan</label>
                                                    <div class="col-md-8">
                                                        <textarea type="text" class="form-control" name="keterangan" id="keterangan"></textarea>
                                                    </div>
                                                </div>
                                            
                                    </div>
                                    <div class="modal-footer">
                                        <button type="button" class="btn btn-default" data-dismiss="modal">Close</button>
                                        <button type="submit" class="btn btn-primary">Add</button>
                                    </div>
                                </form>
                            </div><!-- /.modal-content -->
                        </div><!-- /.modal-dialog -->
                    </div><!-- /.modal -->
                </div><!-- /col-md-2 -->

                <br>
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
                    </div>
                </main>

<?php
include 'footerv2.php';
?>
</body>