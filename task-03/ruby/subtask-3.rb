print "Enter the number: "
n = gets.to_i

for i in 1..n
  for j in 1..(n-i)
    print "  "
  end
  for k in 1..i
    print "* "
  end
  for l in 1..(i-1)
    print "* "
  end
  puts
end

for i in (n-1).downto(1)
  for j in n.downto(i+1)
    print "  "
  end
  for k in 1..i
    print "* "
  end
  for l in 1..(i-1)
    print "* "
  end
  puts
end
