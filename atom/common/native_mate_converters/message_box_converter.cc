// Copyright (c) 2015 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "atom/common/native_mate_converters/message_box_converter.h"

#include "atom/browser/api/atom_api_browser_window.h"
#include "atom/common/native_mate_converters/file_path_converter.h"
#include "atom/common/native_mate_converters/image_converter.h"
#include "native_mate/dictionary.h"

namespace mate {

bool Converter<atom::MessageBoxSettings>::FromV8(
    v8::Isolate* isolate,
    v8::Local<v8::Value> val,
    atom::MessageBoxSettings* out) {
  mate::Dictionary dict;
  if (!ConvertFromV8(isolate, val, &dict))
    return false;
  dict.Get("window", &out->parent_window);
  dict.Get("type", &out->type);
  dict.Get("buttons", &out->buttons);
  dict.Get("defaultId", &out->default_id);
  dict.Get("cancelId", &out->cancel_id);
  dict.Get("options", &out->options);
  dict.Get("title", &out->title);
  dict.Get("message", &out->message);
  dict.Get("detail", &out->detail);
  dict.Get("checkboxLabel", &out->checkbox_label);
  dict.Get("checkboxChecked", &out->checkbox_checked);
  dict.Get("icon", &out->icon);
  return true;
}

}  // namespace mate
