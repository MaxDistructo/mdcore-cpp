/*
#define CATCH_CONFIG_MAIN
#include "lib/catch.hpp"
*/
#include "mdcore/sleepy-integration/bot.h"
#include "mdcore/config.h"
#include "mdcore/sleepy-integration/command.h"

class PingCommand : public mdcore::Command
{
	public:
		PingCommand()
		{
			setName("ping");
			setHelp("A sanity check command, just responds with Pong");
		}
		~PingCommand(){};
		void execute(SleepyDiscord::DiscordClient* client, SleepyDiscord::Message event, std::vector<std::string> args){
			event.reply(client, "Pong!");
		}
};

int main()
{
	mdcore::Bot bot(mdcore::readToken(), mdcore::readOwnerId(), mdcore::readPrefix());
	PingCommand ping;
	bot.useCommandListener();
	bot.registerCommand(ping);
	bot.init();
}



/*
#include "sleepy_discord/sleepy_discord.h"

class MyClientClass : public SleepyDiscord::DiscordClient {
public:
	using SleepyDiscord::DiscordClient::DiscordClient;
	void onMessage(SleepyDiscord::Message message) override {
		if (message.startsWith("whcg hello"))
			sendMessage(message.channelID, "Hello " + message.author.username);
	}
};

int main() {
	MyClientClass client("token", SleepyDiscord::USER_CONTROLED_THREADS);
	client.run();
}
*/
