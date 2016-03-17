/**
* @licence app begin@
* SPDX-License-Identifier: MPL-2.0
*
* \copyright Copyright (C) 2016, PCA Peugeot Citroen
*
* \file main.cpp
*
* \brief This file is part of the Navigation Web API proof of concept.
*
* \author Philippe Colliot <philippe.colliot@mpsa.com>
*
* \version 0.1
*
* This Source Code Form is subject to the terms of the
* Mozilla Public License (MPL), v. 2.0.
* If a copy of the MPL was not distributed with this file,
* You can obtain one at http://mozilla.org/MPL/2.0/.
*
* For further information see http://www.genivi.org/.
*
* List of changes:
* <date>, <name>, <description of change>
*
* @licence end@
*/
#include <node.h>

#include "PositioningWrapper.hpp"

using namespace v8;
using namespace std;


Persistent<FunctionTemplate> PositioningWrapper::constructor;


void PositioningWrapper::Init(Handle<Object> target) {
    HandleScope scope;

    Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
    Local<String> name = String::NewSymbol("PositioningWrapper");

    constructor = Persistent<FunctionTemplate>::New(tpl);
    // ObjectWrap uses the first internal field to store the wrapped pointer.
    constructor->InstanceTemplate()->SetInternalFieldCount(1);
    constructor->SetClassName(name);

    // Add all prototype methods, getters and setters here.

    // This has to be last, otherwise the properties won't show up on the
    // object in JavaScript.
    target->Set(name, constructor->GetFunction());
}

PositioningWrapper::PositioningWrapper() {
}

PositioningWrapper::~PositioningWrapper() {
}

Handle<Value> PositioningWrapper::New(const Arguments& args) {
    HandleScope scope;

    if (!args.IsConstructCall()) {
        return ThrowException(Exception::TypeError(
            String::New("Use the new operator to create instances of this object."))
        );
    }
    PositioningProxy* proxy = new PositioningProxy();

    // Creates a new instance object of this type and wraps it.
    PositioningWrapper* obj = new PositioningWrapper();
    obj->mp_proxy = proxy;
    obj->Wrap(args.This());

    return args.This();
}

void RegisterModule(Handle<Object> target) {
    PositioningWrapper::Init(target);
}

NODE_MODULE(PositioningWrapper, RegisterModule);
