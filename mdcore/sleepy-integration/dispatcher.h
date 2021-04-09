#ifndef _mdcore_Dispatcher_h
#define _mdcore_Dispatcher_h
#include "sleepy_discord/sleepy_discord.h"
#include "listener.h"
#include <vector>

namespace mdcore{
        class Dispatcher : public SleepyDiscord::DiscordClient{
            public:
                Dispatcher(); //DO NOT USE EXCEPT AS A NULL!
                Dispatcher(std::string token) : SleepyDiscord::DiscordClient(token){};
                ~Dispatcher();
                void onMessage(SleepyDiscord::Message message) override{
                    //TODO: Input logging messages here for each event
                    for(auto listener : this->listeners)
                    {
                        listener.onMessage(message);
                    }
                };
                void setListeners(std::vector<Listener> listeners);
                void registerListener(mdcore::Listener listener);
            private:
                std::vector<mdcore::Listener> listeners;
        };
}
#endif