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

$sql = "SELECT ruang.* FROM ruang WHERE NOT EXISTS(SELECT 1 FROM data_tugas_new WHERE data_tugas_new.ruang=ruang.ruang)";
$result = $conn->query($sql);

$ruang;

if ($result->num_rows > 0) {
  // output data of each row
  while($row = mysqli_fetch_object($result)) {
	$ruang[] = $row;
}}

$sql = "SELECT nama FROM data_satpam_new";
$result = $conn->query($sql);

$nama;

if ($result->num_rows > 0) {
  // output data of each row
  while($row = mysqli_fetch_object($result)) {
	$nama[] = $row;
}}

$sql = "SELECT * FROM data_tugas_new";
$result = $conn->query($sql);

$tugas;

if ($result->num_rows > 0) {
  // output data of each row
  while($row = mysqli_fetch_object($result)) {
	$tugas[] = $row;
}}

?>
<div id="layoutSidenav_content">
                <main>
                    <div class="container-fluid " style="margin: auto; margin-top: 25px; box-shadow: 4px 4px 19px rgba(0, 0, 0, 0.25); border-radius: 12px;width: 1260px; height: 768px; left: 445px; top: 218px; ">
                    
                    <div style="padding-top: 50px;">
                    <div class="row">
                    <div class="col-8">
                    <H4>Patrolli Ruangan</H4>
                    </div>
                    <div class="col-4">
                      <?php
                        echo button();
                      ?>
                    
                    </div>
                    </div>
                    </div>

                    <div class="row" style="padding-top: 50px;">
                    <table class="table table-striped table-dark" style="background: #36315B;" width="100%" cellspacing="0">
                        <thead class="text-light">
                           <tr>
                              <th>id Smartcard</th>
                              <th>Nama Satpam</th>
                              <th>Posisi Sekarang</th>
                              <th>Waktu</th>
                              <th>Tugas</th>
                              <th>Hapus</th>
                           </tr>
                        </thead>
                        <tbody>
                        <?php
                                        foreach ($tugas as $tugass) {
                                        ?>
                                        <?php echo "<tr>
                                        <td>" . $tugass->rfid . "</td>"?>
                                        <?php  echo "<td>". $tugass->satpam . "</td>" ?>
                                        <?php  echo "<td>". getdatass(2, $tugass->satpam) . "</td>" ?>
                                        <?php  echo "<td>". $tugass->waktu_cek . "</td>" ?>
                                        <?php  echo "<td>". $tugass->ruang . "</td>" ?>
                                        <?php  echo '<td><a href="api_hapus_tugas.php?user='. $tugass->ruang .'" class="btn"><i class="fas fa-trash-alt"></i></a></td></tr>' ?>
                                        <?php
                                            }
                                        ?>
                        </tbody>
                     </table>


                    </div>
                    
                    </div>
                </main>

                <!-- Modal -->
<div class="modal fade" id="exampleModal" tabindex="-1" role="dialog" aria-labelledby="exampleModalLabel" aria-hidden="true">
  <div class="modal-dialog modal-dialog-centered" role="document">
    <div class="modal-content">
      <div class="modal-header">
        <h5 class="modal-title" id="exampleModalLabel" style="font-weight: bold;font-size: 24px;line-height: 28px;display: flex;align-items: center;">Tambah Penugasan</h5>
        <button type="button" class="close" data-dismiss="modal" aria-label="Close">
          <span aria-hidden="true">&times;</span>
        </button>
      </div>
      <div class="modal-body">


    <form action="api_tambah_tugas.php" method="post">        
    <div class="form-group">
    <label for="exampleFormControlSelect1">Nama Satpam</label>
    <select class="form-control" name="namanya" id="exampleFormControlSelect1">

    <?php
                    foreach ($nama as $namas) {
                      echo '<option>'.$namas->nama.'</option>';
                    }
                ?>
    </select>
    <br>
    <label for="exampleFormControlSelect1">Tugas</label>
      <select class="chosen-select" name="taglist[]" id="taglist" tabindex="8" multiple="" style="width:100%;height:50px" data-placeholder="Pilih Tugas">
                <option value=""></option>
                <?php
                    foreach ($ruang as $ruangs) {
                      echo '<option>'.$ruangs->ruang.'</option>';
                    }
                ?>
                
            </select>
      </div>
      <button type="button" class="btn btn-secondary" data-dismiss="modal">Close</button>
      <button type="submit" class="btn btn-primary">Save changes</button>
    </form>
    </div>
    <div class="modal-footer">





      </div>
    </div>
  </div>
</div>

<?php
                     function getdatass($mode, $ruanganq){
                     
                        require_once('config.php');
                     
                        $conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
                        // Check connection
                        if ($conn->connect_error) {
                           die("Connection failed: " . $conn->connect_error);
                        }
                        
                        //centang
                        if ($mode == 1){
                           $sql = "SELECT status FROM data_masuk WHERE `nama_ruang` = '$ruanganq' AND date > NOW() - INTERVAL 4 DAY_HOUR ORDER BY `date` DESC LIMIT 1";
                           $result = $conn->query($sql);
                           
                           if ($result->num_rows > 0) {
                              return "<i class='fas fa-check'></i>";
                              
                           }
                           else{
                              return "<i class='fas fa-times-circle'></i>";
                           }
                        }
                        
                        //centang
                        if ($mode == 0){
                           $sql = "SELECT status FROM data_masuk WHERE `nama_ruang` = '$ruanganq' AND date > NOW() - INTERVAL 4 DAY_HOUR ORDER BY `date` DESC LIMIT 1";
                           $result = $conn->query($sql);
                           
                           if ($result->num_rows > 0) {
                              while($row = mysqli_fetch_array($result)) {
                                 return $row['status'];
                              
                           }}
                           else{
                              return "Belum Dicek";
                           }
                        }          

                        //posisi
                        if ($mode == 2){
                           $sql = "SELECT `nama_ruang` FROM data_masuk WHERE nama_pengecek = '$ruanganq' AND date > NOW() - INTERVAL 4 DAY_HOUR ORDER BY `date` DESC LIMIT 1";
                           $result = $conn->query($sql);
                           
                           if ($result->num_rows > 0) {
                           // output data of each row
                           while($row = mysqli_fetch_array($result)) {
                              return $row['nama_ruang'];
                              
                           }}
                           else{
                              return "Belum Patroli";
                           }
                        }
                     
                        //waktu cek
                        if ($mode == 3){
                           $sql = "SELECT date FROM data_masuk WHERE nama_pengecek = '$ruanganq' AND date > NOW() - INTERVAL 4 DAY_HOUR ORDER BY `date` DESC LIMIT 1";
                           $result = $conn->query($sql);
                           
                           if ($result->num_rows > 0) {
                           // output data of each row
                           while($row = mysqli_fetch_array($result)) {
                              return $row['date'];
                              
                           }}
                           else{
                              return "Belum Patroli";
                           }
                        }   
                        //Jumlah Yang dicek
                        if ($mode == 4){
                           $sql = "SELECT gedung FROM data_ruang WHERE ruang = '$ruanganq' AND date > NOW() - INTERVAL 4 DAY_HOUR ORDER BY `date` DESC LIMIT 1";
                           $result = $conn->query($sql);
                           
                           if ($result->num_rows > 0) {
                           // output data of each row
                           while($row = mysqli_fetch_array($result)) {
                              return $row['gedung'];
                              
                           }}
                        }            
                     
                     }
?>


<?php
      function button(){
      
        require_once('config.php');
    
        $conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
        // Check connection
        if ($conn->connect_error) {
          die("Connection failed: " . $conn->connect_error);
        }

           $sql = "SELECT id FROM data_tugas_new WHERE status = 0";
           $result = $conn->query($sql);
           
           if ($result->num_rows > 0) {
             return '                     
             <a href="mulai.php?mulai=1&tempat=1" type="button" class="btn btn-primary" style="background: #FB6060; border-color: #60FBD5; color: #000; border-radius: 32px;">Hentikan Patroli</a>
             <button type="button" class="btn text-light" style="background: #655E8B; border-radius: 32px;" data-toggle="modal" data-target="#exampleModal" disabled>Tambah Patroli</button>';
               
           }else{
              return '                     
              <a href="mulai.php?mulai=0&tempat=1" type="button" class="btn btn-primary" style="background: #60FBD5; border-color: #60FBD5; color: #000; border-radius: 32px;">Mulai Patroli</a>
              <button type="button" class="btn text-light" style="background: #655E8B; border-radius: 32px;">Hasil Patroli</button>
              <button type="button" class="btn text-light" style="background: #655E8B; border-radius: 32px;" data-toggle="modal" data-target="#exampleModal">Tambah Patroli</button>';
           }

     }
include 'footerv2.php';
?>
</body>



