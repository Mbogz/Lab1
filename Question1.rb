def summation(nums)
  nums.inject(0) { |acc, num| acc + num }
end

def maximum(nums)
  nums.max
end

def main
  puts "Enter the length of the array: "
  n = gets.chomp.to_i

  puts "Enter the #{n} integers:"
  nums = []
  n.times do
    nums << gets.chomp.to_i
  end

  sum = summation(nums)
  max = maximum(nums)

  puts "The sum is #{sum}."
  puts "The maximum is #{max}."
end

main
