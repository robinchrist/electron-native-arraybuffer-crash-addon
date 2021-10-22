/*********************************************************************
 * NAN - Native Abstractions for Node.js
 *
 * Copyright (c) 2018 NAN contributors
 *
 * MIT License <https://github.com/nodejs/nan/blob/master/LICENSE.md>
 ********************************************************************/

#include <nan.h>
#include "sync.h"   // NOLINT(build/include)
#include <stdexcept>

// Expose synchronous and asynchronous access to our
// Estimate() function
void InitAll(v8::Local<v8::Object> exports) {

    Nan::SetMethod(exports, "calculateSync", CVO::node::CalculateSync);

}

NAN_MODULE_WORKER_ENABLED(addon, InitAll)
