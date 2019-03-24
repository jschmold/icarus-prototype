#include "activity.hpp"
#include <chrono>

using namespace std::chrono;

using namespace Icarus;

Activity::Activity(int duration) {
  this->duration = duration;
}

Activity::~Activity() {
  if (this->end != nullptr) delete this->end;
}

void Activity::execute( ) {
  this->end  = new time_point<system_clock>(
    system_clock::now() + std::chrono::milliseconds((int)this->duration)
  );
}

bool Activity::isFinished() {
  return this->end != nullptr
    && system_clock::now() > *this->end;
}


