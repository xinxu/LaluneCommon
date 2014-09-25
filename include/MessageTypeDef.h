#ifndef __COMMON_HEADER_H_
#define __COMMON_HEADER_H_

//客户端包头定义

#define MSG_LENGTH(d) (*(uint32_t*)(d))
#define MSG_TYPE(d) (*(uint32_t*)((d) + 4))
#define MSG_OPERATION_ID(d) (*(uint32_t*)((d) + 8))
#define MSG_ERROR(d) (*(uint8_t*)((d) + 12)) //后端服务给前端服务返回的错误。如果有错误，那么默认后面的Protobuf就没有了，除非另有约定
#define MSG_ENCRYPTION_TYPE(d) (*(uint8_t*)((d) + 13))
#define MSG_RESERVED(d) (*(uint16_t*)((d) + 14))
#define MSG_HEADER_BASE_SIZE (16)
#define MSG_DATA(d) ((d) + MSG_HEADER_BASE_SIZE)
#define MSG_DATA_LEN(d) (MSG_LENGTH(d) - MSG_HEADER_BASE_SIZE)

//约定：偶数的都是发到服务器的包，奇数的都是服务器发出去的

//消息类型：网关服务相关
#define MSG_TYPE_CONNECT_OTHER (99) //负载均衡：告诉客户端连别的服务
#define MSG_TYPE_LOGIN (100) //登陆相关是特例，网关要处理
#define MSG_TYPE_LOGIN_RESULT (101)
#define MSG_TYPE_LOGIN_QUEUE (103)
#define MSG_TYPE_LOGIN_WAIT (105)

//消息类型：版本服务相关
#define MSG_CHECK_VERSION (10000)
#define MSG_CHECK_VERSION_RESULT (10001)

//消息类型：登陆服务（用户账号服务）相关
#define MSG_TYPE_REGISTER (20000)
#define MSG_TYPE_REGISTER_RESULT (20001)
#define MSG_TYPE_AUTOREGISTER (20002)
#define MSG_TYPE_AUTOREGISTER_RESULT (20003)


//消息类型：控制服务相关（这些其实只在和控制服务的连接里发）
#define MSG_TYPE_CONTROL_SERVER_SAY_HELLO (500000)
#define MSG_TYPE_CONTROL_SERVER_SAY_HELLO_RESULT (500001)
#define MSG_TYPE_CONTROL_SERVER_ADDR_INFO_REFRESH (500011) //这个是群体的刷新，后三个都是单体的
#define MSG_TYPE_CONTROL_SERVER_ADDR_INFO_ADD (500013)
#define MSG_TYPE_CONTROL_SERVER_ADDR_INFO_REMOVE (500015)
#define MSG_TYPE_CONTROL_SERVER_ADDR_INFO_RESTART (500017)
#define MSG_TYPE_CONTROL_SERVER_REPORT_LOAD (500020)
#define MSG_TYPE_CONTROL_SERVER_CMD (500050)
#define MSG_TYPE_CONTROL_SERVER_CMD_RESULT (500051)

#define MSG_TYPE_SPAN (10000)

//服务器类型（每个服务器的消息的分段就是[ID * 10000, (ID+1) * 10000)，这样消息类型转ServerType就除以10000
#define SERVER_TYPE_GATEWAY_SERVER (0)
#define SERVER_TYPE_VERSION_SERVER (1)
#define SERVER_TYPE_LOGIN_SERVER (2)
#define SERVER_TYPE_BASIC_INFO_SERVER (3)
#define SERVER_TYPE_LEAGUE_SERVER (4)
#define SERVER_TYPE_NOTICE_SERVER (5)
#define SERVER_TYPE_RANK_SERVER (6)
#define SERVER_TYPE_ASYNC_BATTLE_SERVER (7)
#define SERVER_TYPE_REPLAY_SERVER (8)
#define SERVER_TYPE_STAT_SERVER (9)
#define SERVER_TYPE_AUTO_MATCH_SERVER (10)
#define SERVER_TYPE_SYNC_BATTLE_SERVER (11)

#define SERVER_TYPE_CONTROL_SERVER (50)

#endif