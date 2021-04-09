#include "aegis.hpp"
#include "aegis/gateway/objects/role.hpp"
#include "aegis/gateway/objects/member.hpp"
#include "aegis/gateway/objects/channel.hpp"
#include "aegis/gateway/objects/guild.hpp"
#include "aegis/gateway/objects/activity.hpp"

namespace mdcore{
    namespace obj{
        using namespace aegis::gateway::events;
        class Listener{
            public:
                void messageRecieved(aegis::gateway::events::message_create event);
                void messageUpdate(aegis::gateway::events::message_update event);
                void messageDeleted(aegis::gateway::events::message_delete event);
                void channelCreate(aegis::gateway::events::channel_create event);
                void channelDelete(aegis::gateway::events::channel_delete event);
                void channelUpdate(aegis::gateway::events::channel_update event);
                void channelPinUpdate(aegis::gateway::events::channel_pins_update event);
                void guildBan(aegis::gateway::events::guild_ban_add event);
                void guildUnban(aegis::gateway::events::guild_ban_remove event);
                void guildCreate(aegis::gateway::events::guild_create event);
                void guildDelete(aegis::gateway::events::guild_delete event);
                void guildEmojiUpdate(aegis::gateway::events::guild_emojis_update event);
                void guildIntegrationUpdate(aegis::gateway::events::guild_integrations_update event);
                void guildMemberJoin(aegis::gateway::events::guild_member_add event);
                void guildMemberLeave(aegis::gateway::events::guild_member_remove event);
                void guildMemberUpdate(aegis::gateway::events::guild_member_update event);
                //void guildMemberChunk();
                void guildRoleCreate(aegis::gateway::events::guild_role_create event);
                void guildRoleDelete(aegis::gateway::events::guild_role_delete event);
                void guildRoleUpdate(aegis::gateway::events::guild_role_update event);
                void guildUpdate(aegis::gateway::events::guild_update event);
                void messageDeleteBulk(aegis::gateway::events::message_delete_bulk event);
                void messageReactionAdd(aegis::gateway::events::message_reaction_add event);
                void messageReactionRemove(aegis::gateway::events::message_reaction_remove event);
                void messageReactionRemoveAll(aegis::gateway::events::message_reaction_remove_all event);
                void userUpdate(aegis::gateway::events::user_update event);
                void voiceStateUpdate(aegis::gateway::events::voice_state_update event);
                void voiceServerUpdate(aegis::gateway::events::voice_server_update event);
                void webhookUpdate(aegis::gateway::events::webhooks_update event);
                void presenceUpdate(aegis::gateway::events::presence_update event);
        };
    }
}