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


$sql3 = "SELECT * FROM data_ruang";
$result = $conn->query($sql3);

$data_ruang;

if ($result->num_rows > 0) {
  // output data of each row
  while($row = mysqli_fetch_object($result)) {
	$data_ruang[] = $row;
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
                                Daftar Ruangan
                            </div>
                            
                            <div class="card-body"> <canvas id="myAreaChart" width="100%" height="40"></canvas>
                            <div class="col-md-2">
                                <button type="button" class="btn btn-primary btn-block" data-toggle="modal" data-target="#add-product"><span class="glyphicon glyphicon-plus-sign"></span> Tambah Ruangan</button>

                                <div class="modal fade" id="add-product" tabindex="-1" role="dialog" aria-hidden="true">
                                    <div class="modal-dialog">
                                        <div class="modal-content">
                                            <form class="form-horizontal" action="insert-ruang.php" method="POST" enctype="multipart/form-data">
                                                <div class="modal-header">
                                                    <h4 class="modal-title">Tambahkan Ruang</h4>
                                                </div>
                                                <div class="modal-body">
                                                <div class="form-group">
                                                    <label for="ruang" class="control-label col-md-4">Nama Ruangan</label>
                                                        <div class="col-md-8">
                                                            <input type="text" class="form-control" name="ruang" id="ruang">
                                                        </div>
                                                    </div>
                                                    <div class="form-group">
                                                        <label for="lantai" class="control-label col-md-4">Lantai</label>
                                                        <div class="col-md-8">
                                                            <select class="form-control" name="lantai" id="lantai">
                                                                <option value="">----</option>
                                                                <option value="1">1</option>
                                                                <option value="2">2</option>
                                                                <option value="3">3</option>
                                                                <option value="4">4</option>
                                                                <option value="5">5</option>
                                                                <option value="6">6</option>
                                                                <option value="7">7</option>
                                                                <option value="8">8</option>
                                                                <option value="9">9</option>
                                                                <option value="10">10</option>
                                                                <option value="11">11</option>
                                                                <option value="12">12</option>

                                                                
                                                               
                                                            </select>
                                                        </div>
                                                    </div>
                                                    <div class="form-group">
                                                        <label for="gedung" class="control-label col-md-4">Gedung</label>
                                                        <div class="col-md-8">
                                                            <select class="form-control" name="gedung" id="gedung">
                                                                <option value="">----</option>
                                                                <option value="D3">Gedung D3</option>
                                                                <option value="D4">Gedung D4</option>
                                                                <option value="Pasca Sarjana">Gedung Pasca Sarjana</option>
                                                               
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
                                                <th>Ruangan</th>
                                                <th>Lantai</th>
                                                <th>Gedung</th>
                                                <th>Keterangan</th>
                                                <th>Hapus</th>

                                            </tr>
                                        </thead>
                                        <tbody>
                                        
                                        <?php
                                        foreach ($data_ruang as $data_ruangx) {
                                        ?>
                                        <?php  echo "<td>" . $data_ruangx->ruang . "</td>" ?>
                                        <?php  echo "<td>" . $data_ruangx->lantai . "</td>" ?>
                                        <?php echo "<td>" . $data_ruangx->gedung . "</td>" ?>
                                        <?php echo "<td>" . $data_ruangx->keterangan . "</td>" ?>
                                        <?php echo '<td class="text-center"><a href="delete-ruang.php?delete=' . $data_ruangx->id . '"><button type="button" class="btn btn-default" >Hapus</button></a></td></tr>'?>
                                        
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