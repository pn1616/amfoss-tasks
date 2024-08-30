def read_number_from_file(filename)
  num = File.read(filename)
  return num.strip.to_i
end

def write_number_to_file(filename, content)
  File.write(filename, content)
end

def generate_pattern(n)
  pattern = []

  for i in 0...n
    line = ' ' * (n - i - 1) + '*' * (2 * i + 1)
    pattern << line
  end

  for i in (n - 2).downto(0)
    line = ' ' * (n - i - 1) + '*' * (2 * i + 1)
    pattern << line
  end

  return pattern.join("\n")
end

def write_pattern_to_file(filename, pattern)
  File.write(filename, pattern)
end

print "Enter the number: "
inputcontent = gets.chomp
write_number_to_file('input4.txt', inputcontent)
n = read_number_from_file('input4.txt')
result = generate_pattern(n)
write_pattern_to_file('output4.txt', result)
