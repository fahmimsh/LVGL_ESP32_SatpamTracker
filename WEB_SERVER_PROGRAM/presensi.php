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
      
      $sql = "SELECT * FROM data_satpam_new";
      $result = $conn->query($sql);
      
      $nama;
      
      if ($result->num_rows > 0) {
        // output data of each row
        while($row = mysqli_fetch_object($result)) {
      	$nama[] = $row;
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
                     <div class="col-8">
                        <table border="0" cellspacing="5" cellpadding="5" >
                           <tbody>
                              <tr>
                                 <td>Tanggal:</td>
                                 <td><input type="text" id="max" name="max"></td>
                              </tr>
                           </tbody>
                        </table>
                     </div>
                     <div class="col-4">
                        <button type="button" class="btn text-light" style="background: #655E8B;border-radius: 32px;  float: right;" data-toggle="modal" data-target="#exampleModal">Tambah Satpam</button>
                     </div>
                  </div>
                  <table id="tabel-dataa" width="100%" height="40" cellspacing="0" class="table table-striped table-dark" style="background: #36315B; ">
                     <thead class="text-light">
                        <tr>
                           <th>NIP</th>
                           <th>Nama</th>
                           <th>Jabatan</th>
                           <th>Alamat</th>
                           <th>No HP</th>
                           <th>Kehadiram</th>
                           <th>Penilaian</th>
                           <th>Laporan</th>
                           <th>Edit</th>
                           <th>Hapus</th>
                        </tr>
                     </thead>
                     <tbody>
                        <?php
                           foreach ($nama as $namas) {
                           ?>
                        <?php echo "<tr>
                           <td>" . $namas->nip . "</td>"?>
                        <?php  echo "<td>". $namas->nama . "</td>" ?>
                        <?php  echo "<td>". $namas->posisi . "</td>" ?>
                        <?php  echo "<td>". $namas->alamat . "</td>" ?>
                        <?php  echo "<td>". $namas->nomor_hp . "</td>" ?>
                        <?php  echo "<td>". date("Y-m-d") . "</td>" ?>
                        <?php  echo "<td>". $namas->nama . "</td>" ?>
                        <?php  echo '<td><button class="btn"  data-toggle="modal" data-target="#report'.$namas->u_id.'"><i class="far fa-clock"></i></button></td>' ?>
                        <?php  echo '<td><button class="btn" data-toggle="modal" data-target="#edit'.$namas->u_id.'"><i class="fas fa-pen"></i></button></td>'?>
                        <?php  echo '<td><a href="api_hapus_satpam.php?uid='.$namas->u_id.'" class="btn"><i class="fas fa-trash-alt"></i></a></td></tr>' ?>
                        <?php
                           }
                           ?>
                     </tbody>
                  </table>
               </div>
            </div>
         </div>
      </div>

      <?php
                           foreach ($nama as $namas) {
                                echo '<!-- Modal -->
                                <div class="modal fade " id="edit'.$namas->u_id.'" tabindex="-1" role="dialog" aria-labelledby="exampleModalLabel" aria-hidden="true">
                                <div class="modal-dialog modal-lg" role="document">
                                <div class="modal-content">
                                    <div class="modal-header">
                                        <h5 class="modal-title" id="exampleModalLabel">Tambah Satpam</h5>
                                        <button type="button" class="close" data-dismiss="modal" aria-label="Close">
                                        <span aria-hidden="true">&times;</span>
                                        </button>
                                    </div>
                                    <div class="modal-body">
                                        <form role="form" action="api_edit_satpam.php" method="post">
                                            <div class="form-group">
                                            <div class="container">
                                                <div class="row">
                                                    <div class="col-sm">
                                                        <p>
                                                        <label for="nama">Nama:</label>
                                                        <input type="text" value="'.$namas->nama.'" name="nama" id="nama'.$namas->u_id.'" style="background: #F4ECFF;border: 1px solid #655E8B;box-sizing: border-box;border-radius: 32px;">
                                                        </p>
                                                        <p>
                                                        <label for="nip">NIP:</label><br>
                                                        <input type="text" value="'.$namas->nip.'" name="nip" id="nip'.$namas->u_id.'" style="background: #F4ECFF;border: 1px solid #655E8B;box-sizing: border-box;border-radius: 32px;">
                                                        </p>
                                                        <p>
                                                        <label for="email">Email:</label>
                                                        <input type="text" value="'.$namas->email.'" name="email" id="email'.$namas->u_id.'" style="background: #F4ECFF;border: 1px solid #655E8B;box-sizing: border-box;border-radius: 32px;">
                                                        </p>
                                                    </div>
                                                    <div class="col-sm">
                                                        <p>
                                                        <label for="alamat">Alamat:</label>
                                                        <input type="text" value="'.$namas->alamat.'" name="alamat" id="alamat'.$namas->u_id.'" style="background: #F4ECFF;border: 1px solid #655E8B;box-sizing: border-box;border-radius: 32px;">
                                                        </p>
                                                        <p>
                                                        <label for="no_hp">No HP:</label>
                                                        <input type="text" value="'.$namas->nomor_hp.'" name="no_hp" id="no_hp'.$namas->u_id.'" style="background: #F4ECFF;border: 1px solid #655E8B;box-sizing: border-box;border-radius: 32px;">
                                                        </p>
                                                        <p>
                                                        <label for="rfid">ID SmardCard:</label>
                                                        <input type="text" value="'.$namas->rfid.'" name="rfid" id="rfid'.$namas->u_id.'" style="background: #F4ECFF;border: 1px solid #655E8B;box-sizing: border-box;border-radius: 32px;">
                                                        </p>
                                                    </div>
                                                    <div class="col-sm">
                                                        <p>
                                                        <label for="posisi">Posisi:</label>
                                                        <input type="text" value="'.$namas->posisi.'" name="posisi" id="posisi'.$namas->u_id.'" style="background: #F4ECFF;border: 1px solid #655E8B;box-sizing: border-box;border-radius: 32px;">
                                                        </p>
                                                        <p>
                                                        <label for="umur">Umur:</label>
                                                        <input type="text" value="'.$namas->umur.'" name="umur" id="umur'.$namas->u_id.'" style="background: #F4ECFF;border: 1px solid #655E8B;box-sizing: border-box;border-radius: 32px;">
                                                        </p>
                                                        <p>
                                                        <label for="uid">UID:</label><br>
                                                        <input readonly  type="text" value="'.$namas->u_id.'" name="uid" id="uid'.$namas->u_id.'" style="background: #F4ECFF;border: 1px solid #655E8B;box-sizing: border-box;border-radius: 32px;">
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
                            </div>';

                            echo '<!-- Modal -->
                                <div class="modal fade " id="report'.$namas->u_id.'" tabindex="-1" role="dialog" aria-labelledby="exampleModalLabel" aria-hidden="true">
                                <div class="modal-dialog modal-lg" role="document">
                                <div class="modal-content">
                                    <div class="modal-header">
                                        <h5 class="modal-title" id="exampleModalLabel">Laporan</h5>
                                        <button type="button" class="close" data-dismiss="modal" aria-label="Close">
                                        <span aria-hidden="true">&times;</span>
                                        </button>
                                    </div>
                                    <div class="modal-body">
                                        
                                            <div align="right">
                                            <button type="button" class="btn btn-secondary" data-dismiss="modal">Close</button>
                                            </div>
                                        </form>
                                    </div>
                                </div>
                                </div>
                            </div>';
                           }
                           ?>






      <!-- Modal -->
      <div class="modal fade " id="exampleModal" tabindex="-1" role="dialog" aria-labelledby="exampleModalLabel" aria-hidden="true">
         <div class="modal-dialog modal-lg" role="document">
            <div class="modal-content">
               <div class="modal-header">
                  <h5 class="modal-title" id="exampleModalLabel">Tambah Satpam</h5>
                  <button type="button" class="close" data-dismiss="modal" aria-label="Close">
                  <span aria-hidden="true">&times;</span>
                  </button>
               </div>
               <div class="modal-body">
                  <form role="form" action="api_tambah_satpam.php" method="post">
                     <div class="form-group">
                        <div class="container">
                           <div class="row">
                              <div class="col-sm">
                                 <p>
                                    <label for="nama">Nama:</label>
                                    <input type="text" name="nama" id="nama" style="background: #F4ECFF;border: 1px solid #655E8B;box-sizing: border-box;border-radius: 32px;">
                                 </p>
                                 <p>
                                    <label for="nip">NIP:</label><br>
                                    <input type="text" name="nip" id="nip" style="background: #F4ECFF;border: 1px solid #655E8B;box-sizing: border-box;border-radius: 32px;">
                                 </p>
                                 <p>
                                    <label for="email">Email:</label>
                                    <input type="text" name="email" id="email" style="background: #F4ECFF;border: 1px solid #655E8B;box-sizing: border-box;border-radius: 32px;">
                                 </p>
                              </div>
                              <div class="col-sm">
                                 <p>
                                    <label for="alamat">Alamat:</label>
                                    <input type="text" name="alamat" id="alamat" style="background: #F4ECFF;border: 1px solid #655E8B;box-sizing: border-box;border-radius: 32px;">
                                 </p>
                                 <p>
                                    <label for="no_hp">No HP:</label>
                                    <input type="text" name="no_hp" id="no_hp" style="background: #F4ECFF;border: 1px solid #655E8B;box-sizing: border-box;border-radius: 32px;">
                                 </p>
                                 <p>
                                    <label for="rfid">ID SmardCard:</label>
                                    <input type="text" name="rfid" id="rfid" style="background: #F4ECFF;border: 1px solid #655E8B;box-sizing: border-box;border-radius: 32px;">
                                 </p>
                              </div>
                              <div class="col-sm">
                                 <p>
                                    <label for="posisi">Posisi:</label>
                                    <input type="text" name="posisi" id="posisi" style="background: #F4ECFF;border: 1px solid #655E8B;box-sizing: border-box;border-radius: 32px;">
                                 </p>
                                 <p>
                                    <label for="umur">Umur:</label>
                                    <input type="text" name="umur" id="umur" style="background: #F4ECFF;border: 1px solid #655E8B;box-sizing: border-box;border-radius: 32px;">
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

   <?php
      include 'footer.php';
      ?>
</body>
