<!DOCTYPE HTML>  
<html>
<head>
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>

  <script type="text/javascript">
    $(document).ready(function(){
    $("form").submit(function(){
    if ($('input:checkbox').filter(':checked').length < 1){
        alert("Check at least one Game!");
    return false;
    }
    });
});

    function myFunction() {
  let x = document.getElementById("height").value;
  if (isNaN(x) || x < 1 || x < 3) {
    alert("Enter the digits of 2-3 length")
  } 
}

</script>



  <style type="text/css">
    form, table{
      padding: 10px;
      height: auto;
      width: 500px;
      border: 1px solid black;
    }

    table{
     margin-top: 50px;
    }
  </style>
</head>
<body>  

<?php
$ride = $name = $height = $price = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {

  $ride = test_input($_POST['ride']);
  $name = test_input($_POST["name"]);
  $height = test_input($_POST["height"]);
  $price = test_input($_POST["price"]);
  // $code = test_input($_POST["code"]);
}

function test_input($data) {
  $data = trim($data);
  $data = stripslashes($data);
  $data = htmlspecialchars($data);
  return $data;
}
?>


<form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>"> 

  <h3><strong>THEME PARK RIDES</strong></h3>

<label>Select a Ride:</label>
          <input type="checkbox" name="ride" value="Vortex">Vortex</input>
<input type="checkbox" name="ride" value="Todal Wave">Todal Wave</input>
<input type="checkbox" name="ride" value="Flying Fish">Flying Fish</input>
<br>
<br>
  
  <label> Type of Ride: </label>
  <input type="text" name="name">
  <br><br>

 <label>Minimum Height</label> 
 <input type="number" name="height" id="height">
  <br><br>

  <label>Ticket Price: </label> 
 <input type="text" name="price">
  <br><br>

  <input type="submit" name="submit" onclick="myFunction()" value="Submit">  
</form>


<table>
  <tr>
    <td><?php echo 'Ride Selected : ' . $ride; ?></td>
  </tr>
  <tr>
    <td><?php echo 'Minimum Height Required : ' . $height; ?></td>
  </tr>
  <tr>
    <td><?php echo 'Ticket Price: ' . $price; ?></td>
  </tr>
</table>


</body>
</html>
