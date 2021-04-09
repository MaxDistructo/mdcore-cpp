#include "member.h"
#include "core.h"

Member::Member()
{
    this.user = NULL;
    this.server = NULL;
}
Member::~Member()
{
    this.user = NULL;
    this.server = NULL;
}
Member::Member(SleepyDiscord::Snowflake<SleepyDiscord::Server> serverId, SleepyDiscord::User user)
{
    this.user = user;
    this.server = core_client->getServer(serverId).cast();
}
SleepyDiscord::Server Member::getServer()
{
    return this.server;
}
SleepyDiscord::User Member::getUser()
{
    return this.user;
}