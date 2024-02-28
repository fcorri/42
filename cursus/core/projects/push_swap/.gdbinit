# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    .gdbinit                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcorri <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/21 12:07:47 by fcorri            #+#    #+#              #
#    Updated: 2023/10/07 11:52:08 by fcorri           ###   ########.fr        #
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

