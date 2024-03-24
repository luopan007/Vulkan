/*
 * Vulkan examples debug wrapper
 *
 * Copyright (C) 2016-2023 by Sascha Willems - www.saschawillems.de
 *
 * This code is licensed under the MIT license (MIT) (http://opensource.org/licenses/MIT)
 */

#pragma once
#include "vulkan/vulkan.h"

#include <math.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <fstream>
#include <assert.h>
#include <stdio.h>
#include <vector>
#include <sstream>
#ifdef _WIN32
#include <windows.h>
#include <fcntl.h>
#include <io.h>
#endif
#ifdef __ANDROID__
#include "VulkanAndroid.h"
#endif
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>

namespace vks
{
    namespace debug
    {
        // Default debug callback
        /*
         * @brief messageSeverity : 定了消息的严重性，这是一个枚举类型，可以进行比较运算
         *
         * @brief messageType : 定义消息类型，违反标准或者有损性能
         *
         * @brief pCallbackData : 包含了消息本身的一些细节
         *
         * @brief pUserData : 一个在回调配置期间指定的指针，它允许你传递自己的数据
         */
        VKAPI_ATTR VkBool32 VKAPI_CALL debugUtilsMessageCallback(
            VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
            VkDebugUtilsMessageTypeFlagsEXT messageType,
            const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
            void* pUserData);

        // Load debug function pointers and set debug callback
        void setupDebugging(VkInstance instance);
        // Clear debug callback
        void freeDebugCallback(VkInstance instance);
        // Used to populate a VkDebugUtilsMessengerCreateInfoEXT with our example messenger function and desired flags
        void setupDebugingMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& debugUtilsMessengerCI);
    } // end namespace debug

    // Wrapper for the VK_EXT_debug_utils extension
    // These can be used to name Vulkan objects for debugging tools like RenderDoc
    namespace debugutils
    {
        void setup(VkInstance instance);
        void cmdBeginLabel(VkCommandBuffer cmdbuffer, std::string caption, glm::vec4 color);
        void cmdEndLabel(VkCommandBuffer cmdbuffer);
    } // end namespace debugUtils
} // end namespace vks
