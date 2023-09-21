# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    .gdbinit                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcorri <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/21 12:07:47 by fcorri            #+#    #+#              #
#    Updated: 2023/09/21 14:16:59 by fcorri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

define bin
p /t $arg0
end
define pq
call ft_print_queue(vars)
end
define ps
call ft_print(vars)
end
define pr
p r_a_b
end

#b ft_push_min_ops
#r
#c 13
b ft_order_more
r
ps
