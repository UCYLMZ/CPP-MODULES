#pragma once

#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

class Base
{
	public:
		Base(void);
		virtual ~Base(void);
		Base * generate(void);

};