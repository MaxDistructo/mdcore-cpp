#include "include/mdcore/listener.h"
#include "sleepy_discord/sleepy_discord.h"

void mdcore::Listener::onMessage(SleepyDiscord::DiscordClient* client, SleepyDiscord::Message message)
{
    printf("Running Listener::onMessage(client, message)");
}