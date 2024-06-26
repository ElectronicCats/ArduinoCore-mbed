/*
 * Copyright (c) 2018, Arm Limited and affiliates.
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef GEMALTO_CINTERION_CELLULARCONTEXT_H_
#define GEMALTO_CINTERION_CELLULARCONTEXT_H_

#include "AT_CellularContext.h"

namespace mbed {

class GEMALTO_CINTERION_CellularContext: public AT_CellularContext {
public:
    GEMALTO_CINTERION_CellularContext(ATHandler &at, CellularDevice *device, const char *apn, bool cp_req = false, bool nonip_req = false);
    virtual ~GEMALTO_CINTERION_CellularContext();
    virtual nsapi_error_t connect(const char *sim_pin, const char *apn = 0, const char *uname = 0,
                                  const char *pwd = 0);
    virtual bool get_context();

protected:
#if !NSAPI_PPP_AVAILABLE
    virtual NetworkStack *get_stack();
#endif // NSAPI_PPP_AVAILABLE
    virtual nsapi_error_t do_user_authentication();
    virtual nsapi_error_t enable_access_technology();
};

} /* namespace mbed */

#endif // GEMALTO_CINTERION_CELLULARCONTEXT_H_
