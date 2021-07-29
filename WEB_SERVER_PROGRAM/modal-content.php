<?php
include 'head.php';
require_once('config.php'); 
$conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}
                                        echo ('
                                                    <table class="table table-bordered" cellspacing="0">
                                                        <thead>
                                                            <tr>
                                                                <th>Ruang</th>
                                                                <th>Lantai</th>
                                                                <th>Gedung</th>
                                                                <th>Waktu</th>

                                                            </tr>
                                                        </thead>

                                                        <tbody>
                                            ');

                                            $sql = "SELECT * FROM `tugas_selesai` WHERE `pengecek` = 'Tanner Hatfield' ORDER BY `tugas_selesai`.`waktu` DESC";
                                            $result12 = $conn->query($sql);
    
                                            $tugass12 = array();
    
                                            if ($result12->num_rows > 0) {
                                            // output data of each row
                                                while($row = mysqli_fetch_array($result12)) {
                                                    echo "<tr><td>" . $row['nama_ruang'] . "</td>";
                                                    echo "<td>". $row['nama_ruang'] . "</td>" ;
                                                    echo "<td>" .$row['nama_ruang'] . "</td>" ;
                                                    echo "<td>" . $row['waktu'] . "</td></tr>" ;
                                            }}
                                            else{
                                                    echo "<tr><td>Belum Melakukan Tugas</td>";
                                                    echo "<td>   </td>" ;
                                                    echo "<td>   </td>" ;
                                                    echo "<td>   </td></tr>" ;                                        
                                            }
                                            

                                            echo('
                                            
                                            </tbody>

                                                                            </table>

                                            
                                            ');
                                            include 'footerv2.php';
                                            ?>