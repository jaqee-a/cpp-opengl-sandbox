






#include "sandbox/core/entity.h"
#include "sandbox/core/registry.h"
#include <memory>
class Element {
private:
    std::shared_ptr<Sandbox::Entity> entity;
public:
    Element() {
        this->entity = Sandbox::Registry::RegisterNewEntity();
    };
    ~Element();


    virtual void update();
};
