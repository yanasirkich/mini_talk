/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:56:01 by ysirkich          #+#    #+#             */
/*   Updated: 2024/11/09 05:46:57 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_hander(int signal);
void	put_pid(long number);

int	main(void)
{	
	//signal handling with sigaction
	sigact.sa_handler = &signal_hander;//todo
	sigact.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	ft_putstr_fd("Welcome to my Minitalk server!", 2);
	ft_putstr_fd("Server PID:", 2);
	put_pid(getpid()); //todo
	fd_putstr_fd("\n", 2);
	while (1) //infinite loop to keep the server running
		pause();  //would need to check the reliablity of this approach
	return (0);	 
}
void	signal_hander(int signal)
{
	
}

void	put_pid(long number)
{
	
}