#include <core/game/manager/manager.h>

using namespace game;


ManagerTemplateAccessor::ManagerTemplateAccessor(ManagerTemplate* manager)
	: manager_(manager) { }


ManagerTemplateIterator<GameObject> ManagerTemplateAccessor::Begin() {
	return this->begin();
}


ManagerTemplateIterator<GameObject> ManagerTemplateAccessor::End() {
	return this->end();
}


ManagerTemplateIterator<GameObject> ManagerTemplateAccessor::begin() {
	return ManagerTemplateIterator<GameObject>(manager_, 0);
}


ManagerTemplateIterator<GameObject> ManagerTemplateAccessor::end() {
	return ManagerTemplateIterator<GameObject>(manager_, manager_->size.value);
}


ManagerTemplateAccessor ManagerTemplateProvider::GetAIHeroManager() {
	auto manager = memory::Accessor::AccessModuleAddress<ManagerTemplate*, 0x1859FAC>();
	return ManagerTemplateAccessor(manager);
}
