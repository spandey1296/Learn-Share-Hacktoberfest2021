    	function myFunction() {

    	    var num1 = parseInt(document.getElementById("number1").value);
    	    var num2 = parseInt(document.getElementById("number2").value);
    	    var num3 = parseInt(document.getElementById("number3").value);
    	    var result = num1 * num2 * num3
    	    if (result < 0) {
    	        if (result % 2 == 0) {
    	            document.getElementById("res").innerHTML = result;
    	            document.getElementById("res").style.color = "red";
    	            document.getElementById("img_res").innerHTML = '[even]';
    	            document.getElementById("img_res").style.color = '#8F00FF';
					
    	        } else {
    	            document.getElementById("res").innerHTML = result;
    	            document.getElementById("res").style.color = "red";
    	            document.getElementById("img_res").innerHTML = '[odd]';
    	            document.getElementById("img_res").style.color = '#FFA500';
    	        }
    	    } else {
    	        if (result % 2 == 0) {
    	            document.getElementById("res").innerHTML = result;
    	            document.getElementById("res").style.color = "blue";
    	            document.getElementById("img_res").innerHTML = '[even]';
    	            document.getElementById("img_res").style.color = '#8F00FF';

    	        } else {
    	            document.getElementById("res").innerHTML = result;
    	            document.getElementById("res").style.color = "blue";
    	            document.getElementById("img_res").innerHTML = '[odd]';
    	            document.getElementById("img_res").style.color = '#FFA500';
    	        }
    	    }
    	}