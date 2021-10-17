const SHA256 = require("crypto-js/sha256");
class BlockCrypto {
  constructor(index, current_time, info, prevHash = " ") {
    this.index = index;
    this.current_time = current_time;
    this.info = info;
    this.prevHash = prevHash;
    this.hash = this.computeHash();
  }
  computeHash() {
    return SHA256(
      this.info + this.prevHash + this.current_time + JSON.stringify(this.info)
    ).toString();
  }
}

class Blockchain {
  constructor() {
    this.block1chain = [this.initGenesisBlock()];
    
  }
  initGenesisBlock() {
    return new BlockCrypto(0, "11/08/2021", "first block", "0");
  }
  latestBlock() {
    return this.block1chain[this.block1chain.length - 1];
  }
  addNewBlock(newBlock) {
    newBlock.prevHash = this.latestBlock().hash;
    newBlock.hash = newBlock.computeHash();
    this.block1chain.push(newBlock);
  }
  
checkValidity(){
    // Checking validity
    for(let i = 1; i < this.block1chain.length; i++) {
        const currentBlock = this.block1chain[i];
        const nextBlock= this.block1chain[i-1];
    // Checking current block hash
    
    if(currentBlock.hash !== currentBlock.computeHash()) {
        return false;
    }
    // Comparing current block hash with the next block

    if(currentBlock.prevHash !== nextBlock.hash) {
        return false;
    }
    return true;
}
}
}

let thecoin = new Blockchain();

thecoin.addNewBlock(new BlockCrypto(1, "11/08/2021", {sender: "Dishant Lodaliya", recipient: "Brijesh Patel", quantity: 20}));
thecoin.addNewBlock(new BlockCrypto(2, "12/08/2021", {sender: "Akshat Mehta", recipient: "Jeet Sodha", quantity: 349}));
thecoin.addNewBlock(new BlockCrypto(2, "12/08/2021", {sender: "Deep Menpara", recipient: "Dishant Lodaliya", quantity: 349}));
console.log(thecoin.checkValidity());
console.log(JSON.stringify(thecoin, null,4));
