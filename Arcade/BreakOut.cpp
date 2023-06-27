#include "BreakOut.h"
#include <iostream>


void BreakOut::Init(GameController& controller)
{
	std::cout << "breaik out init" << std::endl;
}
void BreakOut::Update(uint32_t dt)
{
	std::cout << "break out update" << std::endl;
}
void BreakOut::Draw(Screen& screen)
{
	std::cout << "break out draw" << std::endl;
}
std::string BreakOut::GetName() const
{
	return  "break out get name";
}
