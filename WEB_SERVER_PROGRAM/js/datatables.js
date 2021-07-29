// Call the dataTables jQuery plugin

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
  
  $(document).ready(function() {
    $('#dataTable').DataTable({ defaultDate: new Date() });
  });

  $(document).ready(function() {
    $('#dataTablex').DataTable({ defaultDate: new Date() });
  });
  $(document).ready(function() {
    $('#dataTablexz').DataTable();
  });
  $(document).ready(function() {
    $('#dataTablexzz').DataTable();
  });

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
