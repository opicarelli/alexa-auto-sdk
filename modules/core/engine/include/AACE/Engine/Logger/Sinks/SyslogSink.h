/*
 * Copyright 2017-2021 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *     http://aws.amazon.com/apache2.0/
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#ifndef AACE_ENGINE_LOGGER_SINK_SYSLOG_SINK_H
#define AACE_ENGINE_LOGGER_SINK_SYSLOG_SINK_H

#include <AACE/Engine/Logger/LogFormatter.h>
#include "Sink.h"

namespace aace {
namespace engine {
namespace logger {
namespace sink {

class SyslogSink : public Sink {
private:
    explicit SyslogSink(const std::string& id);

public:
    ~SyslogSink() override;

    static std::shared_ptr<SyslogSink> create(const std::string& id);

private:
    void log(
        Level level,
        std::chrono::system_clock::time_point time,
        const char* source,
        const char* threadMoniker,
        const char* text) override;

private:
    std::unique_ptr<aace::engine::logger::LogFormatter> m_formatter;
};

}  // namespace sink
}  // namespace logger
}  // namespace engine
}  // namespace aace

#endif  // AACE_ENGINE_LOGGER_SINK_SYSLOG_SINK_H
