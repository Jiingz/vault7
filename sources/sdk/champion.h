#pragma once


namespace sdk
{

    struct IChampion
    {
        virtual void OnInitialize() = 0;

        virtual void OnUpdate() = 0;

        virtual void OnDestroy() = 0;
    };
}
