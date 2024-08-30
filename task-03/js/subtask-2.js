const fs = require('fs');
const readline = require('readline');

function subtask2() {
  const inputFilePath = 'input.txt';
  const outputFilePath = 'output.txt';

  const content = fs.readFileSync(inputFilePath, 'utf8');
  fs.writeFileSync(outputFilePath, content);
  const final = fs.readFileSync(outputFilePath, 'utf8');
  return final;
}

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Content of the file: \n', (inputContent) => {
  fs.writeFileSync('input.txt', inputContent);
  console.log('printing output.txt...');
  const result = subtask2();
  console.log(result);
  rl.close();
});
