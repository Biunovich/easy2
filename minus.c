#include "1.h"
Comlex minus(Comlex x,Comlex y)
{
	Comlex res;
	res.Re = x.Re - y.Re;
	res.Im = x.Im - y.Im;
	return res;
}