/*********************************************************************
 * NAN - Native Abstractions for Node.js
 *
 * Copyright (c) 2018 NAN contributors
 *
 * MIT License <https://github.com/nodejs/nan/blob/master/LICENSE.md>
 ********************************************************************/

#include <nan.h>
#include "sync.h"  // NOLINT(build/include)
//#include "macro-inferno.h"

namespace CVO::node {
  // Simple synchronous access to the `Estimate()` function
  NAN_METHOD(CalculateSync) {
    Nan::HandleScope scope;
    size_t param = 229377;
    v8::Local<v8::ArrayBuffer> fieldDataBuffer = v8::ArrayBuffer::New(v8::Isolate::GetCurrent(), param * sizeof(float));
    v8::Local<v8::Float32Array> fieldDataArr = v8::Float32Array::New(fieldDataBuffer, 0, param);
    
    float* ptr = (float*)(fieldDataBuffer->GetBackingStore()->Data());

    ptr[0] = 1.0;

    info.GetReturnValue().Set(fieldDataArr);
  }

}
