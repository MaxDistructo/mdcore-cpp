#include "bot.h"
#include <chrono>

using namespace mdcore{
    using namespace obj{
        Bot::Bot()
        {
            listeners = {};
            commands = {};
            coOwners = {};
            ownerId = "";
            name = "";
            token = "";
            prefix = "";
            client = NULL;
            commandListenerEnabled = false;
            commandListener = NULL;
        };
        //We don't really have much to do here, just let sleepy do it's thing
        Bot::~Bot(){
            if(client != NULL)
            {
                client.stopClient();
            }
        };
        Bot::Bot(std::string token)
        {
            listeners = {};
            commands = {};
            coOwners = {};
            ownerId = "";
            name = "";
            prefix = "";
            client = NULL;
            commandListenerEnabled = false;
            commandListener = NULL;
            this.token = token;         
        };
        Bot::Bot(std::string token, std::string ownerId)
        {
            listeners = {};
            commands = {};
            coOwners = {};
            name = "";
            prefix = "";
            client = NULL;
            commandListenerEnabled = false;
            commandListener = NULL;
            this.token = token;
            this.ownerId = ownerId;
        };
        Bot::Bot(std::string token, std::string ownerId, std::string token)
        {
            listeners = {};
            commands = {};
            coOwners = {};
            name = "";
            this.prefix = prefix;
            client = NULL;
            commandListenerEnabled = false;
            commandListener = NULL;
            this.token = token;
            this.ownerId = ownerId;
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
            SleepyDiscord::DiscordClient(token, SleepyDiscord::USER_CONTROLED_THREADS) client;
            client.updateStatus("Loading....", std::chrono::system_clock::now(), 2, false);
            //Perform other setup code here such as passing the listeners to the actual client object
            client.setListeners(listeners);
            if(commandListenerEnabled)
            {
                CommandListener(commands) commandListener;
            }
            client.updateStatus("Use " + prefix + "help", std::chrono::system_clock::now(), 1, false);

        };
        void Bot::registerCommand(Command c)
        {
            commands.push_back(c);
        };
        void Bot::registerListener(Listener listener)
        {
            listeners.push_back(listener);
        };
        void Bot::setOwnerId(std::string id)
        {
            this.ownerId = id;
        };
        void Bot::useCommandListener()
        {
            commandListenerEnabled = !commandListenerEnabled;
        };
        SleepyDiscord::DiscordClient getClient()
        {
            if(client != NULL){
                return client;
            }
            else{
                throw("No client avaliable to retrieve. Please ensure init is ran before attempting to get the client.");
            }
        }
    }
}