#include "dispatcher.h"    
#include "listener.h"

void mdcore::Dispatcher::setListeners(std::vector<mdcore::Listener> listeners)
{
    this->listeners = listeners;
}
void mdcore::Dispatcher::registerListener(mdcore::Listener listener)
{
    this->listeners.push_back(listener);
}