#include <loader/app/locator.h>

using namespace loader;

std::unique_ptr<ResourceHolderNop<ImFont>> Locator::s_fonts_ = nullptr;
std::unique_ptr<ResourceHolder<sdk::ModuleBase>> Locator::s_modules_ = nullptr;



void Locator::Finalize()
{
}


ResourceHolderNop<ImFont>* Locator::GetFonts()
{
    if (!s_fonts_)
    {
        s_fonts_ = std::make_unique<ResourceHolderNop<ImFont>>();
    }

    return s_fonts_.get();
}


ResourceHolder<sdk::ModuleBase>* Locator::GetModules()
{
    if (!s_modules_)
    {
        s_modules_ = std::make_unique<ResourceHolder<sdk::ModuleBase>>();
    }

    return s_modules_.get();
}

