def subtask2
  content = File.read('input3.txt')
  File.write('output3.txt', content)
  final = File.read('output3.txt')
  return final
end

print "Content of the file: \n"
inputcontent = gets

File.write('input3.txt', inputcontent)

puts "printing output.txt..."
result = subtask2
puts result
