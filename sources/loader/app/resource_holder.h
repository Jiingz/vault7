#pragma once

#include <memory>
#include <string>
#include <iterator>
#include <map>


namespace loader
{
    namespace deleters
    {
        struct NoOperation {
            template <typename T>
            void operator()(T const&) const noexcept { }
        };

        template <typename T>
        using DefaultDelete = std::default_delete<T>;
    }


    template <typename TResource, typename TDeleter = deleters::DefaultDelete<TResource>>
    class ResourceHolder
    {
    public:
        using MapType = std::map<std::wstring, std::unique_ptr<TResource, TDeleter>>;
        using Iterator = typename MapType::const_iterator;

        inline void Store(std::wstring id, std::unique_ptr<TResource, TDeleter> resource) {
            resources_[id] = std::move(resource);
        }

        inline void Remove(std::wstring id) {
            auto found = resources_.find(id);

            if (found != resources_.end()) {
                resources_.erase(found);
            }
        }

        inline void Remove(Iterator it) {
            resources_.erase(it);
        }

        inline TResource& Get(std::wstring id) {
            auto found = resources_.find(id);
            return *found->second;
        }

        inline Iterator Begin() const {
            return resources_.cbegin();
        }
        
        inline Iterator End() const {
            return resources_.cend();
        }

    private:
        MapType resources_;
    };

    /**
     * Resources where we are not deleting should use the no operation resource holder.
     */
    template <typename TResource>
    using ResourceHolderNop = ResourceHolder<TResource, deleters::NoOperation>;

    template <typename TResource>
    using ResourcePtr = std::unique_ptr<TResource>;

    /**
     * Resources where we are not deleting should use the no operation resource pointer.
     */
    template <typename TResource>
    using ResourcePtrNop = std::unique_ptr<TResource, deleters::NoOperation>;
}
