//
// Created by 4c3y (acey) on 24.11.22.
//

#include <gtest/gtest.h>
#include <test_utils.h>
#include <log++.h>
#include "callback.h"

using namespace lpp::custom;
using namespace lpp::testing;

TEST(lpp_rosprintf, ros_info) {
  LOG_INIT(*test_argv, logCallback);

  testing::internal::CaptureStdout();
  ROS_INFO(ERROR_MESSAGE, 3.3, 5.5);
  std::string c = testing::internal::GetCapturedStdout();

  ASSERT_EQ(c, info + EXPECTED_ERROR_MESSAGE);
}

TEST(lpp_rosprintf, ros_info_once) {
  LOG_INIT(*test_argv, logCallback);

  testing::internal::CaptureStdout();
  ROS_INFO_ONCE(ERROR_MESSAGE, 3.3, 5.5);
  std::string c = testing::internal::GetCapturedStdout();

  ASSERT_EQ(c, info + EXPECTED_ERROR_MESSAGE);
}

TEST(lpp_rosprintf, ros_warn) {
  LOG_INIT(*test_argv, logCallback);

  testing::internal::CaptureStdout();
  ROS_WARN(ERROR_MESSAGE, 3.3, 5.5);
  std::string c = testing::internal::GetCapturedStdout();

  ASSERT_EQ(c, warning + EXPECTED_ERROR_MESSAGE);
}

TEST(lpp_rosprintf, ros_warn_once) {
  LOG_INIT(*test_argv, logCallback);

  testing::internal::CaptureStdout();
  ROS_WARN_ONCE(ERROR_MESSAGE, 3.3, 5.5);
  std::string c = testing::internal::GetCapturedStdout();

  ASSERT_EQ(c, warning + EXPECTED_ERROR_MESSAGE);
}

TEST(lpp_rosprintf, ros_error) {
  LOG_INIT(*test_argv, logCallback);

  testing::internal::CaptureStdout();
  ROS_ERROR(ERROR_MESSAGE, 3.3, 5.5);
  std::string c = testing::internal::GetCapturedStdout();

  ASSERT_EQ(c, error + EXPECTED_ERROR_MESSAGE);
}

TEST(lpp_rosprintf, ros_error_once) {
  LOG_INIT(*test_argv, logCallback);

  testing::internal::CaptureStdout();
  ROS_ERROR_ONCE(ERROR_MESSAGE, 3.3, 5.5);
  std::string c = testing::internal::GetCapturedStdout();

  ASSERT_EQ(c, error  + EXPECTED_ERROR_MESSAGE);
}