define bin
p /t $arg0
end
define pq
call ft_print_queue(vars)
end
define ps
call ft_print(vars)
end

b min_ops.c:42
#b ft_calc_r_a_b_ops_to_insert
#b ft_push_min_ops
r
