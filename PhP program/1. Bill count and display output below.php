<!DOCTYPE HTML>  
<html>
<head>
</head>
<body>  

<?php
$name = $sold = $price = $code = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
  $name = test_input($_POST["name"]);
  $sold = test_input($_POST["sold"]);
  $price = test_input($_POST["price"]);
  $code = test_input($_POST["code"]);
}

function test_input($data) {
  $data = trim($data);
  $data = stripslashes($data);
  $data = htmlspecialchars($data);
  return $data;
}
?>


<form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">  
  <label> Bill number: </label>
  <input type="text" name="name">
  <br><br>


  <label for="#">Product Code: </label>
  <select id="#" name="code">
    <option value="cu123">cu123</option>
    <option value="cu124">cu124</option>
  </select>
  <br><br>

 <label>Unit Sold: </label> 
 <input type="text" name="sold">
  <br><br>

  <label>Unit Price: </label> 
 <input type="text" name="price">
  <br><br>

  <input type="submit" name="submit" value="Submit">  
</form>

<?php
echo "<h2><u><b>OutPut</b></u></h2>";

echo 'Bill number: ' . $name;

echo "<br>";

echo "jo432 " . $sold . " unit(s) " . " x " . " @RM" . $price ." RM". $sold * $price ;

?>

</body>
</html>