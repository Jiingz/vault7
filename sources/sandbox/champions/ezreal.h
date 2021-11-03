#pragma once

#include <sdk/champion.h>

#include <vector>


namespace sandbox::champions
{
    class Ezreal : public sdk::IChampion
    {
    public:
        void OnInitialize() final override;

        void OnUpdate() final override;

        void OnDestroy() final override;

        // const std::vector<sdk::ChampionFeature> GetFeatures() const final override;

    private:
        
    };
}
