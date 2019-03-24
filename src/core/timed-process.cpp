#include "timed-process.hpp"
#include <chrono>

using namespace std::chrono;

using namespace Icarus;

TimedProcess::TimedProcess(int duration) {
  this->duration = duration;
}

TimedProcess::~TimedProcess() {
  if (this->end != nullptr) delete this->end;
}

void TimedProcess::execute( ) {
  this->end  = new time_point<system_clock>(
    system_clock::now() + std::chrono::milliseconds((int)this->duration)
  );
}

bool TimedProcess::isFinished() {
  return this->end != nullptr
    && system_clock::now() > *this->end;
}


