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

    var minDate, maxDate;
 
    // Custom filtering function which will search data in column four between two values
    $.fn.dataTable.ext.search.push(
        function( settings, data, dataIndex ) {
            var max = maxDate.val();
            var maxDatex = new Date( max );
            maxDatex.setHours(0, 0, 0, 0);
            var date = new Date( data[4] );
            date.setHours(0, 0, 0, 0);
            const diffInMs = Math.abs(maxDatex - date);
     
            if (
                diffInMs == 0 
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
            format: 'MMMM Do YYYY'
        });

        var table2 =  $('#dataTable').DataTable();
     
        // DataTables initialisation
        var table = $('#tabel-dataa').DataTable();
     
        // Refilter the table
        $('#max').on('change', function () {
            table.draw();
        });

       
    });
    $(document).ready(function() {
        // Create date inputs
        maxDate = new DateTime($('#max')  , {
            format: 'MMMM Do YYYY'
        });

        var table2 =  $('#dataTable').DataTable();
     
        // DataTables initialisation
        var table = $('#tabel-dataaa').DataTable();
     
        // Refilter the table
        $('#max').on('change', function () {
            table.draw();
        });

       
    });
    $(document).ready(function() {
        // Create date inputs
        maxDate = new DateTime($('#max')  , {
            format: 'MMMM Do YYYY'
        });

        var table2 =  $('#dataTable').DataTable();
     
        // DataTables initialisation
        var table = $('#tabel-dataaaa').DataTable();
     
        // Refilter the table
        $('#max').on('change', function () {
            table.draw();
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

    $(document).ready(function(){
        $(".datepickerxxx").datepicker();
   });


    


})(jQuery);
