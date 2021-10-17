function validateForm() {  
        
        var pw1 = document.getElementById("pswd1").value;  
          
    
       
        
        if(pw1 == "") {  
          document.getElementById("message1").innerHTML = "**Fill the password please!";  
          return false;  
        }  
       
        
         
        
        if(pw1.length < 8) {  
          document.getElementById("message1").innerHTML = "**Password length must be atleast 8 characters";  
          return false;  
        }  
     
        
        if(pw1.length > 15) {  
          document.getElementById("message1").innerHTML = "**Password length must not exceed 15 characters";  
          return false;  
        }  
       
       
     
        if (pw1.search(/[0-9]/) < 0) {
        document.getElementById("message1").innerHTML = "Your password must contain at least one digit";
        return false;
      }
      if (pw1.search(/[!@#$%^&*]/)) {
        document.getElementById("message1").innerHTML = "Your password must contain special character";
        return false;
      }
        else{
          alert ("Your password created successfully");  
          document.write("JavaScript form has been submitted successfully");

        }
     }

       
 
   
   