#include "bot.h"
#include "core.h"
#include "command_listener.h"
#include <chrono>

namespace mdcore{

        mdcore::Dispatcher* core_client;
        std::string core_prefix;
        Bot::Bot()
        {
            listeners = {};
            commands = {};
            coOwners = {};
            ownerId = "";
            name = "";
            token = "";
            prefix = "";
            commandListenerEnabled = false;
        };
        //We don't really have much to do here, just let sleepy do it's thing
        Bot::~Bot(){
            //this->dispatcher.quit();
        };
        Bot::Bot(std::string token)
        {
            listeners = {};
            commands = {};
            coOwners = {};
            ownerId = "";
            name = "";
            prefix = "";
            commandListenerEnabled = false;
            this->token = token;         
        };
        Bot::Bot(std::string token, std::string ownerId)
        {
            listeners = {};
            commands = {};
            coOwners = {};
            name = "";
            prefix = "";
            commandListenerEnabled = false;
            this->token = token;
            this->ownerId = ownerId;
        };
        Bot::Bot(std::string token, std::string ownerId, std::string prefix)
        {
            listeners = {};
            commands = {};
            coOwners = {};
            name = "";
            this->prefix = prefix;
            commandListenerEnabled = false;
            this->token = token;
            this->ownerId = ownerId;
            core_prefix = prefix;
        };
        void Bot::init()
        {
            if(token == "")
            {
                throw("Token was not set! Terminating process.");
            }
            if(prefix == "")
            {
                prefix = "!";                
            }
            if(ownerId == "")
            {
                printf("ownerId was not set! Any owner specific commands will not work.\n");
            }
            mdcore::Dispatcher dispatcher(token, SleepyDiscord::USER_CONTROLED_THREADS);
            this->dispatcher.run();
            this->dispatcher.waitTilReady();
            core_client = &this->dispatcher;
            this->dispatcher.updateStatus("Loading....", 0, (SleepyDiscord::Status)2, false);
            //Perform other setup code here such as passing the listeners to the actual client object
            this->dispatcher.setListeners(listeners);
            if(commandListenerEnabled)
            {
                mdcore::CommandListener commandListener(commands);
                this->dispatcher.registerListener(commandListener);
            }
            this->dispatcher.updateStatus((std::string)"Use " + prefix + "help", 1, (SleepyDiscord::Status)1, false);
        };
        void Bot::registerCommand(mdcore::Command c)
        {
            commands.push_back(c);
        };
        void Bot::registerListener(mdcore::Listener listener)
        {
            listeners.push_back(listener);
        };
        void Bot::setOwnerId(std::string id)
        {
            this->ownerId = id;
        };
        void Bot::useCommandListener()
        {
            commandListenerEnabled = !commandListenerEnabled;
        };
}