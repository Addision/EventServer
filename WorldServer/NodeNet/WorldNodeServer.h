#pragma once

#include "SeFServerBase.h"

class WorldNodeServer : public SeFServerBase{
public:
    virtual bool InitHelper();
    virtual void OnClientDisconnect(const socket_t sock_fd) {}
    void OtherMessage(const socket_t sock_fd, const int msg_id, const char *msg, const size_t msg_len);

};