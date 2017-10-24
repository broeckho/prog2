/**
 * @file
 * Code used in the exam of the 2009-2010 academic year.
 * @author J. Broeckhove
 */

#include "demobj.h"
#include "demos.h"
#include "tracer/tracer.h"
#include <iostream>

using std::cout;
using std::endl;
using namespace ODemo;

namespace /* anonymous */
{

void func(Vehicle* p)
{
	COMP_MISC_FUNCTION_TRACER;
	p->get_info();
}
void funcBis(const Vehicle& b)
{
	COMP_MISC_FUNCTION_TRACER;
	b.get_info();
}
void funcTer(RoadVehicle r)
{
	COMP_MISC_FUNCTION_TRACER;
	r.get_info();
}

} // end-of-anonymous-namespace

int exam01()
{
	COMP_MISC_FUNCTION_TRACER;
	COMP_MISC_TRACER_OUTPUT_OFF;

	RoadVehicle rv1;
	Bicycle m1("Honda", "black");
	PassengerRoadVehicle prv1(5);
	SailBoat b1("Freddy");

	COMP_MISC_TRACER_OUTPUT_ON;

	{
		COMP_MISC_BLOCK_TRACER("Block 1");

		COMP_MISC_LOG_TRACER(" statement: Bicycle m2(m1);");
		Bicycle m2(m1);

		COMP_MISC_LOG_TRACER(" statement: m2 = m1;");
		m2 = m1;
	}

	{
		COMP_MISC_BLOCK_TRACER("Block 2");

		COMP_MISC_LOG_TRACER(" statement: funcTer(rv1);");
		funcTer(rv1);

		COMP_MISC_LOG_TRACER(" statement: funcBis(m1);");
		funcBis(m1);

		COMP_MISC_LOG_TRACER(" statement: funcTer(prv1);");
		funcTer(prv1);

		COMP_MISC_LOG_TRACER(" statement: func(&b1);");
		func(&b1);
	}

	COMP_MISC_LOG_TRACER(" statement: return 0;");
	return 0;
}
