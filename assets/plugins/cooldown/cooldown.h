#ifndef PLUGINS_COOLDOWN_COOLDOWN_H_
#define PLUGINS_COOLDOWN_COOLDOWN_H_

#include <appetizer.h>


using namespace appetizer;


class Cooldown;
using CooldownCallback = function<void (Cooldown* cooldown)>;


class GAMECONTENT_API Cooldown {
public: // getter/setter
  GETTER_SETTER(real, time_scale)
  GETTER_SETTER(real, duration  )
  GETTER_SETTER(real, cur_time  )
  GETTER_SETTER(CooldownCallback, on_update_func  )
  GETTER_SETTER(CooldownCallback, on_complete_func)

  inline real progress () const { return (duration_ != REAL(0.0))? cur_time_ / duration_ : REAL(0.0); }

  inline bool is_complete () const { return cur_time_ >= duration_; }


public: // methods
  Cooldown (
      real duration = REAL(0.0),
      real time_scale = REAL(1.0),
      CooldownCallback on_complete_func = null,
      CooldownCallback on_update_func = null
  );

  real update (real delta_time);  // returns left time

  void start ();

  void clear ();

  void complete ();


private: // vars
  real time_scale_;
  real duration_;
  real cur_time_;

  CooldownCallback on_update_func_;
  CooldownCallback on_complete_func_;
};



#endif  // ifndef PLUGINS_COOLDOWN_COOLDOWN_H_
