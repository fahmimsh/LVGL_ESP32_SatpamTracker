<?php
//Start session
session_start();
include 'includes/header.php';
?>
<div id="main">
  <div class="container">
      <form method="POST" action="includes/login-exec.php" accept-charset="UTF-8" class="form-signin">
        
        <?php
          if( isset($_SESSION['ERRMSG_ARR']) && is_array($_SESSION['ERRMSG_ARR']) && count($_SESSION['ERRMSG_ARR']) >0 ) {
              ?>
              <div class="alert alert-warning">
                <ul class="list-unstyled">
                  <?php 
                  foreach ($_SESSION['ERRMSG_ARR'] as $msg) {
                    echo '<li>'.$msg.'</li>';
                  }
                  ?>
                </ul>
              </div>
            <?php
            unset($_SESSION['ERRMSG_ARR']);
          }
        ?>
        <div id="layoutSidenav_content" >
            <main>

            <div class="container-fluid " style="width: 60%;position: absolute;top: 50%;-ms-transform: translateY(-50%);transform: translateY(-50%);background: #FFFFFF;box-shadow: 4px 4px 19px rgba(0, 0, 0, 0.25);border-radius: 12px;">
            <div class="row">
              <div class="col">
                <div style="background:linear-gradient(166.77deg, #655E8B 6.73%, #0C052E 97.29%); border-radius: 12px;display: flex;flex-flow: column;height: 100%;">
                  <img src="Vector.svg" style="display: block;margin-left: auto;margin-right: auto;margin-top:20%;margin-bottom:20%;width: 20%;height: 100%;"></img>
                </div>
              </div>
              <div class="col" >

              <div style="position: absolute;top: 50%;-ms-transform: translateY(-50%);transform: translateY(-50%); margin-left: auto;margin-right: auto;width: 70%;">
              <h1 class="form-signin-heading">Satpam Tracker</h1>
                <h3 class="form-signin-heading">Please sign in</h3>
                <br>
                <input type="text" name="username" class="form-control" placeholder="Username" autofocus="" style="background: #F4ECFF;border: 1px solid #655E8B;box-sizing: border-box;border-radius: 32px;">
                <input type="password" name="password" class="form-control" placeholder="Password" style="background: #F4ECFF;border: 1px solid #655E8B;box-sizing: border-box;border-radius: 32px;">
                <button class="btn btn-lg btn-primary btn-block" type="submit" style="background: #60FBD5;border-radius: 32px;">Sign in</button>
                </div>
              </div>
            </div>


            
            </div>
          
            </div>
            </main>
        </div>




        
      <hr>
      </form>
    </div>
</div>
<?php
include 'includes/footer.php';
?>