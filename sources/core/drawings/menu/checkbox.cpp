#include <core/drawings/menu/checkbox.h>

using namespace drawings;

Checkbox::Checkbox(const char* name)
{
	this->name_ = name;
	this->state_ = false;
}

void Checkbox::Render()
{
	ImGui::Checkbox(this->name_, &this->state_);
}
