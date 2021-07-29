/*!
    * Start Bootstrap - SB Admin v6.0.3 (https://startbootstrap.com/template/sb-admin)
    * Copyright 2013-2021 Start Bootstrap
    * Licensed under MIT (https://github.com/StartBootstrap/startbootstrap-sb-admin/blob/master/LICENSE)
    */
    (function($) {
    "use strict";

    // Add active state to sidbar nav links
    var path = window.location.href; // because the 'href' property of the DOM element is the absolute path
        $("#layoutSidenav_nav .sb-sidenav a.nav-link").each(function() {
            if (this.href === path) {
                $(this).addClass("active");
            }
        });

    // Toggle the side navigation
    $("#sidebarToggle").on("click", function(e) {
        e.preventDefault();
        $("body").toggleClass("sb-sidenav-toggled");
    });

    var minDate, maxDate, shif;
 
    // Custom filtering function which will search data in column four between two values
    $.fn.dataTable.ext.search.push(
        function( settings, data, dataIndex ) {
            var max = maxDate.val();
            var shiff = shif.val();
            var maxDatex = new Date( max );
            maxDatex.setHours(0, 0, 0, 0);
            var date = new Date( data[3] );
            var minnn = maxDatex,mannn = maxDatex;
            var jam = new Date( data[3] );
            var jambu;
            console.log(data[3]);
            console.log(shiff);
            console.log(date);
            console.log(maxDatex);
            date.setHours(0, 0, 0, 0);
            if(shiff == 0){
                minnn.setHours(0, 0, 0, 0);
                mannn.setHours(23, 59, 0, 0);

            }
            if(shiff == 1){
                minnn.setHours(6, 0, 0, 0);
                mannn.setHours(8, 0, 0, 0);
            }
            if(shiff == 2){
                minnn.setHours(13, 0, 0, 0);
                mannn.setHours(14, 0, 0, 0);
            }
            if(shiff == 3){
                minnn.setHours(16, 0, 0, 0);
                mannn.setHours(17, 0, 0, 0);
            }
            if(shiff == 4){
                minnn.setHours(23, 0, 0, 0);
                mannn.setHours(23, 59, 0, 0);
            }
            if(jam > minnn && jam < mannn){
                jambu = true;
                console.log(jambu);

            }
            else{
                jambu = false;
                console.log("jam = " + minnn)
                console.log("Jambu = " + jambu);
            }
            const diffInMs = Math.abs(maxDatex - date);
     
            if (
                diffInMs == 0 && jambu == true
            ) {
                console.log('muncul');
                return true;
                
            }
            console.log('ga muncul');
            console.log(diffInMs);
            return false;
        }
    );

    
     
    $(document).ready(function() {
        // Create date inputs
        maxDate = new DateTime($('#max')  , {
            defaultDate: new Date(),
            format: 'MMMM Do YYYY',
            
        });

        shif = $('#maxxx');



        var table2 =  $('#dataTable').DataTable();
     
        // DataTables initialisation
        var table = $('#tabel-dataa').DataTable();
     
        // Refilter the table
        $('#max').on('change', function () {
            table.draw();
            console.log(shif.val());
        });

       
    });

    $(document).ready(function(){
        $('.timepicker').timepicker({
            timeFormat: 'h:mm p',
            interval: 60,
            minTime: '10',
            maxTime: '6:00pm',
            defaultTime: '11',
            startTime: '10:00',
            dynamic: false,
            dropdown: true,
        });
    });

    

//     $(document).ready(function(){
//         $(".datepickerxxx").datepicker();
//    });

   $(document).ready(function () {
    $(".test").click(function () {
        $("#thedialog").attr('src', $(this).attr("href"));
        $("#somediv").dialog({
            width: 400,
            height: 450,
            modal: true,
            close: function () {
                $("#thedialog").attr('src', "about:blank");
            }
        });
        return false;
    });
});

$( "#target" ).click(function() {
    alert( "Handler for .click() called." );
  });
    
  $(".chosen-select").chosen( { width: '100%', height: '50px' });

})(jQuery);
