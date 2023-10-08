#pragma once

#include "AtomicMap.h"
#include "MaaFramework/Instance/MaaResource.h"
#include "Utility.h"
#include "resource.grpc.pb.h"

struct ResourceImpl final : public ::maarpc::Resource::Service
{
    ResourceImpl(UtilityImpl* impl) : utility_impl(impl) {}

    ::grpc::Status create(::grpc::ServerContext* context, const ::maarpc::IdRequest* request,
                          ::maarpc::HandleResponse* response) override;
    ::grpc::Status destroy(::grpc::ServerContext* context, const ::maarpc::HandleRequest* request,
                           ::maarpc::EmptyResponse* response) override;
    ::grpc::Status post_path(::grpc::ServerContext* context, const ::maarpc::HandleStringRequest* request,
                             ::maarpc::IIdResponse* response) override;
    ::grpc::Status status(::grpc::ServerContext* context, const ::maarpc::HandleIIdRequest* request,
                          ::maarpc::StatusResponse* response) override;
    ::grpc::Status wait(::grpc::ServerContext* context, const ::maarpc::HandleIIdRequest* request,
                        ::maarpc::StatusResponse* response) override;
    ::grpc::Status loaded(::grpc::ServerContext* context, const ::maarpc::HandleRequest* request,
                          ::maarpc::BoolResponse* response) override;
    ::grpc::Status hash(::grpc::ServerContext* context, const ::maarpc::HandleRequest* request,
                        ::maarpc::StringResponse* response) override;

    UtilityImpl* utility_impl;
    AtomicMap<MaaResourceHandle> handles;
};