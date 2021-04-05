/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 13:39:19 by gsharony          #+#    #+#             */
/*   Updated: 2021/04/05 08:38:29 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	test_list(bool show_errors);
void	test_vector(bool show_errors);
void	test_map(bool show_errors);
void	test_stack(bool show_errors);
void	test_queue(bool show_errors);

int		main(void)
{
	bool 	show_errors = true;
	test_list(show_errors);
	test_vector(show_errors);
	test_map(show_errors);
	test_stack(show_errors);
	test_queue(show_errors);
	return (0);
}
