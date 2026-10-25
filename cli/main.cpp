/*
 * Copyright 2022 UnitTestBot contributors (utbot.org)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "Server.h"
#include "utils/CLIUtils.h"

#include "loguru.h"

#include <llvm/Support/Signals.h>

#include <cstdlib>
#include "config.h"

int main(int argc, char **argv) {
    setenv("GRPC_ENABLE_FORK_SUPPORT", "1", 1);
    llvm::sys::PrintStackTraceOnErrorSignal(argv[0]);
    CLI::App app{ PROJECT_DESCRIPTION, PROJECT_NAME };
    std::atexit([]() { std::cout << rang::style::reset; });
    try {
        CLIUtils::parse(argc, argv, app);
    } catch (const CLI::ParseError &e) {
        std::cout << (e.get_exit_code() == 0 ? rang::fg::green : rang::fg::red);
        return app.exit(e);
    }
    return 0;
}
