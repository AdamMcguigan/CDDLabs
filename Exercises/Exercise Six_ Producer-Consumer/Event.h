/* Event.h ---
 *
 * Filename: Event.h
 * Description:
 * Author: Joseph
 * Maintainer: Adam Mcguigan
 * Created: Tue Jan  8 12:30:05 2019 (+0000)
 * Version:
 * Package-Requires: ()
 * Last-Updated: Friday March 31  15:30 2023
 *           By: Adam
 */

/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Code: */
/*! \class Event
    \brief A Event Implementation
*/
#pragma once
#include <iostream>
class Event
{
    int number;
 public:
    void createEvent(int t_number){this->number = t_number;std::cout<<"Created " << number << std::endl;};
    void consumeEvent(){std::cout << "Consumed " << number << std::endl;};
};


/* Event.h ends here */
