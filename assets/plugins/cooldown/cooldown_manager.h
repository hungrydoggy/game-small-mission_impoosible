#ifndef PLUGINS_COOLDOWN_COOLDOWN_MANAGER_H_
#define PLUGINS_COOLDOWN_COOLDOWN_MANAGER_H_

#include <appetizer.h>


using namespace appetizer;

class Cooldown;


class GAMECONTENT_API CooldownManager :
    public ObjectTrait,
    public IOnUpdateCallback
{
public: // getter/setter
  ObjectTraitGroupIdType trait_group_id () const override;

  shared_ptr<Cooldown> const&  addCooldown (string const& name, shared_ptr<Cooldown> const& cooldown);
  void removeCooldown (string const& name);

  inline shared_ptr<Cooldown> getCooldown (string const& name) const {
    return getCooldown(StringRegistry::default_registry().lookUp(name));
  }
  shared_ptr<Cooldown> getCooldown (StringRegistryIdType name_reg) const;


protected: // methods
  virtual void onUpdate (double delta_time) override;


private: // vars
  unordered_map<StringRegistryIdType, shared_ptr<Cooldown>> cooldown_map_;
};



#endif  // ifndef PLUGINS_COOLDOWN_COOLDOWN_MANAGER_H_
