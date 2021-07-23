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
require_once('config.php'); 

$conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

$sql = "SELECT * FROM data_presensi";
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
                                                <th>ID Data</th>
                                                <th>NIP</th>
                                                <th>Nama</th>
                                                <th>Posisi</th>
                                                <th>Waktu Presensi</th>
                                            </tr>
                                        </thead>
                                        <tbody>
                                        <?php
                                        while($row = $result->fetch_assoc()) {
                                            echo 

                                            "<tr>
                                                <td>".$row["id"]."</td>
                                                <td>".$row["u_id"]."</td>
                                                <td>".$row["nama"]."</td>
                                                <td>".$row["posisi"]."</td>
                                                <td>".$row["date"]."</td>
                                            </tr>";}
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
include 'footer.php';
?>
</body>