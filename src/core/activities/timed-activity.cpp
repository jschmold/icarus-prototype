#include "timed-activity.hpp"
#include <chrono>

using namespace std::chrono;

using namespace Icarus::Activities;

TimedActivity::TimedActivity(int duration) {
  this->duration = duration;
}

TimedActivity::~TimedActivity() {
  if (this->end != nullptr) delete this->end;
}

double TimedActivity::getProgress() {
  auto now = system_clock::now() - *this->start;
  auto total = *this->end - *this->start;
  return now / total; 
}

void TimedActivity::execute( ) {
  this->end  = new time_point<system_clock>(
    system_clock::now() + std::chrono::milliseconds((int)this->duration)
  );
}

bool TimedActivity::isFinished() {
  return this->end != nullptr
    && system_clock::now() > *this->end;
}

