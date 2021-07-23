<?php
	//Include database connection details
	require_once(__DIR__.'/../config.php');

	$link = mysqli_connect(DB_HOST, DB_USER, DB_PASSWORD);
	if (!$link) {
		die("Cannot access db.");
	}

	$db = mysqli_select_db($link,DB_DATABASE);
	if(!$db) {
		die("Unable to select database");
	}

	$user_id = $_GET['uid'];
	$od_date = date('Y-m-d');
	$od_name = $_GET['name'];
	$od_address = $_GET['address'];
	$od_city = $_GET['city'];
	$od_postal_code = $_GET['postal_code'];
	$od_cost = $_GET['total'];
	$pd_id = $_GET['pd_id'];

	$qry = "INSERT INTO `tbl_order` ( `user_id`, `od_date`, `od_status`, `od_name`, `od_address`, `od_city`, `od_postal_code`, `od_cost`)
			VALUES
				( ".$user_id.", '".$od_date."', 'New', '".$od_name."', '".$od_address."', '".$od_city."', '".$od_postal_code."', '".$od_cost."');
			";
	$result = mysqli_query($link,$qry);

	$od_id = mysqli_insert_id($link);

	$qry = "INSERT INTO `tbl_order_item` (`od_id`, `pd_id`, `od_qty`) VALUES (".$od_id.", ".$pd_id.", 1);";
	$result = mysqli_query($link,$qry);

	$qry = "UPDATE `tbl_product` SET `tbl_product`.`pd_qty` = `tbl_product`.`pd_qty` - 1 WHERE pd_id=".$pd_id;
	$result = mysqli_query($link,$qry);


	//Check whether the query was successful or not
	if($result) {
		echo ("Pesanan Tercatat");
		exit();
	} else {
		die("Query failed: ".mysqli_error($link));
	}
?>