#include "./cooldown_manager.h"

#include "./cooldown.h"



ObjectTraitGroupIdType CooldownManager::trait_group_id () const {
  static auto gid = StringRegistry::default_registry().lookUp("cooldown_manager");
  return gid;
}


void CooldownManager::addCooldown (string const& name, shared_ptr<Cooldown> const& cooldown) {
  cooldown_map_[StringRegistry::default_registry().lookUp(name)] = cooldown;
}


void CooldownManager::removeCooldown (string const& name) {
  cooldown_map_.erase(StringRegistry::default_registry().lookUp(name));
}


shared_ptr<Cooldown> CooldownManager::getCooldown (StringRegistryIdType name_reg) const {
  return cooldown_map_.at(name_reg);
}


void CooldownManager::onUpdate (double delta_time) {
  for (auto& itr : cooldown_map_)
    itr.second->update((real)delta_time);
}
