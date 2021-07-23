<body>
  <div class="wrap">
    <nav>
      <div class="navbar navbar-fixed-top navbar-default">
        <div class="container">
          <div class="navbar-header">
        </button>
          </div>
          <div class="collapse navbar-collapse" role="navigation" id="navbar-main">
            <ul class="nav navbar-nav navbar-right">
              <li>
                <?php if(isset($_SESSION['SESS_USER_ID'])) { ?>
                  <li class="dropdown">
                    <a href="#" class="dropdown-toggle" data-toggle="dropdown">Hi, <?php echo $_SESSION['SESS_USERNAME'] ?>! <b class="caret"></b></a>
                    <ul class="dropdown-menu" style="">
                    </ul>
                  </li>
                <?php } else { ?>
                <a href="login.php">Login</a>
                <?php } ?>
              </li>
            </ul>
          </div>
        </div>
      </div>
    </nav>

    <div class="container" id="messages">
      <?php
          if( isset($_SESSION['MSGS']) && is_array($_SESSION['MSGS']) && count($_SESSION['MSGS']) >0 ) {
              ?>
              <div class="alert alert-success alert-dismissable">
                <button type="button" class="close" data-dismiss="alert" aria-hidden="true">&times;</button>
                <ul class="list-unstyled">
                  <?php 
                  foreach ($_SESSION['MSGS'] as $msg) {
                    echo '<li>'.$msg.'</li>';
                  }
                  ?>
                </ul>
              </div>
            <?php
            unset($_SESSION['MSGS']);
          }
        ?>
        <?php
          if( isset($_SESSION['ERR_MSGS']) && is_array($_SESSION['ERR_MSGS']) && count($_SESSION['ERR_MSGS']) >0 ) {
              ?>
              <div class="alert alert-warning alert-dismissable">
                <button type="button" class="close" data-dismiss="alert" aria-hidden="true">&times;</button>
                <ul class="list-unstyled">
                  <?php 
                  foreach ($_SESSION['ERR_MSGS'] as $msg) {
                    echo '<li>'.$msg.'</li>';
                  }
                  ?>
                </ul>
              </div>
            <?php
            unset($_SESSION['ERR_MSGS']);
          }
        ?>
    </div>