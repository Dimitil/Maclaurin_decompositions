#include <iostream>

int const defPrecision = 50;

double _exp(double x, int precision = defPrecision )
{
	double member = 1;
	double sum = 0;

	for (int i = 1; i <= precision; i++)
	{
		sum += member;
		member *= x / i;
	}
	return sum;
}


double _pow(double a, double x, int precision = defPrecision)
{
	double member = 1;
	double sum = 0;
	
	double ln_a = log(a); //здесь не знаю что придумать (кроме вызова написанной функции _log(a))
	for (int i = 1; i <= precision; i++)
	{
		sum += member;

		member *= x * ln_a  / i;
	}
	return sum;

}


double logFrom1MinusX(double x, int precision = defPrecision) //проверку на ввод сказали не делать
{
	
	double member = x;
	double result = 0;

	for (int i = 1; i <= precision; i++)
	{
		result -= member/i;
		member = member * x;
	}
	return result;

}

double _log(double x, int precision=10)
{
	precision *= 2;
	double base = (1-x)/(1+x);
	double sum = 0;
	double nextMember = base;
	bool needCount = true;
	for (int i = 1; i <= precision; i++)
	{
		if (needCount)
		{
			sum += nextMember / i;
		}
		nextMember *= base;
		needCount = !needCount;
	}

	return -2 * sum;

}



double _sin(double x, int precision = defPrecision)
{
	precision *= 2;
	double result = 0;
	double member = x;

	bool needCount = true;
	bool sign = true;
	for (int i = 2; i <= precision; i++)
	{
		if (needCount && sign)
		{
			result += member;
			sign = !sign;
		}
		else if (needCount && !sign)
		{
			result -= member;
			sign = !sign;
		}
		member *= x / i;
		needCount = !needCount;
	}
	return result;
}

double _sin2(double x, int precision = defPrecision)
{
	precision *= 2;
	double result = 1;
	double base = (3.141592/2 - x) ;
	double member = base * base / 2;
	bool needCount = true;
	bool sign = false;

	for (int i = 3; i <= precision; i++)
	{

		if (needCount && !sign)
		{
			result -= member;
			sign = !sign;
		}
		else if (needCount && sign)
		{
			result += member;
			sign = !sign;
		}
		member *= base / i;
		needCount = !needCount;
	}
	return result;
}

double _sh(double x, int precision = defPrecision)
{
	precision *= 2;
	double member = x;
	double result = 0;
	bool needCount = true;
	for (int i = 2; i <= precision; i++) 
	{
		if (needCount)
		{
			result += member;
		}
		member *= x / i;
		needCount = !needCount;
	}
	return result;
}

double _ch(double x, int precision = defPrecision)
{
	precision *= 2;
	double member = x;
	double result = 1;
	bool needCount = true;
	for (int i = 2; i <= precision; i++)
	{
		member *= x / i;
		if (needCount)
		{
			result += member;
		}
		needCount = !needCount;
	}
	return result;
}

double gip(double x, int m=2, int precision = defPrecision)
{
	double member = 1./2;
	for (int i = 1; i < m; i++)
	{
		member *= member;
	}
	for (int i = 1; i <= precision; i++)
	{
		member *= 2 - x * member;
	}
	return member;
}

double _sqrt(double x, int precision = defPrecision)
{
	double member = 1;
	for (int i = 1; i <= precision; i++)
	{
		member = 0.5 *(member + x / member);
	}
	return member;
}

double _cbrt(double x, int precision = defPrecision)
{
	double member = 1;
	for (int i = 1; i <= precision; i++)
	{
		member = 1./3 * (2*member + x / member / member);
	}
	return member;
}

double _revSqrt(double x, int m=2, int precision = defPrecision) //возможно, m должна быть только четной
{
	double member = 2;
	for (int i = 1; i < m / 2; i++)
	{
		member *= 2;
	}

	member = 1 / member;

	for (int i = 1; i <= precision; i++)
	{
		member = member * 0.5 * (3 - x * member * member);
	}
	return member;
}

int main()
{

	double x=0.6;

	std::cout <<"exp:\n"		<< _exp(x)				<< '\n' << exp(x)		  << "\n\n";

	std::cout << "pow:\n"		<< _pow(x, 4) << '\n'	<< pow(x, 4)			  << "\n\n";

	std::cout << "log(1-x):\n"	<< logFrom1MinusX(x)	<< '\n' << log(1 - x)	  << "\n\n";

	std::cout << "log:\n"		<< _log(x) << '\n'		<< log(x)				  << "\n\n";

	std::cout << "sin:\n"		<< _sin(x) << '\n'		<< sin(x)				  << "\n\n";

	std::cout << "sin2:\n"		<< _sin2(x) << '\n'		<< sin(x)				  << "\n\n";

	std::cout << "sh:\n"		<< _sh(x) << '\n'		<< (exp(x) - exp(-x)) / 2 << "\n\n";

	std::cout << "ch:\n"		<< _ch(x) << '\n'		<< (exp(x) + exp(-x)) / 2 << "\n\n";

	std::cout << "1/x:\n"		<< gip(x) << '\n'		<< 1 / x				  << "\n\n";

	std::cout << "sqrt:\n"		<< _sqrt(x) << '\n'		<< sqrt(x)				  << "\n\n";

	std::cout << "cbrt\n"		<< _cbrt(x) << '\n'		<< pow(x, 1. / 3)		  << "\n\n";

	std::cout << "1/sqrt:\n"	<< _revSqrt(x) << '\n'	<< 1 / sqrt(x)			  << "\n\n";
	return 0;
}