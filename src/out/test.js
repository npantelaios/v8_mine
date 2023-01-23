// How to execute this with d8:
// out/x64.debug/d8 test.js
//
// print bytecode:
// x64.debug/d8 --print-bytecode test.js

console.log("Hello world!");

if (1) {
  console.log("Hello world from inside if");
} else {
  console.log("Else statement");
}

function incrementX(obj) {
  return 1 + obj.x;
}
incrementX({ x: 42 });
c;
