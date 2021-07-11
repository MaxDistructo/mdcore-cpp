#include "../include/mdcore/member.h"
#include "../include/mdcore/core.h"

mdcore::Member::Member()
{
}
mdcore::Member::~Member()
{
}
mdcore::Member::Member(SleepyDiscord::Snowflake<SleepyDiscord::Server> serverId, SleepyDiscord::User user)
{
    this->user = user;
    this->server = core_client->getServer(serverId).cast();
}
SleepyDiscord::Server mdcore::Member::getServer()
{
    return this->server;
}
SleepyDiscord::User mdcore::Member::getUser()
{
    return this->user;
}