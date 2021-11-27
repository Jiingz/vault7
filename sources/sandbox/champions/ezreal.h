#pragma once

#include <sdk/nativescript.h>

#include <vector>


namespace sandbox::champions
{
    class Ezreal : public sdk::NativeScript<sdk::ExecutionLayer::Champion>
    {
    public:
        void OnInitialize() final override;

        void OnUpdate() final override;

        void OnDestroy() final override;

        // const std::vector<sdk::ChampionFeature> GetFeatures() const final override;

    private:
        
    };
}
