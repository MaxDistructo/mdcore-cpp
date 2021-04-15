#include <string>
#include "sleepy_discord/sleepy_discord.h"

void sendDM(SleepyDiscord::BaseDiscordClient client, SleepyDiscord::User member, std::string message)
{
    SleepyDiscord::DiscordClient::DiscordClient::sendDM(member, message);
}