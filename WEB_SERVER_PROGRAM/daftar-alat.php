<?php
//Start session
session_start();
include 'head.php';
?>

<body class="sb-nav-fixed">
<?php
include 'nav.php';
?>

<?php

function generateRandomString($length = 10) {
    $characters = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
    $charactersLength = strlen($characters);
    $randomString = '';
    for ($i = 0; $i < $length; $i++) {
        $randomString .= $characters[rand(0, $charactersLength - 1)];
    }
    return $randomString;
}



require_once('config.php'); 

$conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

function getlastestinfo($iddata){

    require_once('config.php'); 

        $conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
        // Check connection
            if ($conn->connect_error) {
                die("Connection failed: " . $conn->connect_error);
            }   


    $sql2 = "SELECT * FROM data_masuk WHERE u_id = $iddata ORDER BY date DESC LIMIT 1";
    $result2 = $conn->query($sql2);

    if ($result2->num_rows > 0) {
        while($row2 = $result2->fetch_assoc()) {
            $datedata = $row2["date"];
        }
        return $datedata;
    }
    else {
        return "in active";
    }
    
    
}

$sql = "SELECT * FROM data_alat";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
  // output data of each row

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
                                Data Satpam
                            </div>
                            <div class="card-body"> <canvas id="myAreaChart" width="100%" height="40"></canvas>
                            <div class="col-md-2">
                                <button type="button" class="btn btn-primary btn-block" data-toggle="modal" data-target="#add-product"><span class="glyphicon glyphicon-plus-sign"></span> Tambah Alat</button>

                                <div class="modal fade" id="add-product" tabindex="-1" role="dialog" aria-hidden="true">
                                    <div class="modal-dialog">
                                        <div class="modal-content">
                                            <form class="form-horizontal" action="insert-alat.php" method="POST" enctype="multipart/form-data">
                                                <div class="modal-header">
                                                    <h4 class="modal-title">Tambah Alat</h4>
                                                </div>
                                                <div class="modal-body">
                                                <div class="form-group">
                                                        <label for="alat" class="control-label col-md-4">Nama Alat</label>
                                                        <div class="col-md-8">
                                                            <input type="text" class="form-control" name="alat" id="alat">
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
                                <div class="table-responsive">
                                    <table class="table table-bordered" id="dataTable" width="100%" cellspacing="0">
                                        <thead>
                                            <tr>
                                                <th>ID alat</th>
                                                <th>Nama Alat</th>
                                                <th>API Key</th>
                                                <th>Tanggal Ditambahkan</th>
                                                <th>Terakhir Aktif</th>
                                                <th>Hapus</th>
                                            </tr>
                                        </thead>
                                        <tbody>
                                        <?php
                                          while($row = $result->fetch_assoc()) {
                                            echo 
                                        
                                            "<tr>
                                                <td>" . $row["e_id"] . "</td>
                                                <td>" . $row["nama"] . "</td>
                                                <td>"  . $row["api_key"] . "</td>
                                                <td>" . $row["tanggal"] . "</td>
                                                <td>" . getlastestinfo($row["e_id"]) . '</td>
                                                <td class="text-center"><a href="delete-alat.php?delete=' . $row["e_id"] . '"><button type="button" class="btn btn-default" >Hapus</button></a></td></tr>';}
                                            ?>
                                        </tbody>
                                    </table>
                                </div>
                            </div>
                        </div>
                    </div>
                </main>

                <?php
  }
 else {
  echo "0 results";
}
$conn->close();
include 'footerv2.php';
?>
</body>