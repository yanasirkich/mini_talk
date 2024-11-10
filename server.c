/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:56:01 by ysirkich          #+#    #+#             */
/*   Updated: 2024/11/10 12:50:52 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signal_handler(int signal);
static void	put_pid(long number);

int	main(void)
{	
	//signal handling with sigaction
	sigact.sa_handler = &signal_handler;//todo
	sigact.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	ft_putstr_fd("Welcome to my Minitalk server!\n", 2);
	ft_putstr_fd("Server PID:", 2);
	put_pid(getpid()); //todo
	fd_putstr_fd("\n", 2);
	while (1) //infinite loop to keep the server running
		pause();  //would need to check the reliablity of this approach
	return (0);	 
}
static void	signal_handler(int signal)
{ //SIGUSR1 == 0 bit,  SIGUSR2 == 1 bit.
	static int	bit_count = 0; //count of bits of the current char
	static int	current_char = 0; //shifts left by 1 to make space for the new bit
	int			bit;

	if (signal == SIGUSR1)
		bit = 0;
	else if (signal == SIGUSR2)
		bit = 1;
	current_char = (current_char << 1) | bit;
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &current_char, 1);
		bit_count = 0;
		current_char = 0;
	}
}

static void	put_pid(long number)
{
	char	temporary;
	
	if (number > 9)
		put_pid(number / 10);
	temporary = number % 10 + '0';
	write(1, &temporary, 1);
}