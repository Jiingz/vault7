#pragma once

#include <sdk/metadata.h>

#include <vector>


namespace sdk
{

    struct IChampion
    {
        virtual void OnInitialize() = 0;

        virtual void OnUpdate() = 0;

        virtual void OnDestroy() = 0;

        // virtual const std::vector<ChampionFeature> GetFeatures() const = 0;
    };


    //class ChampionBase : public IChampion
    //{
    //public:
    //    ChampionBase(const std::string& name);
    //
    //private:
    //};
}
