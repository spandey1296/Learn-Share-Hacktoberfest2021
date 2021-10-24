const express = require("express");

const app = express();

app.use(express.urlencoded({extended: true}));

app.get("/", function (res, req) {
 req.sendFile(__dirname + "/index.html");
});

app.post("/", function (req, res) {
 var num1 = Number(req.body.num1);
 var num2 = Number(req.body.num2);
 var result = num1 + num2;
 res.send("Result of the calculation is : " + result);
});

app.get("/bmicalculator", function (req, res) {
 res.sendFile(__dirname + "/bmiCalculator.html");
});

app.post("/bmicalculator", function (req, res) {
 var weight = Number(req.body.weight);
 var height = Number(req.body.height);
 var bmi = weight / (Math.pow(height, 2));
 bmi = bmi.toFixed(2);
 res.send("Your BMI is : " + bmi);
});

app.listen(3000, function () {
 console.log("Server is running on port 3000.")
});
