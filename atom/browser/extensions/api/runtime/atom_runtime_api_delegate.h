// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ATOM_BROWSER_EXTENSIONS_API_RUNTIME_ATOM_RUNTIME_API_DELEGATE_H_
#define ATOM_BROWSER_EXTENSIONS_API_RUNTIME_ATOM_RUNTIME_API_DELEGATE_H_

#include <string>

#include "base/macros.h"
#include "extensions/browser/api/runtime/runtime_api_delegate.h"

namespace content {
class BrowserContext;
}  // namespace content

namespace extensions {

class AtomRuntimeAPIDelegate : public RuntimeAPIDelegate {
 public:
  explicit AtomRuntimeAPIDelegate(content::BrowserContext* browser_context);
  ~AtomRuntimeAPIDelegate() override;

  // RuntimeAPIDelegate implementation.
  void AddUpdateObserver(UpdateObserver* observer) override;
  void RemoveUpdateObserver(UpdateObserver* observer) override;
  void ReloadExtension(const std::string& extension_id) override;
  bool CheckForUpdates(const std::string& extension_id,
                       const UpdateCheckCallback& callback) override;
  void OpenURL(const GURL& uninstall_url) override;
  bool GetPlatformInfo(api::runtime::PlatformInfo* info) override;
  bool RestartDevice(std::string* error_message) override;

 private:
  content::BrowserContext* browser_context_;

  DISALLOW_COPY_AND_ASSIGN(AtomRuntimeAPIDelegate);
};

}  // namespace extensions

#endif  // ATOM_BROWSER_EXTENSIONS_API_RUNTIME_ATOM_RUNTIME_API_DELEGATE_H_