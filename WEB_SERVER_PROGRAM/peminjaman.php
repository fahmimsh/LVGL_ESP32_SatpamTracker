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

$sql = "SELECT * FROM data_pinjaman";
$result = $conn->query($sql);

$pinjaman;

if ($result->num_rows > 0) {
  // output data of each row
  while($row = mysqli_fetch_object($result)) {
	$pinjaman[] = $row;
}}  

//$sql = "SELECT ruang.* FROM ruang WHERE NOT EXISTS(SELECT 1 FROM data_pinjaman WHERE data_pinjaman.ruang=ruang.ruang)";
$sql = "SELECT ruang FROM ruang";
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
                <div class="container-fluid " style="padding:50px; background: #FFFFFF;box-shadow: 4px 4px 19px rgba(0, 0, 0, 0.25);border-radius: 12px;">
                        <div class="row">
                        </div>
                        <div class="row">
                        
                        </div>
                        <div class="card mb-4">
                            
                            <div class="card-body">
                                 
 
                                <div class="table-responsive" >
                                
                                <div class="row" style="padding-bottom: 25px;">
                    <div class="col-4">
                    <H4>Jadwal Peminjaman Ruangan</H4>
                    
                    
                    </div>
                    <div class="col-8" style="display: flex;justify-content: flex-end;" >
                    <table border="0" cellspacing="5" cellpadding="5"  >
                                <tbody  >
                                <tr>
                                    <td>Tanggal Digunakan:</td>
                                    <td><input type="text" id="max" name="max"></td>
                                    <td><button type="button" class="btn text-light" style="background: #655E8B;border-radius: 32px;  float: right;" data-toggle="modal" data-target="#exampleModal">Tambah Peminjaman</button></td>
                                </tr>
                                </tbody></table>
                    </div>
                    </div>
                                
                                    <table id="tabel-dataa" width="100%" height="40" cellspacing="0" class="table table-striped table-dark" style="background: #36315B; ">
                                        <thead class="text-light">
                                            <tr>
                                                <th>No</th>
                                                <th>Ruang</th>
                                                <th>Waktu Digunakan</th>
                                                <th>Keperluan</th>
                                                <th>Nama Peminjam</th>
                                                <th>Tgl Dipinjam</th>
                                                <th>NRP</th>
                                                <th>No Hp Peminjam</th>
                                                <th>Status</th>
                                            </tr>
                                        </thead>
                                        <tbody>
                                        <?php
                                        $count = 0; 
                                        foreach ($pinjaman as $pinjamans) {
                                            $startdate = strtotime($pinjamans->waktu1);
                                            $enddate = strtotime($pinjamans->waktu2);
                                        ?>
                                        
                                        <?php echo "<tr>
                                        <td>" . $count . "</td>"?>
                                        <?php  echo "<td>". $pinjamans->ruang . "</td>" ?>
                                        <?php  echo "<td>". date("h:i", $startdate) ."-". date("h:i", $enddate) . "</td>" ?>                                       
                                        <?php  echo "<td>". $pinjamans->keperluan  . "</td>" ?>
                                        <?php  echo "<td>". $pinjamans->nama  . "</td>" ?>
                                        <?php  echo "<td>". $pinjamans->tanggal_dipinjam . "</td>" ?>
                                        <?php  echo "<td>". $pinjamans->nrp  . "</td>" ?>
                                        <?php  echo "<td>". $pinjamans->no_hp  . "</td>" ?>
                                        <?php  echo "<td>";
                                        if($pinjamans->status == 1){
                                            echo "Sudah Dicek"  . "</td></tr>"; 
                                        }
                                        else{
                                            echo "Belum Dicek"  . "</td></tr>";
                                        }?>
                                        <?php
                                        $count++;
                                            }
                                        ?>
                                        </tbody>
                                    </table>
                                </div>
                            </div>
                        </div>
                    </div>

                    <!-- Modal -->
      <div class="modal fade " id="exampleModal" tabindex="-1" role="dialog" aria-labelledby="exampleModalLabel" aria-hidden="true">
         <div class="modal-dialog modal-lg" role="document">
            <div class="modal-content">
               <div class="modal-header">
                  <h5 class="modal-title" id="exampleModalLabel">Tambah Peminjaman</h5>
                  <button type="button" class="close" data-dismiss="modal" aria-label="Close">
                  <span aria-hidden="true">&times;</span>
                  </button>
               </div>
               <div class="modal-body">
                  <form role="form" action="api_tambah_pinjam.php" method="post">
                     <div class="form-group">
                        <div class="container">
                           <div class="row">
                              <div class="col-sm">
                                 <p>
                                    <label for="nama">Nama:</label>
                                    <input type="text" name="nama" id="nama" style="background: #F4ECFF;border: 1px solid #655E8B;box-sizing: border-box;border-radius: 32px;">
                                 </p>
                                 <p>
                                    <label for="nrp">NRP:</label><br>
                                    <input type="text" name="nrp" id="nrp" style="background: #F4ECFF;border: 1px solid #655E8B;box-sizing: border-box;border-radius: 32px;">
                                 </p>
                                 <p>
                                    <label for="no_hp">No HP:</label>
                                    <input type="text" name="no_hp" id="no_hp" style="background: #F4ECFF;border: 1px solid #655E8B;box-sizing: border-box;border-radius: 32px;">
                                 </p>
                              </div>
                              <div class="col-sm">
                                 <p>
                                    <label for="ruangan">Ruangan:</label><br>
                                    <select id="ruangan" name="ruangan" style="width:180px;background: #F4ECFF;border: 1px solid #655E8B;box-sizing: border-box;border-radius: 32px;">
                                    <?php
                                    foreach ($ruang as $ruangs) {
                                        echo '<option value="'.$ruangs->ruang.'">'.$ruangs->ruang.'</option>';
                                    }
                                        ?>
                                    </select>
                                 </p>
                                 <p>
                                    <label for="keperluan">Keperluan:</label>
                                    <input type="text" name="keperluan" id="keperluan" style="background: #F4ECFF;border: 1px solid #655E8B;box-sizing: border-box;border-radius: 32px;">
                                 </p>
                              </div>
                              <div class="col-sm">
                                 <p>
                                    <label for="tgl">Tanggal Digunakan:</label>
                                    <input type="date" name="tgl" id="tgl" style="background: #F4ECFF;border: 1px solid #655E8B;box-sizing: border-box;border-radius: 32px;">
                                 </p>
                                 <p>
                                    <label for="waktu1">Waktu Digunakan:</label><br>
                                    <input type="time" name="waktu1" id="waktu1" size="4" style="background: #F4ECFF;border: 1px solid #655E8B;box-sizing: border-box;border-radius: 32px;">
                                    -
                                    <input type="time" name="waktu2" id="waktu2" size="4" style="background: #F4ECFF;border: 1px solid #655E8B;box-sizing: border-box;border-radius: 32px;">
                                 </p>
                              </div>
                           </div>
                        </div>
                     </div>
                     <div align="right">
                        <button type="button" class="btn btn-secondary" data-dismiss="modal">Close</button>
                        <button type="submit" class="btn btn-primary">Save changes</button>
                     </div>
                  </form>
               </div>
            </div>
         </div>
      </div>
                </main>
</div>
<?php
include 'footer.php';
?>
</body>