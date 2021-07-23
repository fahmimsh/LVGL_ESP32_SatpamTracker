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


$sql2 = "SELECT * FROM data_tugas";
$result = $conn->query($sql2);

$tugasxx;

if ($result->num_rows > 0) {
  // output data of each row
  while($row = mysqli_fetch_object($result)) {
	$tugasxx[] = $row;
}}

//handle delete request


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
                                Daftar Tugas
                            </div>
                            
                            <div class="card-body"> <canvas id="myAreaChart" width="100%" height="40"></canvas>
                            <div class="col-md-2">
                                <button type="button" class="btn btn-primary btn-block" data-toggle="modal" data-target="#add-product"><span class="glyphicon glyphicon-plus-sign"></span> Tambah Penugasan</button>

                                <div class="modal fade" id="add-product" tabindex="-1" role="dialog" aria-hidden="true">
                                    <div class="modal-dialog">
                                        <div class="modal-content">
                                            <form class="form-horizontal" action="insert-data-tugas.php" method="POST" enctype="multipart/form-data">
                                                <div class="modal-header">
                                                    <h4 class="modal-title">Tambahkan Penugasan</h4>
                                                </div>
                                                <div class="modal-body">
                                                <div class="form-group">
                                                        <label for="tugas" class="control-label col-md-4">Nama Tugas</label>
                                                        <div class="col-md-8">
                                                            <input type="text" class="form-control" name="tugas" id="tugas">
                                                        </div>
                                                    </div>
                                                    <div class="form-group">
                                                    <label for="tugdesc" class="control-label col-md-4">Diskripsi Tugas</label>
                                                    <div class="col-md-8">
                                                        <textarea type="text" class="form-control" name="tugdesc" id="tugdesc"></textarea>
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
                                                <th>Tugas</th>
                                                <th>Diskripsi</th>
                                                <th>Hapus</th>
                                            </tr>
                                        </thead>
                                        <tbody>
                                        <?php
                                        foreach ($tugasxx as $tugasxxx) {
                                        ?>
                                        <tr>
                                        <td><?php echo $tugasxxx->tugas ?></td>
                                        <td><?php echo $tugasxxx->tgs_description ?></td>
                                        <td class="text-center"><a href="delete-data-tugas.php?delete=<?php echo $tugasxxx->tugas ?>"><button type="button" class="btn btn-default" >Hapus</button></a></td>
                                        </tr>
                                        <?php
                                            }
                                        ?><tr>
                                            </tr>
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