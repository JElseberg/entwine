/******************************************************************************
* Copyright (c) 2016, Connor Manning (connor@hobu.co)
*
* Entwine -- Point cloud indexing
*
* Entwine is available under the terms of the LGPL2 license. See COPYING
* for specific license text and more information.
*
******************************************************************************/

#pragma once

#include <memory>
#include <vector>

#include <json/json.h>

#include <entwine/tree/config.hpp>

namespace entwine
{

namespace arbiter { class Arbiter; }

class Bounds;
class Builder;
class Delta;
class Manifest;
class Subset;

class ConfigParser
{
public:
    static Json::Value defaults();

    static std::unique_ptr<Builder> getBuilder(
            Json::Value json,
            std::shared_ptr<arbiter::Arbiter> arbiter = nullptr);

    static std::unique_ptr<Builder> getBuilder(const Config& config);

    static std::string directorify(std::string path);

private:
    static void normalizeInput(
            Json::Value& json,
            const arbiter::Arbiter& arbiter);

    static std::unique_ptr<Builder> tryGetExisting(
            const Json::Value& config,
            std::shared_ptr<arbiter::Arbiter> arbiter,
            const std::string& outPath,
            const std::string& tmpPath,
            std::size_t workThreads,
            std::size_t clipThreads);

    static std::unique_ptr<Subset> maybeAccommodateSubset(
            Json::Value& json,
            const Bounds& boundsConforming,
            const Delta* delta);
};

} // namespace entwine

