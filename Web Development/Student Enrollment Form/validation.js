var row =1;

const username=document.getElementById('inname');
const useremail=document.getElementById('inemail');
const userwebsite=document.getElementById('tf1');
const userimage=document.getElementById('inimage');
const validatename=document.getElementById('validatename');
const validateemail=document.getElementById('validateemail');
const validategender=document.getElementById('validategender');
const validateskill=document.getElementById('validateskill');
const validatewebsite=document.getElementById('validatewebsite');
const validateimage=document.getElementById('validateimage');
const submit=document.getElementById('bt1');

let validname=false;
let validemail=false;
let validwebsite=false;
let validimage=false;
let validgender=false;
let validskill=false;

userimage.addEventListener('blur',()=>{

    let regex =  /^(?:(?:https?|ftp):\/\/)?(?:(?!(?:10|127)(?:\.\d{1,3}){3})(?!(?:169\.254|192\.168)(?:\.\d{1,3}){2})(?!172\.(?:1[6-9]|2\d|3[0-1])(?:\.\d{1,3}){2})(?:[1-9]\d?|1\d\d|2[01]\d|22[0-3])(?:\.(?:1?\d{1,2}|2[0-4]\d|25[0-5])){2}(?:\.(?:[1-9]\d?|1\d\d|2[0-4]\d|25[0-4]))|(?:(?:[a-z\u00a1-\uffff0-9]-*)*[a-z\u00a1-\uffff0-9]+)(?:\.(?:[a-z\u00a1-\uffff0-9]-*)*[a-z\u00a1-\uffff0-9]+)*(?:\.(?:[a-z\u00a1-\uffff]{2,})))(?::\d{2,5})?(?:\/\S*)?$/;
    let str=userimage.value.trim();
    if(str.length==0){
        document.getElementById('i').classList.remove('hidden');
        validimage=false;
        validateimage.classList.add('hidden');
        userimage.classList.add('errorcolor');
        return;
     }
  
    if(regex.test(str)){
        validimage=true;
        validateimage.classList.add('hidden');
        userimage.classList.remove('errorcolor');
        document.getElementById('i').classList.add('hidden');
      }else{
      validateimage.classList.remove('hidden');
      userimage.classList.add('errorcolor');
      document.getElementById('i').classList.add('hidden');
      validimage=false;
  }

});

var myFunction=function(){
    let regex= /^[a-z A-Z]([ a-zA-Z]){0,50}$/;
let str=username.value.replace(/\s+/g, ' ').trim();
 if(str.length==0){
    document.getElementById('n').classList.remove('hidden');
    vailidname=false;
    validatename.classList.add('hidden');
    username.classList.add('errorcolor');
    return;
 }
if(regex.test(str)){
   validatename.classList.add('hidden');
   username.classList.remove('errorcolor');
   document.getElementById('n').classList.add('hidden');
   validname=true;
}else{
    document.getElementById('n').classList.add('hidden');
    validatename.classList.remove('hidden');
    username.classList.add('errorcolor');
    vailidname=false;
}

}

var myFunction1 =function(){
    let regex= /^([_\-\.0-9a-zA-Z]+)@([_\-\.0-9a-zA-Z]+)\.([a-zA-Z]){2,20}$/;
    let str=useremail.value.trim();
    if(str.length==0){
        document.getElementById('e').classList.remove('hidden');
        validemail=false;
        validateemail.classList.add('hidden');
        useremail.classList.add('errorcolor');
        return;
     }
    if(regex.test(str)){
        validateemail.classList.add('hidden');
        useremail.classList.remove('errorcolor');
        document.getElementById('e').classList.add('hidden');
       validemail=true;
    }else{
        validateemail.classList.remove('hidden');
        useremail.classList.add('errorcolor');
        document.getElementById('e').classList.add('hidden');
        validemail=false;
    }

}

userwebsite.addEventListener('blur',()=>{
    let regex =  /^(?:(?:https?|ftp):\/\/)?(?:(?!(?:10|127)(?:\.\d{1,3}){3})(?!(?:169\.254|192\.168)(?:\.\d{1,3}){2})(?!172\.(?:1[6-9]|2\d|3[0-1])(?:\.\d{1,3}){2})(?:[1-9]\d?|1\d\d|2[01]\d|22[0-3])(?:\.(?:1?\d{1,2}|2[0-4]\d|25[0-5])){2}(?:\.(?:[1-9]\d?|1\d\d|2[0-4]\d|25[0-4]))|(?:(?:[a-z\u00a1-\uffff0-9]-*)*[a-z\u00a1-\uffff0-9]+)(?:\.(?:[a-z\u00a1-\uffff0-9]-*)*[a-z\u00a1-\uffff0-9]+)*(?:\.(?:[a-z\u00a1-\uffff]{2,})))(?::\d{2,5})?(?:\/\S*)?$/;
    let str=userwebsite.value.trim();
    if(str.length==0){
        document.getElementById('w').classList.remove('hidden');
        validwebsite=false;
        validatewebsite.classList.add('hidden');
          userwebsite.classList.add('errorcolor');
        return;
     }
    if(regex.test(str)){
          validwebsite=true;
          validatewebsite.classList.add('hidden');
          userwebsite.classList.remove('errorcolor');
          document.getElementById('w').classList.add('hidden');
    }else{
        validatewebsite.classList.remove('hidden');
        userwebsite.classList.add('errorcolor');
        document.getElementById('w').classList.add('hidden');
        validwebsite=false;
    }
   
});


submit.addEventListener('click',(e)=> {
     e.preventDefault();
    var name=username.value.replace(/\s+/g, ' ').trim();
    var email=useremail.value.trim();
    var website=userwebsite.value.trim();
    var imagelink=userimage.value.trim();
    var gender="";
    var skills="";

    if(website.indexOf('://')>-1)
    {
        website = website.substring(website.indexOf('://')+3);
     }
    website = (website.indexOf('://') === -1) ? 'http://' + website : website;

    gender=getGender();
    skills=getSkills();
    if(gender.length<2){
        validategender.classList.remove('hidden');
        validgender=false;
    } 
    else
    {
        validategender.classList.add('hidden');
        validgender=true;  
    }

    if(skills.length<=2){
        validateskill.classList.remove('hidden');
        validskill=false;
    }else{         
        validateskill.classList.add('hidden');
                   validskill=true;
    }
    if(!validname){
        if(name.length==0){
            document.getElementById('n').classList.remove('hidden');
            vailidname=false;
            validatename.classList.add('hidden');
            username.classList.add('errorcolor');
         }else{
            document.getElementById('n').classList.add('hidden');
        validatename.classList.remove('hidden');
        username.classList.add('errorcolor');
         }
         
    }


    if(!validemail){
        if(email.length==0){
            document.getElementById('e').classList.remove('hidden');
            validemail=false;
            validateemail.classList.add('hidden');
            useremail.classList.add('errorcolor');
         }else{
            document.getElementById('e').classList.add('hidden');
        validateemail.classList.remove('hidden');
        useremail.classList.add('errorcolor');
         }
      
    }

    if(!validwebsite){
        if(website.length==0){
            document.getElementById('w').classList.remove('hidden');
            validwebsite=false;
            validatewebsite.classList.add('hidden');
              userwebsite.classList.add('errorcolor');
            
         }
        else{
            document.getElementById('w').classList.add('hidden');
        validatewebsite.classList.remove('hidden');
        userwebsite.classList.add('errorcolor');
        }

    }

    if(!validimage){
        if(imagelink.length==0){
            document.getElementById('i').classList.remove('hidden');
            validimage=false;
            validateimage.classList.add('hidden');
            userimage.classList.add('errorcolor');
            
         }
        else{
            document.getElementById('i').classList.add('hidden');
        validateimage.classList.remove('hidden');
        userimage.classList.add('errorcolor');
        }
    }
    

    if(validname && validemail && validimage && validwebsite && validskill && validgender){
         
        addData(name,email,website,imagelink,gender,skills);
        addToLocalData(name,email,website,imagelink,gender,skills);
         
         const bt2=document.getElementById('bt2');
         bt2.click();
    }else
    {
        return;
    }


});


function printLocalData(){
    var itemArrayStr="";
   itemArrayStr=localStorage.getItem('itemObject');
   itemArray=JSON.parse(itemArrayStr);
   if(itemArray==null){
       return;
   }

    for(let i=0;i<=itemArray.length-1;i++){
      var arr=itemArray[i];
        addData(arr.Name,arr.email,arr.website,arr.imagelink,arr.gender,arr.skills);
    }
}

function addToLocalData(name,email,website,imagelink,gender,skills){
    var student = new Object();
    student.Name = name;
    student.website = website;
    student.email = email;
    student.imagelink = imagelink;
    student.gender = gender;
    student.skills = skills;
 
    if(localStorage.getItem('itemObject')==null){
        itemArray=[];
         itemArray.push(student);
         localStorage.setItem('itemObject',JSON.stringify(itemArray));
    }else{
       var itemArrayStr=localStorage.getItem('itemObject');
       var  itemArray=JSON.parse(itemArrayStr);
        itemArray.push(student);
        localStorage.setItem('itemObject',JSON.stringify(itemArray));
    }

}

function getSkills(){
    let skills="";
    if(document.getElementById("cb1").checked == true) {   
        skills = "Java,";
      } 
 
      if(document.getElementById("cb2").checked == true) {   
         skills += "HTML,";
       } 
 
       if(document.getElementById("cb3").checked == true) {   
         skills += "CSS";
       } 
 
      if(skills.length>0 && skills.charAt(skills.length-1)==','){
          skills= skills.substring(0,skills.length-1);
      }

      return skills;

}

function getGender(){
    let gender="";
    if(document.getElementById("grid2").checked == true) {   
        gender="Female"; 
     }
     if(document.getElementById("grid1").checked == true) {   
         gender="Male"; 
      }

      return gender;
}


  function addData(name,email,website,imagelink,gender,skills){
      validgender=false;
      validname=false;
      validemail=false;
      validskill=false;
      validwebsite=false;
      validimage=false;

     var display = document.getElementById("display");

     var newRow=display.insertRow(row);
     var cell1=newRow.insertCell(0);
     var cell2=newRow.insertCell(1);
     imagelink="\""+imagelink+"\"";
      var b="\""+website+"\"";
   
     cell2.innerHTML="<img src="+imagelink+" alt=\""+"No Image"+"\" height=100 width=100></img>";
   var blan="\"_blank\"";
     cell1.innerHTML="<label style=\"margin: 0px 0px;\">"+name+"</label><br>"+gender+"<br>"+email+"<br>"
     +  "<a  href="+b+" target="+blan+" >"+website+"</a><br>"+skills;
  }

  function clearError(){
    validateimage.classList.add('hidden');
    userimage.classList.remove('errorcolor');
     validatewebsite.classList.add('hidden');
  userwebsite.classList.remove('errorcolor');
  validatename.classList.add('hidden');
  username.classList.remove('errorcolor');
    validateemail.classList.add('hidden');
 useremail.classList.remove('errorcolor');
    validategender.classList.add('hidden');
     validateskill.classList.add('hidden');
     document.getElementById('n').classList.add('hidden');
     document.getElementById('e').classList.add('hidden');
     document.getElementById('w').classList.add('hidden');
     document.getElementById('i').classList.add('hidden');

     validname=false;
     validemail=false;
     validwebsite=false;
     validimage=false;
     validgender=false;
     validskill=false;

      
  }

  function removeErrorG(){
    validategender.classList.add('hidden');
    validgender=true;
  }

  function removeErrorC(){
    skills=getSkills();
    if(skills.length<=2){
        validateskill.classList.remove('hidden');
        validskill=false;
    }else{         
        validateskill.classList.add('hidden');
                   validskill=true;
    }
    
  }



  





  


