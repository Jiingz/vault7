#pragma once


namespace sdk
{
    enum class ExecutionLayer
    {
        World,
        Champion
    };

    template <ExecutionLayer TLayer>
    class NativeScript
    {
    public:
        inline NativeScript() { }

        virtual void OnInitialize() = 0;

        virtual void OnUpdate() = 0;

        virtual void OnDestroy() = 0;

        inline ExecutionLayer GetLayer() final override {
            return TLayer;
        }
    };
}
