#include "./cooldown.h"



Cooldown::Cooldown (real duration, real time_scale, CooldownCallback on_complete_func, CooldownCallback on_update_func)
:time_scale_(time_scale),
 duration_(duration),
 cur_time_(duration),
 on_update_func_(on_update_func),
 on_complete_func_(on_complete_func)
{
}


real Cooldown::update (real delta_time) {

  unlikely (cur_time_ >= duration_)
    return delta_time;

  cur_time_ += delta_time * time_scale_;

  unlikely (cur_time_ >= duration_) {
    unlikely (on_complete_func_ != null)
      on_complete_func_(this);
    return cur_time_ - duration_;
  }


  unlikely (on_update_func_ != null)
    on_update_func_(this);
  return REAL(0.0);
}


void Cooldown::start () {
  cur_time_ = REAL(0.0);
}


void Cooldown::clear () {
  cur_time_ = duration_;
}


void Cooldown::complete () {
  cur_time_ = duration_;

  unlikely (on_complete_func_ != null)
    on_complete_func_(this);
}
