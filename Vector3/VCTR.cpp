// VCTR.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Vector3.h"
int main()
{//minimal output capabilities
	Vector3 a;
	Vector3 b;
	std::cin >> a.x>>a.y>>a.z;
	std::cin >> b.x>>b.y>>b.z;
	std::cout<< a.len()<<a.len2();
	std::cout <<(a/2)<<(b/2);
	std::cout<< (a^b).x<<(a^b).y<<(a^b).z;
	return 0;
}

