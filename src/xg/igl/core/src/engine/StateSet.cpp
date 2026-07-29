#include <xg/igl/engine/StateSet.hpp>

#include <algorithm>
#include <vector>

#include <vine/Ptr.hpp>

#include <xg/igl/engine/Program.hpp>
#include <xg/igl/engine/StateAttribute.hpp>
#include <xg/igl/engine/UniformBase.hpp>

namespace xg
{
namespace glr
{
namespace
{

struct StateAttr {
    vine::RefPtr<StateAttribute> attr;

    StateAttr(StateAttribute* sa)
    { attr = sa; }

    bool operator==(StateAttribute* sa) const
    {
        if (!sa)
            return false;

        if (sa->isKindOf(UniformBase::desc()) && attr->isKindOf(UniformBase::desc())) {
            return vine::obj_cast<UniformBase>(sa)->getName() == vine::obj_cast<UniformBase>(attr.get())->getName();
        }
        else {
            return attr.get()->getType() == sa->getType();
        }
    }

    bool operator!=(StateAttribute* sa)
    { return !(*this == sa); }
};

} // namespace

V_OBJECT_META_IMPL(StateSet, Object);

struct StateSet::Data {
    std::vector<StateAttr> attrs;

    vine::RefPtr<Program> shader;
};

StateSet::StateSet()
  : d(new Data())
{}

StateSet::~StateSet()
{ delete d; }

void StateSet::setAttribute(StateAttribute* attr)
{
    if (!attr)
        return;
    auto found_at = std::find(d->attrs.begin(), d->attrs.end(), attr);
    if (found_at == d->attrs.end()) { d->attrs.emplace_back(attr); }
    else {
        found_at->attr = attr;
    }
}

void StateSet::removeAttribute(StateAttribute* attr)
{
    if (!attr)
        return;
    auto found_at = std::find(d->attrs.begin(), d->attrs.end(), attr);
    if (found_at != d->attrs.end()) { d->attrs.erase(found_at); }
}

StateAttribute* StateSet::getAttribute(StateAttribute::Type type) const
{
    auto found_at = std::find_if(d->attrs.begin(), d->attrs.end(), [type](const auto& item) { return type == item.attr.get()->getType(); });
    if (found_at != d->attrs.end()) { return found_at->attr.get(); }
    return nullptr;
}

size_t StateSet::getNumAttributes() const
{ return d->attrs.size(); }

StateAttribute* StateSet::getAttributeAt(size_t i)
{ return (*(d->attrs.begin() + i)).attr.get(); }

Program* StateSet::getShader() const
{ return d->shader.get(); }

void StateSet::setShader(Program* shader)
{
    if (d->shader == shader)
        return;
    d->shader = shader;
}

} // namespace glr
} // namespace xg