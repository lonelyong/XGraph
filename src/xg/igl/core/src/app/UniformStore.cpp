#include <xg/igl/app/UniformStore.hpp>

#include <map>

#include <xg/igl/engine/UniformBase.hpp>

namespace xg
{
namespace glr
{

V_OBJECT_META_IMPL(UniformStore, Object);

struct UniformStore::Data {
    std::string                                      name;
    std::map<std::string, vine::RefPtr<UniformBase>> uniforms;
};

UniformStore::UniformStore()
  : d(new Data())
{}

UniformStore::UniformStore(const std::string& name)
  : d(new Data())
{}

UniformBase* UniformStore::get(const std::string& name) const
{
    if (d->uniforms.contains(name))
        return d->uniforms[name].get();
    return nullptr;
}

void UniformStore::set(const std::string& name, UniformBase* uniform)
{
    if (!uniform)
        d->uniforms.erase(name);
    else
        d->uniforms[name] = uniform;
}

} // namespace glr
} // namespace xg
