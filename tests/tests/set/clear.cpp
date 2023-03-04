/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:20:13 by mleblanc          #+#    #+#             */
/*   Updated: 2022/05/24 02:52:10 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_prelude.hpp"

void set_test_clear()
{
    SETUP_ARRAYS();

    {
        strset m;

        PRINT_ALL(m);

        m.clear();

        PRINT_ALL(m);

        m.insert(str_arr, str_arr + 16);

        PRINT_ALL(m);

        m.clear();

        PRINT_ALL(m);
    }
}

MAIN(set_test_clear)
