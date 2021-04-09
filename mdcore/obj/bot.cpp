#include "bot.h"
#include "core.h"
#include <chrono>

namespace mdcore{

        mdcore::Dispatcher* core_client;
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
            this->client.quit();
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
            //init the client, this needs to eventually be our custom client that can use
            //the registered listeners and commands
            mdcore::Dispatcher(token, SleepyDiscord::USER_CONTROLED_THREADS) dispatcher;
            core_client = &this->dispatcher;
            this->dispatcher.updateStatus("Loading....", std::chrono::system_clock::now(), 2, false);
            //Perform other setup code here such as passing the listeners to the actual client object
            this->dispatcher.setListeners(listeners);
            if(commandListenerEnabled)
            {
                mdcore::CommandListener(commands) commandListener;
                this->dispatcher.registerListener(commandListener);
            }
            this->dispatcher.updateStatus((std::string)"Use " + prefix + "help", static_cast<uint64_t>(std::chrono::system_clock::now()), 1, false);

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
        SleepyDiscord::DiscordClient* getClient()
        {
            return this->&dispatcher;
        };
}