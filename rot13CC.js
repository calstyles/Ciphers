function rot13(str) {
  let newStr = "";

  for(let i = 0; i < str.length; i++){

    if(str[i].charCodeAt(0) <= 77 && str[i].charCodeAt(0) > 64){
        newStr += String.fromCharCode(str[i].charCodeAt(0) + 13); 
    }else if(str[i].charCodeAt(0) >= 78 && str[i].charCodeAt(0) <= 90){
        newStr += String.fromCharCode(str[i].charCodeAt(0) - 13);
    }else{
        newStr += str[i];
    }
  }
  return newStr;
}

console.log(rot13("SERR CVMMN!"));
console.log(rot13("GUR DHVPX OEBJA SBK WHZCF BIRE GUR YNML QBT."));