// Code for Dice 1
var randomNumber1 = Math.random();
randomNumber1 = Math.floor(randomNumber1 * 6) + 1;

document.querySelector(".img1").setAttribute("src", "images/dice"
 +randomNumber1+".png");

// Code for Dice 2
var randomNumber2 = Math.random();
randomNumber2 = Math.floor(randomNumber2 * 6) + 1;

document.querySelector(".img2").setAttribute("src", "images/dice"
 +randomNumber2+".png");

// Comparing both the Random Numbers
if (randomNumber1 > randomNumber2)
{
 document.querySelector("h1").textContent = "🥳 Player 1 Wins!";
}
else if (randomNumber1 < randomNumber2)
{
 document.querySelector("h1").textContent = "Player 2 Wins! 🥳";
}
else
{
 document.querySelector("h1").textContent = "Draw! 😂😂";
}