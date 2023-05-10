#/!bin/bash
start_time_ft=$(date +%s.%N)
./ft_stack  > ft_out  2> ft_err
end_time_ft=$(date +%s.%N)
execution_time_ft=$(echo "$end_time_ft - $start_time_ft" | bc -l)

echo  "ft execution tim : $execution_time_ft"

# Run b.out and capture the execution time in seconds
start_time_std=$(date +%s.%N)

./std_stack > std_out 2> std_err

end_time_std=$(date +%s.%N)
execution_time_std=$(echo "$end_time_std - $start_time_std" | bc -l)
echo  "std execution time : $execution_time_std"
diff ft_out std_out
echo "Test successeded :)"