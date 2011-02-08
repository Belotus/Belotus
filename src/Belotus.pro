TEMPLATE = subdirs
SUBDIRS = BelotusCommon BelotusServer BelotusClient
TARGET = bin/BelotusServer bin/BelotusClient

BelotusServer.depends = BelotusCommon
BelotusClient.depends = BelotusCommon
