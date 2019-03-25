################################################################################
 # 
 #   Created: tue mar 25 01:54:22 -03 2019
 #   Updated: 
 # 
 #------------------------------------------------------------------------------
 #
 #   programa - Made to solve pt.stackoverflow.com/questions/370932
 # 
 #   Copyright (C) 2019 J. F. Candido Filho <jfcandidofilho [at] gmail.com>
 # 
 #   This program is free software: you can redistribute it and/or modify
 #   it under the terms of the GNU General Public License as published by
 #   the Free Software Foundation, either version 3 of the License, or
 #   (at your option) any later version.
 #
 #   This program is distributed in the hope that it will be useful,
 #   but WITHOUT ANY WARRANTY; without even the implied warranty of
 #   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 #   GNU General Public License for more details.
 #
 #   You should have received a copy of the GNU General Public License
 #   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 #
################################################################################

import string
import itertools

padrao  = string.ascii_lowercase
produto = itertools.product( padrao, repeat = 4 )

for i in produto:
    print( i )
