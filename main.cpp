/*
#define CATCH_CONFIG_MAIN
#include "lib/catch.hpp"
*/
#include "mdcore/config.h"
#include "mdcore/sleepy-integration/command.h"
#include "mdcore/sleepy-integration/command_listener.h"
#include "mdcore/sleepy-integration/dispatcher.h"

class PingCommand : public mdcore::Command
{
	public:
		PingCommand()
		{
			setName("ping");
			setHelp("A sanity check command, just responds with Pong");
		}
		~PingCommand(){};
		void execute(SleepyDiscord::DiscordClient* client, SleepyDiscord::Message event, std::vector<std::string> args) override{
			event.reply(client, "Pong!");
		}
};

int main()
{
	mdcore::Dispatcher bot(mdcore::readToken());
	PingCommand ping;
	std::vector<mdcore::Command*> commands = {};
	commands.push_back(*ping);
	mdcore::CommandListener c_listener(commands, mdcore::readPrefix());
	bot.registerListener(*c_listener);
	bot.run();
}
