#/!bin/bash
./ft_map  > ft_out  2> ft_err
./std_map > std_out 2> std_err

diff ft_out std_out
